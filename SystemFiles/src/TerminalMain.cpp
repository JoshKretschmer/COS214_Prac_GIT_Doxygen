#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
#include <algorithm>
#include <sstream>

//ignore errors if you have boost beast somewhere on system
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include "../inc/CreateSucculent.h"
#include "../inc/CreateFlower.h"
#include "../inc/CreateShrub.h"
#include "../inc/Inventory.h"
#include "../inc/PlantGroup.h"
#include "../inc/Plant.h"
#include "../inc/PlantCare.h"
#include "../inc/PotDecorator.h"
#include "../inc/WrapDecorator.h"
#include "../inc/ArrangementDecorator.h"
#include "../inc/Request.h"
#include "../inc/Customer.h"
#include "../inc/Staff.h"
#include "../inc/InventoryClerk.h"
#include "../inc/Horticulturist.h"
#include "../inc/Manager.h"
#include "../inc/InventoryCommand.h"
#include "../inc/GreenHouseCommand.h"
#include "../inc/ManagerCommand.h"
#include "../inc/SalesCommand.h"
#include "../inc/SalesAssociate.h"
#include "../inc/Order.h"
#include "../inc/PaymentSystem.h"
#include "../inc/PurchaseFacade.h"

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;
using namespace boost::beast;

//system components
Inventory inventory;
PaymentSystem paymentSystem;
SalesAssociate sales("Alice");
InventoryClerk clerk("Bob");
Horticulturist horti("Charlie");
Manager manager("Dave");
Customer customer("Eve", "CUST001", &sales);
PurchaseFacade facade(&inventory, &paymentSystem);
Order *currentOrder = nullptr;

//find plant by ID
Plant* findPlantByID(const std::string& id) {
    auto plants = inventory.getPlants();
    for (auto p : plants) {
        if (p->getID() == id) return p;
    }
    return nullptr;
}

//get plant options from HTML
std::string getPlantOptions() {
    std::string options = "";
    auto plants = inventory.getPlants();
    for (auto p : plants) {
        std::string details = p->getDetails();
        std::replace(details.begin(), details.end(), '\n', ' ');
        options += "<option value=\"" + p->getID() + "\">" + details + "</option>";
    }
    return options;
}

//parse form data
std::unordered_map<std::string, std::string> parseForm(const std::string& body) {
    std::unordered_map<std::string, std::string> form;
    size_t start = 0;
    while (start < body.size()) {
        size_t amp = body.find('&', start);
        if (amp == std::string::npos) amp = body.size();
        std::string part = body.substr(start, amp - start);
        size_t eq = part.find('=');
        if (eq != std::string::npos) {
            std::string key = part.substr(0, eq);
            std::string val = part.substr(eq + 1);
            std::replace(val.begin(), val.end(), '+', ' ');
            form[key] = val;
        }
        start = amp + 1;
    }
    return form;
}

//get menu links
std::string getMenuLinks() {
    return "<h2>Menu</h2>"
           "<a href='/browse'>1. Browse Plants</a><br>"
           "<a href='/create_order'>2. Create Custom Order</a><br>"
           "<a href='/view_inventory'>3. View Inventory</a><br>"
           "<a href='/staff_request'>4. Process Staff Request</a><br>"
           "<a href='/undo'>5. Undo Last Order Action</a><br>"
           "<a href='/redo'>6. Redo Last Order Action</a><br>"
           "<a href='/complete'>7. Complete Purchase</a><br>";
}

// wrap content in HTML
std::string wrapHTML(const std::string& content) {
    return "<html><body><h1>Plant Nursery Demo</h1>" + content + getMenuLinks() + "</body></html>";
}

//get browse HTML
std::string getBrowseHTML() {
    std::string html = "<h2>Current Inventory:</h2><ul>";
    InventoryIterator *it = inventory.createIterator();
    for (it->first(); it->hasNext(); it->next()) {
        Plant *p = it->currentItem();
        if (p) {
            html += "<li>" + p->getDetails() + " | State: " + p->getState() + " | Cost: $" + std::to_string(p->getCost()) + "</li>";
        }
    }
    delete it;
    html += "</ul>";
    return wrapHTML(html);
}

//view inventory HTML
std::string getViewInventoryHTML() {
    std::string html = "<h2>Inventory Details:</h2><ul>";
    std::vector<Plant *> plants = inventory.getPlants();
    html += "Total plants: " + std::to_string(plants.size()) + "<br>";
    for (Plant *p : plants) {
        html += "<li>" + p->getDetails() + ", Cost: $" + std::to_string(p->getCost()) + "</li>";
    }
    html += "</ul>";
    return wrapHTML(html);
}

//order HTML
std::string getOrderHTML() {
    if (!currentOrder) return "<p>No current order.</p>";
    std::string html = "<h2>Current Order</h2><ul>";
    for (auto p : currentOrder->getPlants()) {
        html += "<li>" + p->getDetails() + "</li>";
    }
    html += "</ul><p>Total cost: $" + std::to_string(currentOrder->getTotalCost()) + "</p>";
    return html;
}

// Handle request
void handleRequest(http::request<http::string_body>& request, tcp::socket& socket) {
    http::response<http::string_body> response;
    response.version(request.version());
    response.result(http::status::ok);
    response.set(http::field::server, "PlantNurseryServer");
    response.set(http::field::content_type, "text/html");

    std::string target(request.target());

    std::string content = "";

    if (target == "/") {
        content = "<p>Welcome to the Plant Nursery Demo</p>";
    } else if (target == "/browse") {
        content = getBrowseHTML();
        response.body() = content;
        goto send_response;
    } else if (target == "/view_inventory") {
        content = getViewInventoryHTML();
        response.body() = content;
        goto send_response;
    } else if (target == "/create_order") {
        std::string options = getPlantOptions();
        content = "<h2>Create Custom Order</h2>"
                  "<form action='/process_create_order' method='post'>"
                  "Select plant:<br>"
                  "<select name='plantid'>" + options + "</select><br>"
                  "Customizations:<br>"
                  "<input type='checkbox' name='pot'> Pot<br>"
                  "<input type='checkbox' name='wrap'> Wrap<br>"
                  "<input type='checkbox' name='arr'> Arrangement<br>"
                  "<input type='submit' value='Done'>"
                  "</form>";
    } else if (target == "/process_create_order" && request.method() == http::verb::post) {
        auto form = parseForm(request.body());
        auto plantIt = form.find("plantid");
        if (plantIt != form.end()) {
            std::string plantid = plantIt->second;
            Plant *plant = findPlantByID(plantid);
            if (plant) {
                Plant *current = plant->clone();
                if (form.count("pot")) {
                    PotDecorator *pot = new PotDecorator();
                    pot->setWrapped(current);
                    current = pot;
                }
                if (form.count("wrap")) {
                    WrapDecorator *wrap = new WrapDecorator();
                    wrap->setWrapped(current);
                    current = wrap;
                }
                if (form.count("arr")) {
                    ArrangementDecorator *arr = new ArrangementDecorator();
                    arr->setWrapped(current);
                    current = arr;
                }
                if (!currentOrder) {
                    currentOrder = facade.initiatePurchase(&customer, current);
                    content = "<p>Order created with customized plant.</p>";
                } else {
                    facade.addPlantToOrder(currentOrder, current);
                    content = "<p>Added customized plant to order.</p>";
                }
                content += getOrderHTML();
            } else {
                content = "<p>Failed to create plant. Invalid selection.</p>";
            }
        } else {
            content = "<p>No plant selected.</p>";
        }
    } else if (target == "/staff_request") {
        std::string options = getPlantOptions();
        content = "<h2>Process Staff Request</h2>"
                  "<form action='/process_staff' method='post'>"
                  "Select request type:<br>"
                  "<select name='reqtype'>"
                  "<option value='1'>Sales</option>"
                  "<option value='2'>Inventory</option>"
                  "<option value='3'>Greenhouse</option>"
                  "<option value='4'>Manager</option>"
                  "</select><br>"
                  "Select plant:<br>"
                  "<select name='plantid'>" + options + "</select><br>"
                  "<input type='submit' value='Submit Request'>"
                  "</form>";
    } else if (target == "/process_staff" && request.method() == http::verb::post) {
        auto form = parseForm(request.body());
        std::string reqtype = form["reqtype"];
        std::string plantid = form["plantid"];
        std::string type;
        if (reqtype == "1") type = "sales";
        else if (reqtype == "2") type = "inventory";
        else if (reqtype == "3") type = "greenhouse";
        else if (reqtype == "4") type = "manager";
        else {
            content = "<p>Invalid request type.</p>";
            goto wrap;
        }
        Request *req = customer.makeRequest(type, plantid, type == "sales" ? "Pot" : "");
        if (type == "sales") {
            SalesCommand cmd(req);
            sales.handleCommand(&cmd);
        } else if (type == "inventory") {
            InventoryCommand cmd(req);
            sales.handleCommand(&cmd);
        } else if (type == "greenhouse") {
            GreenHouseCommand cmd(req);
            sales.handleCommand(&cmd);
        } else if (type == "manager") {
            ManagerCommand cmd(req);
            sales.handleCommand(&cmd);
        }
        delete req;
        content = "<p>Request processed.</p>";
    } else if (target == "/undo") {
        if (currentOrder) {
            facade.undoLastStep(currentOrder);
            content = "<p>Undone last action.</p>" + getOrderHTML();
        } else {
            content = "<p>No order to undo.</p>";
        }
    } else if (target == "/redo") {
        if (currentOrder) {
            facade.redoStep(currentOrder);
            content = "<p>Redone last action.</p>" + getOrderHTML();
        } else {
            content = "<p>No order to redo.</p>";
        }
    } else if (target == "/complete") {
        if (currentOrder) {
            facade.completePurchase(currentOrder);
            //remove originals from inventory by ID
            auto plants = currentOrder->getPlants();
            for (auto p : plants) {
                std::string id = p->getID();
                Plant* original = findPlantByID(id);
                if (original) {
                    inventory.remove(original);
                    delete original; // Cleanup removed plant
                }
            }
            delete currentOrder;
            currentOrder = nullptr;
            content = "<p>Purchase completed.</p>";
        } else {
            content = "<p>No order to complete.</p>";
        }
    } else {
        response.result(http::status::not_found);
        content = "<p>404 Not Found</p>";
    }

wrap:
    response.body() = wrapHTML(content);

send_response:
    response.prepare_payload();
    http::write(socket, response);
    boost::system::error_code ec;
    socket.shutdown(tcp::socket::shutdown_both, ec);
    // Ignore shutdown errors
}

void runServer() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, {tcp::v4(), 8080});
    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        boost::beast::flat_buffer buffer;
        http::request<http::string_body> request;
        http::read(socket, buffer, request);
        handleRequest(request, socket);
    }
}

int main() {
    std::cout << "Starting Plant Nursery Web Server on http://localhost:8080" << std::endl;

    //initialize chain
    sales.setNextHandler(&clerk);
    clerk.setNextHandler(&horti);
    horti.setNextHandler(&manager);
    clerk.assignJob(&inventory);

    //seed inventory
    CreateSucculent succulentFactory;
    CreateFlower flowerFactory;
    CreateShrub shrubFactory;
    inventory.addPlant(succulentFactory.createPlant("PeanutCactus"));
    inventory.addPlant(succulentFactory.createPlant("HouseLeek"));
    inventory.addPlant(flowerFactory.createPlant("Orchid"));
    inventory.addPlant(shrubFactory.createPlant("HoneySuckle"));
    inventory.addPlant(shrubFactory.createPlant("BeeBlossom"));

    try {
        runServer();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
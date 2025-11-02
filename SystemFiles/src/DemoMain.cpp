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


//with better styling
std::string getMenuLinks() {
    return R"(
        <div class="menu">
            <h2>Navigation Menu</h2>
            <div class="menu-links">
                <a class="menu-link" href='/browse'>Browse Plants</a>
                <a class="menu-link" href='/create_order'>Create Custom Order</a>
                <a class="menu-link" href='/view_inventory'>View Inventory</a>
                <a class="menu-link" href='/staff_request'>Staff Assistance</a>
                <a class="menu-link" href='/undo'>Undo Last Action</a>
                <a class="menu-link" href='/redo'>Redo Last Action</a>
                <a class="menu-link" href='/complete'>Complete Purchase</a>
            </div>
        </div>
    )";
}


//added greenhouse-themed CSS
std::string wrapHTML(const std::string& content) {
    std::string css = R"(
        <style>
            * {
                margin: 0;
                padding: 0;
                box-sizing: border-box;
            }
            
            body {
                font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
                background: linear-gradient(135deg, #e8f5e8 0%, #c8e6c9 50%, #a5d6a7 100%);
                min-height: 100vh;
                padding: 20px;
                color: #2e7d32;
            }
            
            .container {
                max-width: 1200px;
                margin: 0 auto;
                background: rgba(255, 255, 255, 0.95);
                border-radius: 20px;
                box-shadow: 0 10px 30px rgba(76, 175, 80, 0.2);
                overflow: hidden;
                border: 2px solid #4caf50;
            }
            
            .header {
                background: linear-gradient(135deg, #4caf50 0%, #2e7d32 100%);
                color: white;
                padding: 30px;
                text-align: center;
                position: relative;
                overflow: hidden;
            }
            
            .header::before {
                content: "";
                font-size: 120px;
                position: absolute;
                opacity: 0.1;
                top: 10px;
                right: 20px;
            }
            
            .header h1 {
                font-size: 2.5em;
                margin-bottom: 10px;
                text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
            }
            
            .header p {
                font-size: 1.2em;
                opacity: 0.9;
            }
            
            .content {
                padding: 30px;
            }
            
            .menu {
                background: #f1f8e9;
                padding: 25px;
                border-radius: 15px;
                margin: 20px 0;
                border-left: 5px solid #4caf50;
            }
            
            .menu h2 {
                color: #1b5e20;
                margin-bottom: 15px;
                font-size: 1.4em;
            }
            
            .menu-links {
                display: grid;
                grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
                gap: 12px;
            }
            
            .menu-link {
                display: block;
                background: white;
                padding: 15px 20px;
                text-decoration: none;
                color: #2e7d32;
                border-radius: 10px;
                transition: all 0.3s ease;
                border: 2px solid #c8e6c9;
                font-weight: 500;
            }
            
            .menu-link:hover {
                background: #4caf50;
                color: white;
                transform: translateY(-2px);
                box-shadow: 0 5px 15px rgba(76, 175, 80, 0.3);
            }
            
            h2 {
                color: #1b5e20;
                margin: 25px 0 15px 0;
                font-size: 1.6em;
                border-bottom: 2px solid #a5d6a7;
                padding-bottom: 8px;
            }
            
            ul {
                list-style: none;
                margin: 15px 0;
            }
            
            li {
                background: #f1f8e9;
                margin: 8px 0;
                padding: 12px 15px;
                border-radius: 8px;
                border-left: 4px solid #4caf50;
                transition: transform 0.2s ease;
            }
            
            li:hover {
                transform: translateX(5px);
                background: #e8f5e8;
            }
            
            form {
                background: #f1f8e9;
                padding: 25px;
                border-radius: 15px;
                margin: 20px 0;
            }
            
            select, input[type="text"], input[type="submit"] {
                width: 100%;
                padding: 12px;
                margin: 8px 0;
                border: 2px solid #c8e6c9;
                border-radius: 8px;
                font-size: 16px;
                background: white;
                color: #2e7d32;
            }
            
            input[type="submit"] {
                background: linear-gradient(135deg, #4caf50 0%, #2e7d32 100%);
                color: white;
                border: none;
                cursor: pointer;
                font-weight: bold;
                transition: all 0.3s ease;
            }
            
            input[type="submit"]:hover {
                transform: translateY(-2px);
                box-shadow: 0 5px 15px rgba(76, 175, 80, 0.4);
            }
            
            .checkbox-group {
                margin: 15px 0;
            }
            
            .checkbox-item {
                display: flex;
                align-items: center;
                margin: 10px 0;
                padding: 10px;
                background: white;
                border-radius: 8px;
                border: 2px solid #e8f5e8;
            }
            
            .checkbox-item input[type="checkbox"] {
                margin-right: 10px;
                transform: scale(1.2);
            }
            
            .order-summary {
                background: #e8f5e8;
                padding: 20px;
                border-radius: 12px;
                border: 2px solid #4caf50;
                margin: 20px 0;
            }
            
            .order-total {
                font-size: 1.3em;
                font-weight: bold;
                color: #1b5e20;
                text-align: center;
                margin-top: 15px;
                padding-top: 15px;
                border-top: 2px solid #a5d6a7;
            }
            
            .success-message {
                background: #c8e6c9;
                color: #1b5e20;
                padding: 15px;
                border-radius: 8px;
                margin: 15px 0;
                border-left: 4px solid #4caf50;
            }
            
            .error-message {
                background: #ffcdd2;
                color: #c62828;
                padding: 15px;
                border-radius: 8px;
                margin: 15px 0;
                border-left: 4px solid #f44336;
            }
            
            .plant-card {
                background: white;
                padding: 20px;
                margin: 15px 0;
                border-radius: 12px;
                box-shadow: 0 4px 8px rgba(0,0,0,0.1);
                border: 1px solid #c8e6c9;
                transition: all 0.3s ease;
            }
            
            .plant-card:hover {
                transform: translateY(-3px);
                box-shadow: 0 6px 12px rgba(0,0,0,0.15);
            }
            
            .plant-list {
                margin: 20px 0;
            }
            
            @media (max-width: 768px) {
                .container {
                    margin: 10px;
                    border-radius: 15px;
                }
                
                .header h1 {
                    font-size: 2em;
                }
                
                .menu-links {
                    grid-template-columns: 1fr;
                }
            }
        </style>
    )";
    
    std::string html = R"(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Greenhouse Plant Nursery</title>
            )" + css + R"(
        </head>
        <body>
            <div class="container">
                <div class="header">
                    <h1>Greenhouse Plant Nursery</h1>
                    <p>Your one-stop shop for beautiful plants and expert gardening advice</p>
                </div>
                <div class="content">
                    )" + content + getMenuLinks() + R"(
                </div>
            </div>
        </body>
        </html>
    )";
    
    return html;
}


//get browse HTML
std::string getBrowseHTML() {
    std::string html = "<h2>Current Plant Collection</h2><div class='plant-list'>";
    InventoryIterator *it = inventory.createIterator();
    for (it->first(); it->hasNext(); it->next()) {
        Plant *p = it->currentItem();
        if (p) {
            html += "<div class='plant-card'>";
            html += "<strong>" + p->getDetails() + "</strong><br>";
            html += "State: " + p->getState() + " | Cost: $" + std::to_string(p->getCost());
            html += "</div>";
        }
    }
    delete it;
    html += "</div>";
    return wrapHTML(html);
}

//view inventory HTML
std::string getViewInventoryHTML() {
    std::string html = "<h2>Inventory Details</h2><div class='plant-list'>";
    std::vector<Plant *> plants = inventory.getPlants();
    html += "<p><strong>Total plants: " + std::to_string(plants.size()) + "</strong></p>";
    for (Plant *p : plants) {
        html += "<div class='plant-card'>";
        html += "<strong>" + p->getDetails() + "</strong><br>";
        html += "Cost: $" + std::to_string(p->getCost());
        html += "</div>";
    }
    html += "</div>";
    return wrapHTML(html);
}

//order HTML
std::string getOrderHTML() {
    if (!currentOrder) return "<div class='error-message'>No current order active.</div>";
    
    std::string html = "<div class='order-summary'><h2>Current Order</h2><ul>";
    for (auto p : currentOrder->getPlants()) {
        html += "<li>" + p->getDetails() + "</li>";
    }
    html += "</ul><div class='order-total'>Total Cost: $" + std::to_string(currentOrder->getTotalCost()) + "</div></div>";
    return html;
}

//handle request
void handleRequest(http::request<http::string_body>& request, tcp::socket& socket) {
    http::response<http::string_body> response;
    response.version(request.version());
    response.result(http::status::ok);
    response.set(http::field::server, "PlantNurseryServer");
    response.set(http::field::content_type, "text/html");

    std::string target(request.target());

    std::string content = "";

    if (target == "/") {
        content = "<div class='success-message'>Welcome to the Plant Nursery Demo</div>";
    } else if (target == "/browse") {
        content = getBrowseHTML();
        response.body() = content;
        http::write(socket, response);
        return;
    } else if (target == "/view_inventory") {
        content = getViewInventoryHTML();
        response.body() = content;
        http::write(socket, response);
        return;
    } else if (target == "/create_order") {
        std::string options = getPlantOptions();
        content = R"(
            <h2>Create Custom Order</h2>
            <form action='/process_create_order' method='post'>
                <label><strong>Select Plant:</strong></label>
                <select name='plantid'>)" + options + R"(</select>
                
                <div class="checkbox-group">
                    <label><strong>Customizations:</strong></label>
                    <div class="checkbox-item">
                        <input type='checkbox' name='pot' id='pot'>
                        <label for='pot'>Pot Decorator</label>
                    </div>
                    <div class="checkbox-item">
                        <input type='checkbox' name='wrap' id='wrap'>
                        <label for='wrap'>Gift Wrap</label>
                    </div>
                    <div class="checkbox-item">
                        <input type='checkbox' name='arr' id='arr'>
                        <label for='arr'>Arrangement</label>
                    </div>
                </div>
                
                <input type='submit' value='Add to Order'>
            </form>
        )";
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
                    content = "<div class='success-message'>Order created with customized plant.</div>";
                } else {
                    facade.addPlantToOrder(currentOrder, current);
                    content = "<div class='success-message'>Added customized plant to order.</div>";
                }
                content += getOrderHTML();
            } else {
                content = "<div class='error-message'>Failed to create plant. Invalid selection.</div>";
            }
        } else {
            content = "<div class='error-message'>No plant selected.</div>";
        }
    } else if (target == "/staff_request") {
        std::string options = getPlantOptions();
        content = R"(
            <h2>Process Staff Request</h2>
            <form action='/process_staff' method='post'>
                <label><strong>Select request type:</strong></label>
                <select name='reqtype'>
                    <option value='1'>Sales</option>
                    <option value='2'>Inventory</option>
                    <option value='3'>Greenhouse</option>
                    <option value='4'>Manager</option>
                </select>
                
                <label><strong>Select plant:</strong></label>
                <select name='plantid'>)" + options + R"(</select>
                
                <input type='submit' value='Submit Request'>
            </form>
        )";
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
            content = "<div class='error-message'>Invalid request type.</div>";
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
        content = "<div class='success-message'>Request processed successfully.</div>";
        } else if (target == "/undo") {
            if (currentOrder) {
                facade.undoLastStep(currentOrder);
                content = "<div class='success-message'>Undone last action.</div>" + getOrderHTML();
            } else {
                content = "<div class='error-message'>No order to undo.</div>";
            }
        } else if (target == "/redo") {
            if (currentOrder) {
                facade.redoStep(currentOrder);
                content = "<div class='success-message'>Redone last action.</div>" + getOrderHTML();
            } else {
                content = "<div class='error-message'>No order to redo.</div>";
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
                        delete original; //cleanup removed plant
                    }
                }
                delete currentOrder;
                currentOrder = nullptr;
                content = "<div class='success-message'>Purchase completed successfully.</div>";
            } else {
                content = "<div class='error-message'>No order to complete.</div>";
            }
        } else {
            response.result(http::status::not_found);
            content = "<div class='error-message'>404 Not Found</div>";
        }

    wrap:
        response.body() = wrapHTML(content);

        response.prepare_payload();
        
        //use a try-catch block to handle connection errors
        try {
            http::write(socket, response);
            
            //gracefully close the connection
            boost::system::error_code ec;
            socket.shutdown(tcp::socket::shutdown_send, ec);
            //ignore errors during shutdown
        } catch (const std::exception& e) {
            std::cerr << "Error writing response: " << e.what() << std::endl;
        }
}

void runServer() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, {tcp::v4(), 8080});
    
    std::cout << "Server running on http://localhost:8080" << std::endl;
    std::cout << "Press Ctrl+C to stop the server" << std::endl;
    
    while (true) {
        try {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            
            boost::beast::flat_buffer buffer;
            http::request<http::string_body> request;
            
            //Read the request with error handling
            boost::system::error_code ec;
            http::read(socket, buffer, request, ec);
            
            if (ec) {
                if (ec == http::error::end_of_stream) {
                    // disconnected, just continue
                    continue;
                }
                std::cerr << "Error reading request: " << ec.message() << std::endl;
                continue;
            }
            
            //handle the request
            handleRequest(request, socket);
            
        } catch (const std::exception& e) {
            std::cerr << "Server error: " << e.what() << std::endl;
            //Continue running the server even if one request fails
        }
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
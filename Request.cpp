#include "Request.h"

Request::Request() {
    this->action = "";
    this->details = "";
    this->type = "";
}

Request::Request(string type, string details, string action) {
    this->type = type;
    this->details = details;
    this->action = action;
}

Request::~Request() {

}

string Request::getType() {
    return this->type;
}

string Request::getDetails() {
    return this->details;
}

string Request::getAction() {
    return this->action;
}

void Request::setType(string type) {
    if (type.empty()) {
        this->type = "General";
        return;
    }
    this->type = type;
}

void Request::setDetails(string details) {
    this->details = details;
}

void Request::setAction(string action) {
    this->action = action;
}
#include "Discussion.h"

Discussion::Discussion(const std::string& topic) : topic(topic) {}

void Discussion::addMessage(const std::string& msg) {
    messages.push_back(msg);
}

std::vector<std::string> Discussion::getMessages() const {
    return messages;
}

std::string Discussion::getTopic() const {
    return topic;
}

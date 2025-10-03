/**
 * @file Discussion.h
 * @brief Defines the Discussion class for the Nursery System.
 */
#ifndef DISCUSSION_H
#define DISCUSSION_H

#include <string>
#include <vector>

/**
 * @class Discussion
 * @brief Represents a discussion topic in the nursery.
 */
class Discussion {
private:
    std::string topic;
    std::vector<std::string> messages;

public:
    Discussion(const std::string& topic);

    void addMessage(const std::string& msg);
    std::vector<std::string> getMessages() const;
    std::string getTopic() const;
};

#endif

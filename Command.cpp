#include "Command.h"
#include <iostream>

Command::Command() {

}

//##################################################

CareCommand::CareCommand() {

}

void CareCommand::execute() {
    std::cout << "Executing plant care command..." << std::endl;
}

//##################################################

PurchaseCommand::PurchaseCommand() {
    
}

void PurchaseCommand::execute() {
    std::cout << "Executing purchase command..." << std::endl;
}

//##################################################

CommandManager::CommandManager() {

}

void CommandManager::execute() {
    std::cout << "Executing command manager sequence..." << std::endl;
}

Command::~Command() {}
CareCommand::~CareCommand() {}
PurchaseCommand::~PurchaseCommand() {}
CommandManager::~CommandManager() {}




#include "Command.h"

Command::Command(Request* _receiver)
{
    if(_receiver)
    {
        receiver = _receiver;
    }
    else
    {
        cout<<"\n Request object is invalid :)\n";
    }
}

Command::~Command()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}





// ...................... PURCHASE COMMAND .........................//

PurchaseCommand::PurchaseCommand(Request* _receiver) : Command(_receiver)
{
    // no further initialization required :)
}

PurchaseCommand::~PurchaseCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

void PurchaseCommand::execute()
{
    receiver->sendToStaff(); //changes to be made here
}





// ...................... CARE COMMAND .........................//

CareCommand::CareCommand(Request* _receiver) : Command(_receiver)
{
    // no further initialization required :)
}

CareCommand::~CareCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

void CareCommand::execute()
{
    receiver->sendToStaff(); //changes to be made here
}





// ...................... MANAGER COMMAND .........................//

ManagerCommand::ManagerCommand(Request* _receiver) : Command(_receiver)
{
    // no further initialization required :)
}

ManagerCommand::~ManagerCommand()
{
    // no memory management required as Command is not responsible for Request object once it is passed on :)
}

void ManagerCommand::execute()
{
    receiver->sendToStaff(); //changes to be made here
}
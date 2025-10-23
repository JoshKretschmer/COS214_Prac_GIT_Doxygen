#ifndef COMMAND_H
#define COMMAND_H

#include "libraries.h"
#include "Request.h"

class Command
{
protected:
    Request* receiver;

public:
    Command(Request* _receiver);
    virtual ~Command();
    virtual void execute()=0;
};


class PurchaseCommand : public Command
{
public:
    PurchaseCommand(Request* _receiver);
    virtual ~PurchaseCommand();
    virtual void execute() override;
};


class CareCommand : public Command
{
public:
    CareCommand(Request* _receiver);
    virtual ~CareCommand();
    virtual void execute() override;
};

class ManagerCommand : public Command
{
public:
    ManagerCommand(Request* _receiver);
    virtual ~ManagerCommand();
    virtual void execute() override;
};

#endif
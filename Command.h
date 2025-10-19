#ifndef COMMAND_H
#define COMMAND_H



class Command {
    public:
        Command();
        virtual ~Command();
        virtual void execute()=0;
};

class CareCommand : public Command {
    public:
        CareCommand();
        void execute();
};

class PurchaseCommand : public Command {
    public:
        PurchaseCommand();
        void execute();
};

class CommandManager : public Command {
    public:
        CommandManager();
        void execute();
};



#endif //COMMAND_H

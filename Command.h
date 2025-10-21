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
        ~CareCommand() override;
        void execute();
};

class PurchaseCommand : public Command {
    public:
        PurchaseCommand();
        ~PurchaseCommand() override;
        void execute();
};

class CommandManager : public Command {
    public:
        CommandManager();
        ~CommandManager() override;
        void execute();
};



#endif //COMMAND_H

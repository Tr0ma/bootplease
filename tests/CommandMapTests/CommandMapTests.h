#include "events\Event.h"
#include "commands\Command.h"

class CommandA : public Command
{
public:
    CommandA(CommandMap& commandMap) : Command(commandMap) {};
    ~CommandA();

    virtual void Execute() override;

    void OnRelease(const Event& event);
};

class CommandB : public Command
{
public:
    CommandB(CommandMap& commandMap) : Command(commandMap) {};
    ~CommandB();

    virtual void Execute() override;
};

class ExampleEvent : public Event
{
public:
    static const char* START_COMMAND_A;
    static const char* START_COMMAND_B;
    static const char* RELEASE_COMMAND_A;

    explicit ExampleEvent(const char* type) : Event(type) {}
};
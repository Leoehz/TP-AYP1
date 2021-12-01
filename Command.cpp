#include "Command.h"
#include <iostream>
#include <string>

// This is a test

enum CommandType {Fibonacci, Hanoi};

struct UndavCommand::Command{
    string name;
    UndavCommand::CommandType commandType;
    int parameter_int;
};

UndavCommand::Command* UndavCommand::CreateFibonacciCommand(unsigned int n)
{
    Command* fibCommand = new Command;

    fibCommand->name = "Fib(" + std::to_string(n) + ")";
    fibCommand->commandType = Fibonacci;
    fibCommand->parameter_int = n;

    return fibCommand;
}

UndavCommand::Command* UndavCommand::CreateHanoiCommand(unsigned int disks)
{
    Command* hanoiCommand = new Command;

    hanoiCommand->name = "Hanoi for " + std::to_string(disks) +" disks";
    hanoiCommand->commandType = Hanoi;
    hanoiCommand->parameter_int = disks;

    return hanoiCommand;
}

string UndavCommand::GetName(Command* command)
{
    return command->name;
}

void UndavCommand::Execute(Command* command)
{

    switch(command->commandType)
    {
        case Fibonacci:
            std::cout<<UndavCommand::GetName(command)<<"="<<UndavCommand::ExecuteFib(command->parameter_int)<<std::endl;
        break;

        case Hanoi:
            std::cout<<"Total moves: "<<UndavCommand::ExecuteHanoi(command->parameter_int)<<std::endl;
        break;
    }
}

void UndavCommand::Destroy(Command* command)
{
    delete command;
}

int UndavCommand::ExecuteFib(unsigned int n)
{
    if(n == 1) return 1;
    else if (n == 2) return 1;
    else return ExecuteFib(n-1) + ExecuteFib(n-2);
}

int UndavCommand::ExecuteHanoi(unsigned int disks)
{
    if(disks == 1) return 1;
    else if (disks == 2) return 3;
    else return 2*ExecuteHanoi(disks-1) + 1;
}

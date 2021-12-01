#include "BenchmarkMachine.h"
#include "Command.h"
#include <string>
#include <iostream>
#include <chrono>

struct UndavBenchmarkMachine::BenchmarkMachine{
    string description;
    Command* commands[10];
    int n_commands;

};

UndavBenchmarkMachine::BenchmarkMachine* UndavBenchmarkMachine::Create(string description)
{
    BenchmarkMachine* benchmarkMachine = new BenchmarkMachine;
    benchmarkMachine->description = description;
    benchmarkMachine->commands[0] = NULL;
    benchmarkMachine->n_commands = 0;

    return benchmarkMachine;
}

string UndavBenchmarkMachine::GetDescription(BenchmarkMachine* machine)
{
    return machine->description;
}

void UndavBenchmarkMachine::AddCommand(BenchmarkMachine* machine, Command* command)
{
    machine->commands[machine->n_commands] = command;
    machine->n_commands++;
}


void UndavBenchmarkMachine::Execute(BenchmarkMachine* machine)
{
    int command_count = machine->n_commands;

    for (int i = 0; i < command_count; ++i)
    {
        auto beginTime = std::chrono::high_resolution_clock::now();

        std::cout<<"Running "<<UndavCommand::GetName(machine->commands[i])<<"...\n\n";

        UndavCommand::Execute(machine->commands[i]);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

        std::cout<<"Running time:"<<deltaTime.count()<<"ms\n\n";
    }
}

void UndavBenchmarkMachine::Destroy(BenchmarkMachine* machine)
{
    delete machine;
}

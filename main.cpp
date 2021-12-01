#include <iostream>
#include "Command.h"
#include "BenchmarkMachine.h"

using namespace std;
using namespace UndavBenchmarkMachine;
using namespace UndavCommand;

void RunHanoiBenchmark();
void RunFibonacciBenchmark();
void RunBenchmark(BenchmarkMachine* machine, Command** commands, int count);
void DestroyCommands(Command** commands, int count);

int main() {
	RunFibonacciBenchmark();
	RunHanoiBenchmark();
	return 0;
}

void RunHanoiBenchmark(){
	BenchmarkMachine* benchmark = Create("Pruebas sobre hanoi");
	Command* hanoiCommands[4] = {CreateHanoiCommand(3),CreateHanoiCommand(6),CreateHanoiCommand(12),CreateHanoiCommand(18)};
	RunBenchmark(benchmark, hanoiCommands, 4);
	Destroy(benchmark);
	DestroyCommands(hanoiCommands, 4);
}

void RunFibonacciBenchmark(){
	BenchmarkMachine* benchmark = Create("Pruebas sobre Fibonacci");
	Command* fibonacciCommands[4] = {CreateFibonacciCommand(3),CreateFibonacciCommand(9),CreateFibonacciCommand(27),CreateFibonacciCommand(39)};
	RunBenchmark(benchmark, fibonacciCommands, 4);
	Destroy(benchmark);
	DestroyCommands(fibonacciCommands, 4);
}

void RunBenchmark(BenchmarkMachine* machine, Command** commands, int count){
	for(int i=0; i<count;++i){
		AddCommand(machine, commands[i]);
	}

	cout<<"------------------------------"<<endl;
	cout<<GetDescription(machine)<<endl;
	Execute(machine);
	cout<<"------------------------------"<<endl;
}

void DestroyCommands(Command** commands, int count){
	for(int i=0; i<count; ++i){
		Destroy(commands[i]);
	}
}

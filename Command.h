#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
using std::string;

// this is a test

namespace UndavCommand{
	struct Command;

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia lista para utilizar de Command que
	// tiene como nombre el string: "Fib([n])" donde [n] es @n y que al ejecutarse
	// corre el algoritmo de fibonacci (recursivo!) para calcular el fib(n) y muestra por pantalla
	// "Fib(n)=[resultado]" donde [resultado] es el numero de fibonacci para @n
	Command* CreateFibonacciCommand(unsigned int n);

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia lista para utilizar de Command que
	// tiene como nombre el string: "Hanoi for [n] disks" donde [n] es @disks y que al ejecutarse
	// corre el algoritmo de Hanoi (recursivo!) para la cantidad de discos dada por @disks y debe mostrar por pantalla
	// "Total moves [moves]" donde moves es la cantidad de movimientos necesarios para completar el juego de hanoi para la cantidad
	// de discos dadas por @disks
	Command* CreateHanoiCommand(unsigned int disks);

	// Precondicion: @command es una instancia valida
	// Postcondicion: Devuelve el nombre de @command
	string GetName(Command* command);

	// Precondicion: @command es una instancia valida
	// Postcondicion: Ejecuta el comando @command
	void Execute(Command* command);

	// Precondicion: @command es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @command
	void Destroy(Command* command);

	int ExecuteFib(unsigned int n);

	int ExecuteHanoi(unsigned int disks);
}

#endif


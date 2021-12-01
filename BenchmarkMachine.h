#ifndef BENCHMARKMACHINE_H_
#define BENCHMARKMACHINE_H_
#include <string>
#include "Command.h"

using std::string;
using UndavCommand::Command;

namespace UndavBenchmarkMachine{
	struct BenchmarkMachine;

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia lista para utilizar de BenchmarkMachine que
	// tiene una descripcion igual a @description
	BenchmarkMachine* Create(string description);

	// Precondicion: @machine es una instancia valida
	// Postcondicion: Devuelve la descripcion de @machine
	string GetDescription(BenchmarkMachine* machine);

	// Precondicion: @machine y @command son instancias validas
	// Postcondicion: Agrega el comando @command a @machine
	void AddCommand(BenchmarkMachine* machine, Command* command);

	// Precondicion: @machine es una instancia valida
	// Postcondicion: Ejecuta cada uno de los comandos que tiene @machine tomando el tiempo en milisegundos
	// Por cada comando se espera la siguiente salida por pantalla
	// - Antes de que se ejecute el comando se espera el texto: "Running [nombreComando]..."
	// - Luego de la ejecucion del comando se espera el texto: "Running time:[t]ms"
	// donde [nombreComando] es el nombre del comando y [t] es el tiempo en milisegundos
	void Execute(BenchmarkMachine* machine);

	// Precondicion: @machine es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @machine
	void Destroy(BenchmarkMachine* machine);
}

#endif


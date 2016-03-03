#include <iostream>

#include "lib/Interfaz.hpp"

#include "lib/Random.h"
#include "lib/Timer.h"

#include "lib/Instance.hpp"
#include "KP/SolucionMochila.hpp"
#include "TSP/SolucionViajante.hpp"

using namespace std;

int main(int argc, char **argv) {
	Interfaz cli;

	//Siempre se ejcuta hasta que el usuario quiera salir
	while(true) {
		if(not cli.option_menu())
			break;

		//Se ejecuta hasta que se carga una instancia de un fichero valido
		vector<problem_element> inst_v = cli.read_instance();

		//Aqui iria el codigo que hace algo con una instancia
		cli.print_instance(inst_v);
	}

	return 0;
}
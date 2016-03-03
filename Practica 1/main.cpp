#include <iostream>

#include "lib/Interfaz.hpp"

/*
#include "lib/Random.h"
#include "lib/Timer.h"
*/

#include "KP/SolucionMochila.hpp"
#include "TSP/SolucionViajante.hpp"

using namespace std;

int main(int argc, char **argv) {
	Interfaz cli;

	do {
		cli.option_menu();
	} while(cli.getOpt());

	cout << "Esto es el main, no tiene ninguna funcionalidad." << endl;

	return 0;
}
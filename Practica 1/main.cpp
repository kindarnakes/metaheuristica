#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


#include "lib/Interfaz.hpp"

#include "lib/Random.h"
#include "lib/Timer.h"

#include "lib/Instance.hpp"
#include "KP/InstanceKP.hpp"
#include "TSP/InstanceTSP.hpp"
#include "KP/SolucionMochila.hpp"
#include "TSP/SolucionViajante.hpp"
#include "KP/SolGeneratorMochila.hpp"
#include "TSP/SolGeneratorViajante.hpp"


using namespace std;

int main(int argc, char **argv) {

	Interfaz cli;
	srand(time(NULL));


	//Siempre se ejcuta hasta que el usuario quiera salir
	while(true) {
		if(not cli.option_menu())
			break;

		//Se ejecuta hasta que se carga una instancia de un fichero valido
		vector<problem_element> inst_v = cli.read_instance();

		//Aqui iria el codigo que hace algo con una instancia
		//cli.print_instance(inst_v);

		//El problema seleccionado es TSP
		if(cli.getOpt() == 1){
			InstanceTSP tsp_instance(cli.getFileName());
			SolucionViajante best_solution(inst_v.size()), current_solution;
			SolGeneratorViajante sol_gen;
			double best_fitness = 0, actual_fitness = 0;

			//Obtenemos 1000 soluciones diferentes
			for(unsigned int i = 0; i < 1000; i++){
				current_solution = sol_gen.randomSolutionGenerator(inst_v.size());
				actual_fitness = tsp_instance.getAptitude(inst_v, current_solution);

				if(actual_fitness > best_fitness){
					best_solution = current_solution;
					best_fitness = actual_fitness;
				}
			}

			//Muestra la solucion
			cout << "El orden del recorrido es :\n";
			for(auto i : best_solution.getSolucion())
				cout << i << " -> ";

			cout << "\ny la distancia total recorrida " << best_fitness << endl;

		//El problema seleccionado es KP
		} else{
			InstanceKP kp_instance(cli.getFileName());
			SolucionMochila best_solution(inst_v.size()), current_solution;
			SolGeneratorMochila sol_gen;
			double best_fitness = -100, actual_fitness = 0;

			//------------------------------------> Nesesitoh el tamanho de la moshila premoh <-----------------------
			double KP_size = 12000;

			//Obtenemos 1000 soluciones diferentes
			for(unsigned int i = 0; i < 1000; i++){
				current_solution = sol_gen.randomSolutionGenerator(inst_v.size());
				actual_fitness = kp_instance.getAptitude(current_solution, KP_size, inst_v);

				if(actual_fitness > best_fitness){
					best_solution = current_solution;
					best_fitness = actual_fitness;
				}
			}
		}

	}

	return 0;
}

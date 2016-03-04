#include <iostream>
#include <cstdlib>
#include <vector>


#include "lib/Interfaz.hpp"

//#include "lib/Random.h"
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
		cli.print_instance(inst_v);


		//El problema seleccionado es TSP
		if(cli.getTypeProblem() == 1){

			SolucionViajante best_solution(inst_v.size()), actual_solution;
			SolGeneratorViajante soluciones_a_gogo;	//XD No se me ocurria un nombre mejor
			double best_fitness = 0;

			//Obtenemos 1000 soluciones diferentes
			for(unsigned int i = 0; i < 1000; i++){


				/*	Pues parece que vamos a necesitar un constructor de copia


				anterior = posterior;
				posterior = soluciones_a_gogo(inst_v.size());

				//Comparamos el valor de aptitud actual con el mejor encontrando hasta entonces
				//Si es mejor, la guardamos como mejor solucion y mejor fitness y continuamos
				*/
			}

		}



		//El problema seleccionado es KP
		else{

		


		}

	}

	return 0;
}

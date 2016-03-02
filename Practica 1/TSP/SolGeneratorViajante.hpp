#ifndef __SOL_GENERATOR_VIAJANTE_HPP__
#define __SOL_GENERATOR_VIAJANTE_HPP__


#include "SolucionViajante.hpp"
#include "../lib/Miscelanea.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class SolGeneratorViajante{


	public:

		/* ----------------------------------------------------

			Funcion que genera una nueva solucion aleatoria a 
		partir de una permutacion dada, intercambiando N veces
		las posiciones de dos ciudades en el orden del camino 

		----------------------------------------------------- */

		void randomSolutionGenerator(vector <SolucionViajante> &solution){

		  int randPos, aux;

			srand(time(NULL));

			for(unsigned int i = 0; i < solution.size(); i++){

				randPos = rand() % solution.size();
				aux = solution[i];

				solution[i] = solution[randPos];
				solution[randPos] = solution[i];
			}

		}
};


#endif

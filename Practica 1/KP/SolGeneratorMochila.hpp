#ifndef __SOL_GENERATOR_MOCHILA_HPP__
#define __SOL_GENERATOR_MOCHILA_HPP__

#include "SolucionViajante.hpp"
#include "../lib/Miscelanea.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class SolGeneratorMochila{


	public:

		/* ----------------------------------------------------

			Funcion que genera una nueva solucion aleatoria 
		decidiendo el numero de elementos que se incluiran en la
		mochila, y despues en que posiciones

		----------------------------------------------------- */

		void randomSolutionGenerator(vector <SolucionMochila> &solution){

		  int randNum, randPos, aux;

			srand(time(NULL));

			for(unsigned int i = 0; i < solution.size(); i++)
				solution[i] = false;


			randNum = rand() % solution.size();		//Numero de elementos que se incluiran en la mochila
			for(unsigned int i = 0; i < randNum){

				randPos = rand() % solution.size();		//Elemento a añadir
				solution[randPos] = true;
			}

		}
};


#endif

#ifndef __SOL_GENERATOR_MOCHILA_HPP__
#define __SOL_GENERATOR_MOCHILA_HPP__

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

		SolucionMochila randomSolutionGenerator(int objetos){
			
                  SolucionMochila solucion;
			srand(time(NULL));

			for(unsigned int i = 0; i < objetos; i++)
				solucion.setSolucion(i, false);

			for(unsigned int i = 0; i < objetos){
				if (rand()%2 == 1)
				 solucion.setSolucion(i, true);
			}
                       return solucion;
		}
};


#endif

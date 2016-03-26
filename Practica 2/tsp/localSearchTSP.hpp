#ifndef		__LOCAL_SEARCH_TSP__
#define		__LOCAL_SEARCH_TSP__


#include <vector>

#include "../lib/Miscelanea.hpp"

#include "SolucionViajante.hpp"
#include "neighborOperator.hpp"



using namespace std;




class localSearchTSP{


	private:

		double _bestFitness = 0;
		SolucionViaajante _bestSolution;

		neighborOperator _operador;

		bestImrpovementTSP * _bestExplo = NULL;
		firstImrpovementTSP * _firstExplo = NULL;


	public:

		//Constructores
		localSearch(neighborOperator &operador, firstImprovementTSP &explorador){

			_operador = operador;
			_firstExplo = &explorador;

		}

		localSearch(neighborOperator &operador, bestImprovementTSP &explorador){

			_operador = operador;
			_bestExplo = &explorador;

		}
		

		//Modificadores
		void setFitness(double &bestFitness){_bestFitness = bestFitness;};
		void setSolution(Solucion &bestSolution){_bestSolution = bestSolution;};


		//Observadores
		double getFitness(){return _bestFitness;};
		Solucion getSolution(){return _bestSolution;};
		neighborOperator getOperator(){return _operador;};



		//Metodo que devuelve el optimo local ¿Y su valor de fitness?
		void localOptimum(vector <problem_element> &info, const Solucion &initialSolution, Solucion &optimumSolution, double &optimumFitness){


		  int iteraciones = 1000, contador = 0;		//Cuenta el numero de veces que el optimo no varia
		  double actualFitness;
		  Solucion actualSolution;


			_bestSolution = initialSolution;

			while(iteraciones > 0 && contador < 2){


				if(_firstImprovementTSP != NULL){

					//Generamos un vecindario para la solucion y despues lo exploramos
					//El explorador se debe haber iniciado antes con uno de los tipos de operador
					_firstImprovementTSP->generateNeighborhood(_bestSolution);
					actualSolution = _firstImprovementTSP->explorateNeighborhood(info);

				}

				else{


					_bestImprovementTSP->generateNeighborhood(_bestSolution);
					actualSolution = _bestImprovementTSP->explorateNeighborhood(info);
				}

				actualFitness = actualSolution.getAptitude(info);


				/*

					La solucion devuelta en cada iteracion solo puede ser igual o mejor que
				la antetior, porque se incluye a si misma en el vecindario para compararse

																							*/

				if(bestFitness == actualFitness)
					contador++;

				else{

					_bestFitness = actualFitness;
					_bestSolution = actualSolution;
				}


				iteraciones--;
			}



			//Al ser clase, podemos hacer esto fuera de la funcion con los observadores
			optimumSolution = _bestSolution;
			optimumFitness = _bestFitness;
		}


};

#endif

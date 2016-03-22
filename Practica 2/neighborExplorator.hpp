#ifndef		__NEIGHBOR_EXPLORATOR__
#define		__NEIGHBOR_EXPLORATOR__


#include <vector>

using namespace std;



/* De momento lo estoy haciendo todo de forma general para ver como hacerlo


		Quizas podamos implementar en esta clase todo como metodos, pero no 
		se si a lo mejor seria mas coñazo

*/


class neighborExplorator{


	private:

		vector <Solucion> _neighborhood
		neighborOperator _operador;


	public:

		//Constructores
		neighborExplorator(){};
		neighborExplorator(neighborOperator &operador){

			_operador = operador;

		}

		//Modificadores
		void setOperator(neighborOperator &operador){_operador = operador;};

		//Observadores
		vector <Solucion> getSolution(){return _bestSolution;};
		neighborOperator getOperator(){return _operador;};


		//Metodo que genera un vecindario a partir de una solucion inicial y un operador determinado
		void generateNeighborhood(Solucion &initialSolution){

			neighborhood.push_back(initialSolution);

			while(CONDICION_PARADA)		//Numero de vecinos que se quieren generar para cada iteracion

				neighborhood.push_back(_operador.generateNeighbor);

		}


		//Metodo que explora el vecindario en funcion de la estrategia (best o first)
		Solucion explorateNeighborhood(){

			//¿Comprobar si el vector vecindario esta vacio es necesario?
			if(_neighborhood.size() == 0)
				return;


		  double actualFitness, bestFitness;
		  Solucion bestSolution;


			bestSolution = _neighborhood[0];	//El primero sera el optimo actual
			bestFitness = bestSolution.getAptitude();


			for(int i = 1; i < _neighborhood.size(); i++){

				actualFitness = neighborhood[i].getAptitude();

				//OJO --> Dependera del tipo de problema
				if(actualFitness >= bestFitness){

					bestFitness = actualFitness;
					bestSolution = neighborhood[i];
				}

			}


			return bestSolution;	//Devolvemos el ¿nuevo? optimo
		}


};

#endif

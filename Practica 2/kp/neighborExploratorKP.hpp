#ifndef		__NEIGHBOR_EXPLORATOR_KP__
#define		__NEIGHBOR_EXPLORATOR_KP__


#include <vector>

#include "neighborOperator.hpp"

using namespace std;



/* De momento lo estoy haciendo todo de forma general para ver como hacerlo


		Quizas podamos implementar en esta clase todo como metodos, pero no 
		se si a lo mejor seria mas coñazo

*/


class neighborExploratorKP{


	private:

		vector <SolucionMochila> _neighborhood
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
		neighborOperator getOperator(){return _operador;};
		vector <SolucionMochila> getNeighborhood(){return _neighborhood;};
		SolucionMochila getNeighbor(int pos){return _neighborhood[pos];};

		//Funciones auxiliares
		void addNeighbor(SolucionMochila &neighbor){_neighborhood.push_back(neighbor);};
};






class firstImprovementKP: public neighborExploratorKP{



	public:

		//Constructores
		firstImprovementKP(){};
		firstImprovementKP(neighborOperator &operador): neighborExploratorKP(operador){};


		//Metodo que genera un vecindario a partir de una solucion inicial y un operador determinado
		void generateNeighborhood(SolucionMochila &initialSolution){

			addNeighbor(initialSolution);

			while(CONDICION_PARADA){		//Numero de vecinos que se quieren generar para cada iteracion



				addNeighbor(getOperator().generateNeighbor(initialSolution));


			// ---> Hay que controlar que no se repitan soluciones (Funcion que vaya uno a uno??) <---

			}

		}


		//Metodo que explora el vecindario en funcion de la estrategia (best o first)
		SolucionMochila explorateNeighborhood(){


			if(getNeighborhood().size() == 0){

				cout << endl << "El vecindario a explorar esta vacio" << endl << endl;
				exit(0);
			}

		  double actualFitness, bestFitness;
		  SolucionMochila bestSolution;


			bestSolution = getNeighbor(0);				//El primero sera el optimo actual
			bestFitness = bestSolution.getAptitude();


			for(int i = 1; i < getNeighborhood().size(); i++){

				actualFitness = getNeighbor(i).getAptitude();

				//OJO --> Dependera del tipo de problema
				if(actualFitness >= bestFitness)

					return bestSolution;	//Devolvemos el nuevo optimo
				

				else{

					bestFitness = actualFitness;
					bestSolution = getNeighborhood(i);

				}

			}


			return bestSolution;			//El optimo sigue siendo el mismo
		}


};







class bestImprovementKP: public neighborExploratorKP{



	public:

		//Constructores
		bestImprovementKP(){};
		bestImprovementKP(neighborOperator &operador): neighborExploratorKP(operador){};


		//Metodo que genera un vecindario a partir de una solucion inicial y un operador determinado
		void generateNeighborhood(SolucionMochila &initialSolution){

			addNeighbor(initialSolution);

			while(CONDICION_PARADA){		//Numero de vecinos que se quieren generar para cada iteracion



				addNeighbor(getOperator().generateNeighbor(initialSolution));


			// ---> Hay que controlar que no se repitan soluciones (Funcion que vaya uno a uno??) <---

			}

		}


		//Metodo que explora el vecindario en funcion de la estrategia (best o first)
		SolucionMochila explorateNeighborhood(){


			if(getNeighborhood().size() == 0){

				cout << endl << "El vecindario a explorar esta vacio" << endl << endl;
				exit(0);
			}

		  double actualFitness, bestFitness;
		  SolucionMochila bestSolution;


			bestSolution = getNeighbor(0);				//El primero sera el optimo actual
			bestFitness = bestSolution.getAptitude();


			for(int i = 1; i < getNeighborhood().size(); i++){

				actualFitness = getNeighbor(i).getAptitude();

				//OJO --> Dependera del tipo de problema
				if(actualFitness >= bestFitness){

					bestFitness = actualFitness;
					bestSolution = getNeighborhood(i);
				}
			}


			return bestSolution;			//Devolvemos el ¿nuevo? optimo
		}


};




#endif

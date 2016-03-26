#ifndef		__NEIGHBOR_EXPLORATOR_KP__
#define		__NEIGHBOR_EXPLORATOR_KP__


#include <vector>

#include "../lib/Miscelanea.hpp"

#include "neighborOperator.hpp"

using namespace std;


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
		bool addNeighbor(SolucionMochila &neighbor){


			for(int i = 0; i < _neighborhood.size(); i++){

				if(_neighborhood[i] == neighbor)
					return false;
			}

			_neighborhood.push_back(neighbor);

		  return true;
		}

		void reiniciarVecindario(){_neighborhood.clear();};
};






class firstImprovementKP: public neighborExploratorKP{



	public:

		//Constructores
		firstImprovementKP(){};
		firstImprovementKP(neighborOperator &operador): neighborExploratorKP(operador){};


		//Metodo que genera un vecindario a partir de una solucion inicial y un operador determinado
		void generateNeighborhood(SolucionMochila &initialSolution){

			reiniciarVecindario();
			addNeighbor(initialSolution);

			while(CONDICION_PARADA){		//Numero de vecinos que se quieren generar para cada iteracion



				addNeighbor(getOperator().generateNeighbor(initialSolution));


			}

		}


		//Metodo que explora el vecindario en funcion de la estrategia (best o first)
		SolucionMochila explorateNeighborhood(const int &KPSize, vector <problem_element> &info){


			if(getNeighborhood().size() == 0){

				cout << endl << "El vecindario a explorar esta vacio" << endl << endl;
				exit(0);
			}

		  double actualFitness, bestFitness;
		  SolucionMochila bestSolution;


			bestSolution = getNeighbor(0);				//El primero sera el optimo actual
			bestFitness = bestSolution.getAptitude(KPSize, info);


			for(int i = 1; i < getNeighborhood().size(); i++){

				actualFitness = getNeighbor(i).getAptitude(KPSize, info);

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

			reiniciarVecindario();
			addNeighbor(initialSolution);

			while(CONDICION_PARADA){		//Numero de vecinos que se quieren generar para cada iteracion



				addNeighbor(getOperator().generateNeighbor(initialSolution));

			}

		}


		//Metodo que explora el vecindario en funcion de la estrategia (best o first)
		SolucionMochila explorateNeighborhood(const int &KPSize, vector <problem_element> &info){


			if(getNeighborhood().size() == 0){

				cout << endl << "El vecindario a explorar esta vacio" << endl << endl;
				exit(0);
			}

		  double actualFitness, bestFitness;
		  SolucionMochila bestSolution;


			bestSolution = getNeighbor(0);				//El primero sera el optimo actual
			bestFitness = bestSolution.getAptitude(KPSize, info);


			for(int i = 1; i < getNeighborhood().size(); i++){

				actualFitness = getNeighbor(i).getAptitude(KPSize, info);

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

#ifndef		__LOCAL_SEARCH__
#define		__LOCAL_SEARCH__


using namespace std;



/* De momento lo estoy haciendo todo de forma general para ver como hacerlo


		Quizas podamos implementar en esta clase todo como metodos, pero no 
		se si a lo mejor seria mas coñazo

*/

class localSearch{


	private:

		double _bestFitness = 0;
		Solucion _bestSolution;
		neighborOperator _operador;
		neighborExplorator _explorador;


	public:

		//Constructores
		localSearch(){};
		localSearch(neighborOperator &operador, neighborExplorator &explorador){

			_operador = operador;
			_explorador = explorador;

		}

		//Modificadores
		void setFitness(double &bestFitness){_bestFitness = bestFitness;};
		void setSolution(Solucion &bestSolution){_bestSolution = bestSolution;};
		void setOperator(neighborOperator &operador){_operador = operador;};
		void setExplorator(neighborExplorator &explorador){_explorador = explorador;};

		//Observadores
		double getFitness(){return _bestFitness;};
		Solucion getSolution(){return _bestSolution;};
		neighborOperator getOperator(){return _operador;};
		neighborExplorator getExplorator(){return _explorador;};



		//Metodo que devuelve el optimo local ¿Y su valor de fitness?
		void localOptimum(const Solucion &initialSolution, Solucion &optimumSolution, double &optimumFitness){


		  int iteraciones = 1000, contador = 0;		//Cuenta el numero de veces que el optimo no varia
		  double actualFitness;
		  Solucion actualSolution;


			while(iteraciones > 0 && contador < 2){


				//Generamos un vecindario para la solucion y despues lo exploramos
				//El explorador se debe haber iniciado antes con uno de los tipos de operador
				_explorador.generateNeighborhood(_bestSolution);


				//Devolvemos la solucion en funcion del tipo de la estrategia de exploracion (best, first)
				actualSolution = _explorador.explorateNeighborhood();
				actualFitness = actualSolution.getAptitude();	//Habria que cambiar la funcion aptitud de la clase instancia a la clase Solucion


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

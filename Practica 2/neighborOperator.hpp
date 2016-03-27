#ifndef		__NEIGHBOR_OPERATOR__
#define		__NEIGHBOR_OPERATOR__


#include <vector>
#include <cmath>

using namespace std;



/* De momento lo estoy haciendo todo de forma general para ver como hacerlo


		Quizas podamos implementar en esta clase todo como metodos, pero no 
		se si a lo mejor seria mas coñazo

*/


class neighborOperator{


	private:



	public:

		//Constructor vacio
		neighborOperator(){};


		//Metodo que genera un vecino de una solucion, pasandole un vector de posiciones a cambiar
		SolucionMochila generateNeighborKP(SolucionMochila &initialSolution, vector<int> &parametros){
                        int i;
                        SolucionMochila solucion(initialSolution);
                        for (i = 0; i < parametros.size(); i++){
                	        solucion.setSolucion(parametros[i], abs(solucion.getSolucion(parametros[i]) - 1)); 
                                 }
                        return solucion;
		}
		
		
		SolucionViajante generateNeighborTSP(SolucionViajante &initialSolution, int posA, int posB, bool swaap = false){
			SolucionViajante solucion(initialSolution);
			if (swaap == false){
				int aux = solucion.getSolucion(posA);
				solucion.setSolucion(posA, solucion.getSolucion(posB));
				solucion.setSolucion(posB, aux);
			}
			
			
			
		}

};

#endif

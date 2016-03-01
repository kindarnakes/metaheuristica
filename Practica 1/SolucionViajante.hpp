#ifndef __SOLUCIONVIAJANTE__
#define __SOLUCIONVIAJANTE__

#include <vector>

using namespace std;

namespace Metaheuristica{

class SolucionViajante{

 private:
  vector<int> _solucion;

 public:
    //Observadores
  inline vector<int> getSolucion() const
   {return _solucion;};

  int getSolucion(int n) const //Para consultar un elemento de la solución, no se utiliza la posición 0
   { if (n <= _solucion.size())
      return _solucion.at(n);
     else 
      return -1;}; 

   //Modificadores
  inline void setSolucion(vector<int> solucion)
   {_solucion = solucion;};
  
  void setSolucion(int pos, int valor)
   {if (pos <= _objetos)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución, no se utiliza la posicion 0

  //El número de objetos no se podrá modificar, solo se inicializa al principio
  SolucionViajante(int objetos=0){
   int i;
    for (i=0; i<= objetos; i++)
     //colocamos un elemento 0 para no utilizar la posición 0 del vector
    _solucion.push_back(i);
    }
  }
 };  
}
#endif

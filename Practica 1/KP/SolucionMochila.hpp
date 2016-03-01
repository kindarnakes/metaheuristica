#ifndef __SOLUCIONMOCHILA__
#define __SOLUCIONMOCHILA__

#include <vector>

using namespace std;

namespace Metaheuristica{

class Solucion_mochila{

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
   {if (pos <= _solucion.size())
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución, no se utiliza la posicion 0

  SolucionMochila(int objetos=0){
   int i;
   
     for (i=0; i<=objetos; i++){
      //colocamos un elemento más en el vector para no utilizar la posición 0
        _solucion.push_back(0);
      }
   
  }
 };  
}
#endif

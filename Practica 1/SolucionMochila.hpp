#ifndef __SOLUCIONMOCHILA__
#define __SOLUCIONMOCHILA__

#include <vector>

using namespace std;

namespace Metaheuristica{


//Para hacer uso de la clase, hay que usar el constructor, sino se utiliza, el número de objetos quedará fijado a 0 para evitar problemas
class Solucion_mochila{

 private:
  vector<int> _solucion;

 public:
    //Observadores
  inline vector<int> getSolucionMochila() const
   {return _solucion;};

  int getSolucionMochila(int n) const //Para consultar un elemento de la solución, no se utiliza la posición 0
   { if (n <= _solucion.size())
      return _solucion.at(n);
     else 
      return -1;}; 

   //Modificadores
  inline void setSolucionMochila(vector<int> solucion)
   {_solucion = solucion;};
  
  void setSolucionMochila(int pos, int valor)
   {if (pos <= _objetos)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución, no se utiliza la posicion 0

  //El número de objetos no se podrá modificar, solo se inicializa al principio
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

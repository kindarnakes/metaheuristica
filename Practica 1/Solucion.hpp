#ifndef __SOLUCION__
#define __SOLUCION__

#include <vector>

using namespace std;

namespace Metaheuristica{


//Pra hacer uso de la clase, hay que usar el constructor, sino se utiliza, el número de objetos quedará fijado a 0 para evitar problemas
class Solucion{

 private:
  vector<int> _solucion;
  int _objetos;
  bool _viajante; //Falso para la mochila, verdadero para el viajante


 public:
    //Observadores
  inline vector<int> getSolucion() const
   {return _solucion;};

  int getSolucion(int n) const //Para consultar un elemento de la solución, no se utiliza la posición 0
   { if (n <= _objetos)
      return _solucion.at(n);
     else 
      return -1;}; 
 
  inline int getObjetos() const
   {return _objetos;};
 
  inline bool getViajante() const
   {return _viajante;};

   //Modificadores
  inline void setSolucion(vector<int> solucion)
   {_solucion = solucion;};
  
  void setSolucion(int pos, int valor)
   {if (pos <= _objetos)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución, no se utiliza la posicion 0

  //El número de objetos no se podrá modificar, solo se inicializa al principio
  Solucion(int objetos=0, bool viajante=false){
   int i;

   if (!viajante){
   
     for (i=0; i<=objetos; i++){
      //colocamos un elemento más en el vector para no utilizar la posición 0
        _solucion.push_back(0);
      }
     
     _objetos=objetos;
    }

   if (viajante){

    for (i=0; i<= objetos; i++){
     //colocamos un elemento 0 para no utilizar la posición 0 del vector
    _solucion.push_back(i);
     }
    
    _objetos = objetos;
    }
  }
 };  
}
#endif

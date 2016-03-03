#ifndef __SOLUCIONMOCHILA__
#define __SOLUCIONMOCHILA__

#include <vector>

using namespace std;

class SolucionMochila{

 private:
  vector<bool> _solucion;

 public:
    //Observadores
  inline vector<bool> getSolucion() const
   {return _solucion;};

  bool getSolucion(int n) const //Para consultar un elemento de la solución
   { if (n <= _solucion.size()-1)
      return _solucion[n];
     else 
      return -1;}; 

   //Modificadores
  inline void setSolucion(vector<bool> solucion)
   {_solucion = solucion;};
  
  void setSolucion(int pos, bool valor)
   {if (pos <= _solucion.size()-1)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución

  SolucionMochila(int objetos=0){
   int i;
   
     for (i=0; i<objetos; i++){
        _solucion.push_back(false);
      }
   
  }
 };
#endif

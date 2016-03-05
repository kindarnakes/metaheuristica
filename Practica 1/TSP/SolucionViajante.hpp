#ifndef __SOLUCIONVIAJANTE__
#define __SOLUCIONVIAJANTE__

#include <vector>

using namespace std;

class SolucionViajante{

 private:
  vector<int> _solucion;

 public:
    //Observadores
  inline vector<int> getSolucion() const
   {return _solucion;};

  int getSolucion(unsigned int n) const //Para consultar un elemento de la solución
   { if (n <= _solucion.size()-1)
      return _solucion.at(n);
     else 
      return -1;}; 

   //Modificadores
  inline void setSolucion(vector<int> solucion)
   {_solucion = solucion;};
  
  void setSolucion(unsigned int pos, int valor)
   {if (pos <= _solucion.size()-1)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución


	//Sobrecarga Operador =
	SolucionViajante & operator=(const SolucionViajante &s){

		if(this != &p)

			this->_solucion = s.getSolucion();

	  return *this;

	}
     
     
  SolucionViajante(unsigned int objetos=0){
    for (unsigned int i=0; i< objetos; i++)
    _solucion.push_back(i);
  }
 };
#endif

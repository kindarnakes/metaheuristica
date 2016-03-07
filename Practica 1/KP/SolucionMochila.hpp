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

  bool getSolucion(unsigned int n) const //Para consultar un elemento de la solución
   { if (n <= _solucion.size()-1)
      return _solucion[n];
     else 
      return -1;}; 

   //Modificadores
  inline void setSolucion(vector<bool> solucion)
   {_solucion = solucion;};
  
  void setSolucion(unsigned int pos, bool valor)
   {if (pos <= _solucion.size()-1)
     _solucion[pos]=valor;}; //Para modificar un elemento de la solución


	//Sobrecarga Operador =
	SolucionMochila & operator=(const SolucionMochila &s){

		if(this != &s)

			this->_solucion = s.getSolucion();

	  return *this;

	}




	//Sumatorio del peso de la solucion actual
	int pesoSolucion(vector <problem_element> &info){

		if(_solucion.size() != info.size()){

			cout << "Error. El tamaño de los vectores no coincide.";
			exit(0);
		}

	  int sumatorio = 0;

		for(unsigned int i = 0; i < _solucion.size(); i++){


			if (_solucion[i])	//Si el elemento esta incluido, se suma

				sumatorio += info[i].b;
		}

		return sumatorio;
	}


	//Sumatorio del beneficio de la solucion actual
	int beneficioSolucion(vector <problem_element> &info){

		if(_solucion.size() != info.size()){

			cout << "Error. El tamaño de los vectores no coincide.";
			exit(0);
		}

	  int sumatorio = 0;

		for(unsigned int i = 0; i < _solucion.size(); i++){


			if (_solucion[i])	//Si el elemento esta incluido, se suma

				sumatorio += info[i].a;
		}

		return sumatorio;




	}


	//Sumatorio del beneficio de todos los elementos de la instancia
	int beneficioMaximo(vector <problem_element> &info){

		if(_solucion.size() != info.size()){

			cout << "Error. El tamaño de los vectores no coincide.";
			exit(0);
		}

	  int sumatorio = 0;

		for(unsigned int i = 0; i < _solucion.size(); i++){


			sumatorio += info[i].a;
		}

		return sumatorio;
	}






  //Constructor
  SolucionMochila(int objetos=0){
   int i;
   
     for (i=0; i<objetos; i++){
        _solucion.push_back(false);
      }
  }








 };
#endif

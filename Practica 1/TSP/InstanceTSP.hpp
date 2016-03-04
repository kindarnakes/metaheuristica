#ifndef __INSTANCE_TSP_HPP__
#define __INSTANCE_TSP_HPP__

#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

#include "../lib/Instance.hpp"
#include "../lib/Miscelanea.hpp"
#include "SolucionViajante.hpp"

class InstanceTSP : public Instance {
	public:
		//Valores del constructor adaptados a los archivos csv de esta practica
		InstanceTSP(std::string file_name, int header_lines=6, int length_line=3, char separator=' ', int end_lines = 0)
			: Instance(file_name, header_lines, length_line, separator, end_lines)
		{}

		~InstanceTSP() 
		{
			if(_file.is_open())
				_file.close();
		}

		double distancia(const problem_element a, const problem_element b) {
			return sqrt(pow(a.a - b.a,2) + pow(a.b - b.b,2));
		}


		double getAptitude(vector <problem_element> &info, const SolucionViajante &solution){

			double sumatorio = 0.0;

			for(unsigned int i = 0; i < (info.size() - 1); i++){

				//Sumamos la distancia entre el origen y el destino de cada camino de la solucion
				sumatorio += distancia(info[ solution.getSolucion(i) ], info[ solution.getSolucion(i+1) ]);

			}

			return sumatorio;
		}

};

#endif

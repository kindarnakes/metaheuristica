#ifndef __INSTANCE_KP_HPP__
#define __INSTANCE_KP_HPP__

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

#include "../lib/Instance.hpp"
#include "../lib/Miscelanea.hpp"
#include "SolucionMochila.hpp"

class InstanceKP : public Instance {
	public:
		//Valores del constructor adaptados a los archivos csv de esta practica
		InstanceKP(std::string file_name, int header_lines=5, int length_line=1, char separator=',', int end_lines=2) 
			: Instance(file_name, header_lines, length_line, separator, end_lines) 
		{}

		~InstanceKP() 
		{
			if(_file.is_open())
				_file.close();
		}

		int getAptitude(SolucionMochila &solution, const int &KPSize, vector <problem_element> &info){


			int totalSize = solution.pesoSolucion(info);	//Peso de los elementos escogidos

			if(totalSize <= KPSize)

				return solution.beneficioSolucion(info);	//Beneficio de los elementos escogidos


			else{

				int beneSol = solution.beneficioSolucion(info);
				int beneMax = solution.beneficioMaximo(info);	//En vez de en la clase Solucion podemos meterlo en la clase instancia este sumatorio, pero lo he puesto ahi por coherencia

				return (beneSol - beneMax);
			}


		}

};

#endif

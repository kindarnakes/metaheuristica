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
	private:
		int _capacity_line;

	public:
		InstanceKP() {}
		//Valores del constructor adaptados a los archivos csv de esta practica
		InstanceKP(std::string file_name, int header_lines=5, int capacity_line=2, int length_line=1, char separator=',', int end_lines=2) 
			: Instance(file_name, header_lines, length_line, separator, end_lines), _capacity_line(capacity_line)
		{}

		~InstanceKP() 
		{
			if(_file.is_open())
				_file.close();
		}

		unsigned int getCapacity() {
			int capacity;
			const std::string c_line = getHeader(_capacity_line);
			std::regex rgx(".* (\\d+) *$");
			std::smatch match;
			if (std::regex_search(c_line.begin(), c_line.end(), match, rgx))
				capacity = std::stoi(match[1]);
			else
				capacity = -1;

			return capacity;
		}

		//Funcion que devuelve la bondad de una solucion
		int getAptitude(SolucionMochila &solution, const int &KPSize, vector <problem_element> &info){


			int totalSize = solution.pesoSolucion(info);	//Peso de los elementos escogidos

			if(totalSize <= KPSize)

				return solution.beneficioSolucion(info);	//Beneficio de los elementos escogidos


			else{

				int beneSol = solution.beneficioSolucion(info);
				int beneMax = solution.beneficioMaximo(info);

				return (beneSol - beneMax);
			}

		}


		//Funcion que almacena en un fichero una serie de datos de salida del programa
		void saveResults(const double &best_fitness, const SolucionMochila &best_solution){


		  int id = 0;	//Identificador del numero de ejecucion del programa
		  string line;

		  ifstream fr("KP_soluciones.txt");
			
			//Contamos cual ejecucion del programa es esta
			if(fr.is_open()){
				while(! fr.eof()){

					getline(fr, line);
					id++;
				}
			}

			fr.close();


		  ofstream fs("KP_soluciones.txt", std::ofstream::app);	//Abrimos el flujo de salida al fichero


			//Escribimos los resultados de esta ejecucion
			fs << id << " " << best_fitness << "\n";

			fs.close();


		}

};

#endif

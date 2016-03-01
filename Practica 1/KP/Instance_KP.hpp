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

class Instance_KP : public Instance {
	public:
		//Valores del constructor adaptados a los archivos csv de esta practica
		Instance_KP(std::string file_name, int header_lines=5, int length_line=1, char separator=',', int end_lines=2) 
			: Instance(file_name, header_lines, length_line, separator, end_lines) 
		{}

		~Instance_KP() 
		{
			if(_file.is_open())
				_file.close();
		}

		int getAptitude() {return 0;};

};

#endif
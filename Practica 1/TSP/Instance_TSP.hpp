#ifndef __INSTANCE_TSP_HPP__
#define __INSTANCE_TSP_HPP__

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

#include "../Instance.hpp"
#include "../Miscelanea.hpp"

class Instance_TSP : public Instance {
	public:
		Instance_TSP(std::string file_name, int header_lines, int length_line, char separator, int end_lines = 0)
			: Instance(file_name, header_lines, length_line, separator, end_lines)
		{}

		~Instance_TSP() 
		{
			if(_file.is_open())
				_file.close();
		}
};

#endif
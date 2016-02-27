#ifndef __INSTANCE_HPP__
#define __INSTANCE_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Miscelanea.hpp"

class Instance {
	private:
		std::fstream _file;

		std::string _file_name;
		int _header_lines;
		//Line that contains the length of one specific instance
		int _length_line;
		int _instance_length;
		//value separator
		char _separator;
		//Number of lines between two instances
		int _end_lines;

	public:
		Instance(std::string file_name, int header_lines, int length_line, char separator, int end_lines = 0) 
			: _file_name(file_name), _header_lines(header_lines), _length_line(length_line), _end_lines(end_lines)
		{
			_file.open(_file_name);
			_separator = separator;
		}

		~Instance() 
		{
			if(_file.is_open())
				_file.close();
		}

		bool load() {
			if(not _file.is_open()) {
				std::cerr << "File could not be opened." << std::endl;
				return false;
			}

			for(unsigned int i = 0; i < _header_lines+1; i++) {
				if(i == _length_line) {
					std::string line;
					_file.ignore(256, ' ');
					_file >> line;
					_instance_length = std::stoi(line);
				}
				else
					_file.ignore(1024,'\n');
			}

			std::cout << "instance length: " << _instance_length << std::endl;

			std::vector<kp_element> kp_elements;

			std::cout << "separator: " << _separator << std::endl;

			for(unsigned int i = 0; i < _instance_length; i++) {
				std::string value;

				kp_elements.push_back(kp_element());

				getline(_file, value, _separator);
				kp_elements[i].id = std::stof(value);

				getline(_file, value, _separator);
				kp_elements[i].value = std::stof(value);

				getline(_file, value,'\n');
				kp_elements[i].weight = std::stof(value);

				std::cout << kp_elements[i].id << ": \n  w: " << kp_elements[i].weight << "\n  p: " << kp_elements[i].value << std::endl;
			}

			_file.close();

			return true;
		}
};

#endif
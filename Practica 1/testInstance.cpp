#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Instance.hpp"

using namespace std;

int main(int argc, char** argv) {

	int opt;
	int inst_num;
	vector<problem_element> inst_v;

	do {
		cout << "\n\n";
		cout << "¿De que problema desea cargar su instancia? " << endl;
		cout << "  1. TSP" << endl;
		cout << "  2. KP" << endl;
		cout << "  0. Exit" << endl;

		cin >> opt;

		string fileName;
		if(opt != 0) {
			cout << "Introduzca el nombre del fichero: ";
			cin >> fileName;

			cout << "¿Que numero de instancia desea cargar?: ";
			cin >> inst_num;
		}

		bool ret = false;

		if(opt == 1) {
			fileName =  "TSP/" + fileName;
			Instance instance(fileName, 6, 3, ' ');
			ret = instance.loadInstance(inst_v, inst_num);
		} else if(opt == 2) {
			fileName =  "KP/" + fileName;
			Instance instance(fileName, 5, 1, ',', 2);
			ret = instance.loadInstance(inst_v, inst_num);
		}

		if(opt != 0) {
			if(not ret) {
				cerr << "El fichero no se pudo abrir.\n";
				return -1;
			}

			cout << "\nInstancia " << inst_num << " de " << fileName << endl;
			for(unsigned int i = 0; i < inst_v.size(); i++)
				cout << inst_v[i].id << ": \n  w: " << inst_v[i].a << "\n  p: " << inst_v[i].b << endl;
		}

	} while(opt);

	return 0;
}
#include <iostream>
#include <string>
#include <fstream>

#include "Instance.hpp"

using namespace std;

int main(int argc, char** argv) {

	string opt;

	do {
		cout << "\n\n";
		cout << "What problem instance would you like to load? " << endl;
		cout << "  1. TSP" << endl;
		cout << "  2. KP" << endl;
		cout << "  0. Exit" << endl;

		cin >> opt;

		string fileName;
		cout << "Enter the name of the file: ";
		cin >> fileName;
		if(std::stoi(opt) == 1) {
			//string fileName = "TSP/berlin52-tsp.csv";
			fileName =  "TSP/" + fileName;
			Instance instance(fileName, 6, 3, ' ');
			instance.load();
		} else if(std::stoi(opt) == 2) {
			fileName =  "KP/" + fileName;
			Instance instance(fileName, 5, 1, ',');
			instance.load();
		}
	} while(std::stoi(opt));

	return 0;
}
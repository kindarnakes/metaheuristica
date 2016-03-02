//PARA COMPILAR
//g++ -o prueba prueba.cpp seeds.cpp Timer.cpp -lgsl -lgslcblas

#include "lib/Random.h"
#include "lib/Timer.h"
#include <iostream>

using namespace std;

main() {

	Random random;
	random.cambiaSemilla(seeds[1]);

	Timer timer;
	long i = 0;

	while (timer.elapsed_time(timer.REAL) < 3){ //Se ejecuta durante 3 segundos reales
//	while (timer.elapsed_time(timer.VIRTUAL) < 3){ //Se ejecutaría durante 3 segundos de cpu
		i++;
		cout << random.Randint(0, 10) << endl;
	}

	cout << "He generado " << i << " números aleatorios" << endl;

//	for (int i = 0; i < 1000; i++){
//		cout << random.Randint(0, 10) << endl;
//	}

	return 0;
}


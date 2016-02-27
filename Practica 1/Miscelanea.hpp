#ifndef __MISCELANEA_HPP__
#define __MISCELANEA_HPP__

struct kp_element {
	int id;
	double value;
	double weight;
};

struct tsp_element {
	int id;
	double a;
	double b;
};

//Estructura generica para los dos problemas que se podría usar en Instance.hpp
struct problem_element {
	int id;
	double a;
	double b;
};

#endif
#ifndef PARAMETROS_H_
#define PARAMETROS_H_
//#include <omp.h>
#include <getopt.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Parametros {
    public:
		Parametros();
		static void Store(int ac, char * av[]);

		//Retrive informations
		static string getInstancia();
		static string getLocalSearch();
		static string getNeighborhood();
		static int getMaxIterations();
		static int getMaxIdleIterations();
		static int GetSize();
		static string GetVersion();
		static double GetSeed();
    private:
		static map<string,string> vm;
};

#endif /* PARAMETER_H_ */

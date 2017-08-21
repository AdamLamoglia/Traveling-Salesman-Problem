#include "parametros.h"

Parametros::Parametros() {
	// nothing to do here!
}

double Parametros::GetSeed(){
	try {
		return stod(vm["seed"]);
	} catch (exception& e) {
		cout<< "\nfile: "<< __FILE__;
		cout<< ", line: "<< __LINE__;
		cout << ", error: " << e.what() << endl;
		return 0;
	}
}

string Parametros::getInstancia(){
	try {
		return vm["instancia"];
	} catch (exception& e) {
		cout << "error: " << e.what() << endl;
		vm["instancia"] = "default.txt";
		return vm["instancia"];
	}
}

string Parametros::getLocalSearch(){
	try {
		return vm["localsearch"];
	} catch (exception& e) {
		cout << "error: " << e.what() << endl;
		vm["localsearch"] = "best";
		return vm["localsearch"];
	}
}

string Parametros::getNeighborhood(){
	try {
		return vm["neighborhood"];
	} catch (exception& e) {
		cout << "error: " << e.what() << endl;
		vm["neighborhood"] = "n1";
		return vm["neighborhood"];
	}
}

int Parametros::getMaxIterations(){
	try {
		return stoi(vm["maxIterations"]);
	} catch (exception& e) {
		cout<< "\nfile: "<< __FILE__;
		cout<< ", line: "<< __LINE__;
		cout << ", error: " << e.what() << endl;
		return 0;
	}
}

int Parametros::getMaxIdleIterations(){
	try {
		return stoi(vm["maxIdleIterations"]);
	} catch (exception& e) {
		cout<< "\nfile: "<< __FILE__;
		cout<< ", line: "<< __LINE__;
		cout << ", error: " << e.what() << endl;
		return 0;
	}
}

int Parametros::GetSize(){
	try {
		return stoi(vm["size"]);
	} catch (exception& e) {
		cout<< "\nfile: "<< __FILE__;
		cout<< ", line: "<< __LINE__;
		cout << ", error: " << e.what() << endl;
		return 0;
	}
}

string Parametros::GetVersion(){
	return vm["version"];
}

void Parametros::Store(int argc, char * argv[ ]) {

	char optstring[] = "i:a:t:vr:dcq";
	int option_index = 0;
	int opcao = 0;

	struct option long_options[] = {
			{ "version", no_argument, 0,					001 },
			{ "size", required_argument, 0,					002 },
			{ "instancia", required_argument, 0,			003 },
			{ "seed", required_argument, 0,					004 },
			{ "localsearch", required_argument, 0,			005 },
			{ "neighborhood", required_argument, 0,			006 },
			{ "maxIterations", required_argument, 0,		007 },
			{ "maxIdleIterations", required_argument, 0,	010 },
			{ "help", no_argument, 0,						076 },
			{ "h", no_argument, 0,							077 },
			{ 0,0, 0, 0 } };

	opcao = 0;

	while (opcao != -1) {
		opcao = getopt_long(argc, argv, optstring, long_options, &option_index);
		switch (opcao) {
		case 001:
			vm["version"] = "Versao Brasileira, VTI-Rio.";
			break;
		case 002:
		    vm["size"] = string(optarg);
			break;
		case 003:
			vm["instancia"] = string(optarg);
			break;
		case 004:
			vm["seed"] = string(optarg);
			break;
		case 005:
			vm["localsearch"] = string(optarg);
			break;
		case 006:
			vm["neighborhood"] = string(optarg);
			break;
		case 007:
			vm["maxIterations"] = string(optarg);
			break;
		case 010:
			vm["maxIdleIterations"] = string(optarg);
			break;
		case 076:
			cout<<"write a help.";
			break;
	}
}

}

map<string,string> Parametros::vm;

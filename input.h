/*  Created on: Jul 24, 2017
 *      Author: Adam Lamoglia
 */

#include "graph.h"

using namespace std;

 #ifndef VRP_INPUT_H
 #define VRP_INPUT_H

class Input {

	// Sobrecarga de operador
	friend ostream& operator<<(ostream&, const Input &in);

public:

	//nome do arquivo
	string name_;

	//comentário do arquivo
	string comment_;

	//tipo de problema (VRP,TSP,..)
	string type_;

	//tipo de peso das arestas
	string edge_weight_type_;

	//caso o tipo de peso seja EXPLICIT
	string edge_weight_format_;

	//tipo de dados do display
	string display_data_type_;

	//capacidade
	int capacity_;

	// Constructor padrao
	Input();

	// Leitura e armazenamento dos dados de entrada
	void load(ifstream& file_name);

	//verifica se EDGE_WEIGHT_TYPE eh EXPLICIT ou nao
	void verifyExplicit(ifstream &inputFile,string s);

	//construtor do grafo
	void verifySection(ifstream& inputFile,Graph graph,Point aux_point_);

	//construtores para FUNCTIONS

	void makeEUC_2D(ifstream& inputFile,Graph graph, Point aux_point);

	void makeEUC_3D(ifstream& inputFile,Graph graph, Point aux_point);

	void makeMAN_2D(ifstream& inputFile,Graph graph,Point aux_point);

	void makeMAN_3D(ifstream& inputFile,Graph graph, Point aux_point);

	void makeMAX_2D(ifstream& inputFile,Graph graph, Point aux_point);

	void makeMAX_3D(ifstream& inputFile,Graph graph,Point aux_point);

	void makeATT(ifstream& inputFile,Graph graph,Point aux_point);

	void makeGEO(ifstream& inputFile,Graph graph,Point aux_point);

	void makeCEIL_2D(ifstream& inputFile,Graph graph,Point aux_point);

	//construtores para EXPLICIT

	void makeFULL_MATRIX(ifstream& inputFile,Graph graph);

	void makeUPPER_ROW(ifstream& inputFile,Graph graph);

	void makeLOWER_ROW(ifstream& inputFile,Graph graph);

	void makeUPPER_DIAG_ROW(ifstream& inputFile,Graph graph);

	void makeLOWER_DIAG_ROW(ifstream& inputFile,Graph graph);

	void makeUPPER_COL(ifstream& inputFile,Graph graph);

	void makeLOWER_COL(ifstream& inputFile,Graph graph);

	void makeUPPER_DIAG_COL(ifstream& inputFile,Graph graph);

	void makeLOWER_DIAG_COL(ifstream& inputFile,Graph graph);

	//construtor do vetor de demandas

	void makeDemand(ifstream& inputFile,Graph graph);

	//construtor do vetor de depositos

	void makeDepot(ifstream& inputFile,Graph graph);


};

#endif  // VRP

/*
 * tsp.h
 *
 *  Created on: 16 de ago de 2017
 *      Author: adamlamoglia
 */

#include "input.h"

#ifndef TSP_H_
#define TSP_H_

using namespace std;

class Tsp {

public:
	//trajeto na ordem das cidades
	static vector<int> permutation;

	static vector<bool> is_visited;

	//distancia minima
	static double min_distance;

	//distancia minima atual de cada visitacao
	double min_distance_atual;

	//ponto de partida
	int inicio;

	//ponto atual visitado
	int ponto_atual;

	//indice do vertice no vetor de permutacoes
	int indice_vertice_permutacao;

	//vertice escolhido para ser visitado
	int vertice_visitado;


	Tsp();
	void greedyNearestNeighbor();


};



#endif /* TSP_H_ */

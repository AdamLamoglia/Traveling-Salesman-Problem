/*
 * tsp.h
 *
 *  Created on: 16 de ago de 2017
 *      Author: adamlamoglia
 */

#include "input.h"
#include <iostream>
using namespace std;

#ifndef TSP_H_
#define TSP_H_

class Solution {

public:

	friend ostream& operator<<(ostream&, const Solution &s);

	//trajeto na ordem das cidades
	vector<int> permutation;

	vector<bool> is_visited;

	//distancia minima
	double min_distance;

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


	Solution(Input *in);
	void greedyNearestNeighbor1(Input *in);
	void greedyNearestNeighbor2(Input *in);

};



#endif /* TSP_H_ */

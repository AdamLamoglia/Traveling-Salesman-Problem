/*
 * tsp.h
 *
 *  Created on: 16 de ago de 2017
 *      Author: adamlamoglia
 */

#include "input.h"
#include "no.h"
#include <iostream>
using namespace std;

#ifndef TSP_H_
#define TSP_H_

class Solution {

public:

	friend ostream& operator<<(ostream&, const Solution &s);

	//trajeto na ordem das cidades
	vector<int> permutation;

    //vetor de visitados
	vector<bool> is_visited;

    //vetor virtual
	vector<int> vertice;

	vector<int> ciclo;


	//distancia minima
	double min_distance;

	double min_distance_insercao;

	//distancia minima atual de cada visitacao
	double min_distance_atual;

	int aresta_mais_proxima;

	double distancia_aresta_mais_proxima;

	//ponto de partida
	int inicio;

	//ponto atual visitado
	int ponto_atual;

	//indice do vertice no vetor de permutacoes
	int indice_vertice_permutacao;

	int indice_vertice_visitado;


	//vertice escolhido para ser visitado
	int vertice_visitado;

	//vertice escolhido para ser incorporado ao ciclo
	int vertice_incorporado;

	int variacao_comprimento_ciclo;


	Solution(Input *in);
	void setCiclo(Input *in);
	void setVerticeVirtual(Input *in);
	void greedyNearestNeighbor1(Input *in);
	void greedyNearestNeighbor2(Input *in);
	void insercaoMaisProxima(Input *in);
	void insercaoMaisDistante(Input *in);
	void twoOpt(Input *in);

};



#endif /* TSP_H_ */

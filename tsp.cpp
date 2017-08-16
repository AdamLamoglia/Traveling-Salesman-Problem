/*
 * tsp.cpp
 *
 *  Created on: 16 de ago de 2017
 *      Author: adamlamoglia
 */


#include "tsp.h"

using namespace std;

Tsp::Tsp() {
	min_distance = 0;
	min_distance_atual = INT_MAX;

	//vetor vai de 0 ate dimensao - 1
	permutation.resize(Graph::dimension_);

	//vetor vai de 1 ate dimensao
	is_visited.resize(Graph::dimension_+1,false);

	//escolhe um numero aleatorio para ser o inicio
	inicio = rand() % Graph::dimension_ + 1;

	ponto_atual = inicio;
	vertice_visitado = inicio;

	indice_vertice_permutacao = 0;

	//marca o vertice inicial como ja visitado
	is_visited[vertice_visitado] = true;

	//poe o vertice inicial na solucao
	permutation[indice_vertice_permutacao] = vertice_visitado;
}


void Tsp::greedyNearestNeighbor(){

	while(permutation[permutation.size() - 1] != 0){

		indice_vertice_permutacao++;

		min_distance_atual = INT_MAX;

		for(int i = 1;i <= Graph::dimension_; ++i){

			if(is_visited[i] == true)
				continue;

			if(Graph::weight_[ponto_atual][i] < min_distance_atual){
				min_distance_atual = Graph::weight_[ponto_atual][i];
				vertice_visitado = i;
			}

		}

		is_visited[vertice_visitado] = true;

		permutation[indice_vertice_permutacao] = vertice_visitado;

		min_distance+=min_distance_atual;
	}
}





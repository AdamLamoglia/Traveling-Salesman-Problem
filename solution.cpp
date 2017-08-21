/*
 * tsp.cpp
 *
 *  Created on: 16 de ago de 2017
 *      Author: adamlamoglia
 */


#include "solution.h"

using namespace std;

ostream& operator<<(ostream& os, const Solution &s){
	os<<s.min_distance<<endl;
	for(int i=0;i < s.permutation.size();i++){
		os<<s.permutation[i]<<" ";
	}
os<<endl;
	return os;
}

Solution::Solution(Input *in) {
	min_distance = 0;
	min_distance_atual = INT_MAX;

	//vetor vai de 0 ate dimensao - 1
	permutation.resize(in->graph->dimension_);

	//vetor vai de 1 ate dimensao
	is_visited.resize(in->graph->dimension_,false);

	//escolhe um numero aleatorio para ser o inicio
	inicio = rand() % in->graph->dimension_ + 1;

	ponto_atual = inicio;
	vertice_visitado = inicio;

	indice_vertice_permutacao = 0;

	//marca o vertice inicial como ja visitado
	is_visited[vertice_visitado] = true;

	//poe o vertice inicial na solucao
	permutation[indice_vertice_permutacao] = vertice_visitado;
}


void Solution::greedyNearestNeighbor1(Input *in){

	while(permutation[permutation.size() - 1] == 0){

		indice_vertice_permutacao++;

		min_distance_atual = INT_MAX;

		for(int i = 1;i <= in->graph->dimension_; ++i){

			if(is_visited[i] == true)
				continue;

			if(in->graph->weight_[ponto_atual][i] < min_distance_atual){
				min_distance_atual = in->graph->weight_[ponto_atual][i];
				vertice_visitado = i;
			}

		}

		is_visited[vertice_visitado] = true;

		permutation[indice_vertice_permutacao] = vertice_visitado;

		min_distance+=min_distance_atual;

		ponto_atual = vertice_visitado;

	}
}


//
//void Solution::greedyNearestNeighbor2(Input *in){
//
//	int* vvirtual = new int[in];
//
//	while(permutation[permutation.size() - 1] != 0){
//
//		indice_vertice_permutacao++;
//
//		min_distance_atual = INT_MAX;
//
//		for(int i = indice_vertice_permutacao;i <= in->graph->dimension_; ++i){
//
//			if(is_visited[vvirtual[i]] == true)
//				continue;
//
//			if(in->graph->weight_[ponto_atual][i] < min_distance_atual){
//				min_distance_atual = in->graph->weight_[ponto_atual][i];
//				vertice_visitado = i;
//			}
//
//		}
//
//		is_visited[vertice_visitado] = true;
//
//		permutation[indice_vertice_permutacao] = vertice_visitado;
//
//		min_distance+=min_distance_atual;
//	}
//}

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
	is_visited.resize(in->graph->dimension_ + 1,false);

	candidato.resize(in->graph->dimension_ + 1);

    //constroi o vetor virtual
    setVerticeVirtual();

    //inicializa o ciclo do grafo
    setCiclo();

	//escolhe um numero aleatorio para ser o inicio
	inicio = rand() % in->graph->dimension_ + 1;

    //ponto atual eh o inicio
	ponto_atual = inicio;
	//primeiro vertice visitado eh o inicial
	vertice_visitado = inicio;

	//primeiro vertice visitado esta na posicao 0 do vetor permutacao
	indice_vertice_permutacao = 0;

	indice_vertice_visitado = inicio;

	indice_ciclo = 4;

	//marca o vertice inicial como ja visitado
	is_visited[vertice_visitado] = true;

	//poe o vertice inicial na solucao
	permutation[indice_vertice_permutacao] = vertice_visitado;

	swap(vertice[1],vertice[indice_vertice_visitado]);
}

void Solution::setVerticeVirtual(){
    vertice.resize(in->graph->dimension_ + 1);

	for(int i = 0;i <= in->graph->dimension_; i++){
        vertice[i] = i;
	}
}

void Solution::setCiclo(){
	ciclo.resize(in->graph->dimension + 1);

	ciclo[1]->value = 1;
	ciclo[2]->value = 2;
	ciclo[3]->value = 3;

	ciclo[1]->color = ciclo[2]->color = ciclo[3]->color = 1;

	min_distance_insercao = in->graph->weight_[1][2] + in->graph->weight_[2][3] + in->graph->weight_[3][1];
}


void Solution::greedyNearestNeighbor1(Input *in){

    //enquanto a ultima posicao do vetor de solucao for diferente de 0
	while(permutation[permutation.size() - 1] == 0){

		indice_vertice_permutacao++;

        //valor auxiliar
		min_distance_atual = INT_MAX;

		for(int i = 1;i <= in->graph->dimension_; ++i){

            //se entrar no if, entao o vertice ja foi visitado
			if(is_visited[i] == true)
				continue;

            //se a distancia do ponto atual com i atual for menor que a menor distancia atual
			if(in->graph->weight_[ponto_atual][i] < min_distance_atual){

                //seta a menor distancia
				min_distance_atual = in->graph->weight_[ponto_atual][i];

                //por enquanto o vertice visitado eh i
				vertice_visitado = i;
			}

		}

        //marca vertice como visitado
		is_visited[vertice_visitado] = true;

        //poe o vertice no vetor solucao
		permutation[indice_vertice_permutacao] = vertice_visitado;

        //incrementa a distancia total
		min_distance+=min_distance_atual;

        //o ponto atual agora eh o vertice visitado
		ponto_atual = vertice_visitado;

	}
}


void Solution::greedyNearestNeighbor2(Input *in){


	while(permutation[permutation.size() - 1] != 0){

		indice_vertice_permutacao++;

		min_distance_atual = INT_MAX;

		for(int i = indice_vertice_permutacao + 1;i <= in->graph->dimension_; ++i){

			if(in->graph->weight_[ponto_atual][vertice[i]] < min_distance_atual){
				min_distance_atual = in->graph->weight_[ponto_atual][vertice[i]];
				vertice_visitado = vertice[i];
				indice_vertice_visitado = i;
			}

		}

        permutation[indice_vertice_permutacao] = vertice_visitado;

        swap(vertice[indice_vertice_permutacao + 1],vertice[indice_vertice_visitado]);

		min_distance+=min_distance_atual;
	}
}

void Solution::InsercaoMaisProxima(Input *in){

    for(int i = 1;i <= in->graph->dimension_; i++){
        for(int j = 1;j < cont;j++){

        }
    }
}


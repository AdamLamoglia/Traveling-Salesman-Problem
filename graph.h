#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include "point.h"

using namespace std;

#ifndef GRAPH_H_H
#define GRAPH_H_H


class Graph{
    public:
    // Dimens�o do grafo
	 int dimension_;

       //v�rtices do grafo
	 vector<int> vertices_;

	// Matriz de Distancia entre clientes
	 vector< vector<int> > adjacency_;

    /*Matriz de pesos das arestas*/
	 vector<vector<double> > weight_;

    //vetores de latitude e longitude, utilizados para a fun��o GEO
	vector<int> latitude_;
	vector<int> longitude_;

	// Habilitado se o tipo for EUC_2D e suas variantes
	vector<Point> coordenate_;

    //vetor de demanda dos v�rtices
	vector<int> demand_;

	//vetor para armazenar os n�s do grafo que s�o depositos
	vector<int> depot_;

    //construtor padrao
	Graph();

    //construtor do grafo com o numero de vertices
	Graph(int num_vertices_);

	 //Distancia euclidiana em 2D
	void addEdgeEUC_2D(int idx);

	//Distancia euclidiana em 3D
	void addEdgeEUC_3D(int idx);

	//Distancia de manhattan em 2D
	void addEdgeMAN_2D(int idx);

	//Distancia de manhattan em 3D
	void addEdgeMAN_3D(int idx);

	//Distancia m�xima em 2D
	void addEdgeMAX_2D(int idx);

	//Distancia m�xima em 3D
	void addEdgeMAX_3D(int idx);

	//Casos em que os vertices adjacentes estar�o representados em matriz completa
	// matriz triangular superior e inferior
	void addEdgeEXPLICIT(int idx);

	//teto da distancia euclidiana em 2D
	void addEdgeCEIL_2D(int idx);

	//Distancia geogr�fica
	void addEdgeGEO(int idx);

	//Distancia pseudo-euclidiana
	void addEdgeATT(int idx);

};

#endif // GRAPH_H_H

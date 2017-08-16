#include "graph.h"

using namespace std;

//construtor do grafo associando o numero de vertices
Graph::Graph(int num_vertices_) {
	setDimension(num_vertices_);

	vertices_.resize(num_vertices_ + 1);
	adjacency_.resize(num_vertices_ + 1, vector<int>(num_vertices_ + 1));
	weight_.resize(num_vertices_ + 1, vector<double>(num_vertices_ + 1));
	latitude_.resize(num_vertices_ + 1);
	longitude_.resize(num_vertices_ + 1);
	coordenate_.resize(num_vertices_ + 1);
	demand_.resize(num_vertices_ + 1);
	depot_.resize(num_vertices_ + 1);

	for (int i = 1; i <= num_vertices_; ++i) {
		vertices_[i] = i;
	}
}

void Graph::addEdgeEUC_2D(int idx) {
	double xd, yd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = coordenate_[idx].x - coordenate_[i].x;
		yd = coordenate_[idx].y - coordenate_[i].y;
		dij = round(sqrt((xd) * (xd) + (yd) * (yd)));

		weight_[idx][i] = dij;

	}
}

void Graph::addEdgeEUC_3D(int idx) {
	double xd, yd, zd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = coordenate_[idx].x - coordenate_[i].x;
		yd = coordenate_[idx].y - coordenate_[i].y;
		zd = coordenate_[idx].z - coordenate_[i].z;
		dij = round(sqrt((xd) * (xd) + (yd) * (yd) + (zd) * (zd)));

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeMAN_2D(int idx) {
	double xd, yd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = abs(coordenate_[idx].x - coordenate_[i].x);
		yd = abs(coordenate_[idx].y - coordenate_[i].y);
		dij = round(xd + yd);

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeMAN_3D(int idx) {
	double xd, yd, zd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = abs(coordenate_[idx].x - coordenate_[i].x);
		yd = abs(coordenate_[idx].y - coordenate_[i].y);
		zd = abs(coordenate_[idx].z - coordenate_[i].z);

		dij = round(xd + yd + zd);

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeMAX_2D(int idx) {
	double xd, yd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = abs(coordenate_[idx].x - coordenate_[i].x);
		yd = abs(coordenate_[idx].y - coordenate_[i].y);
		dij = max(round(xd), round(yd));

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeMAX_3D(int idx) {
	double xd, yd, zd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = abs(coordenate_[idx].x - coordenate_[i].x);
		yd = abs(coordenate_[idx].y - coordenate_[i].y);
		zd = abs(coordenate_[idx].z - coordenate_[i].z);
		dij = max(round(xd), round(yd), round(zd));

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeATT(int idx) {
	int dij, tij;
	double xd, yd, rij


	for (int i = 1; i <= dimension_; ++i) {

		adjacency_[idx][i] = i;

		xd = coordenate_[idx].x - coordenate_[i].x;
		yd = coordenate_[idx].y - coordenate_[i].y;
		rij = sqrt((xd * xd + yd * yd) / 10.0);
		tij = round(rij);

		if (tij < rij) {
			dij = tij + 1;
		} else {
			dij = tij;
		}

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeCEIL_2D(int idx) {
	double xd, yd;
	int dij;

	for (int i = 1; i <= dimension_; ++i) {
		adjacency_[idx][i] = i;

		xd = coordenate_[idx].x - coordenate_[i].x;
		yd = coordenate_[idx].y - coordenate_[i].y;
		dij = round(sqrt((xd) * (xd) + (yd) * (yd)));

		weight_[idx][i] = dij;
	}

}

void Graph::addEdgeGEO(int idx) {
	double PI = 3.141592, RRR = 6378.388, min, q1, q2, q3;
	int dij, deg;

	for (int i = 1; i <= dimension_; ++i) {
		deg = round(coordenate_[i].x);
		min = coordenate_[i].x - deg;
		latitude_[i] = PI * (deg + (5 * min / 3)) / 180;
		deg = round(coordenate_[i].y);
		min = coordenate_[i].y - deg;
		longitude_[i] = PI * (deg + (5 * min / 3)) / 180;

	}

	for (int i = 1; i <= dimension_; ++i) {
		q1 = cos(longitude_[idx] - longitude_[i]);
		q2 = cos(latitude_[idx] - latitude_[i]);
		q3 = cos(latitude_[idx] + latitude_[i]);
		dij =
				(int) (RRR * acos(0.5 * ((1.0 + q1) * q2 - (1.0 - q1) * q3))
						+ 1.0);
		adjacency_[idx].push_back(i - 1);
		weight_[idx].push_back(dij);
	}

}


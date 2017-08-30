#include "graph.h"


using namespace std;


//construtor do grafo associando o numero de vertices
Graph::Graph(int num_vertices_){
    dimension_ = num_vertices_;


    vertices_.resize(num_vertices_+1);
    adjacency_.resize(num_vertices_+1,vector<int>(num_vertices_+1));
    weight_.resize(num_vertices_+1,vector<double>(num_vertices_+1));
    latitude_.resize(num_vertices_+1);
    longitude_.resize(num_vertices_+1);
    coordenate_.resize(num_vertices_+1);
    demand_.resize(num_vertices_+1);
    depot_.resize(num_vertices_+1);

    for(int i = 1; i <= num_vertices_; ++i){
        vertices_[i] = i;
    }
}

void Graph::addEdgeEUC_2D(int idx){
		int xd,yd,dij;

        for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx][i] = i;

            xd = coordenate_[idx].x-coordenate_[i].x;
            yd = coordenate_[idx].y-coordenate_[i].y;
            dij =round(sqrt((xd)*(xd)+(yd)*(yd)));

            //A lista de pesos agora puxa dij
            weight_[idx][i] = dij;

        }
}

void Graph::addEdgeEUC_3D(int idx){
		for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(round(sqrt(pow(2,coordenate_[idx].x-coordenate_[i].x)+pow(2,coordenate_[idx].y-coordenate_[i].y)+pow(2,coordenate_[idx].z-coordenate_[i].z))));
        }

}


void Graph::addEdgeMAN_2D(int idx){
		for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(round(abs(coordenate_[idx].x-coordenate_[i].x)+abs(coordenate_[idx].y-coordenate_[i].y)));
        }

}

void Graph::addEdgeMAN_3D(int idx){
		for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(round(abs(coordenate_[idx].x-coordenate_[i].x)+abs(coordenate_[idx].y-coordenate_[i].y)+abs(coordenate_[idx].z-coordenate_[i].z)));
        }


}

void Graph::addEdgeMAX_2D(int idx){
		for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(round(max(abs(coordenate_[idx].x-coordenate_[i].x),abs(coordenate_[idx].y-coordenate_[i].y))));
        }

}

void Graph::addEdgeMAX_3D(int idx){
        int dij,tij;

        for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            dij = round(max(abs(coordenate_[idx].x-coordenate_[i].x),abs(coordenate_[idx].y-coordenate_[i].y)));
            tij = round(abs(coordenate_[idx].z-coordenate_[i].z));
            weight_[idx].push_back(max(dij,tij));
        }

}

void Graph::addEdgeATT(int idx){
        int dij;

        for(int i = 1; i <= dimension_; ++i){
            double xd = coordenate_[idx].x - coordenate_[i].x;
            double yd = coordenate_[idx].y - coordenate_[i].y;
            double rij = sqrt( (xd*xd + yd*yd) / 10.0 );
            int tij = round(rij);

            if (tij<rij)
                dij = tij + 1;
            else
                dij = tij;

            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(dij);
        }

}

void Graph::addEdgeCEIL_2D(int idx){
		for(int i = 1; i <= dimension_; ++i){
            adjacency_[idx].push_back(i-1);
            weight_[idx].push_back(ceil(sqrt(pow(2,coordenate_[idx].x-coordenate_[i].x)+pow(2,coordenate_[idx].y-coordenate_[i].y))));
        }

}

void Graph::addEdgeGEO(int idx){
    double PI = 3.141592,RRR = 6378.388;

    for(int i = 1; i <= dimension_; ++i){
        int deg = round(coordenate_[i].x);
        double min = coordenate_[i].x - deg;
        latitude_[i] = PI*(deg+(5*min/3))/180;
        deg = round(coordenate_[i].y);
        min = coordenate_[i].y - deg;
        longitude_[i] = PI*(deg+(5*min/3))/180;

    }

    for(int i = 1; i <= dimension_; ++i){
        double q1 = cos(longitude_[idx] - longitude_[i]);
        double q2 = cos(latitude_[idx] - latitude_[i]);
        double q3 = cos(latitude_[idx] + latitude_[i]);
        int dij = (int) ( RRR * acos( 0.5*((1.0+q1)*q2 - (1.0-q1)*q3) ) + 1.0);
        adjacency_[idx].push_back(i-1);
        weight_[idx].push_back(dij);
    }


}

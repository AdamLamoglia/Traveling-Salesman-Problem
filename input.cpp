#include "input.h"

using namespace std;

Input& Input::operator=(const Input &in){
	cout<<"Nao use o operador de atribuicao"<<endl;
	if (this != &in) {
		this->capacity_ = in.capacity_;
		//todo terminar de implementar
	}
	return *this;
}

Input::Input() {
	name_ = "no name";
	comment_ = "no comment";
	type_ = "no type";
	edge_weight_type_ = "no weight";
	edge_weight_format_ = "no format";
	display_data_type_ = "no data";
	capacity_ = 0;
}

void Input::verifyExplicit(ifstream& inputFile,string s){
	//se a aresta for do tipo "EXPLICIT", entao terao 2 informacoes adicionais, que sao EDGE_WEIGHT_FORMAT e DISPLAY_DATA_TYPE
	if(edge_weight_type_ == "EXPLICIT"){

                //EDGE_WEIGHT_FORMAT
				inputFile >> s;
	                if(s[s.size()-1] != ':'){
	                    inputFile >> s;
	                }

	                //Associacao da string auxiliar s ao tipo entrada para peso das arestas(em forma de matriz completa,
	                //matriz triangular superior, inferior..)
	                inputFile >> edge_weight_format_;


	                //DISPLAY_DATA_TYPE
	                inputFile >> s;

	                if(s[s.size()-1] != ':'){
	                	inputFile >> s;
	                }

	                //Associacao ao tipo de display de dados (?)
	                inputFile >> display_data_type_;

	            }
}

//direciona para o construtor do grafo adequado para o tipo de relacao entre os pesos das arestas
void Input::verifySection(ifstream& inputFile,Point aux_point){

				if(edge_weight_type_ == "EUC_2D"){
					makeEUC_2D(inputFile,aux_point);
				}else if(edge_weight_type_ == "EUC_3D"){
					makeEUC_3D(inputFile,aux_point);
				}else if(edge_weight_type_ == "MAN_2D"){
					makeMAN_2D(inputFile,aux_point);
				}else if(edge_weight_type_ == "MAN_3D"){
						makeMAN_3D(inputFile,aux_point);
				}else if(edge_weight_type_ == "MAX_2D"){
						makeMAX_2D(inputFile,aux_point);
				}else if(edge_weight_type_ == "MAX_3D"){
						makeMAX_3D(inputFile,aux_point);
				}else if(edge_weight_type_ == "ATT"){
						makeATT(inputFile,aux_point);
				}else if(edge_weight_type_ == "GEO"){
						makeGEO(inputFile,aux_point);
				}else if(edge_weight_type_ == "CEIL_2D"){
						makeCEIL_2D(inputFile,aux_point);
				}else if(edge_weight_type_ == "EXPLICIT"){
						if(edge_weight_format_ == "FULL_MATRIX"){
							makeFULL_MATRIX(inputFile);
						}else if(edge_weight_format_ == "UPPER_ROW"){
							makeUPPER_ROW(inputFile);
						}else if(edge_weight_format_ == "LOWER_ROW"){
							makeLOWER_ROW(inputFile);
						}else if(edge_weight_format_ == "UPPER_DIAG_ROW"){
							makeUPPER_DIAG_ROW(inputFile);
						}else if(edge_weight_format_ == "LOWER_DIAG_ROW"){
							makeLOWER_DIAG_ROW(inputFile);
						}else if(edge_weight_format_ == "UPPER_COL"){
							makeUPPER_COL(inputFile);
						}else if(edge_weight_format_ == "LOWER_COL"){
							makeUPPER_COL(inputFile);
						}else if(edge_weight_format_ == "UPPER_DIAG_COL"){
							makeUPPER_DIAG_COL(inputFile);
						}else if(edge_weight_format_ == "LOWER_DIAG_COL"){
							makeLOWER_DIAG_COL(inputFile);
						}
				}
}


//Distancia euclidiana 2D
void Input::makeEUC_2D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

						}

						for (int i = 1; i < graph->dimension_; ++i) {
							graph->addEdgeEUC_2D(i);
						}

}

//Distancia euclidiana 3D
void Input::makeEUC_3D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

	                        inputFile >> aux_point.z;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeEUC_2D(index);
						}

}

//Distancia de manhattan 2D
void Input::makeMAN_2D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeMAN_2D(index);
						}

}

//Distancia de manhattan 3D
void Input::makeMAN_3D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

	                        inputFile >> aux_point.z;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeMAN_3D(index);
						}

}

//Distancia maxima 2D
void Input::makeMAX_2D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeMAX_2D(index);
						}

}

//Distancia maxima 3D
void Input::makeMAX_3D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

	                        inputFile >> aux_point.z;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeMAX_3D(index);
						}

}

//Distancia pseudo euclidiana 2D
void Input::makeATT(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeATT(index);
						}

}

//Distancia geografica
void Input::makeGEO(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeGEO(index);
						}

}

//Teto da distancia euclidiana 2D
void Input::makeCEIL_2D(ifstream& inputFile,Point aux_point){
						int index;

						for (int i = 0; i < graph->dimension_; ++i) {
							inputFile >> index;

							inputFile >> aux_point.x;

	                        inputFile >> aux_point.y;

							graph->coordenate_[index] = aux_point;

							graph->addEdgeCEIL_2D(index);
						}

}

//matriz completa
void Input::makeFULL_MATRIX(ifstream& inputFile){

	for (int i = 0; i < graph->dimension_; ++i) {
			for(int j = 0; j < graph->dimension_; ++j){

				inputFile >> graph->weight_[i][j];

				graph->adjacency_[i][j] = j;
			}
		}
}

//matriz triangular superior em fileira
void Input::makeUPPER_ROW(ifstream& inputFile){
		int l = 0, c = 1;
			//a expressao representa: tamanhoMatriz/2 - diagonalPrincipal
			for(int i = 0; i < (graph->dimension_*graph->dimension_/2) - graph->dimension_; ++i){

					inputFile >> graph->weight_[l][c];

					graph->adjacency_[l][c] = c;

					//esta na ultima linha
					if(c == graph->dimension_-1){
						//quando chega na ultima linha, na proxima iteracao l comeca da proxima coluna + 1
						l++;
						c = l + 1;
					}else{
						c++;
					}
			}
}

//matriz triangular inferior em fileira
void Input::makeLOWER_ROW(ifstream& inputFile){
		int l = 1,c = 0;

		//a expressao representa: tamanhoMatriz/2 - diagonalPrincipal
		for(int i = 0; i < (graph->dimension_*graph->dimension_/2) - graph->dimension_; ++i){

				inputFile >> graph->weight_[l][c];

				graph->adjacency_[l][c] = c;

				//esta na ultima linha
				if(l == graph->dimension_-1){
					//quando chega na ultima linha, na proxima iteracao l comeca da proxima coluna + 1
					c++;
					l = c + 1;
				}else{
					l++;
				}
		}
}

//matriz triangular superior em fileira incluindo a diagonal principal
void Input::makeUPPER_DIAG_ROW(ifstream& inputFile){
	int l = 0, c = 0;

	//a expressao representa: tamanhoMatriz/2 - diagonalPrincipal
	for(int i = 0; i < (graph->dimension_*graph->dimension_/2) - graph->dimension_; ++i){

				inputFile >> graph->weight_[l][c];

				graph->adjacency_[l][c] = c;

				//esta na ultima linha
				if(c == graph->dimension_-1){
						//quando chega na ultima linha, na proxima iteracao l comeca da proxima coluna + 1
						l++;
						c = l;
				}
				else
					c++;
	}
}

//matriz triangular inferior em fileira incluindo a diagonal principal
void Input::makeLOWER_DIAG_ROW(ifstream& inputFile){
	int l = 0,c = 0;

	//a expressao representa: tamanhoMatriz/2
	for(int i = 0; i < (graph->dimension_*graph->dimension_/2); ++i){

			inputFile >> graph->weight_[l][c];

			graph->adjacency_[l][c] = c;

			//esta na ultima linha
			if(l == graph->dimension_-1){
				//quando chega na ultima linha, na proxima iteracao l comeca no mesmo indice da coluna c
				c++;
				l = c;
			}
			else
				l++;
	}
}

//matriz triangular superior em coluna
void Input::makeUPPER_COL(ifstream& inputFile){

}

//matriz triangular inferior em coluna
void Input::makeLOWER_COL(ifstream& inputFile){

}

//matriz triangular superior em coluna incluindo a diagonal principal
void Input::makeUPPER_DIAG_COL(ifstream& inputFile){

}

//matriz triangular inferior em coluna incluindo a diagonal principal
void Input::makeLOWER_DIAG_COL(ifstream& inputFile){

}

void Input::makeDemand(ifstream& inputFile){
		int index;

		for (int i = 0; i < graph->dimension_; ++i) {
	                    inputFile >> index;

	                    inputFile >> graph->demand_[index];
					}
}

void Input::makeDepot(ifstream& inputFile){
	int index;

	while(inputFile >> index, index != -1){
	       graph->depot_[index] = index;
	}
}


// Faz a leitura do arquivo de entrada e armazena as informacoes necessarias
void Input::load(string file_name) {

	ifstream inputFile;

	inputFile.open(file_name.c_str(),ios::in);

    //string auxiliar para entrada
	string s;

	//numeros de vertice do grafo
	int num_vertices_;

	//variavel auxiliar para associar coordenadas
	Point aux_point;

    //getline(inputFile,s);

	if (inputFile.is_open()) {
           // cout<<"Abril, Maio, Junho..."<<endl;

            //NAME
            inputFile >> s;

            //Se a entrada nao estiver com o ":" junto ao tipo (ex: NAME:, EDGE_WEIGHT_TYPE_:)
            if(s[s.size()-1] != ':'){
                inputFile >> s;
            }

            //Associacao do nome do arquivo para s
            inputFile >> name_;


            //COMMENT
            inputFile >> s;

            if(s[s.size()-1] != ':'){
            	inputFile >> s;
            }

            //Associacao do comentario do arquivo para s
            getline(inputFile,comment_);

            //TYPE
            inputFile >> s;

            if(s[s.size()-1] != ':'){
            	inputFile >> s;
            }

            inputFile >> type_;

            //DIMENSION
            inputFile >> s;

            if(s[s.size()-1] != ':'){
            	inputFile >> s;
            }


            inputFile >> num_vertices_;

            //Constroi um novo grafo com a dimensão da entrada
            graph = new Graph(num_vertices_);

            //EDGE_WEIGHT_TYPE
            inputFile >> s;


            if(s[s.size()-1] != ':'){
            	inputFile >> s;
            }

            //getline(inputFile,s);
            inputFile >> edge_weight_type_;


            //funcao para verificar e coletar entrada para o caso de EDGE_WEIGHT_TYPE ser EXPLICIT
            verifyExplicit(inputFile,s);


            //CAPACITY
            inputFile >> s;

            if(s[s.size()-1] != ':'){
            	inputFile >> s;
            }

            //Associacao a capacidade do veiculo
            inputFile >> capacity_;

            //NODE_COORD_SECTION / EDGE_WEIGHT_SECTION
            inputFile >> s;

            //se s for NODE_COORD_SECTION, entao EDGE_WEIGHT_TYPE eh diferente de explicito, ou seja, eh representado
            //por uma funcao
             verifySection(inputFile,aux_point);

            //DEMAND_SECTION
			inputFile >> s;

			makeDemand(inputFile);


			//DEPOT_SECTION
            inputFile >> s;

            makeDepot(inputFile);

            //EOF
            inputFile >> s;

        //fim do arquivo
		inputFile.close();
		}else {
            cout << "Impossivel abrir o arquivo" << endl;
        }
}

#include "input.h"
#include "parametros.h"
#include "solution.h"

using namespace std;

int main(int argc, char*argv[]){


	// Arquivo
    Input entrada;

    Parametros::Store(argc,argv);

    entrada.load(Parametros::getInstancia());

    Solution s(&entrada);

    cout << "passou" << endl;

    s.greedyNearestNeighbor1(&entrada);

   cout<<s<<endl;

   s.greedyNearestNeighbor2(&entrada);

   cout<<s<<endl;


    return 0;
}

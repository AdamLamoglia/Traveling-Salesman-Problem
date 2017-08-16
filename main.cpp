#include "tsp.h"


using namespace std;

int main(){
    Input entrada;

    // Manipulador do arquivo de entrada

    //cout<<argv[0]<<" "<<argv[1]<<endl;

    ifstream file_("entrada.txt");

    if(file_.is_open())
    	entrada.load(file_);

    Tsp t()
}

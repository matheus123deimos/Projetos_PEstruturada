#include <iostream>
#include "fila_LE.hpp"

//const float inf = numeric_limits<float>::infinity();
	/*for(i=0;i<nv;i++){
		cout << "\n";
		for(j=0;j<nv;j++)cout <<  Matriz_Ad[i][j] << ",";
	}*/
		
using namespace std;

int main(){
	
	//Declarações
	int nv;
	int origem;
	Fila_enc<int> Vertices;
	int i;int j;
	
	//Recebe o número de vértices
	
	do{
		cout << "Numero de Vertices: ";
		cin >> nv;
		cout << "\n";
	}while(nv<1);
	
	int Distancia[nv];
	int Matriz_Ad[nv][nv];
	
	//Preenche a Matriz de Adjacência e o Vetor de Distâncias
	
	for(i=0;i<nv;i++){
		Distancia[i] = -1;
		for(j=0;j<nv;j++) Matriz_Ad[i][j] = 0;
	}

    
    //Recebe as Arestas e Preenche a Matriz de Adjacência
    
	cout << "Arestas: ";
	cout << "\n";
	int x;
    int y;
    for(i=0;i<(nv*(nv-1)/2) + nv;++i){
	  cin >> x >> y;
	  if(x == -1 && y == -1) break;
      Matriz_Ad[x-1][y-1] = 1;
      Matriz_Ad[y-1][x-1] = 1;
	}
	
	//Recebe a Origem
	
	do{
		cout << "Origem: ";
		cin >> origem;
	}while(origem<0 || origem >= nv);
	cout << "\n\n";
	
	//Calculo da Distância
	Inicializar_Fila(Vertices);
	Distancia[origem-1] = 0;
	Enfilar(Vertices,(origem -1));
	while(!Vazia(Vertices)){
		i = Desenfilar(Vertices);
		int dist_prox = Distancia[i];
		for(j=0;j<nv;j++){
			if(Matriz_Ad[i][j] && Distancia[j] == -1){
				Distancia[j] = dist_prox + 1;
				Enfilar(Vertices,j);
			}
		}
	}
	
	//Imprime Distancia
	cout << "\n\nDistancia:\n\n";
	for(i=0;i<nv;i++){
		cout << "De " << origem << " a " << i
		<< ":" << Distancia[i] << "\n";
	}
	
	Terminar_Fila(Vertices);
	return 0;
}

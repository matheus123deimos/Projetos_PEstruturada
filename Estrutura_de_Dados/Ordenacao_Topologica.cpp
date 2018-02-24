#include <iostream>
#include "Grafo.hpp"
#include "fila_LE.hpp"

using std::cin; using std::cout; using std::nothrow;

bool V_In(int v, int n, int sair){
		
		if(v<0 || v >n){
			if(v!=sair){
				cout << "\n\nVertice Invalido\n\n";
			}return true;
		}return false;			
}

int main(){
	
	//Declaração das variaveis:
	
	int n_vertices,i,j;  
	const int sair = -1;  
	No<int> *p;
	Grafo G;
	Fila_enc<int> F;
	int vertices_impressos = 0;
	
	//Número de Vértices:
	
	do { 
		cout << "Numero de Vertices: "; 
		cin >> n_vertices; 
	} while(n_vertices < 1);
	
	int *Arestas_IN = new(nothrow) int[n_vertices];
	if(!Arestas_IN){cout <<"\n\nSem memoria para Arestas_IN!\n\n"; return 2;}
	
	//Número de Arestas
	
	cout << "\n\nArestas Do Grafo: (vertices de 0 a " << n_vertices-1 << " ; "<< sair << " para sair):\n";
	
	if (Inicializar_Grafo(G,n_vertices)){ 
		cout << "\n\nSem memoria para G!\n\n"; 
		return 1; 
	}
	
	for (;;)
    {
      cout << "\n\nOrigem:  ";  
	  cin >> i;  
	  if (V_In(i, G.nvertices,sair)) break; 
	  
      cout << "\n\nDestino: ";  
	  cin >> j; 
	  cout << "\n\n";
	  if (V_In(j, G.nvertices,sair)) break; 
      
	  Adicionar_Aresta(G,i,j);
    }
	
	//Preparando para Ordenação Topológica
	
	for (i = 0;i < n_vertices;++i) Arestas_IN[i] = 0;
	 
	for (i = 0; i < n_vertices;++i){
		
		for (p=G.Vertices[i];p; p = p->prox) ++Arestas_IN[p->indice]; 
	}

	Inicializar_Fila(F);
	
	for (i = 0; i < n_vertices; ++i){
    	if(Arestas_IN[i] == 0){
			if(Enfilar(F,i)){
  	        	cout << "\n\nSEM MEMORIA PARA ENFILAR VERTICE INICIAL\n\n"; 
                return 3; 
			}
		}
	}
	
	//Ordenacao Topologica
	cout << "\n\nOrdenacao Topologica:\n\n";
	while (!Vazia(F)){
      i = Desenfilar(F);  
	  cout << "\n\n" <<i+1 << "\n\n";  
	  ++vertices_impressos;
      for (p= G.Vertices[i];p;p=p->prox){
         j = p->indice;
         if(--Arestas_IN[j]==0){
		 	 if(Enfilar(F,j)){ 
             	 cout << "\n\nERRO!\n\n" ; 
  	             return 4;
             }
	     }
      }
    } 
	
	if (vertices_impressos != n_vertices){ 
		cout << "\n\n--> Para Grafo Ciclico: Nao ha Ordenacao Topologica!\n\n"; 
    }

   Terminar_Fila(F);delete[] Arestas_IN;Terminar_Grafo(G);
	
}

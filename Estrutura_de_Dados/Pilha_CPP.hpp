#include <stdlib.h>
#include <iostream>

template <typename T>
struct Pilhalimitada{
    T *v;
    int tam_max;int topo;
    	
};

template <typename T>
bool Inicializar_Pilha(Pilhalimitada<T>&P, int tam_max){
	
	P.v = new(std::nothrow)T[tam_max];
	if(P.v){
		
		P.tam_max = tam_max;
		P.topo = -1;
		return false;
	}
	
}

template <typename T>
void Terminar_Pilha(Pilhalimitada<T>&P){delete[] P.v;}

template <typename T>
void Empilhar(Pilhalimitada<T>&P,T e){
 if(!Esta_Cheia(P)) P.v[++P.topo] = e;
}

template <typename T>
T Desempilhar(Pilhalimitada<T>&P){
  if(!Esta_Vazia(P))	return P.v[P.topo--];
}

template <typename T>//TESTAR ESSAS FUNÇÕES QUE SEGUEMS
T Topo(Pilhalimitada<T>&P){
	return P.v[P.topo];
}

template <typename T>
int Tamanho(Pilhalimitada<T>&P){
	return P.topo + 1;
}

template <typename T>
bool Esta_Vazia(Pilhalimitada<T>&P){
	return P.topo == -1;
}

template <typename T>
bool Esta_Cheia(Pilhalimitada<T>&P){
	return P.topo + 1 == P.tam_max;
}

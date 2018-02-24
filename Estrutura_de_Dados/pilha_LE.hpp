#include <iostream>
using std::nothrow;

template<typename T>
struct Node{
	T e;
	Node<T> *prox;
};

template<typename T>
struct Pilha_enc{
	Node<T> *topo;
};

template<typename T>
void Inicializar_Pilha(Pilha_enc<T>&P){
	P.topo = NULL;
}

template<typename T>
bool Empilhar(Pilha_enc<T>&P,T elem){
	Node <T> *n = new(nothrow) Node<T>;
	if(n){
		n->e = elem;
		n->prox = P.topo;
		P.topo = n;
		return false;
	}return true;
}

template<typename T>
T Desempilhar(Pilha_enc<T>&P){
	T elem = P.topo->e; Node<T> *n = P.topo;
	P.topo = P.topo->prox;
	delete n;
	return elem;
}

template <typename T>
bool Vazia(Pilha_enc<T>&P){
	return P.topo == NULL;
}

template <typename T>
void Terminar_Pilha(Pilha_enc<T>&P){
	while(!Vazia(P)){
		Desempilhar(P);
	}
}


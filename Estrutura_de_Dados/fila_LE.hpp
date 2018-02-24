#include <iostream>
using std::nothrow;

template<typename T>
struct Node{
	T elem;
	Node<T> *prox;
};

template<typename T>
struct Fila_enc{
	Node<T> *inicio,*fim;
};

template<typename T>
void Inicializar_Fila(Fila_enc<T>&F){
	F.inicio = F.fim= NULL;
}

template<typename T>
bool Enfilar(Fila_enc<T>&F, T e){
	Node<T> *n = new(nothrow) Node<T>;
	if(n){
		n->elem = e; n->prox = NULL;
		if(F.inicio == NULL) F.inicio = n;
		else F.fim->prox = n; 
		F.fim = n;
		return false;
	}return true;
}

template<typename T>
T Desenfilar(Fila_enc<T>&F){
	Node<T> *n = F.inicio;
	T e = n->elem;
	F.inicio = n->prox;
	delete n;
	return e;
}

template<typename T>
bool Vazia(Fila_enc<T>&F){ return F.inicio == NULL;}

template<typename T>
void Terminar_Fila(Fila_enc<T>&F){
	while(!Vazia(F)){
		Desenfilar(F);
	}
}

#include <iostream>
using std::nothrow;

template<typename T>
struct NodeDE{
	T elem; NodeDE<T> *ant, *prox;
};

template<typename T>
struct Deque_enc{
	NodeDE<T> *esq, *dir;
};

template<typename T>
void Inicializar_Deque(Deque_enc<T> &D){
	D.esq = D.dir= NULL;
}

template<typename T>
bool Inserir_dir(Deque_enc<T> &D, T e){
	NodeDE<T> *n = new(nothrow) NodeDE<T> ;
	if(n){
		n->elem = e;n->prox = NULL; n->ant = D.dir;
		if(D.dir == NULL) D.esq = n;
		else D.dir->prox = n;
		D.dir = n;
		return false;
	}else return true;
	
}

template<typename T>
bool Inserir_esq(Deque_enc<T> &D,T e){
	NodeDE<T> *n = new(nothrow) NodeDE<T>;
	if(n){
		n->elem = e;n->ant = NULL; n->prox = D.esq;
		if(D.esq == NULL) D.dir = n;
		else D.esq->ant = n;
		D.esq = n;
		return false;
	}else return true;
}

template<typename T>
T Remover_dir(Deque_enc<T> &D){
	NodeDE<T> *n = D.dir;
	T e = n->elem;
	n->ant->prox = n->prox;
	D.dir = n->ant;
	delete n;
	return e;
}

template<typename T>
T Remover_esq(Deque_enc<T> &D){
	NodeDE<T> *n = D.esq;
	T e = n->elem;
	n->prox->ant = n->ant;
	D.esq = n->prox;
	delete n;
	return e;
}

template<typename T>
bool Vazia(Deque_enc<T> &D){
	return D.esq == NULL && D.dir == NULL;
}

template<typename T>
void Terminar_Deque(Deque_enc<T> &D){
	NodeDE<T> *n = D.dir;
	while(n){
	    NodeDE<T> *p = n;
	    n = n->prox;
	    delete p;
    }
}


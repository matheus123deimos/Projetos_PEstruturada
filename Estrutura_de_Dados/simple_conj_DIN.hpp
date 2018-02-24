#include <iostream>
using std::nothrow;

template<typename T>
struct Node{T elem; Node<T> *prox;};

template<typename T>
struct ConjuntoDim{Node<T> *prim;};

template<typename T>
void Inicializar_Conjunto(ConjuntoDim<T> &C){C.prim = NULL;};

template<typename T>
bool Inserir(ConjuntoDim<T> &C,T e){

	Node<T> *m = new(nothrow) Node<T>;
	if(m){
		m->elem = e;
		m->prox = C.prim;
		C.prim = m;
		return false;
		
	}else return true;
}

template<typename T>
bool Pertence(ConjuntoDim<T>&C,T e){
	for(Node<T>*n = C.prim;(n);n=n->prox){
		if(n->elem==e) return true;
	}return false;
}

template<typename T>
bool Remover(ConjuntoDim<T> &C,T e){
	if(C.prim){
		Node<T> *n = C.prim;
		if(n->elem == e){C.prim = n->prox;delete n;return true;}
        for(;;){
			Node<T> *a = n;
			n = n->prox;
			if(n==NULL) return false;
			if(n->elem==e){a->prox = n->prox;delete n;return true;}
		}
	}else return false;
}

template<typename T>
void Terminar_Conjunto(ConjuntoDim<T>&C){
	for(Node<T>*n = C.prim;(n);){
		Node<T> *p = n->prox;
		delete n;
		n=p;
	}
}

template<typename T>
bool Vazio(ConjuntoDim<T>&C){return C.prim == NULL;}

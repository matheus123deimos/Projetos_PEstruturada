#include <iostream>
using std::nothrow;

template<typename T>
struct Pilha_Ilimitada{
	T *v; int topo, tam_v;
};

template<typename T>
bool Inicializar_Pilha(Pilha_Ilimitada<T>&P){
    P.v = new(nothrow) T[1];
    if(P.v){
    	P.topo = -1;
    	P.tam_v = 0;
    	return false;
	}return true;
}

template<typename T>
bool Esta_Vazia(Pilha_Ilimitada<T>&P){
	if(P.topo<0) return true;
	return false;
}

template<typename T>
void Terminar_Pilha(Pilha_Ilimitada<T>&P){delete[]P.v;}

template<typename T>
bool Empilhar(Pilha_Ilimitada<T>&P,T e){
	
	if(!Esta_Vazia(P)&&(P.topo+1==P.tam_v)){
		T *aux = new(nothrow) T[2*P.tam_v];int i;
		
		if(aux){
		    for(i=0;i<P.tam_v;++i) aux[i] = P.v[i];
		    aux[P.tam_v]=e; delete[]P.v;
		    P.v=aux; ++P.topo; ++P.tam_v;
		    return false;
	    }else return true;
	    
	}else if(Esta_Vazia(P)||P.topo<P.tam_v-1){
		 P.v[++P.topo] = e;
		 ++P.tam_v; return false;    
	}else return true;
}

template<typename T>
T Desempilhar(Pilha_Ilimitada<T>&P){
	T topo;
	if(!Esta_Vazia(P)) topo = P.v[P.topo--];
	return topo;
}

//Funções Adicionais: Topo e Tamanho

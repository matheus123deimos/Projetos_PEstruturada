#include <iostream>
//Fila Não Circular
using std:: nothrow;

template<typename T>
struct Fila_Limitada{
	T *v; int tam_v, inicio, fim;
};

template<typename T>
bool In_Fila(Fila_Limitada<T>&F, int tam_max){
	
	F.v = new(nothrow) T[tam_max];
	if(F.v){
		F.tam_v = tam_max;
		F.inicio = 0;
		F.fim = -1;
		return false;
		
	}else return true;
	
}

template<typename T>
bool Esta_Vazia(Fila_Limitada<T>&F){
	return F.fim < 0 || (F.fim==F.inicio-1&&F.fim>=0);
}

template<typename T>
bool Esta_Cheia(Fila_Limitada<T>&F){
	return F.fim==F.tam_v-1; 
}

template<typename T>
void Enfilar(Fila_Limitada<T>&F,T e){
  if(!Esta_Cheia(F)){
    if(F.fim==F.inicio-1&&F.fim>=0) {F.inicio = 0; F.fim = -1;}
	F.v[++F.fim] = e;
  }
}

template<typename T>
T Desenfilar(Fila_Limitada<T>&F){
 T primeiro;
 if(!Esta_Vazia(F)){
     primeiro  = F.v[F.inicio];
     ++F.inicio;
     if(Esta_Vazia(F)&&F.fim==F.tam_v-1){F.inicio = 0; F.fim = -1; return primeiro;}
  }return primeiro;
}

template<typename T>
void Terminar_Fila(Fila_Limitada<T>&F) {delete[]F.v;}
//Funções Adicionais: Topo;Tamanho
//Colocar A volta ao inicio  também no Empilhar

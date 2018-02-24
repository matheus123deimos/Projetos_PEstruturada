#include <iostream>
using std:: nothrow;

template<typename T>
struct Deque_Limitada{
	T *v; int tam_v, esq, dir;
};

template<typename T>
bool In_Deque(Fila_Limitada<T>&D, int tam_max){
	
	D.v = new(nothrow) T[tam_max];
	if(D.v){
		D.tam_v = tam_max;
		D.esq = -1;
		D.dir =  -1;
		return false;
			
	}else return true;
	
}

template<typename T>//modificar dependendo de como for as funções de adicionar e remover
bool Esta_Vazia(Fila_Limitada<T>&D){
	return
}

template<typename T>
bool Esta_Cheia(Fila_Limitada<T>&D){
	return  
}

template<typename T>///
void Adc_Dir(Deque_Limitada<T>&D,T e){
    if(Esta_Vazia(D)){D.v[++D.dir]=e;++D.esq;}
    else if(!Esta_Cheia(D)){
            if(D.dir==D.tam_v-1){
                T Vetor_Ax[(D.dir-D.esq)+2];int i;
                for(i=0;i<=D.dir-D.esq;++i) Vetor_Aux[i] = D.v[D.esq+i];
                D.v[D.dir-D.esq)+1] = e;
                for(i=0;i<=D.dir-D.esq+1;++i) D.v[i] = Vetor_Aux[i];
                D.esq = 0;D.dir= (D.dir-D.esq) +1;
            }else{D.v[++D.dir];}  
    }    
}

template<typename T>
void Adc_Esq(Deque_Limitada<T>&D,T e){
     if(!Esta_Vazia(D)){
         if(!Esta_Cheia(D)){
          if(D.dir==D.tam_v-1){D.v[--D.esq]=e;return;}
          T Vetor_Ax[(D.dir-D.esq)+2];int i;
          Vetor_Ax[0]=e;for(i=0;i<=D.dir-D.esq;++i) Vetor_Ax[i+1] = D.v[D.esq+i];
          for(i=0;i<(D.dir-D.esq)+2;++i) D.v[D.tam_v-1-i] = Vetor_Aux[(D.dir-D.esq+1)-i];
          return;
         }
     }
     else if(Esta_Vazia(D)){
     if(D.esq == D.dir){D.v[++D.esq]=e;++D.dir;return;}
     D.v[--D.esq]=e; return;
    }
    return;
}


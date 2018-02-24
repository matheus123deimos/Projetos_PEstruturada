#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Vetor[MAX];int n = 0;int m = 0;int Qe = 0;
int *p = Vetor;int *q = Vetor;
//int Stack_Empty(void);
void Enqueue(int);int Dequeue(void);
int Queue_Empty(void);int Queue_Full(void);
int main()
{   
	int aux;int aux1;int aux2;int aux3;int aux4;
	for(aux=0;aux<MAX;aux++) Vetor[aux] = 0;
	for(;;){
		fflush(stdin);
		printf("\nEscolha:Adicionar(a),Remover(r),Visualizar(v),Sair(s):");
		char esc = getchar();
		switch(esc){
			case 'a':
				if(Queue_Full()){
					printf("\nFila Cheia!\n");break;
				}
				printf("\nDigite um Numero: ");
				scanf("%d",&aux1);
				printf("\n%d %d \\ %d\n",m,n,Qe);
				Enqueue(aux1);
				printf("\n%d %d \\ %d\n",m,n,Qe);
				break;
			case 'r':
				//if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				if(Queue_Empty()){
					printf("\nFila Vazia!\n");break;
				}
				if(Qe>0){printf("\nValor%d: %d removido!\n",m-1,Dequeue());break;}
				break;
			case 'v':
				//if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				if(m<n){
					for(aux2=m;aux2<n;aux2++){
						//printf("\n%d  %d\n",m,n);
						printf("\nValor%d: %d\n",aux2,Vetor[aux2]);
						if(aux2== MAX-1) printf("\nValor%d: %d\n",n,Vetor[n]);
			    	}
				}else if(n<m){
					for(aux3=m;aux3<MAX;aux3++) printf("\nValor%d: %d\n",aux3,Vetor[aux3]);
					for(aux4=n;aux3<n;aux3++) printf("\nValor%d: %d\n",aux4,Vetor[aux4]);
				}else printf("\nFila Vazia\n");
				break;
			case 's':
				exit(0);
			
			default:
				continue;
			
		}
	}
	
}

//Diz se a Fila está vazia
int Queue_Empty(void){ if(Qe == 0) return 1;return 0;}
//Diz se a Fila está cheia
int Queue_Full(void){if(Qe == MAX)return 1;return 0;}
//q == (p + 1)
//Adiciona um Elemento da Fila
void Enqueue(int x){
	if(n<MAX){
		*p = x;
		 p++;
		 if(n!= MAX -1) n++;
		 Qe++;
	}else if(n == MAX){
	   *p = Vetor[0];
	    n = 1;
	   *p = x;
		return;
	}
}

//Recupera um Elemento da Fila
int Dequeue(void){
	int x;
	if(m<MAX){
	   x = *q;
	   q++;
	   m++;
	   Qe--;
	   return x;
    }else if(m == MAX){
	   *q = Vetor[0];
	    m = 0;
	    x = *q;
		return x;
	}
	return -1;
}


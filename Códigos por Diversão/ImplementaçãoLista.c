#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Vetor[MAX];int n = 0;int m = 0;
int *p = Vetor;int *q = Vetor;
//int Stack_Empty(void);
void Enqueue(int);int Dequeue(void);
int main()
{   
	int aux;int aux1;int aux2;
	for(aux=0;aux<MAX;aux++) Vetor[aux] = 0;
	for(;;){
		fflush(stdin);
		printf("\nEscolha:Adicionar(a),Remover(r),Visualizar(v),Sair(s):");
		char esc = getchar();
		switch(esc){
			case 'a':
				//if(n==MAX){printf("\nPilha Cheia!\n");break;}
				printf("\nDigite um Numero: ");
				scanf("%d",&aux1);
				Enqueue(aux1);
				break;
			case 'r':
				//if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				printf("\nValor%d: %d removido!\n",n,Dequeue());
				break;
			case 'v':
				//if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				for(aux2=m;aux2<n;aux2++){
					//printf("\n%d  %d\n",m,n);
					printf("\nValor%d: %d\n",aux2,Vetor[aux2]);
			    }
				break;
			case 's':
				exit(0);
			
			default:
				continue;
			
		}
	}
	
}

//Diz se a Pilha está vazia
//int Stack_Empty(void){ if(*p == 0) return 1;return 0;	}

//Adiciona um Elemento da Fila
void Enqueue(int x){
	*p = x;
	if(*p == *q){
	   *p = Vetor[0];
	    p++;
		n++;
		return;
	}else{p++;n++;}
}

//Recupera um Elemento da Fila
int Dequeue(void){
	int x = *q;
	if(*q == *p){
		*q = Vetor[0];
		q++;
		m++;
		return;
	}
	else{q++;m++;}
	return x;
}


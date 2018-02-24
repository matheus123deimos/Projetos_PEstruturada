#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Vetor[MAX];int n = 0;
int *p = Vetor;
int Stack_Empty(void);void Push(int);int Pop(void);
int main()
{   
	int aux;
	for(aux=0;aux<MAX;aux++) Vetor[aux] = 0;
	for(;;){
		fflush(stdin);
		printf("\nEscolha:Adicionar(a),Remover(r),Visualizar(v),Sair(s):");
		char esc = getchar();
		switch(esc){
			case 'a':
				if(n==MAX){printf("\nPilha Cheia!\n");break;}
				int aux1;
				printf("\nDigite um Numero: ");
				scanf("%d",&aux1);
				Push(aux1);
				break;
			case 'r':
				if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				printf("\nValor%d: %d removido!\n",n,Pop());
				break;
			case 'v':
				if(Stack_Empty()){printf("\nPilha Vazia!\n");break;}
				int aux2;
				for(aux2=0;aux2<n;aux2++) printf("\nValor%d: %d\n",aux2,Vetor[aux2]);
				break;
			case 's':
				exit(0);
			
			default:
				continue;
			
		}
	}
	
}

//Diz se a Pilha está vazia
int Stack_Empty(void){ if(*p == 0) return 1;return 0;	}

//Adiciona um Elemento da Pilha
void Push(int x){
	if(Stack_Empty()){*p = x;n++;return;}
	p++;*p = x;n++;
}

//Recupera um Elemento da Pilha
int Pop(void){p--;n--;return *(p+1);}

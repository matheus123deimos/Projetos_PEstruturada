#include <stdlib.h>
#include <stdio.h>
#define MAX 100


int *p;
int *tos;
int *bos;
int t;
void push(int);
int pop(void);

int main()
{
	int a,b;
	char s[80];
	
	p = (int *) malloc(MAX*sizeof(int));
	if(!p){
		printf("\nFalha de alocacao\n");
		exit(1);
	}
	tos = p;
	bos = p+MAX-1;
	for(t=0;t<MAX;++t) *(p + t) = 0;
	printf("Calculadora de Quatro Funçcoes\n");
	printf("Digite 's' para sair\n");
	printf("\nDigite Dois Números: ");
	scanf("%d %d",&a,&b);push(a);push(b);
	do {
		printf(": ");
		gets(s);
		switch(*s){
			case '+':
				printf("\n%d  %d  %d\n",*p,*tos,*bos);
				a = pop();
				b = pop();
				//printf("%d\n",a+b);
				push(a+b);
				printf("\n%d  %d  %d\n",*p,*tos,*bos);
				break;
			case '-':
				a = pop();
				b = pop();
				printf("%d\n",b-a);
				push(b-a);
				break;
			case '*':
				a = pop();
				b = pop();
				printf("%d\n",b*a);
				push(b*a);
				break;
			case '/':
				a = pop();
				b = pop();
				if(a==0){
					printf("divisao por 0\n");
					break;
				}printf("%d\n",b/a);
				push(b/a);
				break;
			case '.':
				a = pop();
				push(a);
				printf("O valor atual da pilha e:%d\n",a);
				break;
			default:
				push(atoi(s));	
		}
	}while(*s!='s');
}
//Armazena Elementos na Pillha
void push(int i)
{
	if(p>bos){
		printf("Pilha cheia\n");
		return;
	}
	*p = i;
	p++;	
}
//Recupera Elementos do Topo da Pilha
int pop(void)
{
	p--;
	if(p<0){
		printf("Pilha vazia\n");
		return 0;
	}
	return *(p-1);
}

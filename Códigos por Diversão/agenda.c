#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 3

char *p[MAX],*qretrieve(void);
int spos = 0;
int rpos = 0;
void enter(void),qstore(char*q),review(void),delete1(void);

int main()
{
	char s[80];
	register int t;
	
	for(t=0;t<MAX;++t) p[t] = NULL;
	for(;;){
		printf("Inserir,Listar,Remover,Sair: ");
		gets(s);
		*s = toupper(*s);
		switch(*s){
			case 'I':
				enter();
				break;
			case 'L':
				review();
				break;
			case 'R':
				delete1();
				break;
			case 'S':
				exit(0);
		}
	}
}

//Insere um evento na fila
void enter(void)
{
	char s[256],*p;
	do{
		printf("Insira o evento %d",spos + 1);
		gets(s);
		if(*s == 0) break;
		p = malloc(strlen(s)+1);
		if(!p){
			printf("Sem memória.\n");
			return;
		}
		strcpy(p,s);
		qstore(p);
	}while(*s);
}

//Vê o que ta na fila
void review(void)
{
	register int t;
	for(t=rpos;t<spos;++t)
		printf("%d. %s\n",t+1,p[t]);
}
//Apaga um evento da fila
void delete1(void)
{
	char *p;
	
	if((p=qretrieve())==NULL) return;
	printf("%s\n",p);
}

//Armazena um Evento
void qstore(char *q)
{
	if(spos==MAX){
		printf("Lista cheia\n");
		return;
	}
	p[spos] = q;
	spos++;
}
//Recupera um evento
char *qretrieve(void)
{
	if(rpos==spos){
		printf("Sem eventos.\n");
		return NULL;
	}
	rpos++;
	return p[rpos-1];
}

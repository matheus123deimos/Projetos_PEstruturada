#include <stdlib.h>
#include <stdio.h.>
#include <string.h>
#include <ctype.h>
#define MAX 5

char *p[MAX],*qcretrieve(void);
int spos = 0;
int rpos = 0;
void enter(void),qcstore(char*q),review(void),delete1(void);

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
		qcstore(p);
	}while(*s);
}
void review(void)
{
	register int t;
	if(rpos<=spos){
		for(t=rpos;t<MAX;++t){printf("%d. %s\n",t+1,p[t]);}
	}else if(rpos>spos){
		for(t=rpos;t<MAX-1;++t) printf("%d. %s\n",t+1,p[t]);
		for(t=0;t<spos;++t) printf("%d. %s\n",t+1,p[t]);
	}
}

void delete1(void)
{
	char *p;
	
	if((p=qcretrieve())==NULL) return;
	printf("%s\n",p);
}
void qcstore(char *q)
{
	if(spos-rpos==MAX-1){
		printf("Lista cheia\n");
		return;
 	}else if(rpos-spos==1){
 		printf("Lista cheia\n");
		return;
	}
	printf("\n%d  %d\n",rpos,spos);
	if(spos==MAX-1){p[spos] = q;spos = 0;return;}
	p[spos] = q;
	spos++;
	printf("\n%d  %d\n",rpos,spos);
}

char *qcretrieve(void)
{
	
	if(rpos==spos){
		printf("\nSem eventos para recuperar\n");
		return NULL;
	}
	rpos++;
	printf("\n%d  %d\n",rpos,spos);
	if(rpos==MAX){rpos = 0;rpos++;}
	return p[rpos-1];
}

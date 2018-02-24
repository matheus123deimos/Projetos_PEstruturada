#include <stdio.h>
#include <stdlib.h>

struct address{
	
	char name[40];
	char street[40];
	char city[20];
	char state[3];
	char zip[11];
	struct address *next;
}info;

struct address *start,*last = NULL;

void display(struct address *start);
struct address *search(struct address *start, char *n);
void sldelete(struct address *p,struct address *i,struct address **start,struct address **last);
void sls_store(struct address *i,struct address **start,struct address **last);
//void slstore(struct address *i,struct address **last);

int  main()
{
	
	for(;;){
		fflush(stdin);
		printf("\nEscolha:Adicionar(a),Remover(r),Visualizar(v),Sair(s):");
		char esc = getchar();
		switch(esc){
			case 'a':
				printf("\nDigite o Nome: ");
				scanf("%s",info.name);
				fflush(stdin);
				/*printf("\nDigite a Rua: ");
				scanf("%s",info.street);
				fflush(stdin);
				printf("\nDigite a Cidade: ");
				scanf("%s",info.city);
				fflush(stdin);
				printf("\nDigite o Estado: ");
				fflush(stdin);
				scanf("%s",info.state);
				fflush(stdin);
				printf("\nDigite o Cep: ");
				fflush(stdin);
				scanf("%s",info.zip);
				fflush(stdin);*/
				struct address *p = &info;
				struct address **Com = &start;
				struct address **Fim = &last;
				sls_store(p,Com,Fim);
				break;
			case 'r':
				break;
			case 'v':
				display(start);
				break;
			case 's':
				exit(0);
			
			default:
				continue;
			
		}
	}
} 

void display(struct address *start)
{
	while(start){
		printf("\n%s\n",start->name);
		start = start->next;
	}
}

struct address *search(struct address *start, char *n){
	while(start){
		if(!strcmp(n,start->name)) return start;
		start = start->next;
	}
	return NULL;
}

void sldelete(struct address *p,struct address *i,
struct address **start,struct address **last){

if(p) p->next = i->next;
else *start = i->next;
if(i==*last && p) *last = p;
}

void sls_store(struct address *i,struct address **start,struct address **last)
{
	struct address *old, **p;
	p = &(*start);
	if(!*last){
		printf("\nEstou aqui- 0\n");
		i->next =NULL;
		*last = i;
		*start = i;
		printf("%s",(*p)->name);
		return; 
	}
	/*old = NULL;
	while(p){
		if(strcmp(p->name,i->name)<0)
		{	
			printf("\nEstou aqui - 1\n");
			old = p;
			p = p->next;
		}
		else{
			if(old){
				printf("\nEstou aqui - 2\n");
				old->next = i;
				i ->next = p;
				return;
			}
			printf("\nEstou aqui - 3\n");
			i->next = p;
			*start = i;
			return;
		}
		printf("\nEstou aqui - 4\n");
		(*last)->next = i;
		i->next = NULL;
		*last = i;
	}*/
}

/*void slstore(struct address *i,struct address **last)
{
	if(!*last) *last = i;
	else (*last)->next = i;
	i -> next = NULL;
   *last = i;
}*/

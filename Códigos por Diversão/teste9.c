#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

struct list_type
{
char name[40];
char street[40];
char city[30];
char state[3];
char zip[10];
}list[SIZE];

int menu(void);
void init_list(void),enter(void);
void display(void),save(void);
void load(void);

void main(void)
{   
	char choice;
	FILE *fp = fopen("maillist","r+b");
	init_list();
	for(;;)
	{
		choice = menu();
		switch(choice)
		{
			case '1': enter();break;
			case '2': display();break;
			case '3': load();break;
			case '4': save();break;
			case '5': fclose(fp);exit(0);
			default:  printf("\nComando Errado\n");
		}
	}
}

/*Inicializa a Lista*/
void init_list(void)
{
	register int t;
	for(t=0;t<SIZE;t++) *list[t].name = '\0';
	/*um nome de comprimento zero significa vazio*/
}
/*Põe os nomes na lista*/
void enter(void)
{
	register int i;
	for(i=0;i<SIZE;i++){
		if(!*list[i].name) break;
	}
	
	if(i==SIZE)
	{
		printf("\nlista cheia\n");
		return;	
	}
	printf("\nnome: ");
	gets(list[i].name);
	fflush(stdin);
	printf("\nrua: ");
	gets(list[i].street);
	fflush(stdin);
	printf("\ncidade: ");
	gets(list[i].city);
	fflush(stdin);
	printf("\nestado: ");
	gets(list[i].state);
	fflush(stdin);
	printf("\nCEP: ");
	gets(list[i].zip);	
	fflush(stdin);
}
/* Mostra a lista */
void display(void)
{
	register int t;
	for(t=0;t<SIZE;t++)
	{
		if(*list[t].name){
			printf("\n%s\n",list[t].name);
			printf("%s\n",list[t].street);
			printf("%s\n",list[t].city);
			printf("%s\n",list[t].state);
			printf("%s\n",list[t].zip);
		}
	}
}
/* Salva a Lista */
void save(void)
{
	FILE *fp;
	register int i;
	
	if((fp=fopen("maillist","r+b"))== NULL){
		printf("\ncO arquivo nao pode ser aberto\n");
		return;
	}
	for(i=0;i<SIZE;i++)
	{
		if(*list[i].name)
		{
			if((fwrite(&list[i],sizeof(struct list_type),1,fp) != 1))
			{
				printf("\nErro de escrita no arquivo\n");
			}
		}
	}
	rewind(fp);
}
/* Carrega o arquivo */
void load(void)
{
	FILE *fp;
	register int i;
	if((fp=fopen("maillist","r+b"))==NULL)
	{
		printf("\nO arquivo nao pode ser aberto.\n");
		return;
	}
	init_list();
	for(i=0;i<SIZE;i++)
	{
		if(fread(&list[i],sizeof(struct list_type),1,fp)!=1)
		{
			if(feof(fp)) break;
			printf("\nErro de leitura no arquivo.\n");
		}
	}
	rewind(fp);
}
/* Obtém uma seleção do menu. */
menu(void)
{
	char s;
	do{
		
		printf("\n1 - Inserir\n");
		printf("2 - Visualizar\n");
		printf("3 - Carregar\n");
		printf("4 - Salvar\n");
		printf("5 - Terminar\n");
		printf("escolha: ");
		s = getchar();
		fflush(stdin);
	}while(s == 1|| s == 2|| s == 3|| s == 4|| s == 5);
	return s;
}

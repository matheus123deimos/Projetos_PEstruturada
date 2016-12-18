
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

struct Not//Estrutura que guarda os predicad os do Notbook

{
    char marca[10];
    char modelo[10];
    char proces[10];
    int HD;
    int RAM;
    double tela;
    char InOt[10];
    char So[10];
    int valor;
    char codec[8];//Codec é um código alfa-numerico composto pelo primeiro caracter da marca do Notbook, pelo primiro
                  //caracter do modelo do Notebok, pelo primeiro caracter do processador do Notebook , pelo tamanho da
                  //tela e por ultimo a quantidade de memória RAM do computador se os caracteres forem letras devem ser gravadas maiusculas
                  //Tudo isso para dessa forma ser facil oacesso aos notbooks do Estoque ,necessitando apenas olha-los na mostragem
};

struct listaNot//Estrutura que guarda outras estruturas Notbook  e gerencia a quantidade de Notbooks
{
     unsigned nco;  // Número de contatos na lista
    struct Not Notb[MAX];
};

void lb(void)//Função Limpadora de BUFFER
{
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}
void mostreNot(struct Not note)//Função que mostra os dados de um Notbook
{
    printf("%-9s%-5s  %-8s  %-4d     %-2d       %.1f    %-9s %-9s   %d",note.marca,note.modelo,note.proces,note.HD,note.RAM,note.tela,note.InOt,note.So,note.valor);
}

void insereNot(struct listaNot *lista, struct Not note)//Função que adiciona um Notbook em uma Lista de Notbooks qualquer
{
    lista->Notb[lista->nco++] = note;
}


void mostreLN(struct listaNot *lista)//Função que vaarre um vetor de estruturas Not Mostrando os Notbooks Presentes
{
    int i;
    printf("\n\n------------------------------ Lista de Notbooks -------------------------------\n");
    printf("MARCA-- MODEl-- PROCE-- HD(GB)-- RAM(GB)-- TEL(po)-- IN.OUT-- SIS.OPER-- VAL(R$)\n");
    for(i=0; i<lista->nco; i++) {
        mostreNot(lista->Notb[i]);
        printf("\n");
    }
    printf("\n\n");
}



int buscaNot(struct listaNot *lista,char codigo[8])//Função que busca o Notbook pelo seu Codec e retorna o seu indice na lista
{
    int i;
    for(i=0; i<lista->nco; i++){
        if(strcmp(codigo,lista->Notb[i].codec) == 0){

        	return i;
    	}
    }
    return -1;
}
int buscamarca(struct listaNot *lista, char marc[10])//Função que busca um notbook pela sua marca e retorna o seu índice
{
    int i;
    for(i=0; i<lista->nco; i++){
        if((strcmp(lista->Notb[i].marca,marc)) == 0){

        	return i;
        	break;
    	}

    }
    return -1;
}

int buscaproces(struct listaNot *lista, char proc[10])//Função que busca um Notbook pelo seu processador e retorna o seu índice
{
    int i;
    for(i=0; i<lista->nco; i++){
        if((strcmp(lista->Notb[i].proces,proc)) == 0){

        	return i;
        	break;

    	}
    }
    return -1;
}
void mostFilterM(struct listaNot *lista,char marc[10])//função de mostragem de notbooks pela Marca
{
    int i;
    if(buscamarca(lista,marc) == -1){
        printf("\nEsta marca esta em falta no Estoque.");
    }
    else
    {
        printf("\n\n------------------------------ Notbooks/(MARCA) --------------------------------\n");
        printf("MARCA-- MODEl-- PROCE-- HD(GB)-- RAM(GB)-- TEL(po)-- IN.OUT-- SIS.OPER-- VAL(R$)\n");
        for(i = 0; i<lista->nco; i++) {
            if((strcmp(lista->Notb[i].marca,marc)) == 0){
                mostreNot(lista->Notb[i]);
                printf("\n");
            }
        }
    }

    printf("\n\n");
}
void mostFilterP(struct listaNot *lista,char proc[10])//Função de mostragem de Notbooks pelo processador
{
    int i;
    if(buscaproces(lista,proc) == -1){
        printf("\nComputadores com esse processador faltam no estoque.");
    }
    else
    {
        printf("\n\n------------------------------ Notbooks/(PROCESSADOR) -------------------------------\n");
        printf("MARCA-- MODEl-- PROCE-- HD(GB)-- RAM(GB)-- TEL(po)-- IN.OUT-- SIS.OPER-- VAL(R$)\n");
        for(i = 0; i<lista->nco; i++) {
            if((strcmp(lista->Notb[i].proces,proc)) == 0){
                mostreNot(lista->Notb[i]);
                printf("\n");
            }
        }
    }
    printf("\n\n");
}


int ordenaPreco(const void *n1, const void *n2)//Função de Ordenação da lista de Notbooks,por preço, para ser usadas com o qsort()
{
    struct Not *cn1 = (struct Not *) n1;
    struct Not *cn2 = (struct Not *) n2;
    return cn1->valor - cn2->valor;
}

int ordenaPro(const void *n1, const void *n2)//Função de Ordenação da lista de Notbooks,por processador, para ser usadas com o qsort()
{
    struct Not *cn1 = (struct Not *) n1;
    struct Not *cn2 = (struct Not *) n2;
    return strcmp(cn1->proces,cn2->proces);
}

int ordenaMarca(const void *n1, const void *n2)//Função de Ordenação da lista de Notbooks,por marca, para ser usadas com o qsort
{
    struct Not *cn1 = (struct Not *) n1;
    struct Not *cn2 = (struct Not *) n2;
    return strcmp(cn1->marca,cn2->marca);
}
struct Not removeNot(struct listaNot *lista,char codigo[8])//função para remover um Notbook de uma lista qualquer,recebe o codec do Notbook
{
    int i;
    struct Not res = lista->Notb[buscaNot(lista,codigo)];
    for(i=buscaNot(lista,codigo); i<lista->nco-1; i++)
        lista->Notb[i] = lista->Notb[i+1];
    lista->nco--;
    return res;
}

void mudaNot(struct listaNot *lista,char codigo[8])//função que  modifica os dados de um Notbooks, só os que o usuário desejar
{  int atr = 0;
   char y = 'A';
   int i = 1;
   int t = buscaNot(lista,codigo);
   while(i<10)
   {
	if(i == 1)
	{
	   printf("\n\nDeseja Modificar a Marca?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVA MARCA: ");
			scanf("%s",lista->Notb[t].marca);
			atr = 1;
			i = i +1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
        if(y!= 's'&& y!= 'S' && y!='N' && y!='n')
        {
            printf("\nComando Invalido!");
            lb();
        }

	}

	if(i == 2)
	{  lb();
       	   printf("\n\nDeseja Modificar a Modelo?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVO MODELO:");
			scanf("%s",lista->Notb[t].modelo);
			atr = 1;
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
        if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }


	}

	if(i == 3)
	{  lb();
	   printf("\n\nDeseja Modificar o Processador?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVO PROCESSADOR: ");
			scanf("%s",lista->Notb[t].proces);
			atr = 1;
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }
	}

	if(i == 4)
	{  lb();
	   printf("\n\nDeseja Modificar a capacidade do HD?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVA CAPACIDADE DE HD: ");
			scanf("%d",&lista->Notb[t].HD);
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
            printf("\nComando Invalido!");
        }
	}

	if(i == 5)
	{  lb();
	   printf("\n\nDeseja Modificar a capacidade de memoria RAM?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVA CAPACIDADE DE MEMORIA RAM: ");
			scanf("%d",&lista->Notb[t].RAM);
			atr = 1;
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }
	}

	if(i == 6)
	{  lb();
	   printf("\n\nDeseja Modificar o tamanho da Tela?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVA TELA: ");
			scanf("%lf",&lista->Notb[t].tela);
			atr = 1;
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }
	}

	if(i == 7)
	{  lb();
	   printf("\n\nDeseja Modificar a quantidade de Entradas e Saidas?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVA QUANTIDADE DE ENTRADAS E SAIDAS: ");
			scanf("%s",lista->Notb[t].InOt);
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
            printf("\nComando Invalido!");
        }
	}

	if(i == 8)
	{  lb();
	   printf("\n\nDeseja Modificar o Sistema Operacional?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVO SISTEMA OPERACIONAL: ");
			scanf("%s",lista->Notb[t].So);
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }
	}

	if(i == 9)
	{  lb();
	   printf("\n\nDeseja Modificar o Valor?(s/n): ");
	   y = getchar();
		if(y == 's' || y == 'S')
		{
			printf("\n\nNOVO VALOR: ");
			scanf("%d",&lista->Notb[t].valor);
			i = i + 1;
		}
		if(y == 'n' || y == 'N')
		{
			i = i + 1;
		}
		if(y!= 's'&& y!= 'S' && y!='N' && y!='n' )
        {
		    printf("\nComando Invalido!");
        }
	}
   }
   if(atr == 1)
    {
    printf("\n\n*** Modificar Codec ***\n\n");
    printf("NOVO CODEC:  ");
    scanf("%s",lista->Notb[t].codec);
   }
}




void AdicionarNotbook(struct listaNot *lista,struct Not novo)//Função que adiciona um Notbook a lista de Notbooks
{
   int i = 1;
   printf("\n\n--- Inserir novo Notbook ---\n");
   while(i<11)
   {
	if(i == 1)
	{
		printf("\n\nMARCA: ");
		scanf("%s",novo.marca);
		lb();
		i = i +1;
	}

	if(i == 2)
	{
		printf("\n\nMODELO: ");
		scanf("%s",novo.modelo);
		lb();
		i = i + 1;
	}

	if(i == 3)
	{
		printf("\n\nPROCESSADOR: ");
		scanf("%s",novo.proces);
		lb();
		i = i + 1;
	}

	if(i == 4)
	{
		printf("\n\nCAPACIDADE DE HD: ");
		scanf("%d",&novo.HD);
		lb();
		i = i + 1;
	}

	if(i == 5)
	{
		printf("\n\nCAPACIDADE DE MEMORIA RAM: ");
		scanf("%d",&novo.RAM);
		lb();
		i = i + 1;
	}

	if(i == 6)
	{
		printf("\n\nTELA: ");
		scanf("%lf",&novo.tela);
		lb();
		i = i + 1;
	}

	if(i == 7)
	{
		printf("\n\nENTRADAS E SAIDAS: ");
		scanf("%s",novo.InOt);
		lb();
		i = i + 1;
	}

	if(i == 8)
	{
		printf("\n\nSISTEMA OPERACIONAL: ");
		scanf("%s",novo.So);
		lb();
		i = i + 1;
	}

	if(i == 9)
	{
		printf("\n\nVALOR: ");
		scanf("%d",&novo.valor);
		lb();
		i = i + 1;
	}

	if(i == 10)
	{

		printf("\n\nCODEC: ");
		scanf("%s",novo.codec);
        int rb = buscaNot(lista,novo.codec);
        if(rb >= 0)
		{
           printf("\n  **** Notbook existente ****\n\n");
		}
		else
        {
           lb();
		   i = i + 1;
        }
	}
   }
   insereNot(lista,novo);
}










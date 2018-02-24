#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct list_type
{
char name[40];
char street[40];
char city[30];
char state[3];
char zip[10];
}list[SIZE];

int main(int argc,char *argv[])
{
	
	FILE *fp;
	register int t = atol(argv[2]) - 1;
	if(argc!=3)
	{
		printf("\nUso: SEEK nomearq end\n");
		exit(1);
	}
	if((fp=fopen(argv[1],"r+b")) ==NULL)
	{
		printf("\nO arquivo não pode ser aberto.\n");
		exit(1);
	}
	if(fseek(fp,t*sizeof(struct list_type),SEEK_SET))
	{
		printf("\nErro na busca.\n");
		exit(1);
	}
	
	char nome[40];char rua[40];char cidade[30];
	char estado[3];char cep[10];
	
	if(fread(nome,40*sizeof(char),1,fp)!=1){
		if(feof(fp)){
			printf("\nAcabou a lista!\n");
			exit(1);
		} 
		printf("\nErro de leitura no arquivo.\n");exit(1);
	}
	
	if(fread(rua,40*sizeof(char),1,fp)!=1){
		if(feof(fp)) exit(1);
		printf("\nErro de leitura no arquivo.\n");exit(1);
	}
	
	if(fread(cidade,30*sizeof(char),1,fp)!=1){
		if(feof(fp)) exit(1);
		printf("\nErro de leitura no arquivo.\n");exit(1);
	}
	
	if(fread(estado,3*sizeof(char),1,fp)!=1){
		if(feof(fp)) exit(1);
		printf("\nErro de leitura no arquivo.\n");exit(1);
	}
	
	if(fread(cep,10*sizeof(char),1,fp)!=1){
		if(feof(fp)) exit(1);
		printf("\nErro de leitura no arquivo.\n");exit(1);
	}
	
	
	printf("\n%s\n",nome);
	printf("%s\n",rua);
	printf("%s\n",cidade);
	printf("%s\n",estado);
	printf("%s\n",cep);
	
	fclose(fp);
	
}

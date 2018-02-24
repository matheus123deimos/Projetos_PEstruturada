#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define NUM_ELEMENTS 4

struct address{
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	char zip[11];	
}ainfo;

struct address addrs [NUM_ELEMENTS] = {
	"A. Alexander","101 1st St","Olney","Ga","55555",
	"B. Bertrand","22 2st Ave","Oakland","Pa","34232",
	"C. Carlisle","33 3st Blvd","Ava","Or","92000",
	"D. Dodger","4 Fourth Dr","Fresno","Mi","45678",
};

void quick_disk(FILE *fp,int count);
void qs_disk(FILE *fp,int left,int right);
void swap_all_fields(FILE*fp,long i,long j);
char *get_zip(FILE*fp,long rec);

void main()
{
	FILE *fp;int i;
	if((fp=fopen("mlist","wb")) == NULL){
		printf("O arquivo não pode ser aberto para escrita.\n");
		exit(1);
	}
	printf("Gravando dados não ordenados para disco.\n");
	fwrite(addrs,sizeof(addrs),1,fp);
	rewind(fp);
	for(i=0;i<NUM_ELEMENTS;i++){fscanf(fp,"%s%s%s%s%s",addrs[i].name,
	addrs[i].street,addrs[i].city,addrs[i].state,addrs[i].zip);}
	for(i=0;i<NUM_ELEMENTS;i++){printf("%s/%s/%s/%s/%s\n",addrs[i].name,
	addrs[i].street,addrs[i].city,addrs[i].state,addrs[i].zip);}
	printf("\n");
	fclose(fp);
	
	if((fp=fopen("mlist","r+"))==NULL){
		printf("O arquivo nao pode ser aberto para leitura/escrita.\n");exit(1);
	}
	//printf("Ordenando arquivo de disco. \n");
	//rewind(fp);
	//quick_disk(fp,NUM_ELEMENTS);
	//rewind(fp);
	//fseek(fp,0,SEEK_SET);
	//for(i=0;i<NUM_ELEMENTS;i++)
	fscanf(fp,"%s %s %s %s %s",addrs[0].name,addrs[0].street,addrs[0].city,addrs[0].state,addrs[0].zip);
	//for(i=0;i<NUM_ELEMENTS;i++)
	fprintf(stdout,"%s,%s,%s,%s,%s",addrs[0].name,addrs[0].street,addrs[0].city,addrs[0].state,addrs[0].zip);
	printf("\n");
	fclose(fp);
	printf("Lista ordenada.\n");
}

void quick_disk(FILE *fp,int count)
{
	qs_disk(fp,0,count-1);
}

void qs_disk(FILE *fp,int left,int right)
{
	long int i, j;
	char x[100];
	
	i = left; j = right;
	
	strcpy(x,get_zip(fp,(long)(i+j)/2));
	rewind(fp);
	do{
		while(strcmp(get_zip(fp,i),x)<0 && i<right)i++;
		while(strcmp(get_zip(fp,j),x)>0 && j>left)j--;
		if(i<=j){
			swap_all_fields(fp,i,j);
			i++;j--;
		}
	}while(i<=j);
	if(left<j) qs_disk(fp,left,(int)j);
	if(i<right) qs_disk(fp,(int) i,right); 
}

void swap_all_fields(FILE *fp,long i,long j)
{
	char a[sizeof(ainfo)], b[sizeof(ainfo)];
	fseek(fp,sizeof(ainfo)*i,SEEK_SET);
	fread(a,sizeof(ainfo),1,fp);
	fseek(fp,sizeof(ainfo)*j,SEEK_SET);
	fread(b,sizeof(ainfo),1,fp);
	fseek(fp, sizeof(ainfo)*j,SEEK_SET);
	fwrite(a, sizeof(ainfo),1,fp);
	fseek(fp, sizeof(ainfo)*i,SEEK_SET);
	fwrite(b, sizeof(ainfo),1,fp);
}

char *get_zip(FILE *fp, long rec)
{
	struct address *p;
	p = &ainfo;	
	fseek(fp,rec*sizeof(ainfo),SEEK_SET);
	fread(p, sizeof(ainfo),1,fp);
	
	return ainfo.zip;
}

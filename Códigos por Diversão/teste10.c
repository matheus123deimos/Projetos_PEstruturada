#include <stdio.h>
#include <io.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char s[80];
	int t;
	
	if((fp=fopen("test","w"))==NULL)
	{
		printf("O arquivo nao pode ser aberto.\n");
		exit(1);
	}
	printf("Digite um string e um numero:");
	scanf("%s %d",s,&t);
	fprintf(fp,"%s %d",s,t);
	fclose(fp);
	if((fp=fopen("test","r"))==NULL)
	{
		printf("O arquivo nao pode ser encontrado");
		exit(1);
	}
	fscanf(fp,"%s%d",s,&t);
	printf("\n%s %d\n",s,t);
}

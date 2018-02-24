#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	char str[80];
	FILE *fp;
	if((fp = fopen("TEST","w")) == NULL)
	{
		printf("O arquivo não pode ser aberto.\n");
		exit(1);
	}
	do
	{
		printf("Digite uma string (CR para sair): \n");
		gets(str);
		strcat(str,"\n");
		fputs(str,fp);
	}while(*str!='\n');	
	
}

#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[])
{
	FILE *fp;
	char ch;
	if(argc!=2)
  {
  	printf("Voce esqueceu de digitar o nome do arquivo.\n");
  	exit(1);
  }
  if((fp=fopen(argv[1],"r"))==NULL)
  {
  	printf("O arquivo não pode ser aberto.\n");
  	exit(1);
  }
  while(!feof(fp))
  {
  	putchar(ch);
  	ch = getc(fp);
  }
  fclose(fp);
}

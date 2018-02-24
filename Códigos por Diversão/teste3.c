#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[])
{
	FILE *in,*out;
	char ch;
	if(argc!=3)
  	{
  		printf("Voce esqueceu de digitar o nome do arquivo.\n");
  		exit(1);
  	}
  	if((in=fopen(argv[1],"rb"))==NULL)
  	{
  		printf("O arquivo-fonte n�o pode ser aberto.\n");
		exit(1);	
	}
	if((out=fopen(argv[2],"wb"))==NULL)
	{
		printf("O arquivo-destino n�o pode ser aberto.\n");
		exit(1);
	}
    while(!feof(in))
	{
		ch = getc(in);
		if(!feof(in)) putc(ch,out);	
	}	
    fclose(in);
    fclose(out);
}

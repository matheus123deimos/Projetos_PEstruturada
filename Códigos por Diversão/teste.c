#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void main(int argc,char *argv[])
{
  
  FILE *fp;
  char ch;
  
  if(argc!=2)
  {
  	printf("Voce esqueceu de digitar o nome do arquivo.\n");
  	exit(1);
  }
  if((fp=fopen(argv[1],"w"))==NULL)
  {
  	printf("O arquivo não pode ser aberto.\n");
  	
  	exit(1);
  }
  ch = getchar();
  do{
    putc(ch,fp);
    ch = getchar();
  }while(ch!='$');
  fclose(fp);
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "fcntl.h"

#define BUF_SIZE 128

void input(char *buf, int fd1);
void display(char *buf, int fd2);

void main()
{   
	char buf[BUF_SIZE];
	int fd1, fd2;
	if(creat("matheus1",O_RDWR) == -1)
	{
		printf("O arquivo matheus1 nao pode ser criado");
		exit(1);	
	}
	if(creat("matheus2",O_RDWR) == -1)
	{
		printf("O arquivo matheus2 nao pode ser criado");
		exit(1);	
	}
	if((fd1 = open("matheus1",O_RDWR)) == -1)
	{
		printf("O arquivo matheus1 nao pode ser aberto");
		exit(1);	
	}
	if((fd1 = open("matheus2",O_RDWR)) == -1)
	{
		printf("O arquivo matheus2 nao pode ser aberto");
		exit(1);	
	}
	input(buf,fd1);
	close(fd1);
	display(buf,fd2);
	close(fd2);
}

	void input(char *buf,int fd1)
	{
		register int t;
		do{
			for(t=0;t<BUF_SIZE;t++) buf[t] = '\0';
			gets(buf);
			if(write(fd1,buf,BUF_SIZE)!=BUF_SIZE)
			{
				printf("Erro de escrita");
				exit(1);
			}
		}while(strcmp(buf,"quit"));
	}
	
	void display(char *buf, int fd2)
	{
		for(;;)
		{
			if(read(fd2,buf,BUF_SIZE)==0) return;
			printf("%s\n",buf);
		}
	}

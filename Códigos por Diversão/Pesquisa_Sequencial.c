#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sequential_search(char *item, int count,char key);
int main()
{
	
	char *nome = "abcdefghijlmnopqrstuvxz";
	int index = sequential_search(nome,strlen(nome),'i');
	printf("%d",index);
	
}

int sequential_search(char *item, int count,char key)
{
	register int t,u; 
	for(t=0,u=count-1;t<(count-1)/2 || u<=(count-1)/2;++t,--u)
	{
			if(key==item[t]&&key==item[u]) return t;	
			else if(key==item[t]) return t;
			else if(key==item[u]) return u;		
	}
	return -1;
}

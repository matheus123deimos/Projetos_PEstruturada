#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char *item,int count);

int main()
{
	char s[32] = "zxvutsrqpnmljihgfedcba9876543210";
	bubble(s,strlen(s));
	printf("A string ordenada e: %s.\n",s);
}

void bubble(char *item,int count)
{
	register int a,b; 
	int exchange;
	char t;
	
	do{
		exchange = 0;
		for(a=count-1;a>0;--a)
		{
			if(item[a-1]>item[a]){
				t = item[a-1];
				item[a-1] = item[a];
				item[a] = t;
				exchange = 1;
			}
		}
		
		for(a=1;a<count;a++)
		{
			if(item[a-1]>item[a]){
				t = item[a-1];
				item[a-1] = item[a];
				item[a] = t;
				exchange = 1;
			}
		}
	}while(exchange);
	
	
}

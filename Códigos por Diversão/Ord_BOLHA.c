#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char *item,int count);
char s[32];
void main()
{
	char s[32] = "zxvutsrqpnmljihgfedcba9876543210";
	bubble(s,strlen(s));
	printf("A string ordenada e: %s.\n",s);
}

void bubble(char *item,int count)
{
	register int a,b;
	register char t;
	
		for(a=1;a<count;++a){
			
			for(b=count-1;b>=a;--b){
				if(item[b-1]>item[b]){
				t = item[b-1];
				item[b-1] = item[b];
				item[b] = t;
			  }
			}
		}
}

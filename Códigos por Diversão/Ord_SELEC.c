#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void select(char *,int);
int main()
{
	char s[22] = "zxvutsrqpnmljihgfedcba";
	select(s,strlen(s));
	printf("A string ordenada e: %s.\n",s);
}

void select(char *item,int count)
{
	register int a, b, c;
	int exchange;
	char t;
	
	for(a=0;a<count-1; ++a){
		exchange = 0;
		c = a;
		t = item[a];
		for(b=a+1;b<count;++b){
			if(item[b]<t){
				c = b;
				t = item[b];
				exchange = 1;
			}
		}
		if(exchange){
			item[c] = item[a];
			item[a] = t;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char *,int);

int main()
{
	char s[32] = "zxvutsrqpnmljihgfedcba9876543210";
	insert(s,strlen(s));
	printf("A string ordenada e: %s.\n",s);
}

void insert(char *item,int count)
{
	
	register int a, b;
	char t;
	for(a=1;a<count;++a)
	{
		t = item[a];
		for(b=a-1;b>=0 && t<item[b];b--)
		{
			item[b+1] = item[b];
		}
		item[b+1] = t;
	}
	
}

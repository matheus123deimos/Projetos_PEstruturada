#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell(char *,int);

int main()
{
	char s[32] = "zxvutsrqpnmljihgfedcba9876543210";
	shell(s,strlen(s));
	printf("A string ordenada e: %s.\n",s);
}

void shell(char *item,int count)
{
	register int i, j, gap, k;
	char x, a[3];
	a[0] = 3;a[1] = 2;a[2] = 1;
	for(k=0;k<3;k++){
		gap = a[k];
		for(i=gap;i<count;++i){
			x = item[i];
			for(j=i-gap;x<item[j] && j>=0;j=j-gap){
				item[j+gap] = item[j];
			}item[j+gap] = x; 
		}
	}
}

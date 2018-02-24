#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binary(char *item,int count, char key);
int main()
{
	char *nome = "abcdefghijlmnopqr";
	int index = binary(nome,strlen(nome),'g');
	printf("%c",nome[index]);
}

int binary(char *item,int count, char key)
{
	int low,high,mid;
	low = 0; high = count - 1;
	while(low<=high){
		mid = (low + high)/2;
		if(key<*(item+mid)) high = mid -1;
		else if(key>*(item+mid)) low = mid + 1;
		else return mid;
	}
	return -1;
}

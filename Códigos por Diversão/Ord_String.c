#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void quick_string(char item[][10],int);
void qs_string(char item[][10],int left,int right);
int main()
{	
	int i = 0;
	char s[][10]= {"Matheus","Ana","Jovita","Antonio","Zeca","Pedro",
   "Emanuelly","Tereza","Joana","Mercedes"};
	quick_string(s,10);
	do{
		
		printf("%s\n",s + i);
	}while(i++ < 9);
}

void quick_string(char item[][10],int count)
{
	qs_string(item,0,count-1);
}

void qs_string(char item[][10],int left,int right)
{
	register int i,j;
	char *x;
	char temp[10];
	
	i = left;j = right;
	x = item[(left+right)/2];
	do{
		while(strcmp(item[i],x)<0 && i<right) i++;
		while(strcmp(item[j],x)>0 && j>left) j--;
		if(i<=j){
			strcpy(temp, item[i]);
			strcpy(item[i], item[j]);
			strcpy(item[j],temp);
			i++;j--;
		}
	}while(i<=j);
	if(left<j) qs_string(item,left,j);
	if(i<right) qs_string(item,i,right);
}

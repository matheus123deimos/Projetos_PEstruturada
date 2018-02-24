#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address{
	char *name;
	char *street;
	char *city;
	char *state;
	char *zip;
}ad1,ad2,ad3,ad4,ad5,mala_direta[5];

int i = 0;

void quick_struct(struct address item[],int count);
void qs_struct(struct address item[],int left,int right);

void main()
{   
	
	ad1.name = "Matheus Cordeiro";
	ad1.street = "Tomas de Aquino";
	ad1.city = "Fortaleza";
	ad1.state = "CE";
	ad1.zip = "45604567";
	mala_direta[0] = ad1;
	
	ad2.name = "Franscisco Cesar";
	ad2.street = "Tertuliano Guanabara";
	ad2.city = "Florianopolis";
	ad2.state = "SC";
	ad2.zip = "34064567";
	mala_direta[1] = ad2;
	
	ad3.name = "Margarida Maria";
	ad3.street = "Jovita Arantes";
	ad3.city = "Ouro Preto";
	ad3.state = "MG";
	ad3.zip = "46540577";
	mala_direta[2] = ad3;
	
	ad4.name = "Josefa Freitas";
	ad4.street = "Sebastiao Silva";
	ad4.city = "Campinas";
	ad4.state = "Sp";
	ad4.zip = "46605476";
	mala_direta[3] = ad4;
	
	ad5.name = "Menelaus Pires";
	ad5.street = "Clarindo Persival";
	ad5.city = "Olinda";
	ad5.state = "PE";
	ad5.zip = "65653433";
	mala_direta[4] = ad5;
	
	quick_struct(mala_direta,5);
	
	do{
		
		printf("%s\n",(*(mala_direta + i)).zip);
	}while(i++ < 4);
}

void quick_struct(struct address item[],int count)
{
	qs_struct(item,0,count-1);
}

void qs_struct(struct address item[],int left,int right)
{
	register int i,j;
	char *x;
	struct address temp;
	
	i = left; j = right;
	x = item[(left+right)/2].zip;
	
	do{
		while(strcmp(item[i].zip,x)<0 && i<right) i++;
		while(strcmp(item[j].zip,x)>0 && j>left) j--;
		if(i<=j){
			temp =item[i];
			item[i] = item[j];
			item[j] = temp;
			i++;j++;
		}
	}while(i<=j);
	if(left<j) qs_struct(item,left,j);
	if(i<right) qs_struct(item,i,right);
}

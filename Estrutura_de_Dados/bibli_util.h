#include <stdio.h>
#include <stdlib.h>

long int *Deci(long double x,int y){
	long int deci[2];
	deci[0] = (long int)x;
	long double pd = x - deci[0];
	do{
		pd = pd*10.0;
		y--;
	}while(y>0);
	if(pd<0) pd = pd*(-1);
	deci[1] = (long int)pd;
	long int *p = deci;
	return p;
}//Semelhante a função modf de <math.h>
////no futuro tentar fazer com o long daouble em vez do long int
int posDot(long double x){ int b = (int)x;if((long  double)(x-b) == 0.0)return 0;else return 1;}



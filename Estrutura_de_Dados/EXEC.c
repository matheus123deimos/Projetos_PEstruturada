#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha_Imp_1.h"
#include "bibli_util.h"

int main(){
	
	//Estimativa para dar certo
	//limite de caracteres = 100
	struct pilha Calc = GerP();
    struct pilha *C = &Calc;
    char s[100];
    int i;
    int j;
    long double a;
    long double b;
    long double c;
    long double som;
    long double sub;
    long double mut;
    long double div;

    printf("Digite a Sentenca: ");
    gets(s);
    
    //Calculadora
    printf("\n\n%d\n\n",strlen(s));
    for(i=0;i<=strlen(s)-1;i++){
    	
    if(i!= 0){

    long double vo = (long double)(s[i]-'0');
    long double vo2 = (long double)(s[i-1]-'0');
    long double vo3 = (long double)(s[i+1]-'0');
    
    som = (long double)'+';
    sub = (long double)'-';
    mut = (long double)'*';
    div = (long double)'/';
    
    if((vo>9.0 | vo<0.0)|(!(vo>9.0 | vo<0.0)&&(vo2>9.0 | vo2<0.0)&&(vo3>9.0 | vo3<0.0))){  

    	switch(s[i]){
    	    int i;
    		case '(':
    		    continue;
    		case ' ':
    	        continue;
    		case ')':
    			a = pop(C);
    			printf("\n%d\n",(int)a);
    			b = pop(C);
    			printf("\n%d\n",(int)b);
    			c = pop(C);
    		    printf("\n%d\n",(int)c);
    			if(b == som) push(a+c,C);
    			else if(b == sub) push(c-a,C);
    			else if(b == mut) push(a*c,C);
    			else push(c/a,C);
    		    printf("\n\n%d\n\n",(int)tp(C));
    			break;
    	    case '+':
    	        push(som,C);
    	    	break;
    	    case '-':
			    push(sub,C);
			    break;
    	    case '*':
			    push(mut,C);
			    break;
    	    case '/':
			    push(div,C);
    	    	break;
    	    default:
    	    	push(vo,C);
        }
     }
     
     else{
     	    if(vo2>9.0 | vo2<0.0){push(10.0*vo + vo3,C);}
     	    else{
     	    	if(!(vo3>9.0 | vo3<0.0)){
     		        long double aux = pop(C);
     		        push(10.0*aux + vo3,C);}}}}
         
   }
    
    
    if(!posDot(C->vect[0])) printf("\n\nO Resultado e: %d\n",(long int)pop(C));
    else {
	   long double aux = pop(C);
	   printf("\n\nO Resultado e: %ld,%ld\n",*Deci(aux,9),*(Deci(aux,9)+1));
    }
    
	char sair;
    do{
       printf("\nDigite 's' para sair: ");
       scanf("%c",&sair);
    }while(sair != 's');
}



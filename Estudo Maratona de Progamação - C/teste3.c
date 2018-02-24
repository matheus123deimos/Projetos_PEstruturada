#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n,i,j,cont,aux2[100],cont1;
	char aux[100];
	cont = 1;cont1 = 0;

	while (scanf("%d", &n) != EOF) {
		
    	fflush(stdin);
		printf("Instancia %d\n",cont);
		gets(aux);
		for(i=0,j=0;;i=i+2,j++)
		{
			aux2[j] = aux[i] - '0';
			if(aux[i+1] == '\0')
			{
				aux2[j+1] = -31;
				break;
			}
		}
		
		for(i=0;;i++)
		{
			if(aux2[i] == -31)
			{
				printf("nao achei\n\n");
				break;
			}
			
			if(n == 1 && aux2[i] == cont1)
			{
				printf("%d\n\n",cont1);
				break;
			}
			
			if(i>0 && aux2[i] == cont1)
			{
				printf("%d\n\n",cont1);
				break;
			}
			cont1 += aux2[i];
		}
		fflush(stdin);
		cont++;
	}

}

#include <stdlib.h>
#include <iostream>

int main()
{   
	int n,i,j,cont,auxs[100],auxs2;
	cont = 1;auxs2 = 0;
    while(true)
	{	
		std::cin >> n;
		if(!std::cin) break;
		std::cout << "Instancia " << cont << "\n";
		for(i=0;i<n;i++)
		{
			std::cin >> auxs[i];
			auxs2 += auxs[i];
			for(j=i;j<0;j--){
				if(auxs2 == auxs[i]){std::cout << auxs2;cont++;continue;}
			} 
		}
		std::cout<<"nao achei\n";
		cont++;
	}	
    			
	
}

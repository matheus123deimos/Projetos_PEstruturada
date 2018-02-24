#include <stdlib.h>
#include <iostream>

int main()
{   
    int entrada,i,l,f,t;
    char nome1[10],nome2[10],venced[100];
    entrada = l = f = 1;
    t = 0;
    std::cin >> entrada ;
    while(entrada){
       std::cout <<"Teste " << ++t <<"\n";
       i = 0;
       std::cin >> nome1 >> nome2;
       while(i<entrada){
          std::cin >> l >> f;
          if((l+f)%2 == 0) venced[i] = 'P';
          if((l+f)%2 != 0) venced[i] = 'I';
          i++;
       }
       for(i = 0;i<entrada;i++)
       {
       		if(venced[i] == 'P'){std::cout<< nome1<<"\n";}
            else if(venced[i] == 'I'){std::cout <<nome2<<"\n";}
	   }
	   std::cin >> entrada ;
    }
 
    return 0;
}

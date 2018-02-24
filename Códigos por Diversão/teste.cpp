#include <stdlib.h>
#include <iostream>

int main()
{   
    int entrada,i,A,B,a,b,teste;
    while (entrada) {
       std::cin >> entrada;
       a = b = teste = 0;
       i = 1;
       while(i<entrada){
          std::cin >> A >> B;
          std::cout << "\n" << A == B << "\n";
          if(A > B){a++;}
          else if(B < A){b++;} 
          std::cout << "\n" <<i << "//" << entrada << "//"<< a << " " << b <<"\n"; 
          i++;
       }
       if(a>b){std::cout << "Teste " << teste << "\nAldo\n";}
       else if(b>a) std::cout << "Teste " << teste << "\nBeto\n";
    }
    
   

}

#include <iostream>
#include <stdlib.h>
#include <cctype>
#include "Pilha_CPP.hpp"

int main(){
    using std::cin;
    using std::cout;
    using std::isdigit;
    
    cout << "Digite a expressão";
    const int tam_e = 100;
    char e[tam_e];
    int i;

    for(i=0;i<tam_e;++i){
	cin.get(e[i]);
	if(e[i] == '\n'){break;}
    
        if(i==tam_e){
	       std::cout<<"Expressão grande demais!!\n";
	       return 1;
	       
	}
    }

    Pilhalimitada<double> Pn;
    Pilhalimitada<char>Po;

    if(Inicializar_Pilha(Pn,tam_e)||Inicializar_Pilha(Po,tam_e)){
        cout<<"Sem memória!\n";
        return 2;
    }
    
     for(i=0;e[i]!='\n';++i){
           if(isdigit(e[i])){
               double num = 0;
               do{
                   num = num*10 + (e[i]-'0');
                   ++i;
               }while(isdigit(e[i]));
               --i;
               Empilhar(Pn,num);
            }//if is digit
        
            else if(e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/'){
               Empilhar(Po,e[i]);
            }//if is oper
        
            else if(e[i] == ')'){
        
              double dir = Desempilhar(Pn);
              double esq = Desempilhar(Pn);
              char op = Desempilhar(Po);
              double res;
         
              switch(op){
          
                  case'+':
                      res = esq+dir;
                      break;
                  
                  case'-':
                      res = esq-dir;
                      break;
              
                  case'*':
                      res = esq*dir;
                      break;
                  
                  case'/':
                      res = esq/dir;
                      break;
          
            }
            Empilhar(Pn,res);
        }//if ')'


    }//for e[i]
    
    cout<< "Resultado: " << Desempilhar(Pn)<<'\n';
    Terminar_Pilha(Po);
    Terminar_Pilha(Pn);
    return 0;
}//main

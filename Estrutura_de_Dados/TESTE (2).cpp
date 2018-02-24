#include <stdlib.h>
#include <iostream>
#include "Pilha_CPP.hpp"

int main(){
	
	Pilhalimitada<int> P;
	
    if ( Inicializar_Pilha(P,10) ) {std::cout << "Sem memória!\n"; return 1; }

    Empilhar(P,10); Empilhar(P,-2); Empilhar(P,300);

    std::cout << Desempilhar(P) << '\n';
    std::cout << Desempilhar(P) << '\n';
    std::cout << Desempilhar(P) << '\n';

    Pilhalimitada<double> Q;

    bool erro = Inicializar_Pilha(Q,20);

    if (erro) {std::cout << "Sem memória!\n"; return 2; }

    Empilhar(Q, 3.14);

    double x = Desempilhar(Q); std::cout << x << '\n';

    Terminar_Pilha(Q);
    Terminar_Pilha(P);
	
}

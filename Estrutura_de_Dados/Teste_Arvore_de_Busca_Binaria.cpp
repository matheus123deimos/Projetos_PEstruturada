#include <iostream>
#include <stdlib.h>
#include<time.h>
#include "Dicionario_ABB.hpp"
using std::nothrow; using std::cin; using std::cout;

void Imp_EMO(Node_ABB<char,float> *);
void Imp_PREO(Node_ABB<char,float> *);
void Imp_POSO(Node_ABB<char,float> *);

int main(){
	
Dicionario_ABB<char,float> DABB;int i;
float notas[7] = {6.23,4.56,7.80,10.00,6.70,3.56,7.89};
char frequencia[7] = {'d','b','f','a','c','e','g'};

Inicializar_DABB(DABB);
for(i=0;i<7;++i){if(Inserir_DABB(DABB,frequencia[i],notas[i])){cout << "Erro de Alocacao";return 0;}}
//Terminar_DABD(DABB);
i =6;int j;
while(!Vazio(DABB)){
	cout << "Arvore de Busca Binaria: ";
	Imp_EMO(DABB.raiz);cout<<"\n\n";
    cout << "\n\nFrequencia: ";
    for(j=0;j<=i;++j) cout << frequencia[j]<<", ";
	cout<<"\n\n";
	const char *EONE = Vazio(DABB)? "\nE vazio\n": "\nNao e vazio\n\n";
    cout << EONE;
	int p;
	cout << "\n\nA Raiz e: " << DABB.raiz->chave;
	cout << "\n\nQue indice você quer remover ?: ";
	cin >> p;
	char k = frequencia[p];
	cout<< "\n\nRemover: " << k << ", " << "no indice " << p<<"\n\n"<<" i = "<<i<<"\n\n";
	for(j=p;j<i;++j) frequencia[j] = frequencia[j+1];
	Remover_DABB(DABB,Procurar_DABB(DABB,k));
	--i;}
	return 0;
}



void Imp_EMO(Node_ABB<char,float> *raiz){
	if(raiz != NULL){
		Imp_EMO(raiz->fiesq);
		cout <<raiz->chave<<"||";
		Imp_EMO(raiz->fidir);
	}
}

void Imp_PREO(Node_ABB<char,float> *raiz){
	if(raiz != NULL){
		cout << " || " <<raiz->chave;
		Imp_PREO(raiz->fiesq);
		Imp_PREO(raiz->fidir);
	}
}

void Imp_POSO(Node_ABB<char,float> *raiz){
	if(raiz != NULL){
		Imp_POSO(raiz->fiesq);
		Imp_POSO(raiz->fidir);
		cout << " || " <<raiz->chave;
	}
}
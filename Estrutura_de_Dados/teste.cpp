#include <iostream>
#include "Conj_Din_Bin.hpp"


using std::cout;
using std::cin;

struct Aluno
{
	char *nome;
    int matricula;

};

inline int& MAT(Aluno &a){return a.matricula;}

int main(){

Conj_db<Aluno,int,MAT> CDB;
char nomes[][10] = {"Matheus","Emanuelly","Gael","Jadson"};
int matriculas[4] = {396436,345678,282956,123456};
struct Aluno a1,a2,a3,a4;
struct Aluno alunos[4] = {a1,a2,a3,a4};
int i;
for(i=0;i<=3;++i){alunos[i].nome = nomes[i];alunos[i].matricula = matriculas[i];}

//USO DO CONJUNTO
Inicializar_CDB(CDB);
if(Inserir_CDB(CDB,alunos[0])){cout <<"\n"<<"Erro ao adicionar a1"<<"\n";return 0;}
if(Inserir_CDB(CDB,alunos[1])){cout <<"\n"<<"Erro ao adicionar a2"<<"\n";return 0;}
if(Inserir_CDB(CDB,alunos[2])){cout <<"\n"<<"Erro ao adicionar a3"<<"\n";return 0;}
if(Inserir_CDB(CDB,alunos[3])){cout <<"\n"<<"Erro ao adicionar a4"<<"\n";return 0;}

//TESTA A BUSCA BINARIA
/*for(i=0;i<=3;++i){
    int m;
	cout << "\n\nQuem voce quer buscar: ";
	cin >> m;
	int matr = (int)m;
	int indice = Procura_Binaria(CDB,matr);
	//cout <<indice<< "\n\n";
	if(indice>=0){
		cout << "\n\nNome: " << CDB.v[indice].nome;
	} 
}*/

//TESTA A REMOÇÂO 
int j;

for(i=0;i<=3;++i){
	int m;
	for(j=0;j<CDB.nume;++j){
		cout << "\n\nNome: " << CDB.v[j].nome;
		cout << "\n\nMatricula: " << CDB.v[j].matricula;
	}
	cout << "\n\nQuem voce quer remover: ";
	cin >> m;
	struct Aluno removido = Remover_CDB(CDB,m);
	cout << "\n\nO aluno removido foi: " << removido.nome;
}
Terminar_CDB(CDB);

/*for(i=0;i<4;i++){
    if(i==0) cout <<DQ.esq->elem<<", ";
    else{
    	int j;
    	NodeDE<int> *AUX = DQ.esq;
    	for(j=0;j<i;j++) AUX = AUX->prox;
    	cout <<AUX->elem<<", ";
	}
}*/

return 0;
}

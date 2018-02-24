#include <iostream>
using std::nothrow;using std::cout;
//Pior caso da Busca é o melhor caso da Realocação e o melhor caso da Realocação é o melhor caso da Busca
template<typename Te, typename Tc,Tc& chave(Te& e)>
struct Conj_db{Te *v;int tamv;int nume;};

template<typename Te, typename Tc,Tc& chave(Te& e)>
bool Inicializar_CDB(Conj_db<Te,Tc,chave> &CDB){
	Te *v = new(nothrow) Te[1];
	if(v){
		CDB.v = v;CDB.tamv = 1;CDB.nume = 0;
		return false;
	}return true;
}

template<typename Te, typename Tc,Tc& chave(Te& e)>
bool Inserir_CDB(Conj_db<Te,Tc,chave> &CDB, Te e){
	int j = 0;int k;Te a,b;
	//Adiciono ao Conjunto Vazio
	if(!CDB.nume){CDB.v[0] = e;++CDB.nume;return false;}
    
 	//Realoco Minha Memória
    else if(CDB.tamv == CDB.nume){
		int i;Te *copia = new(nothrow) Te[2*CDB.tamv];
		if(copia){
			for(i=0;i<CDB.tamv;++i){
				copia[i] = CDB.v[i];
			}CDB.v = copia;CDB.tamv = 2*CDB.tamv;
        }else return true;
	}
	
	
	//Matenho a Ordem do Conjunto
	while(chave(CDB.v[j])<=chave(e)){++j;}
    a = CDB.v[j];
	for(k=j+1;k<=CDB.nume;++k){
		b = CDB.v[k];
		CDB.v[k] = a;                                
		a = b;
	}
	
	CDB.v[j] = e;
	++CDB.nume;
    return false;
}

//O compilador já trunca normalmente
//O compilador procura dentro da estrutura por chaves com aquele tipo que estamos comparando

template<typename Te, typename Tc,Tc& chave(Te& e)>
int Procura_Binaria(Conj_db<Te,Tc,chave> &CDB, Tc ch){
	
	int menor, maior,mediana;
	menor = 0;maior = CDB.nume -1;
	
	while(menor<=maior){
		mediana = (menor+maior)/2;
		//cout << "\n\nMediana: "<< mediana;
		if(ch==chave(CDB.v[mediana])) return mediana;
		else if(ch < chave(CDB.v[mediana])) maior = mediana - 1;
        else menor = mediana + 1;
	}return -1;
	
}

template<typename Te, typename Tc,Tc& chave(Te& e)>
Te Remover_CDB(Conj_db<Te,Tc,chave> &CDB, Tc ch){
	
	int j = Procura_Binaria(CDB,ch);Te nao_achado;
	if(j>=0){
		int i;Te e = CDB.v[j];
		for(i=j;i<CDB.nume-1;++i) CDB.v[i] = CDB.v[i+1];
		--CDB.nume;
		return e;
	}
	return nao_achado;;
}



template<typename Te, typename Tc,Tc& chave(Te& e)>
void Terminar_CDB(Conj_db<Te,Tc,chave> &CDB){delete[] CDB.v;} 
//Eu só tenho que deletar aqulilo que eu peço para alocar o resto
//o sistema operacional se encarrega
//Vazia e Cheia

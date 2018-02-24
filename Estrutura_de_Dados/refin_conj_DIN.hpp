#include <iostream>
using std::nothrow;

template<typename T>
struct NodeDE{T elem;NodeDE<T> *prox,*ant;};

template<typename Te, typename Tc,Tc& chave(Te& e)>
struct ConjuntoDimDe{NodeDE<Te>*sent;};

template<typename Te, typename Tc,Tc& chave(Te& e)>
bool Inicializar(ConjuntoDimDe<Te,Tc,chave> &C){
	C.sent = new(nothrow) NodeDE<Te>;
	if(C.sent){
		C.sent->ant = C.sent->prox = C.sent;
		return false;
	}else return true;
}

//Nessa Inserção eu posso retornar um ponteiro que pode ser armazenado
template<typename Te, typename Tc,Tc& chave(Te& e)>
//NodeDE<Te>* Inserir(ConjuntoDimDe<Te,Tc,chave>&C,Te e){
bool Inserir(ConjuntoDimDe<Te,Tc,chave>&C,Te e){
	NodeDE<Te> *n = new(nothrow) NodeDE<Te>;
	if(n){
		n->elem = e;
		n->prox = C.sent->prox;
		n->ant = C.sent;
		C.sent->prox = n->prox->ant = n;
		return false;
	}return true;
}

template<typename Te, typename Tc,Tc& chave(Te& e)>
NodeDE<Te>* Procurar(ConjuntoDimDe<Te,Tc,chave> &C,Tc c){
	chave(C.sent->elem) = c;
	NodeDE<Te> *n = C.sent->prox;
	while(chave(n->elem)!=c){n = n->prox;}
	return (n == C.sent)?NULL:n;
}

template<typename Te, typename Tc,Tc& chave(Te& e)>
Te Remover(ConjuntoDimDe<Te,Tc,chave> &C,NodeDE<Tc> *n){
	Te e = n->elem;
	n->ant->prox = n->prox;
	n->prox->ant = n->ant;
	delete n;
	return e;
}

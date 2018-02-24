#include <iostream>

using std::nothrow;using std::cout;

//Nó do tipo Arvore_Binaria_de_Busca

template<typename TC, typename TV>
struct Node_ABB{TC chave;TV valor;Node_ABB<TC,TV> *pai,*fiesq,*fidir;};

//Dicionário

template<typename TC, typename TV>
struct Dicionario_ABB{Node_ABB<TC,TV> *raiz;};

//Inicializar Diciário

template<typename TC, typename TV>
void Inicializar_DABB(Dicionario_ABB<TC,TV> &DABB){DABB.raiz = NULL;}

//Inserir no Dicionário

template<typename TC,typename TV>
bool Inserir_DABB(Dicionario_ABB<TC,TV> &DABB,TC c, TV v){
	
	Node_ABB<TC,TV> *n = new(nothrow) Node_ABB<TC,TV>;
	if(n == NULL){return true;}
	
	n->chave = c; n->valor = v; n->fiesq = n->fidir = NULL;

	if(DABB.raiz == NULL) {n->pai = NULL;DABB.raiz = n;}
		
    else{
		
		Node_ABB<TC,TV> *p = DABB.raiz;
		for(;;){
			if(c < p->chave){
				if(p->fiesq == NULL){p->fiesq = n; n->pai = p;break;}
                else p = p->fiesq;
			}else{
				if(p->fidir == NULL){p->fidir = n; n->pai = p;break;}
                else p = p->fidir;
			}
		}
	}
	
	return false;
}

//Busca Binaria na Arvore de Busca Binaria

template<typename TC,typename TV>
Node_ABB<TC,TV> *Procurar_DABB(Dicionario_ABB<TC,TV> &DABB, TC c){
	
	Node_ABB<TC,TV> *p = DABB.raiz;
	if(p!=NULL){
		for(;;){
			if(c == p->chave) return p;
			else if(c<p->chave){
				if(p->fiesq == NULL) return NULL;
				else p = p->fiesq;
			}
			else{
				if(p->fidir == NULL) return NULL;
				else p = p->fidir;
			}
		}
	}
	return NULL;
	
}

//Função de Remoção: Algoritmo Retirado do livro: Algoritmos: Teoria e Prática,pg 218,3º Edição

template<typename TC, typename TV>
void Remover_DABB(Dicionario_ABB<TC,TV> &DABB, Node_ABB<TC,TV> *n){
	//Trata o caso de n não possuir filhos
	if(n->fiesq == NULL && n->fidir == NULL){
		if(n == DABB.raiz) DABB.raiz = DABB.raiz->pai;
		else if(n == n->pai->fiesq) n->pai->fiesq = n->fidir;
		else n->pai->fidir  = n->fidir;
	}
    else{		
		//Trata o caso de n possuir 1 filho
		if(n->fiesq == NULL){
			if(n->pai == NULL){cout<<"\n\nraiz\n\n";DABB.raiz = n->fidir;n->fidir->pai = n->pai;}
			else if(n == n->pai->fiesq){cout<<"\n\nAqui1\n\n";n->pai->fiesq = n->fidir;n->fidir->pai = n->pai;}
			else{cout<<"\n\nAqui2\n\n";n->pai->fidir = n->fidir;n->fidir->pai = n->pai;}
		}
	
		else if(n->fidir == NULL){
			if(n->pai == NULL){cout<<"\n\nraiz2\n\n";DABB.raiz = n->fiesq;n->fiesq->pai = n->pai;}
			else if(n == n->pai->fiesq){cout<<"\n\nAqui3\n\n";n->pai->fiesq = n->fiesq;n->fiesq->pai = n->pai;}
			else{cout<<"\n\nAqui4\n\n";n->pai->fidir = n->fiesq;n->fiesq->pai = n->pai;}
		}
		
	    //Trata o caso de n possuir dois filhos
	    
		else{
			Node_ABB<TC,TV> *s = n->fidir;//nó sucessor
			cout <<"\n\nsucessor: " << s->chave;
			if(s->fiesq != NULL) cout << "\n\nOla\n\n";
			while(s->fiesq != NULL) s = s->fiesq;//achar o menor nó na subarvore a direita de n
	        if(s->pai!=n){//caso onde o filho direito possui um filho esquerdo, pelo menos
				s->pai->fiesq = s->fidir;
	            if(s->fidir != NULL) s->fidir->pai = s->pai;
				s->fidir = n->fidir;//faz o filho direito de n ser o se s
	            s->fidir->pai = s;//faz o pai do filho direito de n ser s
    	        cout<<"\n\nOi\n\n";
	        }
	        if(n->pai == NULL){cout << "\n\nraiz3\n\n";DABB.raiz = s;}
	        else if(n==n->pai->fiesq){cout<<"\n\nAqui5\n\n";n->pai->fiesq = s;}// coloca o filho esquerdo de n->pai como sendo ses se n o for
	        else{cout<<"\n\nAqui6\n\n";n->pai->fidir = s;}//coloca o filho direito de n->pai como sendo s se n o for
	        s->pai = n->pai;//coloca o pai de s como sendo o pai de n
	        s->fiesq = n->fiesq;//coloca o filho esquerdo de s como sendi o filho esquerdo de n
	        s->fiesq->pai = s;//coloca o pai do filho esquerdo de n como sendo s
		}
	}
	delete n;
}

template <typename TC, typename TV>
bool Vazio(Dicionario_ABB<TC,TV> &DABB){return DABB.raiz == NULL;}

template <typename TC, typename TV>
void Terminar_DABD(Dicionario_ABB<TC,TV> &DABB){
	while(!Vazio(DABB)) Remover_DABB(DABB,DABB.raiz);
}



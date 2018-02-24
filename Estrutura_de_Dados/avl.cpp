#include <iostream>

typedef double TC; typedef float TV;

struct Noh { TC chave; TV valor; Noh *esq, *dir, *pai; int h;};
struct DicAVL { Noh *raiz; };

//Inicializdor
void inicializar (DicAVL &D){D.raiz = NULL;}

//Retorna a Altura do Nó
int Altura(Noh *p){if(p!=NULL)return p->h;return 0;}
//Retorna o Balanceamento do Nó
int Balanceamento(Noh* p){return Altura(p->esq)-Altura(p->dir);}
//Retorna o Nó de Maior Altura
int Max(Noh* p,Noh* q){int max = (Altura(p)>=Altura(q))?Altura(p):Altura(q);return max;}

//Rotação Esquerda_Esquerda
void Rot_LL(Noh *a){
	Noh *auxiliar = a->esq;
	auxiliar->pai = a->pai;
	a->esq = auxiliar->dir;
	if(a->esq!=NULL)a->esq->pai = a;
	if(a->pai!=NULL){
		if(a==a->pai->esq)a->pai->esq = auxiliar;
		else a->pai->dir = auxiliar;
	}
	a->pai = auxiliar;
	auxiliar->dir = a;
}

//Rotação Direita_Direita
void Rot_RR(Noh *a){
	Noh *auxiliar = a->dir;
	auxiliar->pai = a->pai;
	a->dir = auxiliar->esq;
	if(a->dir!=NULL)a->dir->pai = a;
	if(a->pai!=NULL){
		if(a==a->pai->esq)a->pai->esq = auxiliar;
		else a->pai->dir = auxiliar;
	}
	a->pai = auxiliar;
	auxiliar->esq = a;
	
}

//Rotação Esquerda_Direita
void Rot_LR(Noh *a){Rot_RR(a->esq);Rot_LL(a);}

//Rotação Direita_Esquerda
void Rot_RL(Noh *a){Rot_LL(a->dir);Rot_RR(a);}

//Modificador_Da_Altura
void Mod_h(Noh *p){
	    Noh* aux = p;
        while(aux!=NULL){
            aux->h = 1 + Max(aux->esq,aux->dir);
            aux = aux->pai;
		}
}

//Balanceador
void Balancear(DicAVL &D,Noh* a){
	while(a!=NULL){
		
		int bal=Balanceamento(a);int baldir;int balesq;
		if(a->dir!=NULL){baldir = Balanceamento(a->dir);}
        if(a->esq!=NULL){balesq = Balanceamento(a->esq);}
  	
		switch(bal){
			case 0:
				a = a->pai;
				break;
            case 1:
            	a = a->pai;
            	break;
            case -1:
            	a = a->pai;
            	break;
            case  2:
            	if(balesq==1||balesq==0){
   			        bool raz = (D.raiz==a)?true:false;
                    Rot_LL(a);Mod_h(a);
					if(raz) D.raiz = a->pai;
				
                }
				else if(balesq==-1){	
						bool raz = (D.raiz==a)?true:false;
						Rot_LR(a);
						--a->pai->esq->h;
						Mod_h(a);
						if(raz) D.raiz = a->pai;
                }
				a = a->pai;
			    break;
			case -2:
				if(baldir==-1||baldir==0){
					bool raz = (D.raiz==a)?true:false;
					Rot_RR(a);Mod_h(a);
					if(raz) D.raiz = a->pai;
				}
				else if(baldir==1){   
						bool raz = (D.raiz==a)?true:false;
						Rot_RL(a);
						--a->pai->dir->h;
						Mod_h(a);
						if(raz) D.raiz = a->pai;
                }
				a = a->pai;
			    break;	
		}
	}
	
}


//Busca_Binaria
Noh* procurar (DicAVL &D, TC c){
	
    Noh *p = D.raiz;
	if(p!=NULL){
		for(;;){
			if(c == p->chave) return p;
			else if(c<p->chave){
				if(p->esq == NULL) return NULL;
				else p = p->esq;
			}
			else{
				if(p->dir == NULL) return NULL;
				else p = p->dir;
			}
		}
	}
	return NULL;
}

//Inserção
Noh* inserir (DicAVL &D, TC c, TV v){
	
    Noh *n = new(std::nothrow) Noh;
	if(n == NULL){return n;}
	n->chave = c; n->valor = v; n->esq = n->dir = NULL;n->h = 1; 
	if(D.raiz == NULL){n->pai = NULL;D.raiz = n;return n;}
    else{
		Noh *p = D.raiz;
		for(;;){
			if(c <= p->chave){
				if(p->esq == NULL){
				    p->esq = n; n->pai = p;
	    	        Mod_h(p);
    	            Balancear(D,p);
    	            break;
				}
				else p = p->esq;
			}else{
				if(p->dir == NULL){
					p->dir = n; n->pai = p;
                    Mod_h(p);
					Balancear(D,p);
					break;
                }
                else p = p->dir;
			}
        }
        
	}
		
   	return n;        
}

//Remoção
void remover(DicAVL &D,Noh *n){
   
	if(n->esq == NULL && n->dir == NULL){
        Noh *Pai = n->pai;
		if(n == D.raiz) D.raiz = D.raiz->pai;
		else if(n == n->pai->esq) n->pai->esq = n->dir;
		else n->pai->dir  = n->dir;
		delete n;
		Mod_h(Pai);
		Balancear(D,Pai);
	}
    else{
    	
		if(n->esq == NULL){
            Noh *Pai = n->pai;
			if(n->pai == NULL){D.raiz = n->dir;n->dir->pai = n->pai;}
			else if(n == n->pai->esq){n->pai->esq = n->dir;n->dir->pai = n->pai;}
			else{n->pai->dir = n->dir;n->dir->pai = n->pai;}
            delete n;
            Mod_h(Pai);
			Balancear(D,Pai);
		}
	
		else if(n->dir == NULL){
            Noh *Pai = n->pai;
			if(n->pai == NULL){D.raiz = n->esq;n->esq->pai = n->pai;}
			else if(n == n->pai->esq){n->pai->esq = n->esq;n->esq->pai = n->pai;}
			else{n->pai->dir = n->esq;n->esq->pai = n->pai;}
            delete n;
            Mod_h(Pai);
			Balancear(D,Pai);
		}
		
	    
		else{
            Noh *Pai = n->pai;
			Noh *s = n->dir;
			while(s->esq != NULL) s = s->esq;
	        if(s->pai!=n){
				s->pai->esq = s->dir;
	            if(s->dir != NULL) s->dir->pai = s->pai;
				s->dir = n->dir;
	            s->dir->pai = s;
	        }
	        if(s->pai!=n)Pai = s->pai;
	        else Pai = s;
	        if(n->pai == NULL){D.raiz = s;}
	        else if(n==n->pai->esq){n->pai->esq = s;}
	        else{n->pai->dir = s;}
	        s->pai = n->pai;
	        s->esq = n->esq;
	        s->esq->pai = s;
	        delete n;
            Mod_h(Pai);
			Balancear(D,Pai);
	        
		}
	}
	
}

void terminar (DicAVL &D){
	if(D.raiz != NULL){
		DicAVL Df;
		Df.raiz = D.raiz->esq;
		terminar(Df);
		Df.raiz = D.raiz->dir;
		terminar(Df);
		Noh *deletar = D.raiz;
		delete deletar;
	}

}



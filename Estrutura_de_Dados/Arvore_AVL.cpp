#include <iostream>
#include <stdlib.h>
using std::nothrow; using std::cin; using std::cout;
typedef double TC; typedef float TV;

struct Noh { TC chave; TV valor; Noh *esq, *dir, *pai; int h;};
struct DicAVL { Noh *raiz; };


void inicializar (DicAVL &D){D.raiz = NULL;}


void Aumentar_h(DicAVL &D,Noh *p){
		Noh *adicao = p;
        Noh *Pai = adicao->pai;
        Noh *Irmao = (adicao==Pai->esq)?Pai->dir:Pai->esq;
        ++adicao->h;
        while(adicao!=D.raiz){
    		if(Irmao==NULL){++Pai->h;adicao=Pai;}
            else if(Irmao->h<adicao->h){++Pai->h;adicao=Pai;}
            else break;
		}
}

void Diminuir_h(DicAVL &D,Noh *p){
	Noh *remocao = p;
    Noh *Pai = remocao->pai;
    Noh *Irmao = (remocao==Pai->esq)?Pai->dir:Pai->esq;
    --remocao->h;
    while(remocao!=D.raiz){
            if(Irmao->h<remocao->h){--Pai->h;remocao=Pai;}
            else break;
	}
}


void Rot_LL(Noh *a){
	Noh *Esq = a->esq->dir;
	a->esq->dir = a;
	a->esq->pai = a->pai;
	a->pai = a->esq;
	a->esq = Esq;
}

void Rot_RR(Noh *a){
	Noh *Dir = a->dir->esq;
	a->dir->esq = a;
	a->dir->pai = a->pai;
	a->pai = a->dir;
	a->dir = Dir;
}

void Rot_LR(Noh *a){Rot_RR(a->esq);Rot_LL(a);}

void Rot_RL(Noh *a){Rot_LL(a->dir);Rot_RR(a);}

int Desbalanceou(Noh *adicao){//Avalia se ocorreu um desbalanceamento; adicao diferente da raiz
	Noh *Tio;
	Noh *Pai = adicao->pai;
	Noh *Avo = (Pai->pai!=NULL)?Pai->pai:NULL;
	Noh *Irmao = (adicao==Pai->dir)?Pai->esq:Pai->dir;
	if(Avo!=NULL) Tio = (Pai==Avo->dir)?Avo->esq:Avo->dir;
	else Tio = NULL;
	
	if(Irmao==NULL || abs(adicao->h-Irmao->h)==2)return 1;
	else if(Avo==NULL) return 2;
	else if(abs(Pai->h-Tio->h)==2)return 3;
	else return 5;
	
}



Noh* Balancear(DicAVL &D,Noh *p){
	int chave = Desbalanceou(p);
	Noh *Pai = p->pai;
	Noh *Avo = (Pai->pai!=NULL)?Pai->pai:NULL;
	
    switch(chave){
    	
		case 1:
			if(Pai->esq==p){Rot_LL(Pai);--Pai->h;return p;}
			else{Rot_RR(Pai);--Pai->h;return p;}
			break;
		case 2:
		    return NULL;
		case 3:
			if(Avo->esq==Pai){
				Rot_LR(Avo);
				++p->h;
				--Pai->h;
				Avo->h = Avo->h -2;
				return p;
			}
            else{
				Rot_RL(Avo);
            	++p->h;
				--Pai->h;
				Avo->h = Avo->h -2;	
				return p;
			}
            break;
		default:
			return NULL;
			break;
		}
}

//Busca_Binaria
Noh* procurar (DicAVL &D, TC c){
	
    Noh *p = D.raiz;
	if(p->dir != p->esq){
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
	if(c == p->chave) return p;
	return NULL;
}


Noh* inserir (DicAVL &D, TC c, TV v){
	
    Noh *n = new(nothrow) Noh;
	if(n == NULL){return n;}
	
	n->chave = c; n->valor = v; n->esq = n->dir = NULL;n->h = 1; 

	if(D.raiz == NULL){n->pai = NULL;D.raiz = n;return n;}

    else{
    	
		Noh *p = D.raiz;
		for(;;){
			if(c <= p->chave){
				if(p->esq == NULL){
				    p->esq = n; n->pai = p;
				    if(p!=D.raiz&&p->dir==NULL){
				    	Aumentar_h(D,p);
				    	Noh *aux = p;
				    	Noh *q = D.raiz;
				    	while(aux != D.raiz){
				    		if(aux==q)
							aux = Balancear(D,aux);
						}
						break;
					}
					if(p==D.raiz){++p->h;break;}
					break;	
				}
				else p = p->esq;
			}else{
				if(p->dir == NULL){
					p->dir = n; n->pai = p;
					if(p!=D.raiz&&p->esq == NULL){
						Aumentar_h(D,p);
						Noh *aux = p;
						while(aux != D.raiz){
							aux = Balancear(D,aux);
						}
						break;
					}
					if(p==D.raiz){++p->h;break;}
					break;
                }
                else p = p->dir;
			}
        }
        
	}
		
   	return n;        
}

/*void remover (DicAVL &D, Noh *n){
	
	//Trata o caso de n não possuir filhos
	if(n->esq == NULL && n->dir == NULL){
		if(n == D.raiz){D.raiz = D.raiz->pai;}
		else{
              Noh *Pai = n->pai;int h_n = n->h;Noh *Tio;
              Noh *Avo = Pai->pai;
              Noh *Irmao = (n==Pai->esq)?Pai->dir:Pai->esq;
              if(n == Pai->esq) Pai->esq = n->dir;
              else Pai->dir = n->dir;
              if(Pai->esq==NULL && Pai->dir==NULL;){
			  	  Diminuir_h(Pai);//n não tem filhos
              	  if(Avo != NULL){
                         while(aux != D.raiz){
   	   	   	                   Balancear(D,aux);
   	   	   	                   aux = aux->pai;
  	        	    
                       }
                  }
				
   	           }else{ 
			   	   if(n_h<Irmao->h){
				   	   if(Pai->esq==NULL){
					   	   Rot_RR(Pai);--Pai->esq->h;
					   	   if(Avo!=NULL){
                           	   Noh *aux = Avo;
 	  	  	               	   while(aux != D.raiz){
  	  	  	                    	Balancear(D,aux);
  	  	  	                    	aux = aux->pai;
    	  	                	}  
					   	   }
				   	   }else{
					   	   Rot_LL(Pai);--Pai->dir->h;
					   	   if(Avo!=NULL){
                           	   Noh *aux = Avo;
 	  	  	               	   while(aux != D.raiz){
  	  	  	                    	Balancear(D,aux);
  	  	  	                    	aux = aux->pai;
                        	}  
				   	   }
			   		  }	
               }
        
          }
		}
	}else{
		
		//Trata o caso de n possuir 1 filho
		if(n->esq == NULL){
			if(n->pai == NULL){D.raiz = n->dir;n->dir->pai = n->pai;}
            else{
            	Noh* Pai = n->pai;
				else if(n == n->pai->esq){n->pai->esq = n->dir;n->dir->pai = n->pai;}
				else{n->pai->dir = n->dir;n->dir->pai = n->pai; 
                while()Balancear_Rem(Pai);
			}
		}
		else if(n->dir == NULL){
			if(n->pai == NULL){D.raiz = n->esq;n->esq->pai = n->pai;}
            else{
            	Noh* Pai = n->pai;
				else if(n == n->pai->esq){n->pai->esq = n->esq;n->esq->pai = n->pai;}
				else{n->pai->dir = n->esq;n->esq->pai = n->pai;}
                Balancear_Rem(Pai);//
			}
		}
	
		//Trata o caso de n possuir dois filhos
		else{
			Noh *s = n->dir;//nó sucessor
			while(s->esq != NULL) s = s->esq;//achar o menor nó na subarvore a direita de n
            Noh *Pai = s->pai;
	        if(s->pai!=n){//caso onde o filho direito possui um filho esquerdo, pelo menos
				Pai->esq = s->dir;
	            if(s->dir != NULL) s->dir->pai = Pai;
				s->dir = n->dir;//faz o filho direito de n ser o de s
	            s->dir->pai = s;//faz o pai do filho direito de n ser s
	        }
	        if(n->pai == NULL){D.raiz = s;}
	        else if(n==n->pai->esq){n->pai->esq = s;}// coloca o filho esquerdo de n->pai como sendo ses se n o for
	        else{n->pai->dir = s;}//coloca o filho direito de n->pai como sendo s se n o for
	        s->pai = n->pai;//coloca o pai de s como sendo o pai de n
	        s->esq = n->esq;//coloca o filho esquerdo de s como sendi o filho esquerdo de n
	        s->esq->pai = s;//coloca o pai do filho esquerdo de n como sendo s
	        
	        Balancear_Rem(Pai);
		}
		
		
		
	}

}*/
//void terminar (DicAVL &D);

int  main(){
	
return 0;
}


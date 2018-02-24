#include <stdio.h>
#include <stdlib.h>

#define MX  100

struct pilha{
	long double vect[MX];
	long double top;
	int tam;
	int mx;
};


//Declaração das funções
long double tp(struct pilha *p);
long double *vt(struct pilha *p);
int tm(struct pilha *p);
int mx(struct pilha *p);
int ep(struct pilha *p);
int fl(struct pilha *p);
void set_tm(struct pilha *p,int x);
void set_tp(struct pilha *p,long double x);
void set_vect(struct pilha *p,long double *v);
void add(struct pilha *p,long double x,int y);
void push(long double x,struct pilha *p);
long double pop(struct pilha *p);
void swap(struct pilha *m,struct pilha *n);
int eql(struct pilha *m,struct pilha *n);
int cp(struct pilha *m,struct pilha *n);


//Gerar a pilha
struct pilha GerP(void){
	struct pilha ph;
	struct pilha *p = &ph;
	set_tm(p,0);
	int i;for(i=0;i<MX;i++) add(p,-1.0,1);
	set_tp(p,*vt(p));
	p->mx = MX;
	return ph;//construir o atributo full ; tentar diminuir oacesso aos atributos através dos métodos
}


long double tp(struct pilha *p){return p->top;}//Retorna o próximo elemento da pilha
long double *vt(struct pilha *p){long double *e = p->vect;return e;}//Retorna um ponteiro para o preimeiro elemento de vect
int tm(struct pilha *p){return p->tam;}//Retorna o tamanho atual da da pilha
int mx(struct pilha *p){return p->mx;}//Retorna o tamanho máximo da pilha
int ep(struct pilha *p){if(!tm(p))return 1;else return 0;}//Diz se a pilha está vazia ou não
int fl(struct pilha *p){if(!(tm(p)<mx(p)))return 1;else return 0;}//Diz se a pilha esta cheia

void set_tm(struct pilha *p,int x){p->tam = x;}//trocar o tamanho
void set_tp(struct pilha *p,long double x){p->top = x;}//trocar o topo
void set_vect(struct pilha *p,long double *v){int i;for(i=0;i<tm(p);i++){long double k=*(v+i);p->vect[i]=k;}}//trocar o vetor

void add(struct pilha *p,long double x,int y){p->vect[tm(p)-y] = x;}//Adicionar um elemento

//Adiciona um Elemento da Pilha
void push(long double x,struct pilha *p){if(!fl(p)){set_tm(p,tm(p)+1);add(p,x,1);set_tp(p,*(vt(p)+tm(p)-1));}}
//Recupera um Elemento da Pilha
long double pop(struct pilha *p){
	if(!ep(p)){
	           long double Rer= tp(p);add(p,-1.0,1);
			   if(tm(p)>1){set_tp(p,*(vt(p)+tm(p)-2));}
			   else{set_tp(p,*(vt(p)+tm(p)-1));}
			   set_tm(p,tm(p)-1);return Rer;
	}
	return -1.0;}
//Trocar pilha
void swap(struct pilha *m,struct pilha *n){set_tm(m,tm(n));set_tp(m,tp(n));set_vect(m,vt(n));}
//Compara duas pilhas
int cp(struct pilha *m,struct pilha *n){
	if(tm(m)<tm(n)) return -1;
	else if(tm(m)==tm(n)) return 0;
	else return 1;}
//Compara a igualdade de duas pilhas
int eql(struct pilha *m,struct pilha *n){
	   int i;
       if(!cp(m,n)){for(i==0;i<tm(m);i++){long double r=*(vt(m)+i);long double s=*(vt(n)+i);if(r!=s) return 0;};return 1;}
	   else return 0;}

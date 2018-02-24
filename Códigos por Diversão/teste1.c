#include <stdio.h>
#include <stdlib.h>

struct teste1{
	char *nome;
};

int main()
{
	struct teste1 t,*start,**p;
	t.nome = "Matheus";
	start = &t;
	p = &(start);
	printf("%s",(**p).nome);
	
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

main()
{
	FILE *in = fopen("Teteu","wb");
	getch();
	int resul = fflush(in);
	printf("\n%i\n",resul);
}

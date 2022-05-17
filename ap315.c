#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int nombre1 = 0;
	int nombre2 = 0;

	scanf("%d",&nombre1);
	
	scanf("%d",&nombre2);

	int modulo = nombre1&nombre2;

	printf("le modulo calculer est de: %d\n",modulo);
	return 0;
}
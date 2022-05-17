#include <stdio.h>
#include <stdlib.h>

//----------------------parie fonction-------------------------------------

int entier(int val)
{
	int tous;

	tous = val%2;

	return tous;
}

//----------------------parie main-------------------------------------

int main(int argc, char const *argv[])
{
	int nombre,results = 0;

	printf("donnez votre entier\n");
	scanf("%i",&nombre);

	//printf("%i\n",entier(nombre));

	results = entier(nombre);

	if (results==1)
	{
		printf("votre entier est impair\n");
	}
	else
	{
		printf("votre entier est pair\n");
	}

	return 0;
}
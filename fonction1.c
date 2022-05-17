#include <stdio.h>
#include <stdlib.h>

//----------------------parie fonction-------------------------------------

void entier(int val1,int val2)
{
	int sauve;

	sauve = val1;
	val1 = val2;
	val2 = sauve;

	printf("votre entier1 est devenue %i et votre entier2 est devenue %i\n",val1,val2);
}

//----------------------parie main-------------------------------------


int main(int argc, char const *argv[])
{
	int nombre1,nombre2 = 0;

	printf("donnez votre premier entier\n");
	scanf("%i",&nombre1);

	printf("donnez votre deuxiéme entier\n");
	scanf("%i",&nombre2);

	printf("votre entier1 est: %i et votre entier2 est: %i\n",nombre1,nombre2);

	entier(nombre1,nombre2);

	return 0;
}
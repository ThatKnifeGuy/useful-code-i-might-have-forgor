/*Bernard Alexandre BTS-snir1
30/11/2021
les fonctions!
*/
#include <stdio.h>
#include <stdlib.h>

int triple(int nombre)
{
	int resultat = 0;

	resultat = 3 * nombre;
	return resultat;
}

int addition(int a, int b)
{
	return a + b;
}

void bonjour()
{
	printf("bonjour\n");
}

//---------------------------------------programme principal---------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
	bonjour();

	printf("le triple est %i\n",triple(5));

	printf("le resultat de l'addition est %i\n",addition(5,5));

	return 0;
}
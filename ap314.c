#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int resultat = 0;
	double resultat_decimal = 0;

	resultat = 5 + 3;
	printf("5 + 3 = %d\n",resultat);

	resultat_decimal = 5.0 / 2.0;
	printf("5 / 2 = %f\n",resultat_decimal);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	float t = 1.1;
  	float p = 1.1;

  	printf("saisir votre taille\n""Taille:\n");
  	scanf("%f",&t);
  	printf("taille entré: %f\n",t);

  	printf("saisir votre poids\n""Poids:\n");
  	scanf("%f",&p);
  	printf("poids entré: %f\n",p);

  	float squared = t*t;
  	float imc = 0.0;

  	imc = p/squared;

  	printf("votre IMC est de: %f\n",imc);

  	return 0;
}
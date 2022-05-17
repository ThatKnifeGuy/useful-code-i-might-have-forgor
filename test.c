#include <stdio.h>
#include <stdlib.h>


void IMC(int poids, int age, int taille, int sexe)
{
	double tailleCarre = 0.0;
	float resultat = 0.0;

	tailleCarre = taille*taille;
	resultat =  poids/tailleCarre;
	resultat = resultat*10000;

	switch (sexe)
	{
		case 0:
			printf("Bonjour,vous êtes un homme\n"
			"vous avez %i ans\n"
			"vous pesez %i Kg\n"
			"vous mesurez %d cm\n"
			"et votre IMC est de %f\n",age,poids,taille,resultat);
			break;
		case 1:
			printf("Bonjour,vous êtes une femme\n"
			"vous avez %i ans\n"
			"vous pesez %i Kg\n"
			"vous mesurez %d cm\n"
			"et votre IMC est de %f\n",age,poids,taille,resultat);
			break;
	}
}



int main(int argc, char const *argv[])
{
	int poids;
	int age;
	int taille;
	int sexe;

	printf("Quel est votre poids (en Kg)?..\n");
	scanf("%i",&poids);

	printf("Quel est votre âge?..\n");
	scanf("%i",&age);

	printf("Quel est votre taille (en cm)?..\n");
	scanf("%i",&taille);

	printf("Quel est votre genre? (0 pour homme et 1 pour femme)\n");
	scanf("%i",&sexe);

	IMC(poids,age,taille,sexe);

	return 0;
}
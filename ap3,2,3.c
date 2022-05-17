/*Bernard Alexandre BTS-snir1
25/11/2021
utilisation de "for" pour compter jusqu'à 10 en affichant chaque chiffres
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int compteur; //création de la variable "compteur"

	for (compteur = 0;compteur < 11;compteur = compteur + 1) 
	{	//on met la variable à 0 et tant quel est plus petit que 10 on rajoute 1
		printf("%i\n",compteur); //on affiche entre chaque éxecution la valeur de la variable
	}
	return 0;
}
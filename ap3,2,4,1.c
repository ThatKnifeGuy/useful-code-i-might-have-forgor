/*Bernard Alexandre BTS-snir1
25/11/2021
utilisation de "while" pour compter jusqu'à 10 en affichant chaque chiffres
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int compteur = 0; //création de la variable "compteur"
	
	while (compteur < 10)    
	{              //tant que la variable compteur est en dessous de 10 on éxecute la programme ci-dessous
		compteur = compteur + 1;     //on ajoute 1 à la varible compteur
		printf("%i\n",compteur);     //on affiche la valeur de la variable compteur
	}

	return 0;
}
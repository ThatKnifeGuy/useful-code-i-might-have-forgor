/*Bernard Alexandre BTS-snir1
02/12/2021
le jeu du hasard!(avec compteur d'essais et 2 joueur et difficulté modifiable)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv)
{
	int player = 1;
	int x,diff,nombreMystere,nombreEntre,nombreTry = 0;
	//les trois variable de difficulté
	int MAX1 = 100;
	int MAX2 = 1000;
	int MAX3 = 10000;

	//On demande à l'utilisateur de choisir une difficulté
	printf("Quel niveau de difficulté voulait vous prendre? 1? 2? ou 3?\n");
	
	//tant que la variable diff est à 0 le jeu de commenceras pas 
	//il faut au mois avoir la variable diff à 1 2 ou 3 pour commencer une partie
	while(diff==0)
	{
		scanf("%d",&diff);
		if (diff==1)
		{
			printf("Vous avez pris la difficulté 1\n");
			x=MAX1;
		}
		else if (diff==2)
		{
			printf("Vous avez pris la difficulté 2\n");
			x=MAX2;
		}
		else if (diff==3)
		{
			printf("Vous avez pris la difficulté 3\n");
			x=MAX3;
		}
		else
		{
			printf("prenez une des trois difficulté énnoncer\n");
		}
	}

	int MAX = x, MIN = 1;

	//choix du nombre de joueur
	printf("pour jouer en solo entre 1 sinon entré 2 pour 2 joueur\n");
	scanf("%d",&player);

	if (player==1)
	{
		//génération du nombre aléatoire pour 1 joueur
		srand(time(NULL));           
		nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
	}
	else
	{
		//le joueur 2 est demander le nombre mystère à trouver pour le joueur 1
		printf("joueur 2 choisis un nombre..\n");
		scanf("%d",&nombreMystere);
	}
	/* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le 
	nombre mystère*/
	do
	{
		//On ajoute 1 essai et on demande le nombre

		nombreTry = nombreTry + 1;
		printf("Quel est le nombre ? ");
		scanf("%d", &nombreEntre);

		//On compare le nombre entré avec le nombre mystère

		if (nombreMystere > nombreEntre)
			printf("C'est plus !\n\n");
		else if (nombreMystere < nombreEntre)
			printf("C'est moins !\n\n");
		else
			printf("Bravo, vous avez trouve le nombre mystère en %i coups !!!\n\n",nombreTry);
		//affiche le message de victoire ainsi que le nombre de essai
	}
	while (nombreEntre != nombreMystere);

	return 0;
}


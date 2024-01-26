#include <stdio.h>
#include <stdlib.h>

//Demande l'age et l'argent sur le terminal et répond une des deux issues selon la réponse

int main(int argc, char const *argv[])
{
	int age,argent; /*on crée les variables*/

	printf("quel est votre age?\n");
	scanf("%d",&age);
	printf("de combien de $$$ avez vous?\n");
	scanf("%d",&argent);
;
	if (age > 30 || argent >100000)
	{
		printf("bienvenue chez PicsouBank\n!");
	}
	else
	{
		printf("hors de ma vue miserable!\n");
	}
	return 0;
}

/*Bernard Alexandre BTS-snir1
25/01/2022
fonction qui calcul le kW/h d'un appareil électrique
*/

#include <stdio.h>
#include <stdlib.h>

//----------------------parie fonction-------------------------------------
//puissance x temps = kW/h

int consom(int pui,int tem)
{
	int resul;
	resul = pui*tem;
	printf("consomation = %d kw/h\n",resul);
	return resul;
}


//----------------------parie main-------------------------------------
int main(int argc, char const *argv[])
{
	int val1,val2,kwh;

	printf("quel est la puissance de votre appareil électrique? (en kW)\n");
	scanf("%d",&val1);

	printf("quel est ça durée de fonctionnement? (en heure)\n");
	scanf("%d",&val2);

	kwh = consom(val1,val2);

	if(kwh<5)
	{
		printf("faible consomation\n");
	}
	else if(kwh>5 && kwh<10)
	{
		printf("consomation normale\n");
	}
	else if(kwh>5)
	{
		printf("haute consomation\n");
	}

	return 0;
}
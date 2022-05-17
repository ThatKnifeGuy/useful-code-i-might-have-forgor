#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int age,argent; /*on crée les variables*/

	printf("quel est votre age?\n");
	scanf("%d",&age);
	
	printf("de combien de $$$ avez vous?\n");
	scanf("%d",&argent);

	if (age <= 10 && argent<=1000)
	{
		printf("Hors de ma vue jeune miserable\n");
	}
	else
	{
		if(age <= 10 && argent>=1001 && argent<=10000)
		{
			printf("Salut jeune\n");
		}
		else
		{
			if (age <= 10 && argent>=10001 && argent<=100000)
			{
				printf("Bienvenue jeune Picsou\n");
			}
			else
			{
				if (age>=11 && age<=20 && argent<=1000)
				{
					printf("Hors de ma vue,adolescent miserable\n");
				}
				else
				{
					if (age>=11 && age<=20 && argent>=1001 && argent<=10000)
					{
						printf("Salut adolescent\n");
					}
					else
					{
						if (age>=11 && age<=20 && argent>=10001 && argent<=100000)
						{
							printf("Bienvenue adolescent Picsou\n");
						}
						else
						{
							if (age>=21 && age<=30 && argent<=1000)
							{
								printf("Hors de ma vue jeune adulte miserable\n");
							}
							else
							{
								if (age>=21 && age<=30 && argent>=1001 && argent<=10000)
								{
									printf("Salut jeune adulte\n");
								}
								else
								{
									if (age>=21 && age<=30 && argent>=10001 && argent<=100000)
									{
										printf("Bienvenue jeune adulte Picsou\n");
									}
									else
									{
										if (age>=31 && age<=40 && argent<=1000)
										{
											printf("Hors de ma vue vieux miserable\n");
										}
										else
										{
											if (age>=31 && age<=40 && argent>=1001 && argent<=10000)
											{
												printf("Salut vieux\n");
											}
											else
											{
												if (age>=31 && age<=40 && argent>=10001 && argent<=100000)
												{
													printf("Bienvenue vieux Picsou\n");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
/*Bernard Alexandre BTS-snir1
07/04/2022
Projet domotique chatBot
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//***********************DEFINITION DES FONCTIONS F1, F2, et F3*******************


char cuisine[10] = "cuisine";
char salon[10] = "salon";
char chambre[10] = "chambre";
char sdb[20] = "salle de bain";
char temperature[20] = "temperature";
char lampe[10] = "lampe";
char humidite[10] = "humidite";
char volet[10] ="volet";
char presence[10] = "presence";
char allumer[10] = "allumer";
char eteindre[10] = "eteindre";
char ouvrir[10] = "ouvrir";
char fermer[10] = "fermer";
char question[10] = "question";



char mots_salon[20][20] = {"salon", "sallon", "saloon", "calon", "callon", "caloon", "Salon", "Sallon", "Saloon", "Calon", "Callon", "Caloon", "living room", "Living room", "fin"};
char mots_cuisine[20][20] = {"cuisine", "kuisine", "quisine", "cuissine", "Cuisine", "Kuisine", "Quisine", "Cuissine", "Kitchen", "kitchen", "fin"};
char mots_chambre[20][20] = {"chambre", "jambre", "chanbre", "janbre", "Chambre", "Jambre", "Chanbre", "Janbre", "living room", "fin"};
char mots_sdb[21][20] = {"salle de bain", "sale de bain", "calle de bain", "cale de bain", "sdb", "Salle de bain", "Sale de bain", "Calle de bain", "Cale de bain", "Sdb", "salle 2 bain", "Salle 2 bain", "sale 2 bain", "Sale 2 bain", "cale 2 bain", "Cale 2 bain", "calle 2 bain", "Calle 2 bain", "bathroom", "bath room", "fin"};
char mots_temperature[20][20] = {"temperature", "Temperature", "tenperature", "Tenperature", "heat", "Heat", "fin"};
char mots_lampe[20][20] = {"lampe", "Lampe", "lanpe", "Lanpe", "lamp", "Lamp", "fin"};
char mots_humidite[20][20] = {"humidite", "Humidite", "humiditer", "Humiditer", "humidity", "Humidity", "fin"};
char mots_volet[20][20] = {"volet", "Volet", "vollet", "Vollet", "shutter", "Shutter", "shuter", "Shuter", "fin"};
char mots_presence[20][20] = {"presence", "Presence", "presensse", "Presensse", "prezence", "Prezence", "fin"}; 
char mots_allumer[20][20] = {"allumer", "Allumer", "alumer", "Alumer", "turn on", "Turn on", "fin"};
char mots_eteindre[20][20] = {"eteindre", "Eteindre", "etaindre", "Etaindre", "turn off", "Turn off", "shutdown", "fin"};
char mots_ouvrir[20][20] = {"ouvrir", "Ouvrir", "ouvre", "Ouvre", "open", "Open", "fin"};
char mots_fermer[20][20] = {"fermer", "Fermer", "ferme", "Ferme", "close", "Close", "shut", "fin"};
char mots_question[20][20] = {"question", "Question", "fin"};

bool F1(char phrase[50], char tableau[20][20])
{
    char * result = strstr(phrase, tableau[0]);

    // Affichage d'une réponse à l'utilisateur.
    while (strcmp(tableau[i],"fin") != 0)
    {
    	if ( result == NULL ) 
    	{
    	    printf( "le mot %s du tableau n'existe pas dans la phrase\n", tableau);
    	    return false;
    	} 
    	else 
    	{
    	    printf( "La chaîne contient le mot %s du tableau\n", tableau);
    	    return true;
    	}
	}
}

char F2_piece(bool bool_cuisine, bool bool_salon, bool bool_chambre, bool bool_sdb)
{
    if(bool_cuisine && !bool_salon && !bool_chambre && !bool_sdb)
    {
        return 'K';
    }
    if(!bool_cuisine && bool_salon && !bool_chambre && !bool_sdb)
    {
        return 'L';
    }
    if(!bool_cuisine && !bool_salon && bool_chambre && !bool_sdb)
    {
        return 'M';
    }
    if(!bool_cuisine && !bool_salon && !bool_chambre && bool_sdb)
    {
        return 'N';
    }
}

char F2_objet(bool bool_humidite, bool bool_lampe, bool bool_temperature, bool bool_volet, bool bool_presence)
{
	if(bool_humidite && !bool_lampe && !bool_temperature && !bool_volet && !bool_presence)
    {
        return 'A';
    }
    if(!bool_humidite && bool_lampe && !bool_temperature && !bool_volet && !bool_presence)
    {
        return 'B';
    }
    if(!bool_humidite && !bool_lampe && bool_temperature && !bool_volet && !bool_presence)
    {
        return 'C';
    }
    if(!bool_humidite && !bool_lampe && !bool_temperature && bool_volet && !bool_presence)
    {
        return 'D';
    }
    if(!bool_humidite && !bool_lampe && !bool_temperature && !bool_volet && bool_presence)
    {
        return 'E';
    }
}

char F2_req(bool bool_allumer, bool bool_eteindre, bool bool_ouvrir, bool bool_fermer, bool bool_question)
{
	if(bool_allumer && !bool_eteindre && !bool_ouvrir && !bool_fermer && !bool_question)
    {
        return 'F';
    }
    if(!bool_allumer && bool_eteindre && !bool_ouvrir && !bool_fermer && !bool_question)
    {
        return 'G';
    }
    if(!bool_allumer && !bool_eteindre && bool_ouvrir && !bool_fermer && !bool_question)
    {
        return 'H';
    }
    if(!bool_allumer && !bool_eteindre && !bool_ouvrir && bool_fermer && !bool_question)
    {
        return 'I';
    }
    if(!bool_allumer && !bool_eteindre && !bool_ouvrir && !bool_fermer && bool_question)
    {
        return 'J';
    }   
}
/*
void initialisation_matrice(void)
{
    //faire une boucle for pour itialiser toutes les cases de la matrice à "Z. Plusieurs boucles for imbriquées ..."

...

    //Remplir les cases de la matrice au cas par cas : 

    matrice['A'-'A']['J'-'F']['K'-'K']='Y'
    matrice['A'-'A']['J'-'F']['L'-'K']='Y';
    matrice['A'-'A']['J'-'F']['M'-'K']='Y';
    matrice['A'-'A']['J'-'F']['N'-'K']="AJ1\r";

    //Faire quelques test : que donne un printf de matrice['A']['J']['N'] ?
    //Que donne un printf de matrice['A']['J']['K'] ?
}
*/

//***********************PARTIE MAIN*******************

int main(int argc, char const *argv[])
{
	 //Récupération de la phrase de l'utilisateur 
    char buffer[ 255 ];
    printf( "Veuillez saisir votre souhait : \n" );
    scanf( "%[^\n]", buffer );
    fgetc( stdin );

    //Appel de la fonction 1 pour vérifier si les mots du tableau sont dans la phrase
    bool bool_salon = F1(buffer, mots_salon);
    bool bool_cuisine = F1(buffer, mots_cuisine);
    bool bool_chambre = F1(buffer, mots_chambre);
    bool bool_sdb = F1(buffer, mots_sdb);
    bool bool_humidite = F1(buffer, mots_humidite);
    bool bool_lampe = F1(buffer, mots_lampe);
    bool bool_temperature = F1(buffer, mots_temperature);
    bool bool_volet = F1(buffer, mots_volet);
    bool bool_presence = F1(buffer, mots_presence);
    bool bool_allumer = F1(buffer, mots_allumer);
    bool bool_eteindre = F1(buffer, mots_eteindre);
    bool bool_ouvrir = F1(buffer, mots_ouvrir);
    bool bool_fermer = F1(buffer, mots_fermer);
    bool bool_question = F1(buffer, mots_question);


    //Appel de la fonction 2 pour obtenir le caractère correspondant aux booléens 
    char char_piece = F2_piece(bool_cuisine, bool_salon, bool_chambre, bool_sdb);
    char char_objet = F2_objet(bool_humidite, bool_lampe, bool_temperature, bool_volet, bool_presence);
    char char_req = F2_req(bool_allumer, bool_eteindre, bool_ouvrir, bool_fermer, bool_question);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



//************************AIDE MEMOIRE****************************
char salon[10] = "salon";
char *salon = "salon";

char cuisine[10] = "cuisine";
char *cuisine = "cuisine";

char mots_salon[20][20] = {"salon, sallon, saloon"};
char *mots_salon[10] = {"salon, sallon, saloon"};

char mots_salon[20][20] = {"cuisine, cuissine, kuisine"};
char *mots_salon[10] = {"cuisine, cuissine, kuisine"};

salon[0] => 's'
salon[1] => 'a'
salon[2] => 'l'
salon[3] => 'o'
salon[4] => 'n'

mots_salon[0] => "salon"
mots_salon[1] => "sallon"
mots_salon[2] => "saloon"

mots_salon[1][2] => "l"


/*ATTENTION : on ne test jamais l'égalité de deux mots avec un égal :

if(salon == cuisine) => Invalide

On utilise une fonction de la librairie str : 

if(strcmp(salon, cuisine) != null) => valide

*/

//**********************FIN AIDE MEMOIRE ******************************





//***************** DEBUT DU CODE *******************

//On définit au début, avant toutes les fonctions, les variables globales (tableaux, matrice, etc.)

char * matrice[5][5][4]; //Définition de la matrice pour la fonction 3

//Définir tous les tableaux contenant les mots des pièces, des objets et des requetes. 



//***********************DEFINITION DES FONCTIONS F1, F2, et F3*******************



bool F1(char phrase[50], char tableau[20][20])
{

    //Partie itération du tableau, à développer. 


    char * result = strstr(phrase, tableau[0]);

    // Affichage d'une réponse à l'utilisateur.
    if ( result == NULL ) {
        puts( "le mot du tableau n'existe pas dans la phrase " );
        return false;
    } else {
        puts( "La chaîne contient le mot du tableau" );
        return true;
    }


}



char F2_piece(bool_cuisine, bool bool_salon, bool bool_chambre, bool bool_sdb)
{
    if(bool_cuisine && !bool_salon && !bool_chambre && !bool_sdb)
    {
        return 'K';
    }

    ...
}

char F2_objet(bool bool_humidite, bool bool_lampe, bool bool_temperature, bool bool_volet, bool bool_presence)
{


    
}

char F2_req(bool bool_allumer, bool bool_eteindre, bool bool_ouvrir, bool bool_fermer, bool bool_question)
{


    
}



//Pour la fonction F3, réfléchir à l'utilisation de la matrice. Faut il vraiment une fonction pour obtenir la trame ? 
//matrice['A']['J']['N'] = "AJ1" donc l'utilisation simple de la matrice avec des variables donne directement la trame.
//On aurait surtout besoin d'une fonction qui initialise la matrice et qui la remplisse. 


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



    //Appel de la fonction 2 pour obtenir le caractère correspondant aux booléens 
    char char_piece = F2_piece(bool_cuisine, bool_salon, bool_chambre, bool_sdb);






    return 0;
}
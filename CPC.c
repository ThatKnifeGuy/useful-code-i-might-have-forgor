#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

char * matrice[5][5][4];


int setup_com(int serial_port)
{

   // Create new termios struc, we call it 'tty' for convention
  struct termios tty;

  // Read in existing settings, and handle any error
  if(tcgetattr(serial_port, &tty) != 0) {
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
      return 1;
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO; // Disable echo
  tty.c_lflag &= ~ECHOE; // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
  tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
  // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
  // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

  tty.c_cc[VTIME] = 200;    // Wait for up to 20s (200 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  // Set in/out baud rate to be 9600
  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);
  sleep(1);

  // Save tty settings, also checking for error
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
  sleep(1);
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
      return 1;
  }
  sleep(1);

  return 0;

}


void envoyer_trame(char *trame,int serial_port)
{
 
   // Open the serial port. Change device path as needed (currently set to an standard FTDI USB-UART cable type device)


  sleep(1);

  write(serial_port, trame, sizeof(trame));
  sleep(1);

}


int lire_com(char *read_buf, int serial_port)
{
  read_buf[0]='\0';
  sleep(1);
  memset(read_buf, '\0', sizeof(read_buf));

  int num_bytes = read(serial_port, read_buf, sizeof(read_buf));

  if (num_bytes < 0) {
      printf("Error reading: %s", strerror(errno));
      return 1;
  }

  //printf("Read %i bytes. Received message: %s\n", num_bytes, buf);

  fflush(stdin);
  return 0;
}



bool recherche_mot(const char tableau[][25], const char phrase[150])
{
    int i = 0;

    char *resultat = NULL;
    char *fin = NULL;

  	while(resultat == NULL && fin == NULL)
  	{
        resultat = strstr(phrase, tableau[i]);
        fin = strstr(tableau[i], "fin");
        i++;

        if (resultat != NULL)
        {
            return true;
        }

    } 
    return false;
}



char recherche_piece(bool cuisine, bool salon, bool chambre, bool sdb)
{
	if (!cuisine && !salon && !chambre && sdb)
    {
    	//PIECE = SALLE DE BAIN (N)
        //printf("PIECE SALLE DE BAIN\n");
        return 'N';
    }
    else if (!cuisine && !salon && chambre && !sdb)
    {
    	//PIECE = CHAMBRE (M)
    	//printf("PIECE CHAMBRE\n");
    	return 'M';
    }
    else if (!cuisine && salon && !chambre && !sdb)
    {
    	//PIECE = SALON (L)
    	//printf("PIECE SALON\n");
    	return 'L';
    }
    else if (cuisine && !salon && !chambre && !sdb)
    {
    	//PIECE = CUISINE (K)
    	//printf("PIECE CUISINE\n");
    	return 'K';
    }
    else
    {
    	return 'R';
    }
}

char recherche_composant(bool humidite, bool lumiere, bool temperature, bool volet, bool presence)
{
	if (!humidite && !lumiere && !temperature && !volet && presence)
    {
     	//COMPOSANT = PRESENCE (E)
       	//printf("COMPOSANT PRESENCE\n");
       	return 'E';
    }
    else if (!humidite && !lumiere && !temperature && volet && !presence)
    {
      	//COMPOSANT = VOLET (D)
      	//printf("COMPOSANT VOLET\n");
      	return 'D';
    }
    else if (!humidite && !lumiere && temperature && !volet && !presence)
    {
       	//COMPOSANT = TEMPERATURE (C)
      	//printf("COMPOSANT TEMPERATURE\n");
      	return 'C';
    }
    else if (!humidite && lumiere && !temperature && !volet && !presence)
    {
       	//COMPOSANT = LUMIERE (B)
       	//printf("COMPOSANT LUMIERE\n");
       	return 'B';
    }
    else if (humidite && !lumiere && !temperature && !volet && !presence)
    {
       	//COMPOSANT = HUMIDITE (A)
       	//printf("COMPOSANT HUMIDITE\n");
       	return 'A';
    }
    else
    {
       	return 'P';
    }
}

char recherche_requete(bool allumer, bool eteindre, bool ouvrir, bool fermer, bool demande)
{
	if (!allumer && !eteindre && !ouvrir && !fermer && demande)
    {
       	//REQUETE = QUESTION (J)
      	//printf("REQUETE QUESTION\n");
      	return 'J';
    }
    else if (!allumer && !eteindre && !ouvrir && fermer && !demande)
    {
      	//REQUETE = FERMER (I)
      	//printf("REQUETE FERMER\n");
      	return 'I';
    }
    else if (!allumer && !eteindre && ouvrir && !fermer && !demande)
    {
      	//REQUETE = OUVRIR (H)
     	//printf("REQUETE OUVRIR\n");
     	return 'H';
    }
    else if (!allumer && eteindre && !ouvrir && !fermer && !demande)
    {
      	//REQUETE = ETEINDRE (G)
       	//printf("REQUETE ETEINDRE\n");
       	printf("bingo \n");
       	return 'G';
    }
    else if (allumer && !eteindre && !ouvrir && !fermer && !demande)
    {
      	//REQUETE = ALLUMER (F)
       	//printf("REQUETE ALLUMER\n");
       	return 'F';
    }
    else
    {
      	return 'Q';
    }
}

int main(int argc, char const *argv[])
{
  system("clear");

  int serial_port = open("/dev/ttyACM0", O_RDWR);
  char read_buf [256];
  setup_com(serial_port);

  
 
  
	while (1)
	{
      char *trame = NULL;
		  char phraseEntree[150];
      char phraseEntreeCOPIE[150];
      char phraseEntreeTentativeN2[150];
		  char piece = 'Z';
      char composant = 'Z';
      char requete = 'Z';

        // Mot clés pour les pièces (cuisine, salon, chambre et salle de bain)
		  const char motClePieceCuisine[][25] = {"cuisine", "Cuisine", "uisine", "cuisin", "kitchen", "fin"};
      const char motClePieceSalon[][25] = {"salon", "Salon", "alon", "sallon", "Sallon", "dsalon", "fin"};
      const char motClePieceChambre[][25] = {"chambre", "Chambre", "cambre", "hambre", "chanbre", "chambbre", "fin"};
      const char motClePieceSDB[][25] = {"salle de bain", "Salle de bain", "Salle de Bain", "salle de Bain", "sdb", "SDB", "salle d'eau", "Salle d'eau", "fin"};
      const char lexiqueLumiere[][25] = {"lumiere", "lumière", "Lumiere", "Lumière", "lampe", "Lampe", "ampoule", "luminaire", "Ampoule", "Luminaire", "Lustre", "lustre", "LED", "led", "fin"};
      const char lexiqueTemperature[][25] = {"temperature", "Temperature", "température", "Température", "temp", "chaleur", "chaud", "froid", "degre", "degres", "degrees", "fin"};
      const char lexiqueVolet[][25] = {"volet", "store", "rideau", "Volet", "Store", "Rideau", "Rideau roulant", "volet roulant", "fin"};
      const char lexiquePresence[][25] = {"quelqu'un", "Quelqu'un", "Quelque chose", "quelque chose", "presence", "présence", "mouvement", "Presence", "Présence", "Mouvement", "mouvment", "fin"};
      const char lexiqueHumidite[][25] = {"humidité", "Humidité", "humidite", "humiditée", "humiditee", "fin"};
      const char motCleActionON[][25] = {"Allumer", "allumer", "Alumer", "alumer", "Allumé", "allumé", "allume", "Allume", " ON ", " on ", "mettre en route", "met en route", "demarre", "démarre", "Démarre", "Demarre", "fin"};
      const char motCleActionOFF[][25] = {"Eteindre", "eteindre", "éteindre", "eteind", "Eteind", "Eteinds", "stop", "arrete", "Arrete", "Arrête", "arrête", "OFF", "off", "met hors-tension", "hors tension", "hors-tension", "fin"};
      const char motCleActionOuvrir[][25] = {"Ouvre", "ouvre", "Ouvrir", "ouvrir", "Ovrire", "ouvr", "fin"};
      const char motCleActionFermer[][25] = {"Ferme", "ferme", "Fermer", "fermer", "fermé", "Fermé", "Fermez", "fermez", "fin"};
      const char motCleActionDemande[][25] = {"Combien", "combien", "Quelle est", "quelle est", "Pourcentage", "pourcentage", "fait il", "fait-il", "Est-ce qu'il y a", "est-ce qu'il y a", "Est ce qu'il y a", "est ce qu'il y a", "Il y a t-il", "il y a t il", "?", "fin"};

      bool pieceCuisine = false;
      bool pieceSalon = false;
      bool pieceChambre = false; 
		  bool pieceSDB = false;
      bool composantLumiere = false;
      bool composantTemp = false;
      bool composantVolet = false;
      bool composantPresence = false;
      bool composantHumidite = false;
      bool actionAllumer = false;
      bool actionEteindre = false;
      bool actionOuvrir = false;
      bool actionFermer = false;
      bool actionDemande = false;

      char trame_neant[]="NEANT";
      char trame_ZZZ[]="ZZZ";


      for (int i = 0 ; i<5 ; i++)
      {
        for (int j = 0 ; j<5 ; j++)
        {
          for (int k = 0 ; k<4 ; k++)
          {
            matrice[i][j][k]=trame_neant; 
          }
        }
        
      }



      matrice['A'-'A']['J'-'F']['K'-'K']=trame_ZZZ;
      matrice['A'-'A']['J'-'F']['L'-'K']=trame_ZZZ;
      matrice['A'-'A']['J'-'F']['M'-'K']=trame_ZZZ;
      matrice['A'-'A']['J'-'F']['N'-'K']="AJ1\r";

      matrice['B'-'A']['F'-'F']['K'-'K']="BF1\r";
      matrice['B'-'A']['F'-'F']['L'-'K']=trame_ZZZ;
      matrice['B'-'A']['F'-'F']['M'-'K']="BF2\r";
      matrice['B'-'A']['F'-'F']['N'-'K']="BF3\r";

      matrice['B'-'A']['G'-'F']['K'-'K']="BG1\r";
      matrice['B'-'A']['G'-'F']['L'-'K']=trame_ZZZ;
      matrice['B'-'A']['G'-'F']['M'-'K']="BG2\r";
      matrice['B'-'A']['G'-'F']['N'-'K']="BG3\r";

      matrice['C'-'A']['J'-'F']['K'-'K']=trame_ZZZ;
      matrice['C'-'A']['J'-'F']['L'-'K']="CJ1\r";
      matrice['C'-'A']['J'-'F']['M'-'K']="CJ2\r";
      matrice['C'-'A']['J'-'F']['N'-'K']=trame_ZZZ;

      matrice['D'-'A']['H'-'F']['K'-'K']=trame_ZZZ;
      matrice['D'-'A']['H'-'F']['L'-'K']="DH1\r";
      matrice['D'-'A']['H'-'F']['M'-'K']=trame_ZZZ;
      matrice['D'-'A']['H'-'F']['N'-'K']=trame_ZZZ;

      matrice['D'-'A']['I'-'F']['K'-'K']=trame_ZZZ;
      matrice['D'-'A']['I'-'F']['L'-'K']="DI1\r";
      matrice['D'-'A']['I'-'F']['M'-'K']=trame_ZZZ;
      matrice['D'-'A']['I'-'F']['N'-'K']=trame_ZZZ;

      matrice['E'-'A']['J'-'F']['K'-'K']=trame_ZZZ;
      matrice['E'-'A']['J'-'F']['L'-'K']="EJ1\r";
      matrice['E'-'A']['J'-'F']['M'-'K']=trame_ZZZ;
      matrice['E'-'A']['J'-'F']['N'-'K']=trame_ZZZ;

    
      printf("Bonjour, que puis-je faire pour vous ? \n");
		  fgets(phraseEntree,150,stdin);

     //   printf("Depart : Etat pieceCuisine : %d\n, Etat pieceSalon : %d\n, tat pieceChambre %d\n, Etat pieceSDB : %d\n, Etat composantLumiere : %d\n, Etat composantTemp : %d\n, Etat composantVolet : %d\n, Etat composantPresence : %d\n, Etat composantHumidite : %d\n, Etat actionAllumer : %d\n, Etat actionEteindre : %d\n, Etat actionOuvrir : %d\n, Etat actionFermer : %d\n, Etat actionDemande : %d\n", pieceCuisine, pieceSalon, pieceChambre, pieceSDB, composantLumiere, composantTemp, composantVolet, composantPresence, composantHumidite, actionAllumer, actionEteindre, actionOuvrir, actionFermer, actionDemande);

        //Copie de la phrase initiale
      strcpy(phraseEntreeCOPIE, phraseEntree);

        //Recherche des lettres correspondantes aux pieces, composant et requete en fonction des booléens
      do
      {
        	pieceCuisine = recherche_mot(motClePieceCuisine, phraseEntree);
        	pieceSalon = recherche_mot(motClePieceSalon, phraseEntree);
        	pieceChambre = recherche_mot(motClePieceChambre, phraseEntree);
        	pieceSDB = recherche_mot(motClePieceSDB, phraseEntree);

      
        	piece = recherche_piece(pieceCuisine, pieceSalon, pieceChambre, pieceSDB);

        	if (piece == 'R')
        	{
              printf("Précisez la pièce : \n");
              fflush(stdin);
              fgets(phraseEntreeTentativeN2,150,stdin);
              strcpy(phraseEntree, phraseEntreeTentativeN2);
        	}
        } while (piece == 'R');
        
        strcpy(phraseEntree, phraseEntreeCOPIE); //Remise en place de la phrase d'origine pour continuer son traitement

        do
        {

        	 composantLumiere = recherche_mot(lexiqueLumiere, phraseEntree);
	         composantTemp = recherche_mot(lexiqueTemperature, phraseEntree);
	         composantVolet = recherche_mot(lexiqueVolet, phraseEntree);
	         composantPresence = recherche_mot(lexiquePresence, phraseEntree);
	         composantHumidite = recherche_mot(lexiqueHumidite, phraseEntree);      

        	 composant = recherche_composant(composantHumidite, composantLumiere, composantTemp, composantVolet, composantPresence);

        	 if (composant == 'P')
        	 {
                printf("Précisez le composant : \n");
                fflush(stdin);
                fgets(phraseEntreeTentativeN2,150,stdin);
                strcpy(phraseEntree, phraseEntreeTentativeN2);
            }
          } while (composant == 'P');

        strcpy(phraseEntree, phraseEntreeCOPIE); //Remise en place de la phrase d'origine pour continuer son traitement

        do
        {
        	 actionAllumer = recherche_mot(motCleActionON, phraseEntree);
	         actionEteindre = recherche_mot(motCleActionOFF, phraseEntree);
	         actionOuvrir = recherche_mot(motCleActionOuvrir, phraseEntree);
	         actionFermer = recherche_mot(motCleActionFermer, phraseEntree);
	         actionDemande = recherche_mot(motCleActionDemande, phraseEntree);

        	 requete = recherche_requete(actionAllumer, actionEteindre, actionOuvrir, actionFermer, actionDemande);

        	 if (requete == 'Q')
        	 {
                printf("Précisez de le type de votre demande : \n");
                fflush(stdin);
                fgets(phraseEntreeTentativeN2,150,stdin);
                strcpy(phraseEntree, phraseEntreeTentativeN2);
        	 }
        } while (requete == 'Q');


        if (strstr(matrice[composant-'A'][requete-'F'][piece-'K'],"ZZZ") != NULL)
        {
          printf("Aucun capteur de ce type dans la pièce demandée. Veuillez reformuler votre question en changeant la pièce. \n\n\n");

        }
        else if (strstr(matrice[composant-'A'][requete-'F'][piece-'K'],"NEANT") != NULL)
        {
          printf("Veuillez reformuler votre phrase \n\n\n");

        }
        else
        {

        trame = matrice[composant-'A'][requete-'F'][piece-'K'];

        printf(" J'envoie la trame %s \n\n\n", trame);
        envoyer_trame(trame,serial_port);

        }
        
    }
}
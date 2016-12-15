// Importation des librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

// Importation des programmes annexes
#include "getch.c"
#include "affiDyn.c"
#include "menustats.c"
#include "writestats.c"
#include "termsaver1.c"
#include "termsaver2.c"
#include "termsaver3.c"

int main(int argc, char *argv[]) {
	
	int cdr;
	char imgname[16];
		
	// Vide la console
	system("clear");
		
	// Génération de 2 chiffres aléatoires
	srand(time(NULL));
	int rdm = rand() % 3;
	int rdmimg = (rand() % 5) + 1;
	
	// Si on ne lance que ./exiasaver, un écran aléatoire est chargé
	if(argc == 1) {
		if(rdm == 0) {
			// Enregistre dans l'historique
			writeHistory("statique");
			// Affiche l'écran de veille statique
			sprintf(imgname, "screens/img%d.pbm", rdmimg);
			cdr = afficheImage(imgname);
		}
		else if(rdm == 1) {
			// Enregistre dans l'historique
			writeHistory("dynamique");
			// Affiche l'écran de veille dynamique
			cdr = dynamique();
		}
		else if(rdm == 2) {
			// Enregistre dans l'historique
			writeHistory("interactif");
			// Affiche l'écran de veille interactif
			cdr = inter();
		}
		else {
			printf("ERREUR, Nombre aléatoire incorrect\n");
			return 1;
		}
	}
	// ./exiasaver a un argument (-stats, -statique, -dynamique, -interactif)
	else if(argc == 2) {
		if(strcmp(argv[1], "-stats") == 0) {
			// Ouvre le menu des statistiques
			cdr = statsMenu();
		}
		else if(strcmp(argv[1], "-statique") == 0) {
			// Enregistre dans l'historique
			writeHistory("statique");
			// Affiche l'écran de veille statique
			sprintf(imgname, "screens/img%d.pbm", rdmimg);
			cdr = afficheImage(imgname);
		}
		else if(strcmp(argv[1], "-dynamique") == 0) {
			// Enregistre dans l'historique
			writeHistory("dynamique");
			// Affiche l'écran de veille dynamique			
			cdr = dynamique();
		}
		else if(strcmp(argv[1], "-interactif") == 0) {
			// Enregistre dans l'historique
			writeHistory("interactif");		
			// Affiche l'écran de veille interactif
			cdr = inter();
		}
		// Erreur si le nom de l'argument n'existe pas	
		else {
			printf("Argument invalide\n");
			return 1;
		}
	}
	// Erreur si ils y a plus de 2 d'arguments
	else {
		printf("Nombre d'arguments invalide\n");
		return 1;
	}
	// Retourne un code d'erreur 1 lors d'un problème et 0 lorsque tout fonctionne
	return cdr;
}

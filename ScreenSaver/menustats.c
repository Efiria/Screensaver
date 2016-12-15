int statsMenu() {
	
	// Bouton du clavier initialiser avec un caractère vide
	char key = '\0';
	// Tableau contenant les caractères (100 max) d'une ligne 
	char txt[100];
	
	// Ouverture du fichier d'historique
	FILE * statsFile = NULL;
	statsFile = fopen("historique.txt", "r");
	
	// Affichage du menu tant que le bon bouton n'a pas été appuyer
	while(key == '\0') {
		printf("Menu des statistiques :\n\n");
		printf("(A)fficher les statistiques\n");
		printf("(Q)uitter le menu\n");
		printf("\n");
		
		// Récupération du bouton appuyer dans la variable
		key = getch();
		
		if((key == 'a')||(key == 'A')) {
			// Lecture ligne par ligne du fichier jusqu'à sa fin
			if(statsFile != NULL) {
				while(fgets(txt, 100, statsFile) != NULL) {
					// Affichage des lignes dans le terminale
					printf("%s", txt);
				}
			}
		}
		// Fin du programme si la touche Q est appuyé
		else if((key == 'q')||(key == 'Q')) {
			break;
		}
		// Retour au début du menu si la touche est incorrect
		else {
			system("clear");
			key = '\0';
			continue;
		}
	}
	// Fermeture du fichier
	fclose(statsFile);
	return 0;
	
}

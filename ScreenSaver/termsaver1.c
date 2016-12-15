int afficheImage(char *filename) {
	int i = 1000, j, larg = 0, haut = 0, tmp = 0, imax;
	char ascii[i];
	
	// Récupération de la taille du terminal
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	// Ouverture de l'image
        FILE * file = NULL;
        file = fopen(filename, "r");
	
	if(file != NULL) {
		i = 0;
		// Lecture en boucle caractère par caractère jusqu'à la fin du fichier
		while(ascii[i] != EOF) {
			ascii[i] = fgetc(file);
			// Conversion des 1 en # et incrémentation d'une colonne
			if(ascii[i] == '1') {
				ascii[i] = 35;
				tmp++;
			}
			// Conversion des 0 en vide et incrémentation d'une colonne
			else if(ascii[i] == '0') {
				ascii[i] = 32;
				tmp++;
			}
			// Incrémentation d'une ligne
			else if (ascii[i] == '\n') {
				haut++;
				larg = tmp;
				tmp = 0;
			}
			i++;
		}
		// Affectation du nombre total/maximum de caractère
		imax = i;
		
		fclose(file);
		// Centrage de la première ligne
		for(j = 0; j < ((w.ws_row - larg) / 2); j++) {
			printf("\n");
		}
		for(j = 0; j < ((w.ws_col - haut) / 2); j++) {
			printf(" ");
		}
		// Affichage des caractères
		for(i = 0; i < imax; i++) {
			if(ascii[i] == 35) {
				printf("%c", (char)ascii[i]);
			}
			else if(ascii[i] == 32) {
				printf("%c", (char)ascii[i]);
			}
			// Saut de ligne et centrage de la ligne suivante
			else if (ascii[i] == '\n') {
				printf("%c", (char)ascii[i]);
				for(j = 0; j < ((w.ws_col - haut) / 2); j++) {
					printf(" ");
				}
			}
		}
	}
	else {
		printf("Erreur lors de l'ouverture du fichier %s\n", filename);
		return 1;
	}
	printf("\n");
	// Attente d'un caractère avant la fermeture du programme
	getch();
	return 0;
}

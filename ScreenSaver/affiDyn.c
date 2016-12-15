int afficheChiffre(char *filename) {
	
	// Nombre maximum de caractères dans le fichier
	int i = 1000;
	// Tableau contenant les caractères
	char ascii[i];
	
	// Ouverture du fichier
        FILE * file = NULL;
        file = fopen(filename, "r");
	
	if(file != NULL) {
		i = 0;
		// Lecture, affichage et conversion caractère par caractère
		while(ascii[i] != EOF) {
			// Récupération du caractère dans le tableau
			ascii[i] = fgetc(file);
			if(ascii[i] == '1') {
				ascii[i] = 35;
				printf("%c", (char)ascii[i]);
			}
			else if(ascii[i] == '0') {
				ascii[i] = 32;
				printf("%c", (char)ascii[i]);
			}
			else if (ascii[i] == '\n') {
				printf("%c", (char)ascii[i]);
			}
			else {
				break;	
			}
			i++;
		}
		// Fermeture du fichier
		fclose(file);
	}
	else {
		printf("Erreur lors de l'ouverture du fichier %s\n", filename);
		return 1;
	}
	return 0;
}

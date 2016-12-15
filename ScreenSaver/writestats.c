// Argument contenant le type d'écran qui a été réaliser
void writeHistory(char *type) {
	
	// Récupération de la date et l'heure courante
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant = *localtime(&secondes);

	// Ouverture du fichier d'historique
	FILE * statsFile = NULL;
	statsFile = fopen("historique.txt", "a+");
	
	// Ecriture de l'historique dans le fichier
	if(statsFile != NULL) {
		fprintf(statsFile,"%d/%d %d:%d:%d %s\n", instant.tm_mday, instant.tm_mon+1, instant.tm_hour, instant.tm_min, instant.tm_sec, type);
	
		//
		fclose(statsFile);
	}
}

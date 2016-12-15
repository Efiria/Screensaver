//Variable pour la direction de lavion
struct avion {
    int direction;
    int vary;
    int varx;
} avion;
char stavion[3] = "000";
//Varibale pour la console
int maxx;
int maxy;
 
//Declaration des fonctions
int setPosition();
int afficherAvion();
int consoleaffiche();
 
 
int inter() {
    //Structure pour recuperer la taille de la console
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   
    maxy = w.ws_row ; //On recupere la valeur max des lignes
    maxx = w.ws_col ; //Valeur max des colones
    avion.varx = (maxx - sizeof(avion)) / 2; //Aligner au milieu en fonction de la taille de la console et de l'avion en largeur
    avion.vary = (maxy / 2); //Aligne en hauteur en fonction de la taille de la console
   
    //Debut du programme
    consoleaffiche();
   
    return 0;
}
 
int consoleaffiche() { 
   
    int lancement = 0;
   
    //Creation de la variable aleatoire pour le positionement de lavion
    srand(time(NULL));
    int pdebut = rand() %4;
    printf("%d\n", pdebut);
   
    //Comparaison en fonction de la
    if (pdebut == 0) avion.direction = 1;
	else if (pdebut == 1)  avion.direction = 2;
        else if (pdebut == 2)  avion.direction = 3;
        else if (pdebut == 3)  avion.direction = 4;
    setPosition(avion.direction,lancement);
   
    //On lance la boucle pour faire bouger l'avion
    lancement = 1;
 
  while(1) {
 
    //On recupere la valeur que l'utilisateur a ecrit
    char input = getch();
   
    //On compare afin de savoir qu'elle est le caractere ecrit
    if (input == 'z') avion.direction = 1 ;
        else if (input == 's') avion.direction = 2 ;
        else if (input == 'q') avion.direction = 3 ;
        else if (input == 'd') avion.direction = 4 ;
        else if (input == 'x') {
            system("clear");
            return 0;
        }
   
    setPosition(avion.direction,lancement);
  }
 
  return 0;
}
 
int setPosition(int vDirection, int vlancement) {
//Fonction qui va permettre de changer la position de l'avion
 
//Si on est dans la boucle on peut le deplacer
if (vlancement == 1) {
    switch(vDirection) {
        case 1 :
            //Vers le haut
            if (avion.vary > 0) {
                avion.vary --;
                //Si on touche le haut de la console
                if (avion.vary == 0) avion.vary = maxy;
            }
            break;
        case 2 :
            //Vers le bas
            if (avion.vary <= maxy) {
                avion.vary ++;
                //Si on touche le bas on l'envoi en haut
                if (avion.vary == maxy) avion.vary = 0;
            }
            break;
        case 3 :
            //Vers la gauche
            if (avion.varx > 0) {
                avion.varx --;
                //Si on touche le bord de gauche on l'envoi a droite
                if  (avion.varx == 0) avion.varx = maxx;
            }
            break;
        case 4 :
            //Vers la droite
            if (avion.varx <= maxx) {
                avion.varx ++;
                //Si on touche a droite on envoi a gauche
                if (avion.varx == maxx) avion.varx = 1;
            }
            break;
    }
  }
   
    //On affiche l'avion
    afficherAvion(vDirection);
 
    return 0;
}
 
int afficherAvion(int affichage) {
   
    system("clear");   
 
   
    //Permet de deplacer le curseur avec x et y comme valeurs
    printf("\033[%d;%dH", avion.vary, avion.varx);
    printf("%s\n", stavion);
 
    switch (affichage) {
        case 1 :
            //On le passe en position haute.
            printf("\033[%d;%dH", avion.vary - 2, avion.varx + 1);
            printf("0\n");
   
            printf("\033[%d;%dH", avion.vary - 1, avion.varx + 1);
            printf("0\n");
 
            break;
        case 2 :
            //On le passe en position basse
            printf("\033[%d;%dH", avion.vary + 2, avion.varx + 1);
            printf("0\n");
   
            printf("\033[%d;%dH", avion.vary + 1, avion.varx + 1);
            printf("0\n");
            break;
        case 3 :
            //On le passe en position gauche
            printf("\033[%d;%dH", avion.vary - 1, avion.varx + 2);
            printf("0\n");
   
            printf("\033[%d;%dH", avion.vary + 1, avion.varx + 2);
            printf("0\n");
            break;
        case 4 :
            //On le passe en position droite
            printf("\033[%d;%dH", avion.vary - 1, avion.varx);
            printf("0\n");
   
            printf("\033[%d;%dH", avion.vary + 1, avion.varx);
            printf("0\n");
            break;
    }
   
    return 0;
 

    }


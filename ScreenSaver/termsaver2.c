int dynamique() {
    char num[8];
    char file[5];
    char vide1; // Cette variable va nous servir à afficher le 0 lorsque l'heure est inférieur à 10.
    char vide2; // Cette variable va nous servir à afficher le 0 lorsque la minute est inférieur à 10.
    char vide3; // Cette variable va nous servir à afficher le 0 lorsque la saconde est inférieur à 10.
 
    int i;  // Cette variable va nous servir pour pouvoir parcourir le tableau num[].
    int nb; // Cette variable contient le chiffre de type entier
    int cdr; // Cette variable contient le code de retour
    int n;  // Cette variable va nous servir à déterminer le nombre de seconde avant l'actualisation de l'heure.
    printf("Temps d'actualisation en secondes: ");
    scanf("%d", &n); // on détermine n.
    system("clear"); // permet d'éffacer tout ce qu'il y a dans le terminal avant que seul l'heure soit affichée.
   
     
    while(1) { // on répète tant qu'il n'y a pas de break.
       
        vide1 = '\0', vide2 = '\0', vide3 = '\0'; // permet de mettre un carctère vide ::::::: je sais pas à quoi ça sert.
        time_t secondes; // type de variable qui va nous servir à afficher les secondes
        struct tm instant; // structure qui représente un instant avec plusieurs variables qui contient par exemple l'heure, les minutes, les secondes et même la date.
        time(&secondes); //
        instant =*localtime(&secondes); // On remplit les variables contenue dans struct via localtime
       
        if(instant.tm_hour < 10) { // Ceci va nous permettre d'afficher un 0 lorsque l'heure est inférieur à 10, exemple : 09h 10m 10s
         vide1 = '0';
        }
   
        if(instant.tm_min < 10) { // Ceci va nous permettre d'afficher un 0 lorsque la minute est inférieur à 10, exemple : 09h 09m 10s
         vide2 = '0';
        }
       
        if(instant.tm_sec < 10) { // Ceci va nous permettre d'afficher un 0 lorsque la seconde est inférieur à 10, exemple : 09h 09m 09s
         vide3 = '0';
        }
 
        sprintf(num,"%c%d:%c%d:%c%d-", vide1, instant.tm_hour, vide2, instant.tm_min, vide3, instant.tm_sec); // On transforme les variable de type entier l'heure contenue dans struct en char
           
        i = 0; // Pour commencer par le premier caractère.
        while(1) {
            i++; // On incrémente pour lire tous les charactères
            if(num[i] == ':') { // Si on a : alors on affiche l'image corréspondante.
                cdr = afficheChiffre("num/dp.pbm");
            }
            else if(num[i] == '\0') { // Si on a un retour à la ligne, alors on continue la boucle.
                continue;
            }
            else if (num[i] == '-') { // On a mis un - à la fin, cela va nous servir à quitter la boucle.
                break;         
            }
            else {            // Si on un un autre charactère que \0 ou -, alors on affiche l'image corréspondante.
                nb = num[i] - '0'; // On converti le caractère en entier
                sprintf(file, "num/%d.pbm", nb);
                cdr = afficheChiffre(file);
            }
        }
        printf("Ce message sera actualise dans quelques secondes");
 
        for (i = 0; i < n; i++)
        {
             printf(".");
             fflush(stdout);
             sleep(1);
        }
        system("clear");
    }
    return 0;

    }


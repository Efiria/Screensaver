#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128

void afficher_image(FILE *tmps);

int main()
{
    char *imagev = "avion.pbm";
    FILE *tmps = NULL;

    if((tmps = fopen(imagev,"r"))==NULL) {
        fprintf("Le fichier %d existe pas \n", imagev);
        return 1;
    }
    afficher_image(tmps);

    fclose(tmps);

    return 0;
}

void afficher_image(FILE *tmps) {
    char lire_image[MAX_LEN];

    while (fgets(lire_image, sizeof(lire_image), tmps) != NULL) {
        printf("%s", lire_image);
    }
}

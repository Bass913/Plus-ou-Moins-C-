#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int continuerPartie = 1;

    while (continuerPartie)
    {
        int nombreMystere = 0, nombreEntre = 0, nombreCoups = 0;
        int MAX = 100, MIN = 1;
        int choix = 0;
        printf("Menu : \n");
        printf("1 - Facile (1 a 100)\n");
        printf("2 - Moyen (1 a 1000)\n");
        printf("3 - Difficile (1 a 10000)\n");
        printf("Choisis un niveau de difficulte : \n");
        scanf("%d", &choix);

        while (choix < 1 || choix > 3)
        {
            printf("Choisis un niveau qui existe ! \n");
            scanf("%d", &choix);
        }

        switch (choix)
        {
            case 2:
                MAX = 1000;
                break;
            case 3:
                MAX = 10000;
                break;

        }
    // Génération du nombre aléatoire
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */
        do
        {
            // On demande le nombre
            printf("Quel est le nombre ? ");
            scanf("%d", &nombreEntre);
            // On compare le nombre entré avec le nombre mystère
            if (nombreMystere > nombreEntre)
            {
               printf("C'est plus !\n");
               nombreCoups++;
            }
            else if (nombreMystere < nombreEntre)
            {
                printf("C'est moins !\n");
                nombreCoups++;
            }
            else
            {
                printf ("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n", nombreCoups);
            }

        }   while (nombreEntre != nombreMystere);

    printf("Voulez-vous rejouer ? 1/0");
    scanf("%d", &continuerPartie);
    }
    return 0;
}

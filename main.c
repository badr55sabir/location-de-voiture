#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car.h"



void main()
{
    char nomp[50];
    int age;
    int P;
    char nomp1[100];
    int found = 0;
    FILE *np;
    char nompre[50];
    char pass[50];
    char ligne[100];
    int chx;
    int ca;
    int ca1;
    int ca2;
    int ca3;

    char* nomPrenom;
    char* passWord;

    printf("Soyez bienvenue dans notre espace de location.\nVotre confort et satisfaction sont notre priorite\n");
    printf("Veuillez entrer votre nom et prenom: ");
    scanf("%[^\n]s", nompre);
    fflush(stdin);

    np = fopen("np.txt", "a+");
    if (np == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    while (fgets(nomp1, sizeof(nomp1), np) != NULL)
    {
        nomp1[strcspn(nomp1, "\n")] = '\0';


        nomPrenom = strtok(nomp1, ";");
        passWord = strtok(NULL, ";");
        if (nomPrenom && strcmp(nompre, nomPrenom) == 0)
        {
            found = 1;
            break;
        }
    }


    if (!found)
    {
        printf("Vous devez d'abord creer un compte.\n");
        printf("Donnez votre age s'il vous plait :\n");
        scanf("%d",&age);
        fflush(stdin);
        if (age<18)
        {
            printf("vous etes mineur.\n");
        }
        else
        {
            printf("Etes vous dans la periode d'essai ? --> si oui : entrez 1 \t sinon entrez 2 :\n");
            scanf("%d",&P);
            fflush(stdin);
            if(P==1)
            {
                printf("desole, nous ne pouvons pas louer la voiture :\n");

            }
            else
            {
                printf("Doonnez votre mot de passe :\n");
                scanf("%[^\n]s",pass);
                fflush(stdin);
                fprintf(np, "%s;%s\n", nompre, pass);

            }
        }

    }
    else

    {
        do
        {
            fflush(stdin);
            printf("Entrer le password:\n");
            scanf("%[^\n]s",pass);
        }
        while(strcmp(pass, passWord) != 0);


    }


    fclose(np);
  printf("Nous vous souhaitons la bienvenue dans notre espace  de location\n");
    do
    {
        printf("Veuillez choisir ce qui vous convient :\n");
        printf("1-Ajouter une voiture \n");
        printf("2-Afficher une voiture \n");
        printf("3-Supprimer une voiture \n");
        printf("4-Modifier une voiture \n");
        printf("0-Quitter\n");
        printf("Donner votre choix :");
        scanf("%d",&chx);

        switch(chx)
        {


        case 1 :
            printf("Ajouter la voiture selon leur categorie :\n");
            printf("1-Categorie economique\n");
            printf("2-Categorie moyenne\n");
            printf("3-Categorie luxe\n");
            printf("Votre choix : ");
            scanf("%d", &ca);

            switch(ca)
            {
            case 1:
                economi();
                break;
            case 2:
                moyenne();
                break;
            case 3:
                luxe();
                break;
            default:
                printf("Choix invalide\n");
                break;
            }


            break;
        case 2 :

            printf("Afficher la voiture selon leur categorie :\n");
            printf("1-Categorie economique\n");
            printf("2-Categorie moyenne\n");
            printf("3-Categorie luxe\n");
            printf("Votre choix : ");
            scanf("%d", &ca1);

            switch(ca1)
            {
            case 1:
                afficherVoitures1();
                break;
            case 2:
                afficherVoitures2();
                break;
            case 3:
                afficherVoitures3();
                break;

            }


            break;
        case 3 :

            printf("Supprimer la voiture selon leur categorie:\n");
            printf("1-Categorie economique\n");
            printf("2-Categorie moyenne\n");
            printf("3-Categorie luxe\n");
            printf("Votre choix : ");
            scanf("%d", &ca2);

            switch(ca2)
            {
            case 1:
                supprimer_voiture1();
                break;
            case 2:
                supprimer_voiture2();
                break;
            case 3:
                supprimer_voiture3();
                break;


            }
            break;
             case 4 :

            printf("Modifier  la voiture selon leur categorie:\n");
            printf("1-Categorie economique\n");
            printf("2-Categorie moyenne\n");
            printf("3-Categorie luxe\n");
            printf("Votre choix : ");
            scanf("%d", &ca3);

            switch(ca3)
            {
            case 1:
                modifierVoiture1();
                break;
            case 2:
                modifierVoiture2();
                break;
            case 3:
                modifierVoiture3();
                break;


        }
        }
    }
    while(chx!=0);

}

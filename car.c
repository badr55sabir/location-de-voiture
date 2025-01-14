#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car.h"


void economi(void)
{
    FILE *eco;
    voitur vo;
    char marque1[20];
    int tr = 0;


    eco = fopen("economi.CSV", "a+");
    if (eco == NULL)
    {
        printf("erorr.\n");
        return;
    }


    printf("Entrer la marque: ");
    scanf("%19s", marque1);
    fflush(stdin);


    while (fread(&vo, sizeof(vo), 1, eco) == 1)
    {
        if (strcmp(vo.marque, marque1) == 0)
        {
            tr = 1;
            break;
        }
    }

    if (tr)
    {
        printf("La voiture exist.\n");
        fclose(eco);
        return;
    }


    printf("Entrer (ID): ");
    scanf("%d", &vo.ID);
    fflush(stdin);

    printf("Entrer le model: ");
    scanf("%d", &vo.model);
    fflush(stdin);

    printf("Nombre de place: ");
    scanf("%d", &vo.nbredeplace);
    fflush(stdin);

    printf("Prix par jour (DH): ");
    scanf("%f", &vo.prjour);
    fflush(stdin);

    printf("Type de carburant: ");
    scanf("%49s", vo.typca);
    fflush(stdin);

    printf("Automatique ou manuelle: ");
    scanf("%19s", vo.trans);
    fflush(stdin);

    printf("Disponible ou non disponible: ");
    scanf("%19s", vo.dispo);
    fflush(stdin);


    strcpy(vo.marque, marque1);


    fwrite(&vo, sizeof(vo), 1, eco);
    printf("La voiture a ete ajoutee avec succes.\n");


    fclose(eco);
}




void moyenne(void)
{
    FILE *moy;
    voitur vo;
    char marque1[20];
    int tr = 0;


    moy = fopen("moyenne.CSV", "a+");
    if (moy == NULL)
    {
        printf("erorr.\n");
        return;
    }


    printf("Entrer la marque: ");
    scanf("%19s", marque1);
    fflush(stdin);


    while (fread(&vo, sizeof(vo), 1, moy) == 1)
    {
        if (strcmp(vo.marque, marque1) == 0)
        {
            tr = 1;
            break;
        }
    }

    if (tr)
    {
        printf("La voiture exist.\n");
        fclose(moy);
        return;
    }


    printf("Entrer (ID): ");
    scanf("%d", &vo.ID);
    fflush(stdin);

    printf("Entrer le model: ");
    scanf("%d", &vo.model);
    fflush(stdin);

    printf("Nombre de place: ");
    scanf("%d", &vo.nbredeplace);
    fflush(stdin);

    printf("prix par jour (DH): ");
    scanf("%f", &vo.prjour);
    fflush(stdin);

    printf("Type de carburant: ");
    scanf("%49s", vo.typca);
    fflush(stdin);

    printf("Automatique ao manuelle: ");
    scanf("%19s", vo.trans);
    fflush(stdin);

    printf("Disponible ou non disponible: ");
    scanf("%19s", vo.dispo);
    fflush(stdin);


    strcpy(vo.marque, marque1);


    fwrite(&vo, sizeof(vo), 1, moy);
    printf("La voiture a ete ajoutee avec succes.\n");


    fclose(moy);
}






void luxe(void)
{
    FILE *lx;
    voitur vo;
    char marque1[20];
    int tr = 0;


    lx = fopen("luxe.CSV", "a+");
    if (lx == NULL)
    {
        printf("erorr.\n");
        return;
    }


    printf("entrer la marque: ");
    scanf("%19s", marque1);
    fflush(stdin);


    while (fread(&vo, sizeof(vo), 1, lx) == 1)
    {
        if (strcmp(vo.marque, marque1) == 0)
        {
            tr = 1;
            break;
        }
    }

    if (tr)
    {
        printf("La voiture exist.\n");
        fclose(lx);
        return;
    }


    printf("Entrer (ID): ");
    scanf("%d", &vo.ID);
    fflush(stdin);

    printf("Entrer le model: ");
    scanf("%d", &vo.model);
    fflush(stdin);

    printf("Nombre de place: ");
    scanf("%d", &vo.nbredeplace);
    fflush(stdin);

    printf("Prix par jour: ");
    scanf("%f", &vo.prjour);
    fflush(stdin);

    printf("Type de carburant: ");
    scanf("%49s", vo.typca);
    fflush(stdin);

    printf("Automatique ao manuelle: ");
    scanf("%19s", vo.trans);
    fflush(stdin);

    printf("Disponible ou non disponible: ");
    scanf("%19s", vo.dispo);
    fflush(stdin);


    strcpy(vo.marque, marque1);


    fwrite(&vo, sizeof(vo), 1, lx);
    printf("La voiture a ete ajoutee avec succes.\n");


    fclose(lx);
}




void afficherVoitures1(void)
{
    FILE *eco;
    voitur vo;
    int found = 0;

    eco = fopen("economi.CSV", "r");
    if (eco == NULL)
    {
        printf("error.\n");
        return;
    }

    printf("\nles vouiture qui sont disponibles:\n");
    printf("ID  Marque\tModel\tNbr-place\tPrix/Jour\tType-carburant\tauto\manuelle\tDisponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&vo, sizeof(vo), 1, eco) == 1)
    {
        found = 1;
        printf("%d  %s\t%d\t\t%d\t\t%.2f\t\t%s\t\t%s\t\t%s\n", vo.ID, vo.marque, vo.model,vo.nbredeplace, vo.prjour,vo.typca,vo.trans, vo.dispo);
    }

    if (!found)
    {
        printf("n'exist pas.\n");
    }

    fclose(eco);
}




void afficherVoitures2(void)
{
    FILE *moy;
    voitur vo;
    int found = 0;

    moy = fopen("moyenne.CSV", "r");
    if (moy == NULL)
    {
        printf("error.\n");
        return;
    }

    printf("\nles vouiture disponeble:\n");
     printf("ID  Marque\tModel\tNbr-place\tPrix/Jour\tType-carburant\tauto\manuelle\tDisponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    while (fread(&vo, sizeof(vo), 1, moy) == 1)
    {
        found = 1;
        printf("%d  %s\t%d\t\t%d\t\t%.2f\t\t%s\t\t%s\t\t%s\n", vo.ID, vo.marque, vo.model,vo.nbredeplace, vo.prjour,vo.typca,vo.trans, vo.dispo);
    }

    if (!found)
    {
        printf("n'exist pas.\n");
    }

    fclose(moy);
}






void afficherVoitures3(void)
{
    FILE *lx;
    voitur vo;
    int found = 0;

    lx = fopen("luxe.CSV", "r");
    if (lx == NULL)
    {
        printf("error.\n");
        return;
    }

    printf("\nles vouiture disponeble:\n");
     printf("ID  Marque\tModel\tNbr-place\tPrix/Jour\tType-carburant\tauto\manuelle\tDisponibilite\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&vo, sizeof(vo), 1, lx) == 1)
    {
        found = 1;
        printf("%d  %s\t%d\t\t%d\t\t%.2f\t\t%s\t\t%s\t\t%s\n", vo.ID, vo.marque, vo.model,vo.nbredeplace, vo.prjour,vo.typca,vo.trans, vo.dispo);
    }

    if (!found)
    {
        printf("n'exist pas.\n");
    }

    fclose(lx);
}


void supprimer_voiture1(void)
{
    FILE *eco, *temp;
    voitur vo;
    int id_supprimer;
    int trouve = 0;


    eco = fopen("economi.CSV", "r");
    if (eco == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la création du fichier temporaire.\n");
        fclose(eco);
        return;
    }


    printf("Entrer l'ID de la voiture a supprimer: ");
    scanf("%d", &id_supprimer);


    while (fread(&vo, sizeof(vo), 1, eco) == 1)
    {
        if (vo.ID == id_supprimer)
        {
            trouve = 1;
        }
        else
        {

            fwrite(&vo, sizeof(vo), 1, temp);
        }
    }

    fclose(eco);
    fclose(temp);

    if (trouve)
    {

        remove("economi.CSV");
        rename("temp.CSV", "economi.CSV");
        printf("La voiture a ete supprimee avec succes.\n");
    }
    else
    {

        remove("temp.CSV");
        printf("La voiture avec l'ID %d n'existe pas.\n", id_supprimer);
    }
}



void supprimer_voiture2(void)
{
    FILE *moy, *temp;
    voitur vo;
    int id_supprimer;
    int trouve = 0;


    moy = fopen("moyenne.CSV", "r");
    if (moy == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la creation du fichier temporaire.\n");
        fclose(moy);
        return;
    }


    printf("Entrer l'ID de la voiture a supprimer: ");
    scanf("%d", &id_supprimer);


    while (fread(&vo, sizeof(vo), 1, moy) == 1)
    {
        if (vo.ID == id_supprimer)
        {
            trouve = 1;
        }
        else
        {

            fwrite(&vo, sizeof(vo), 1, temp);
        }
    }

    fclose(moy);
    fclose(temp);

    if (trouve)
    {

        remove("moyenne.CSV");
        rename("temp.CSV", "moyenne.CSV");
        printf("La voiture a ete supprimee avec succes.\n");
    }
    else
    {

        remove("temp.CSV");
        printf("La voiture avec l'ID %d n'existe pas.\n", id_supprimer);
    }
}


void supprimer_voiture3(void)
{
    FILE *lx, *temp;
    voitur vo;
    int id_supprimer;
    int trouve = 0;


    lx = fopen("luxe.CSV", "r");
    if (lx == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la creation du fichier temporaire.\n");
        fclose(lx);
        return;
    }


    printf("Entrer l'ID de la voiture a supprimer: ");
    scanf("%d", &id_supprimer);


    while (fread(&vo, sizeof(vo), 1, lx) == 1)
    {
        if (vo.ID == id_supprimer)
        {
            trouve = 1;
        }
        else
        {

            fwrite(&vo, sizeof(vo), 1, temp);
        }
    }

    fclose(lx);
    fclose(temp);

    if (trouve)
    {

        remove("luxe.CSV");
        rename("temp.CSV", "luxe.CSV");
        printf("La voiture a ete supprimee avec succes.\n");
    }
    else
    {

        remove("temp.CSV");
        printf("La voiture avec l'ID %d n'existe pas.\n", id_supprimer);
    }
}






void modifierVoiture1(void)
{
    FILE *eco, *temp;
    voitur vo;
    int id, trouve = 0;

    eco = fopen("economi.CSV", "r");
    if (eco == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la creation du fichier temporaire.\n");
        fclose(eco);
        return;
    }

    printf("Entrer l'ID de la voiture a lmodifier : ");
    scanf("%d", &id);

    while (fread(&vo, sizeof(vo), 1, eco) == 1)
    {
        if (vo.ID == id)
        {
            trouve = 1;

            printf("Modifier les informations de la voiture (ID: %d):\n", vo.ID);

            printf("Entrer la nouvelle marque: ");
            scanf("%19s", vo.marque);

            printf("Entrer le nouveau modèle: ");
            scanf("%d", &vo.model);

            printf("Entrer le nouveau nombre de places: ");
            scanf("%d", &vo.nbredeplace);

            printf("Entrer le nouveau prix par jour: ");
            scanf("%f", &vo.prjour);

            printf("Entrer le nouveau type de carburant: ");
            scanf("%49s", vo.typca);

            printf("Entrer le nouveau type de transmission (automatique/manuelle): ");
            scanf("%19s", vo.trans);

            printf("Entrer la disponibilité (disponible/non disponible): ");
            scanf("%19s", vo.dispo);

            printf("Les informations ont été mises à jour.\n");
        }

        fwrite(&vo, sizeof(vo), 1, temp);
    }

    fclose(eco);
    fclose(temp);

    if (trouve)
    {
        remove("economi.CSV");
        rename("temp.CSV", "economi.CSV");
        printf("Modification enregistrée avec succès.\n");
    }
    else
    {
        remove("temp.CSV");
        printf("Voiture avec l'ID %d non trouvée.\n", id);
    }
}




void modifierVoiture2(void)
{
    FILE *moy, *temp;
    voitur vo;
    int id, trouve = 0;

    moy = fopen("moyenne.CSV", "r");
    if (moy == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la création du fichier temporaire.\n");
        fclose(moy);
        return;
    }

    printf("Entrer l'ID de la voiture à modifier : ");
    scanf("%d", &id);

    while (fread(&vo, sizeof(vo), 1, moy) == 1)
    {
        if (vo.ID == id)
        {
            trouve = 1;

            printf("Modifier les informations de la voiture (ID: %d):\n", vo.ID);

            printf("Entrer la nouvelle marque: ");
            scanf("%19s", vo.marque);

            printf("Entrer le nouveau modèle: ");
            scanf("%d", &vo.model);

            printf("Entrer le nouveau nombre de places: ");
            scanf("%d", &vo.nbredeplace);

            printf("Entrer le nouveau prix par jour: ");
            scanf("%f", &vo.prjour);

            printf("Entrer le nouveau type de carburant: ");
            scanf("%49s", vo.typca);

            printf("Entrer le nouveau type de transmission (automatique/manuelle): ");
            scanf("%19s", vo.trans);

            printf("Entrer la disponibilité (disponible/non disponible): ");
            scanf("%19s", vo.dispo);

            printf("Les informations ont été mises à jour.\n");
        }

        fwrite(&vo, sizeof(vo), 1, temp);
    }

    fclose(moy);
    fclose(temp);

    if (trouve)
    {
        remove("moyenne.CSV");
        rename("temp.CSV", "moyenne.CSV");
        printf("Modification enregistrée avec succès.\n");
    }
    else
    {
        remove("temp.CSV");
        printf("Voiture avec l'ID %d non trouvée.\n", id);
    }
}





void modifierVoiture3(void)
{
    FILE *lx, *temp;
    voitur vo;
    int id, trouve = 0;

    lx = fopen("luxe.CSV", "r");
    if (lx == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    temp = fopen("temp.CSV", "w");
    if (temp == NULL)
    {
        printf("Erreur lors de la création du fichier temporaire.\n");
        fclose(lx);
        return;
    }

    printf("Entrer l'ID de la voiture à modifier : ");
    scanf("%d", &id);

    while (fread(&vo, sizeof(vo), 1, lx) == 1)
    {
        if (vo.ID == id)
        {
            trouve = 1;

            printf("Modifier les informations de la voiture (ID: %d):\n", vo.ID);

            printf("Entrer la nouvelle marque: ");
            scanf("%19s", vo.marque);

            printf("Entrer le nouveau modèle: ");
            scanf("%d", &vo.model);

            printf("Entrer le nouveau nombre de places: ");
            scanf("%d", &vo.nbredeplace);

            printf("Entrer le nouveau prix par jour: ");
            scanf("%f", &vo.prjour);

            printf("Entrer le nouveau type de carburant: ");
            scanf("%49s", vo.typca);

            printf("Entrer le nouveau type de transmission (automatique/manuelle): ");
            scanf("%19s", vo.trans);

            printf("Entrer la disponibilité (disponible/non disponible): ");
            scanf("%19s", vo.dispo);

            printf("Les informations ont été mises à jour.\n");
        }

        fwrite(&vo, sizeof(vo), 1, temp);
    }

    fclose(lx);
    fclose(temp);

    if (trouve)
    {
        remove("luxe.CSV");
        rename("temp.CSV", "luxe.CSV");
        printf("Modification enregistrée avec succès.\n");
    }
    else
    {
        remove("temp.CSV");
        printf("Voiture avec l'ID %d non trouvée.\n", id);
    }
}

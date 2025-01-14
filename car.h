#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

typedef struct
{
    int ID;
    char marque[20];
    int model;
    int nbredeplace;
    float prjour;
    char typca[50];
    char trans[20];
    char dispo[20];
} voitur;


void economi();
void moyenne();
void luxe();
void afficherVoitures1();
void afficherVoitures2();
void afficherVoitures3();
void supprimer_voiture1();
void supprimer_voiture2();
void supprimer_voiture3();
void modifierVoiture1();
void modifierVoiture2();
void modifierVoiture3();

#endif // CAR_H_INCLUDED

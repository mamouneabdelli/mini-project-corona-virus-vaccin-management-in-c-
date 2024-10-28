#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char type[30];
    Date date_prem;
    int nbj;
} Vaccin;

typedef struct {
    char cin[30];
    char nom[30];
    char prenom[30];
    Vaccin vac;
} Citoyen;

#define max 100

void lecture(Citoyen c[max], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("c[%d]\n", i);
        printf("Enter the CIN: ");
        scanf("%s", c[i].cin);
        printf("Enter the name: ");
        scanf("%s", c[i].nom);
        printf("Enter the family name: ");
        scanf("%s", c[i].prenom);
        printf("Enter the type of vaccine: ");
        scanf("%s", c[i].vac.type);
        printf("Enter the vaccination date (day month year): ");
        scanf("%d %d %d", &c[i].vac.date_prem.jour, &c[i].vac.date_prem.mois, &c[i].vac.date_prem.annee);
    }
}

void affichage(Citoyen c[max], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nDetails of Citizen %d:\n", i + 1);
        printf("CIN: %s\n", c[i].cin);
        printf("Name: %s\n", c[i].nom);
        printf("Family Name: %s\n", c[i].prenom);
        printf("Vaccine Type: %s\n", c[i].vac.type);
        printf("Date (DD/MM/YYYY): %02d/%02d/%d\n", c[i].vac.date_prem.jour, c[i].vac.date_prem.mois, c[i].vac.date_prem.annee);
    }
}

void totalVaccin(Citoyen c[max], int n) {
    int i, countAstraZeneca = 0, countSinopharm = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(c[i].vac.type, "AstraZeneca") == 0) {
            countAstraZeneca++;
        } else if (strcmp(c[i].vac.type, "Sinopharm") == 0) {
            countSinopharm++;
        }
    }
    printf("\nTotal AstraZeneca: %d\n", countAstraZeneca);
    printf("Total Sinopharm: %d\n", countSinopharm);
}

void CitoyenVac(Citoyen c[max], int n, char type[30], Citoyen tab[max], int *k) {
    int i;
    *k = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(c[i].vac.type, type) == 0) {  // Corrected strcmp usage
            tab[*k] = c[i];
            (*k)++;
        }
    }
}

int main() {
    int n, k;
    Citoyen citizens[max], selectedCitizens[max];

    printf("Enter the number of citizens: ");
    scanf("%d", &n);

    lecture(citizens, n);
    affichage(citizens, n);
    totalVaccin(citizens, n);

    char vaccineType[30];
    printf("\nEnter vaccine type to filter citizens: ");
    scanf("%s", vaccineType);

    CitoyenVac(citizens, n, vaccineType, selectedCitizens, &k);
    printf("\nCitizens with vaccine type %s:\n", vaccineType);
    affichage(selectedCitizens, k);

    return 0;
}

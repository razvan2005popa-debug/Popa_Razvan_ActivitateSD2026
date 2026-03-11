//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina {
//    int id;
//    int nrUsi;
//    float pret;
//    char* model;
//    char* numeSofer;
//    unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//    //afiseaza toate atributele unei masini
//    printf("\n ID Masina: %d", masina.id);
//    printf("\n nr usi Masina: %d", masina.nrUsi);
//    printf("\n pret Masina: %f", masina.pret);
//    printf("\n model Masina: %s", masina.model);
//    printf("\n nume sofer Masina: %s", masina.numeSofer);
//    printf("\n serie Masina: %c\n", masina.serie);
//
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//    //afiseaza toate elemente de tip masina din vector
//    //prin apelarea functiei afisareMasina()
//    for (int i = 0; i < nrMasini; i++) {
//        afisareMasina(masini[i]);
//    }
//}
//
//void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//    (*nrMasini)++;
//    Masina* aux = malloc(sizeof(Masina) * (*nrMasini));
//    for (int i = 0; i < (*nrMasini-1); i++) {
//        aux[i] = (*masini)[i];//shallow copy
//    }
//    aux[(*nrMasini) - 1] = masinaNoua;
//    free(*masini);
//    *masini = aux;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//    char linie[50];
//    fgets(linie, 50, file);
//    char delim[3] = ",\n";
//    Masina masina;
//    masina.id = atoi(strtok(linie, delim));
//    masina.nrUsi = atoi(strtok(NULL, delim));
//    masina.pret = atof(strtok(NULL, delim));
//
//    char* model = strtok(NULL, delim);
//    masina.model = malloc(strlen(model + 1) * sizeof(char));
//    strcpy(masina.model, model);
//
//    char* numeSofer = strtok(NULL, delim);
//    masina.numeSofer = malloc(strlen(numeSofer + 1) * sizeof(char));
//    strcpy(masina.numeSofer, model);
//
//    char* serie = strtok(NULL, delim);
//    masina.serie = serie[0];
//
//    return masina;
//
//
//
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//    //functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//    //prin apelul repetat al functiei citireMasinaFisier()
//    //numarul de masini este determinat prin numarul de citiri din fisier
//    //ATENTIE - la final inchidem fisierul/stream-ul
//    Masina* masini = NULL;
//    *nrMasiniCitite = 0;
//    FILE* file = fopen(numeFisier, "r");
//    while (!feof(file)) {
//        adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
//    }
//    fclose(file);
//    return masini;
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//    //este dezalocat intreg vectorul de masini
//}
//
//int main() {
//
//    Masina* masini;
//    int nr = 0;
//    masini = citireVectorMasiniFisier("masini.txt", &nr);
//    afisareVectorMasini(masini, nr);
//
//
//    return 0;
//}
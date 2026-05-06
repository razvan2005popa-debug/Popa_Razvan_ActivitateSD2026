//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
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
////creare structura pentru un nod dintr-un arbore binar de cautare
//
//
//typedef struct Nod Nod;
//
//struct Nod {
//    Nod* stanga;
//    Nod* dreapta;
//    Masina masina;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//    char buffer[100];
//    char sep[3] = ",\n";
//    if (!fgets(buffer, 100, file)) {
//        Masina m1;
//        m1.id = -1; // sentinel for EOF / invalid
//        m1.nrUsi = 0;
//        m1.pret = 0;
//        m1.model = NULL;
//        m1.numeSofer = NULL;
//        m1.serie = 0;
//        return m1;
//    }
//    char* aux;
//    Masina m1;
//    aux = strtok(buffer, sep);
//    if (!aux) {
//        m1.id = -1;
//        m1.nrUsi = 0;
//        m1.pret = 0;
//        m1.model = NULL;
//        m1.numeSofer = NULL;
//        m1.serie = 0;
//        return m1;
//    }
//    m1.id = atoi(aux);
//    m1.nrUsi = atoi(strtok(NULL, sep));
//    m1.pret = atof(strtok(NULL, sep));
//    aux = strtok(NULL, sep);
//    m1.model = (char*)malloc(strlen(aux) + 1);
//    strcpy(m1.model, aux);
//
//    aux = strtok(NULL, sep);
//    m1.numeSofer = (char*)malloc(strlen(aux) + 1);
//    strcpy(m1.numeSofer, aux);
//
//    m1.serie = *strtok(NULL, sep);
//    return m1;
//}
//
//void afisareMasina(Masina masina) {
//    printf("Id: %d\n", masina.id);
//    printf("Nr. usi : %d\n", masina.nrUsi);
//    printf("Pret: %.2f\n", masina.pret);
//    printf("Model: %s\n", masina.model);
//    printf("Nume sofer: %s\n", masina.numeSofer);
//    printf("Serie: %c\n\n", masina.serie);
//}
//
//
//void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua) {
//    //adauga o noua masina pe care o primim ca parametru in arbore,
//    //astfel incat sa respecte princiippile de arbore binar de cautare
//    //dupa o anumita cheie pe care o decideti - poate fi ID
//    if ((*radacina) == NULL) {
//        Nod* nou = (Nod*)malloc(sizeof(Nod));
//        nou->masina = masinaNoua;
//        nou->stanga = NULL;
//        nou->dreapta = NULL;
//        (*radacina) = nou;
//        return;
//    }
//
//    if (masinaNoua.id < (*radacina)->masina.id) {
//        adaugaMasinaInArbore(&(*radacina)->stanga, masinaNoua);
//    }
//    else {
//        adaugaMasinaInArbore(&(*radacina)->dreapta, masinaNoua);
//    }
//
//
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    Nod* radacina = NULL;
//    if (!f) {
//        return NULL;
//    }
//    while (1) {
//        Masina m = citireMasinaDinFisier(f);
//        if (m.id == -1) break;
//        adaugaMasinaInArbore(&radacina, m);
//    }
//    fclose(f);
//    return radacina;
//}
//
//void afisareMasiniDinArbore(Nod* radacina) {
//    //afiseaza toate elemente de tip masina din arborele creat
//    //prin apelarea functiei afisareMasina()
//    //parcurgerea arborelui poate fi realizata in TREI moduri
//    //folositi toate cele TREI moduri de parcurgere
//
//    if (radacina) {
//        afisareMasiniDinArbore(radacina->stanga);
//        afisareMasina(radacina->masina);
//        afisareMasiniDinArbore(radacina->dreapta);
//    }
//}
//
//void afisarePostordine(Nod* radacina) {
//    if (radacina) {
//        afisarePostordine(radacina->stanga);
//        afisarePostordine(radacina->dreapta);
//        afisareMasina(radacina->masina);
//
//    }
//}
//
//void dezalocareArboreDeMasini(Nod** radacina) {
//    if (*radacina) {
//        dezalocareArboreDeMasini(&(*radacina)->stanga);
//        dezalocareArboreDeMasini(&(*radacina)->dreapta);
//        free((*radacina)->masina.model);
//        free((*radacina)->masina.numeSofer);
//        free(*radacina);
//        *radacina = NULL;
//    }
//}
//
//Masina getMasinaByID(Nod* radacina, int id) {
//    if (radacina == NULL) {
//        Masina m_goala = { 0, 0, 0, NULL, NULL, 0 };
//        return m_goala;
//    }
//
//    if (radacina->masina.id == id) {
//        // Deep copy pentru a evita problemele de memorie la free
//        Masina m = radacina->masina;
//        m.model = _strdup(radacina->masina.model);
//        m.numeSofer = _strdup(radacina->masina.numeSofer);
//        return m;
//    }
//
//    if (id < radacina->masina.id) {
//        return getMasinaByID(radacina->stanga, id);
//    }
//    else {
//        return getMasinaByID(radacina->dreapta, id);
//    }
//}
//
//int determinaNumarNoduri(Nod* radacina) {
//    //calculeaza numarul total de noduri din arborele binar de cautare
//    if (radacina) {
//        return 1 + determinaNumarNoduri(radacina->stanga) + determinaNumarNoduri(radacina->dreapta);
//    }
//    return 0;
//}
//
//int calculeazaInaltimeArbore(Nod* radacina) {
//    //calculeaza inaltimea arborelui care este data de
//    //lungimea maxima de la radacina pana la cel mai indepartat nod frunza
//    if(radacina == NULL) {
//        return -1;
//    }else{
//		return 1 + max(calculeazaInaltimeArbore(radacina->stanga), calculeazaInaltimeArbore(radacina->dreapta));
//    }
//    return 0;
//}
//
//float calculeazaPretTotal(Nod* radacina) {
//    //calculeaza pretul tuturor masinilor din arbore.
//    if (radacina == NULL) {
//        return 0;
//    }
//    else {
//		float nrStanga = calculeazaPretTotal(radacina->stanga);
//        float nrDreapta = calculeazaPretTotal(radacina->dreapta);
//		return radacina->masina.pret + nrStanga + nrDreapta;
//    }
//    return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*arbore de masini*/ const char* numeSofer) {
//    //calculeaza pretul tuturor masinilor unui sofer.
//    return 0;
//}
//
//int main() {
//    Nod* arbore = citireArboreDeMasiniDinFisier("masiniArbore.txt");
//    afisareMasiniDinArbore(arbore);
//    afisareMasina(getMasinaByID(arbore, 5));
//
//    printf("Numar total de noduri: %d\n", determinaNumarNoduri(arbore));
//
//	printf("Inaltimea arborelui: %d\n", calculeazaInaltimeArbore(arbore));
//
//	printf("Pretul total al masinilor: %.2f\n", calculeazaPretTotal(arbore));
//
//    dezalocareArboreDeMasini(&arbore);
//    return 0;
//}
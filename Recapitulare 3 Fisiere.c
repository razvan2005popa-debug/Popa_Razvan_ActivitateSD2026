//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	//afiseaza toate atributele unei masini
//	printf("\n\nID: %d ", masina.id);
//	printf("\nNrUsi: %d ", masina.nrUsi);
//	printf("\nPret: %5.2f ", masina.pret);
//	printf("\nModel: %s ", masina.model);
//	printf("\nNume sofer: %s ", masina.numeSofer);
//	printf("\nSerie: %c ", masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	//afiseaza toate elemente de tip masina din vector
//	//prin apelarea functiei afisareMasina()
//	if(masini!=NULL)
//	{
//		for (int i = 0; i < nrMasini; i++) {
//			afisareMasina(masini[i]);
//		}
//	}
//}
//
//void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
//	//adauga in vectorul primit o noua masina pe care o primim ca parametru
//	//ATENTIE - se modifica numarul de masini din vector;
//	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i< *nrMasini; i++) {
//		aux[i] = (*masini)[i];
//	}
//	aux[(*nrMasini)] = masinaNoua;
//	free(*masini);
//	*masini = aux;
//	(*nrMasini)++;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	//functia citeste o masina dintr-un strceam deja deschis
//	//masina citita este returnata;
//	Masina m;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//	m.id =atoi(strtok(buffer, sep));
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	m.model = (char*)malloc(sizeof(char) * strlen(aux) + 1);
//	strcpy(m.model, aux);
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(sizeof(char) * strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//	m.serie = strtok(NULL, sep)[0];
//	return m;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaFisier()
//	//numarul de masini este determinat prin numarul de citiri din fisier
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* file = fopen(numeFisier, "r");
//	Masina* masini = NULL;
//	(*nrMasiniCitite) = 0;
//	while (!feof(file)) {
//		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
//	}
//	fclose(file);
//	return masini;
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	//este dezalocat intreg vectorul de masini
//	for (int i = 0; i < *nrMasini; i++) {
//		if(((*vector)[i].model)!=NULL)
//			free((*vector)[i].model);
//		if (((*vector)[i].numeSofer) != NULL)
//			free((*vector)[i].numeSofer);
//	}
//	free(*vector);
//	(*vector) = NULL;
//	(*nrMasini) = 0;
//}
//
//int main() {
//	int nrMasini=0;
//	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
//	afisareVectorMasini(masini,nrMasini);
//
//	return 0;
//}
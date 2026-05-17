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
//
//typedef struct Nod Nod;
//struct Nod {
//    Nod* left;
//    Nod* right;
//    Masina masina;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//int calculeazaInaltimeArbore(Nod* root) {
//	if (root != NULL) {
//		return max(calculeazaInaltimeArbore(root->left), calculeazaInaltimeArbore(root->right)) + 1;
//	}
//	else
//		return 0;
//}
//
////ALTE FUNCTII NECESARE:
//// - aici veti adauga noile functii de care aveti nevoie.
//
//char calculGE(Nod* root) {
//	if (root) {
//		return calculeazaInaltimeArbore(root->left) - calculeazaInaltimeArbore(root->right);
//	}
//	else
//		return 0;
//}
//
//void rotireStanga(Nod** root) {
//	Nod* aux = (*root)->right;
//	(*root)->right = aux->left;
//	aux->left = *root;
//	(*root) = aux;
//}
//
//void rotireDreapta(Nod** root) {
//	Nod* aux = (*root)->left;
//	(*root)->left = aux->right;
//	aux->right = *root;
//	(*root) = aux;
//}
//
//void adaugaMasinaInArboreEchilibrat(Nod** root, Masina masinaNoua) {
//	//adauga o noua masina pe care o primim ca parametru in arbore,
//	//astfel incat sa respecte principiile de arbore binar de cautare ECHILIBRAT
//	//dupa o anumita cheie pe care o decideti - poate fi ID
//	if (*root) {
//		if ((*root)->masina.id > masinaNoua.id) {
//			adaugaMasinaInArboreEchilibrat(&(*root)->left, masinaNoua);
//		}
//		else {
//			adaugaMasinaInArboreEchilibrat(&(*root)->right, masinaNoua);
//		}
//		int grad = calculGE(*root);
//		if (grad == 2) {//dezechilibru in stanga
//			if (calculGE((*root)->left) == 1) {//cazul stanga-stanga
//				rotireDreapta(root);
//			}
//			else {//cazul stanga-dreapta
//				rotireStanga(&(*root)->left);
//				rotireDreapta(root);
//			}
//		}
//		else if (grad == -2) {//dezechilibru in dreapta
//			if (calculGE((*root)->right) == -1) {//cazul dreapta-dreapta
//				rotireStanga(root);
//			}
//			else {//cazul dreapta-stanga
//				rotireDreapta(&(*root)->right);
//				rotireStanga(root);
//			}
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->masina = masinaNoua;
//		nou->left = NULL;
//		nou->right = NULL;
//		(*root) = nou;
//	}
//}
//
//Masina* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f = fopen(numeFisier, "r");
//	Nod* root = NULL;
//	while (!feof(f))
//	{
//		Masina masina = citireMasinaDinFisier(f);
//		adaugaMasinaInArboreEchilibrat(&root, masina);
//	}
//	fclose(f);
//	return root;
//}
//
//void afisareMasiniDinArbore(Nod* root) {
//	//afiseaza toate elemente de tip masina din arborele creat
//	//prin apelarea functiei afisareMasina()
//	//parcurgerea arborelui poate fi realizata in TREI moduri
//	//folositi toate cele TREI moduri de parcurgere
//	if (root) {
//		afisareMasina(root->masina);
//		afisareMasiniDinArbore(root->left);
//		afisareMasiniDinArbore(root->right);
//	}
//}
//
//void dezalocareArboreDeMasini(Nod** root) {
//	//sunt dezalocate toate masinile si arborele de elemente
//	if (*root) {
//		dezalocareArboreDeMasini(&(*root)->left);
//		dezalocareArboreDeMasini(&(*root)->right);
//		free((*root)->masina.model);
//		free((*root)->masina.numeSofer);
//		free(*root);
//		*root = NULL;
//
//	}
//}
//
////Preluati urmatoarele functii din laboratorul precedent.
////Acestea ar trebuie sa functioneze pe noul arbore echilibrat.
//
//Masina getMasinaByID(/*arborele de masini*/int id);
//
//int determinaNumarNoduri(/*arborele de masini*/);
//
//float calculeazaPretTotal(/*arbore de masini*/);
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* root, const char* numeSofer) {
//	float sum = 0;
//	if (root) {
//		sum += calculeazaPretulMasinilorUnuiSofer(root->left, numeSofer);
//		sum += calculeazaPretulMasinilorUnuiSofer(root->right, numeSofer);
//		if (root->masina.numeSofer && strcmp(root->masina.numeSofer, numeSofer) == 0) {
//			sum += root->masina.pret;
//		}
//
//	}
//	return sum;
//}
//
//int main() {
//	Nod *root = citireArboreDeMasiniDinFisier("masini.txt");
//	afisareMasiniDinArbore(root);
//	printf("Pretul total al masinilor soferului Ion Popescu este: %.2f\n", calculeazaPretulMasinilorUnuiSofer(root, "Ionescu"));
//	dezalocareArboreDeMasini(&root);
//
//	return 0;
//}
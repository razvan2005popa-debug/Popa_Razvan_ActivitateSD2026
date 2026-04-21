#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

//STACK
//Alegeti prin ce veti reprezenta stiva si creati structura necesara acestei stive
//putem reprezenta o stiva prin LSI, LDI sau vector

struct Nod {
	Masina info;
	struct Nod* next;
};
typedef struct Nod Nod;
//am ales LSI

void pushStack(Nod** stack, Masina masina) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masina;
	nou->next = *stack;
	*stack = nou;
}

Masina popStack(Nod** stack) {
	Masina masina;
	if (*stack != NULL) {
		Nod* aux = *stack;
		*stack = (*stack)->next;
		masina = aux->info;
		free(aux);
	}
	return masina;
}

void emptyStack(Nod** stack) {
	while (*stack) {
		Nod* aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
}

Nod* citireStackMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	Nod* stack=NULL;
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		pushStack(&stack, citireMasinaDinFisier(f));
	}
	fclose(f);
	return stack;
}

void dezalocareStivaDeMasini(/*stiva*/) {
	//sunt dezalocate toate masinile si stiva de elemente
}

int size(Nod* stack) {
	//returneaza numarul de elemente din stiva
	int dim = 0;
	while (stack) {
		dim++;
		stack = stack->next;
	}
	return dim;
}

//QUEUE
//Alegeti prin ce veti reprezenta coada si creati structura necesara acestei cozi
//putem reprezenta o coada prin LSI, LDI sau vector
void enqueue(/*coada*/ Masina masina) {
	//adauga o masina in coada
}

Masina dequeue(/*coada*/) {
	//extrage o masina din coada
}

void* citireCoadaDeMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
}

void dezalocareCoadaDeMasini(/*coada*/) {
	//sunt dezalocate toate masinile si coada de elemente
}


//metode de procesare
Masina getMasinaByID(/*stiva sau coada de masini*/int id);

float calculeazaPretTotal(/*stiva sau coada de masini*/);

int main() {

	Nod* stiva = citireStackMasiniDinFisier("masini.txt");
	Masina masina = popStack(&stiva);
	afisareMasina(masina);
	printf("\n=-===-=-=-=-==-=-=-==-==--==-=-=\n\n");
	masina = popStack(&stiva);
	afisareMasina(masina);

	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//struct Telefon {
//	int id;
//	int RAM;
//	char* producator;
//	float pret;
//	char serie;
//};
//
//struct Telefon initializare(int id, int RAM, const char* producator, float pret, char serie) {
//	struct Telefon t;
//	t.id = id;
//	t.RAM = RAM;
//	t.producator = (char*)malloc(sizeof(char)*(strlen(producator)+1));
//	strcpy_s(t.producator, strlen(producator) + 1, producator);
//	t.pret = pret;
//	t.serie = serie;
//	return t;
//}
//
//void afisare(struct Telefon t) {
//	printf("\n id: %d", t.id);
//	printf("\n ram: %d", t.RAM);
//	printf("\n producator: %s", t.producator);
//	printf("\n pret: %5.2f", t.pret);
//	printf("\n serie: %c", t.serie);
//}
//
//void modificaPret(struct Telefon* t, float pretnou) {
//	if (pretnou != t->pret && pretnou > 0) {
//		t->pret = pretnou;
//	}
//		
//}
//
//void dezalocare(struct Telefon *t) {
//	if (t->producator != NULL)
//	{
//		free(t->producator);
//		t->producator = NULL;
//	}
//}
//
//int main() {
//	struct Telefon t;
//	t = initializare(1, 256, "samsung", 2000.5, 'A');
//	afisare(t);
//	modificaPret(&t, 2454.3);
//	afisare(t);
//	dezalocare(&t);
//	return 0;
//}
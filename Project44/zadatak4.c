#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct Polinomi;
typedef struct Polinomi* Pozicija;

typedef struct Polinomi {
	int koef;
	int eksp;
	Pozicija next;
}_polinom;
void ucitaj(char[20], Pozicija);
void suma(Pozicija, Pozicija, Pozicija);
void unos(Pozicija, Pozicija);
void rezultat(Pozicija, int, int);
void ispis(Pozicija);

int main() {
	int i = 0;
	_polinom head;
	_polinom prvi;
	_polinom suma;
	head.next = NULL;
	prvi.next = NULL;
	suma.next = NULL;
	ucitaj("polinomi1.txt", &head);
	ucitaj("polinomi2.txt", &prvi);
	ispis(&suma);
}

void ucitaj(char c[20], Pozicija p) {
	FILE* ulz = NULL;
	Pozicija q;
	ulz = fopen(c, "r");
	if (ulz == NULL)
		return -1;
	while (!feof(ulz)) {
		q = (Pozicija)malloc(sizeof(Pozicija));
		fscanf(ulz, "%d %d", q->koef, q->eksp);
		unos(p, q);
	}
}

void unos(Pozicija p, Pozicija q) {
	while (p->next != NULL && p->next->eksp < q->eksp)
		p = p->next;
	q->next = p->next;
	p->next = q;
}


void suma(Pozicija p, Pozicija r, Pozicija q) {
	Pozicija pom;
	while (p != NULL && r != NULL) {
		if (p->eksp == r->eksp) {
			rezultat(q, p->koef + r->koef, p->eksp);
			p = p->next; r = r->next;
		}
		else if (p->eksp > r->eksp) {
			rezultat(q, p->koef, p->eksp); p = p->next;

		}
		else {
			rezultat(q, r->koef, r->eksp); r = r->next;
		}
	}
	if (p != NULL) pom = p;
	else pom = r;
	while (pom != NULL) {
		rezultat(q, pom->koef, pom->eksp);
		pom = pom->next;
	}
}

void rezultat(Pozicija suma, int k, int e) {

	while (suma->next != NULL && suma->next->eksp < suma->eksp)
		suma = suma->next;
	suma->koef = k;
	suma->eksp = e;
}

void ispis(Pozicija p) {
	p = p->next;
	while (p != NULL) {
		printf("%dx %d ", p->koef, p->eksp);
		p = p->next;
	}
}



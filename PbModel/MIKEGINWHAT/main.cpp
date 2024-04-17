#include <iostream>
#include "Functions.h"
int main()
{
	Student b1;
	Student b2;
	b1.setname("Mihaita");
	b1.setengleza(10);
	b1.setmate(7);
	b1.setistorie(5);

	b2.setname("Alexutzu");
	b2.setengleza(9);
	b2.setmate(9);
	b2.setistorie(8);

	printf("Student 1:\n");
	printf("Nume: %s\n", b1.getname());
	printf("Nota Engleza: %d\n", b1.getengleza());
	printf("Nota Mate: %d\n", b1.getmate());
	printf("Nota Istorie: %d\n\n", b1.getistorie());

	printf("Student 2:\n");
	printf("Nume: %s\n", b2.getname());
	printf("Nota Engleza: %d\n", b2.getengleza());
	printf("Nota Mate: %d\n", b2.getmate());
	printf("Nota Istorie: %d\n\n", b2.getistorie());

	printf("Comparatie nume: %d \n", comparename(b1, b2));
	printf("Comparatie nota mate: %d \n", comparemate(b1, b2));
	printf("Comparatie nota engleza: %d \n", compareengleza(b1, b2));
	printf("Comparatie nota istorie: %d \n", compareistorie(b1, b2));
	printf("Comparatie medie: %d \n", comparemedie(b1, b2));

	return 0;
}
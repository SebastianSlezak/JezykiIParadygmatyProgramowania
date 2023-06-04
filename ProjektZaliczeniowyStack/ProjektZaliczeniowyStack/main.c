#include "interfejs.h"
#include "stos.h"

#include <stdio.h>

#pragma warning(disable: 4996)

int main() {
	Stack stack;
	initStack(&stack);

	int option;
	do {
		wyswietlMenu();
		printf("Wybor: ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			dodajStudenta(&stack);
			break;
		case 2:
			pobierzStudenta(&stack);
			break;
		case 3:
			odnajdzStudenta(&stack);
			break;
		case 4:
			zapiszStos(&stack);
			break;
		case 5:
			odczytajStos(&stack);
			break;
		case 6:
			wyswietlStos(&stack);
			break;
		case 7:
			czyscStos(&stack);
			break;
		case 0:
			czyscStos(&stack);
			printf("Koniec programu.\n");
			break;
		default:
			printf("Nieprawidlowy wybor. Sprobuj ponownie.\n");
			break;
		}

		printf("\n");
	} while (option != 0);

	freeStack(&stack);

	return 0;
}

#include "interfejs.h"
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

#pragma warning (disable : 4996)

void wyswietlMenu() {
	printf("======= MENU =======\n");
	printf("1. Dodaj studenta\n");
	printf("2. Pobierz studenta\n");
	printf("3. Odnajdz studenta\n");
	printf("4. Zapisz stos do pliku\n");
	printf("5. Odczytaj stos z pliku\n");
	printf("6. Wyswietl wszystkie elementy stosu\n");
	printf("7. Czysc stos\n");
	printf("0. Wyjscie\n");
	printf("====================\n");
}

void dodajStudenta(Stack* stack) {
	char nazwisko[100];
	int rokUrodzenia;
	int kierunekStudiow;

	printf("Podaj nazwisko studenta: ");
	scanf("%s", nazwisko);
	printf("Podaj rok urodzenia studenta: ");
	scanf("%d", &rokUrodzenia);
	printf("Wybierz kierunek studiow:\n");
	printf("1. Informatyka\n");
	printf("2. Matematyka\n");
	printf("3. Fizyka\n");
	printf("Wybor: ");
	scanf("%d", &kierunekStudiow);

	MY_STUDENT* student = createStudent(nazwisko, rokUrodzenia, kierunekStudiow - 1);
	push(stack, student);
}

void pobierzStudenta(Stack* stack) {
	MY_STUDENT* student = (MY_STUDENT*)pop(stack);
	if (student != NULL) {
		printf("Pobrany student:\n");
		displayStudent(student);
		freeStudent(student);
	}
}

void odnajdzStudenta(Stack* stack) {
	char nazwisko[100];
	printf("Podaj nazwisko studenta do odnalezienia: ");
	scanf("%s", nazwisko);

	StackNode* currentNode = stack->top;
	while (currentNode != NULL) {
		MY_STUDENT* student = (MY_STUDENT*)currentNode->data;
		if (strcmp(student->nazwisko, nazwisko) == 0) {
			printf("Znaleziony student:\n");
			displayStudent(student);
			return;
		}
		currentNode = currentNode->next;
	}

	printf("Nie znaleziono studenta o podanym nazwisku.\n");
}

void zapiszStos(Stack* stack) {
	char fileName[100];
	printf("Podaj nazwe pliku do zapisu: ");
	scanf("%s", fileName);

	FILE* file = fopen(fileName, "wb");
	if (file == NULL) {
		printf("Blad: Nie mozna otworzyc pliku %s\n", fileName);
		return;
	}

	StackNode* currentNode = stack->top;
	while (currentNode != NULL) {
		MY_STUDENT* student = (MY_STUDENT*)currentNode->data;
		fwrite(student->nazwisko, sizeof(char), strlen(student->nazwisko) + 1, file);
		fwrite(&(student->rokUrodzenia), sizeof(int), 1, file);
		fwrite(&(student->kierunekStudiow), sizeof(int), 1, file);
		currentNode = currentNode->next;
	}

	fclose(file);
	printf("Stos zostal zapisany do pliku %s.\n", fileName);
}

void odczytajStos(Stack* stack) {
	char fileName[100];
	printf("Podaj nazwe pliku do odczytu: ");
	scanf("%s", fileName);

	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("Blad: Nie mozna otworzyc pliku %s\n", fileName);
		return;
	}

	MY_STUDENT student;
	while (fread(student.nazwisko, sizeof(char), sizeof(student.nazwisko), file) > 0) {
		fread(&(student.rokUrodzenia), sizeof(int), 1, file);
		fread(&(student.kierunekStudiow), sizeof(int), 1, file);

		MY_STUDENT* newStudent = createStudent(student.nazwisko, student.rokUrodzenia, student.kierunekStudiow);
		if (newStudent != NULL) {
			push(stack, newStudent);
		}
	}

	fclose(file);
	printf("Stos zostal odczytany z pliku %s.\n", fileName);
}

void wyswietlStos(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stos jest pusty.\n");
		return;
	}

	printf("Zawartosc stosu:\n");
	StackNode* currentNode = stack->top;
	while (currentNode != NULL) {
		MY_STUDENT* student = (MY_STUDENT*)currentNode->data;
		displayStudent(student);
		currentNode = currentNode->next;
		printf("\n");
	}
}

void czyscStos(Stack* stack) {
	while (!isEmpty(stack)) {
		MY_STUDENT* student = (MY_STUDENT*)pop(stack);
		freeStudent(student);
	}
	printf("Stos zostal wyczyszczony.\n");
}
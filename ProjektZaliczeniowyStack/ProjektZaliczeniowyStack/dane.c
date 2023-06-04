#include "dane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

MY_STUDENT* createStudent(const char* nazwisko, int rokUrodzenia, int kierunekStudiow) {
	MY_STUDENT* student = (MY_STUDENT*)malloc(sizeof(MY_STUDENT));
	student->nazwisko = (char*)malloc((strlen(nazwisko) + 1) * sizeof(char));
	strcpy(student->nazwisko, nazwisko);
	student->rokUrodzenia = rokUrodzenia;
	student->kierunekStudiow = kierunekStudiow;
	return student;
}

void freeStudent(MY_STUDENT* student) {
	free(student->nazwisko);
	free(student);
}

void displayStudent(MY_STUDENT* student) {
	printf("Nazwisko: %s\n", student->nazwisko);
	printf("Rok urodzenia: %d\n", student->rokUrodzenia);

	const char* kierunkiStudiow[] = { "Informatyka", "Matematyka", "Fizyka" };
	printf("Kierunek studiow: %s\n", kierunkiStudiow[student->kierunekStudiow]);
}

void saveStudentToFile(MY_STUDENT* student, const char* fileName) {
	FILE* file = fopen( fileName, "wb");
	if (file == NULL) {
		printf("Error: Unable to open file %s\n", fileName);
		return;
	}

	fwrite(student, sizeof(MY_STUDENT), 1, file);
	fclose(file);
}

MY_STUDENT* readStudentFromFile(const char* fileName) {
	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("Error: Unable to open file %s\n", fileName);
		return NULL;
	}

	MY_STUDENT* student = (MY_STUDENT*)malloc(sizeof(MY_STUDENT));
	fread(student, sizeof(MY_STUDENT), 1, file);
	fclose(file);

	return student;
}

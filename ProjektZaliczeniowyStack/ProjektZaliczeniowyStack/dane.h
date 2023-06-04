#ifndef DANE_H
#define DANE_H

#pragma warning(disable: 4996)

typedef struct {
	char* nazwisko;
	int rokUrodzenia;
	enum {
		INFORMATYKA,
		MATEMATYKA,
		FIZYKA
	} kierunekStudiow;
} MY_STUDENT;

MY_STUDENT* createStudent(const char* nazwisko, int rokUrodzenia, int kierunekStudiow);
void freeStudent(MY_STUDENT* student);
void displayStudent(MY_STUDENT* student);
void saveStudentToFile(MY_STUDENT* student, const char* fileName);
MY_STUDENT* readStudentFromFile(const char* fileName);

#endif

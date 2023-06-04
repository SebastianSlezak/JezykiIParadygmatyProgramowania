#ifndef INTERFEJS_H
#define INTERFEJS_H

#include "stos.h"
#include "dane.h"

#pragma warning(disable: 4996)

void wyswietlMenu();
void dodajStudenta(Stack* stack);
void pobierzStudenta(Stack* stack);
void odnajdzStudenta(Stack* stack);
void zapiszStos(Stack* stack);
void odczytajStos(Stack* stack);
void wyswietlStos(Stack* stack);

#endif

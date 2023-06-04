#ifndef STOS_H
#define STOS_H

#include "dane.h"

#pragma warning(disable: 4996)

typedef struct StackNode {
	void* data;
	struct StackNode* next;
} StackNode;

typedef struct {
	StackNode* top;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, void* data);
void* pop(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif

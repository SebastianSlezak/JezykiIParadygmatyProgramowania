#include "stos.h"
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

void initStack(Stack* stack) {
	stack->top = NULL;
}

void push(Stack* stack, void* data) {
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

void* pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Blad: Stos jest pusty.\n");
		return NULL;
	}

	StackNode* topNode = stack->top;
	void* data = topNode->data;
	stack->top = topNode->next;
	free(topNode);
	return data;
}

int isEmpty(Stack* stack) {
	return (stack->top == NULL);
}

void freeStack(Stack* stack) {
	while (!isEmpty(stack)) {
		pop(stack);
	}
}

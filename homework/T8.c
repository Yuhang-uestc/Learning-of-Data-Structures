#include<stdio.h>
#include<stdlib>

#define MAX_SIZE 100
typedef struct{
	int data[MAX_SIZE];
	int top;
}Stack;

void InitStack(Stack *s)
{
	s->top = -1;
}

int IsEmpty(Stack *s)
{
	return s->top == -1;
}
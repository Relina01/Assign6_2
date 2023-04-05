#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
typedef int element;

typedef struct
{
	element* data;
	int capacity;
	int top;
} Stack;

void init_stack(Stack* s, int capacity)
{
	s->top = -1;
	s->data = NULL;
	s->capacity = capacity;
}

int is_empty(Stack* s)
{
	return (s->top == -1);
}

int is_full(Stack* s)
{
	return (s->top == (MAX - 1));
}

void push(Stack* s, element item)
{
	if (is_full(s)) {
		if (s->data == NULL) {
			s->data = (element*)malloc(2 * s->capacity * sizeof(element));
		}
		else {
			s->data = (element*)realloc(s->data, 2 * s->capacity * sizeof(element));
		}
		if (s->data == NULL) {
			printf("Memory allocation failed\n");
			exit(1);
		}
		s->capacity *= 2;
	}
	s->top++;
	s->data[s->top] = item;
}

element pop(Stack* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Empty error\n");
		return;
	}
	int data = s->data[s->top];
	s->top--;
	return data;
}

int main()
{
	time_t t = time(NULL);
	unsigned int seed = (unsigned int)t;
	srand(seed);

	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	init_stack(s, MAX);

	for (int i = 0; i < 30; i++)
	{
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0)
		{
			push(s, rand_num);
			printf("push : %d\n", rand_num);
		}
		else
		{
			pop(s);
			printf("pop : %d\n", rand_num);
		}
	}
	free(s);
	return 0;
}
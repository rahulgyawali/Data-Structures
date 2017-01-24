#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
	int top;
	int size;
	int* arr;
};

struct Stack* create (int capacity )
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = capacity;
	stack->arr = (int *)malloc(sizeof(int)*capacity);
	return stack;
}

int empty(struct Stack* stack)
{
	return (stack->top == -1);
}

int full (struct Stack* stack)
{
	return (stack->top == (stack->size - 1));
}

void push (struct Stack* stack,int x)
{
	if (!(full(stack))){
		stack->top = stack->top + 1;
		stack->arr[stack->top] = x;
		printf("%d is PUSHED ON THE STACK\n",stack->arr[stack->top]);
	} else {

		printf("STACK OVERFLOW\n");
		return;
	}

}

int pop (struct Stack* stack)
{
	if(!(empty(stack))) {

		int x;
		x = stack->arr[stack->top];
		stack->top = stack->top - 1;
		printf("%d is POPPED OUT OF STACK\n",x );
		return x;

	} else {

			printf("STACK UNDERFLOW\n");
			return INT_MIN;
	}
}

int peek (struct Stack* stack)
{
	if (!empty(stack))
	{
		return stack->arr[stack->top];
	} else {

        return INT_MIN;
	}
}

int main()
{
	struct Stack* stack = NULL;
	stack = create(3);
	push(stack,10);
	push(stack,11);
	push(stack,12);
	push(stack,13);
	pop(stack);
	printf("%d is PEEK\n",peek(stack));
	pop(stack);
	printf("%d is PEEK\n",peek(stack));
	pop(stack);
	printf("%d is PEEK\n",peek(stack));
	pop(stack);
	return 0;
}

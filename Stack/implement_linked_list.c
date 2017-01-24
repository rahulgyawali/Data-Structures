#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode
{
	int info;
	struct StackNode* link;
};

struct StackNode* newnode(int x)
{
	struct StackNode* temp = (struct StackNode*)malloc(sizeof(StackNode));
	temp->info = x;
	temp->link = NULL;
	return temp;
}


int empty(struct StackNode* root)
{

	return !root;
}

void push (struct StackNode** root, int x)
{ 

		struct StackNode* temp = NULL;
		temp = newnode(x);
		temp->link = *root;
		*root = temp;
		printf("%d IS PUSHED\n",(*root)->info); 
	
}

int pop (struct StackNode** root)
{
	if (empty(*root)) {
		
		printf("STACK UNDERFLOW\n");
		return INT_MIN;
	} 

		struct StackNode* temp;
		int x;
		temp = *root;
		x = temp->info;
		*root = (*root) -> link;
		free(temp);
		printf("%d IS POPPED FROM STACK\n",x);
		return x;
}



int peek (struct StackNode* root)
{	
	if (empty(root))
	{
		return INT_MIN;
	}

	return root->info;
}

int main()
{
	struct StackNode* root = NULL;

	push(&root,10);
	push(&root,11);
	push(&root,12);
	pop(&root);
	printf("%d is TOP\n",peek(root));
	pop(&root);
	printf("%d is TOP\n",peek(root));
	pop(&root);
	printf("%d is TOP\n",peek(root));
	pop(&root);
	return 0;
}
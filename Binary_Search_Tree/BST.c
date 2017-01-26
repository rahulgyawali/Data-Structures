#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;

	struct node* left;

	struct node* right;
};


struct node* new(int);
struct node* add(struct node*,int);
int find_min (struct node*);
int find_max (struct node*);
int search (struct node*,int);
struct node* create(struct node*);
int height (struct node*);
int max(int,int);
struct node* delete(struct node*,int);
void inorder(struct node*);
void postorder(struct node*);
void preorder(struct node*);

struct node* new(int x)
{

	struct node* tmp;

	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = x;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

struct node* add(struct node* root,int  x)
{ 
	if (root == NULL) {

		root = new(x);
	}

	else if (x < (root->info)) {

		root->left = add(root->left,x);
	}

	else if (x > (root -> info)) {
	
		
		root->right = add(root->right,x);
	}


	return root;
}
int find_min (struct node* root)
{

	if(root->left == NULL) {

		return root->info;
	}

	else {	
		return find_min(root->left);

	}	

}

int find_max (struct node* root)
{
	if (root->right == NULL) {

		return root->info;
	}
		
	else {

		return find_max(root->right);
	}

}

int search (struct node* root,int x)
{
	if(root == NULL) {
		
		
		
		return 0;	

	}
	
	else if(root->info == x) {
		
		return 1;
	
	}
	
	else if(x < root->info) {

		return search(root->left,x);
	}

	else {

		return search(root->right,x);
	}
}

struct node* create(struct node* root)
{
	int x;

	int i;

	int n;

	printf("Enter the no. of nodes\n");

	scanf("%d",&n);


	printf("Enter the values of nodes one by one\n");

	for ( i = 0; i < n; i++) {

		scanf("%d",&x);
		
		root = add(root,x);
	}

	return root;

}
int height (struct node* root)
{
	if (root == NULL) {
	
		return -1;
	}

	int  hl = height(root->left);
	
	int hr = height(root->right);

	return (max(hl,hr) + 1);

}

int max(int x,int y)
{
	if(x>y) {

		return x;
	}
	
	else if(y>x) {

		return y;
	}

	else {

		return x;
	}

}

struct node*  delete (struct node* ptr,int key)
{

	struct node* tmp;

	struct node* succ;

	if (ptr == NULL) {		

		printf("Key not found\n");
		
		return ptr;
	
	}

	if (key < ptr->info) {


		ptr->left = delete(ptr->left,key);
	
	}

	else if (key > ptr->info) {

		ptr->right = delete(ptr->right,key);
	}

	else {

		if (ptr->left != NULL && ptr->right != NULL) {
		
			succ  = ptr->right;
	
			while(succ->left) {

				succ = succ->left;
			}
			
			ptr->info = succ->info;
		
			ptr->right = delete(ptr->right,succ->info);
		}

		else {

			tmp  = ptr;
	
			if (ptr->left !=NULL) {
				
					ptr = ptr->left;
				
			}

			else if (ptr->right != NULL) {


					ptr = ptr->right;
			}
		
			else {

				ptr = NULL;
			}
			
			free(tmp);
		}		
	}

	return ptr;
}

void inorder(struct node* root) 
{

	if(root == NULL) {

		return;
	}
	
	inorder(root->left);

	printf("%d ",root->info);

	inorder(root->right);


}
void postorder(struct node* root) 
{

	if(root == NULL) {

		return;
	}
	
	postorder(root->left);

	postorder(root->right);

	printf("%d ",root->info);

}

void preorder(struct node* root) 
{

	if (root == NULL) {

		return;
	}
	
	printf("%d ",root->info);

	preorder(root->left);

	preorder(root->right);


}

int main()
{

struct node* root = NULL;

root = create(root);

printf("Indorder Traversal\n");

inorder(root);

printf("\n");

return 0;

}

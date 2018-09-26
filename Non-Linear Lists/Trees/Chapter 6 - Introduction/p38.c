//Algo to check if binary tree is complete
#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define True 1
#define False 0
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
struct node* stack[10];
int top = -1;
struct node* pop()
{
	return stack[top--];
}
void push(struct node* item)
{
	stack[++top] = item;
}
struct node* createNode(int data)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	return new;
}
int count(struct node *root)
{
	if(root != NULL)
	{
		return 1 + count(root->left) + count(root->right);
	}
	else
		return 0;
}
void preorder(struct node *tree)
{
	if(tree != NULL)
	{
		struct node *new;
		push(tree);
		while(top != -1)
		{
			new = pop();
			printf("%d \n", new->data);
			if(new->right)
				push(new->right);
			if(new->left)
				push(new->left);
		}
	}
	printf("\n");
}

int main()
{
	struct node *l = createNode(5);
	root = l;
	root->left = createNode(54);
	root->right = createNode(65);
	root->left->left = createNode(564);
	root->left->right = createNode(5);
	root->right->right = createNode(5);

	int c;
	c =  count(root);
	printf("number of leaf nodes in the tree: %d\n", c);
	preorder(root);


}

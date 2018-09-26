//Algo to count the number of nodes in a binary tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;

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

int main()
{
	root = createNode(5);
	struct node *l11 = createNode(9), *l12 = createNode(54), *l22 = createNode(32);
	root->left = l11;
	root->right = l12;
	l12->right = l22;
	struct node * new = createNode(551);
	l22->right = new;
	int c = count(root);
	printf("number of nodes in the tree: %d\n", c);



}

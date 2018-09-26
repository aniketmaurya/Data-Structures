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
bool check_complete(struct node *tree)
{
	if (tree != NULL)
	{
		if(tree->left && tree->right)
		{
			return (check_complete(tree->left) && check_complete(tree->right));
		}
		if(!tree->left && tree->right)
			return False;
		else
			return True;
	}	struct node *l11 = createNode(9), *l12 = createNode(54), *l22 = createNode(32);
	root->left = l11;
	root->right = l12;
	l12->right = l22;
	struct node *new1 = createNode(551), *new2 = createNode(591);
	l22->right = new1;
    l22->left = new2;
	l11->left = createNode(564);
	l11->right = createNode(2541);
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
	if(check_complete(root) == True)
	{
		printf("complete binary tree\n" );
	}
	else
	{
		printf("not complete bt\n" );
	}


}

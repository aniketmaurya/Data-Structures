//Algo to delete all the leaves of a binary tree
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
void delete_leaf(struct node **tree)
{
	if(*tree != NULL)
	{
		if((*tree)->left == NULL && (*tree)->right == NULL)
        {
			free(*tree);
			*tree = NULL;
        }
        else
        {
            delete_leaf(&((*tree)->left));
			delete_leaf(&((*tree)->right));
        }
	}
}

int main()
{
	struct node *l = createNode(5);
	root = l;
	struct node *l11 = createNode(9), *l12 = createNode(54), *l22 = createNode(32);
	root->left = l11;
	root->right = l12;
	l12->right = l22;
	struct node *new1 = createNode(551), *new2 = createNode(591);
	l22->right = new1;
    l22->left = new2;
	l11->left = createNode(564);
	l11->right = createNode(2541);
	int c;
	c =  count(root);
	printf("number of leaf nodes in the tree: %d\n", c);
	delete_leaf(&root);
	c = count(root);

	printf("number of leaf nodes in the tree: %d\n", c);


}

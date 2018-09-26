//Algo to count the number of leaves in a binary Tree
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

int count_leaves(struct node *root)
{
	if(root != NULL)
	{
		if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return count_leaves(root->left) + count_leaves(root->right);
        }
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
	struct node *new1 = createNode(551), *new2 = createNode(551);;
	l22->right = new1;
    l22->left = new2;
	int c = count_leaves(root);
	printf("number of leaf nodes in the tree: %d\n", c);



}

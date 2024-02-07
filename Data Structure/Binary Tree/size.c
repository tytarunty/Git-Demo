#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

/* Computes the number of nodes in a tree. */
int size(struct node* node) 
{ 
if (node==NULL) 
	return 0;
	int l = size(node->left);
	int r =  size(node->right);
	return l + 1 + r ; 
}

/* Driver program to test size function*/
int main()
{
struct node *root = newNode(1);
root->left	 = newNode(2);
root->right	 = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5); 

printf("Size of the tree is %d", size(root)); 
getchar();
return 0;
}

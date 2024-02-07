#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int data);
void PreOrderTraversal(struct node *root);
void PostOrderTraversal(struct node *root);
void InOrderTraversal(struct node *root);

int main()
{
    struct node *p=CreateNode(4);
    struct node *p1=CreateNode(1);
    struct node *p2=CreateNode(6);
    struct node *p3=CreateNode(5);
    struct node *p4=CreateNode(2);

    p->left   = p1;
    p->right  = p2;
    p1->left  = p3;
    p1->right = p4;
//      4
//    /  \
//   1    6
//  / \
// 5   2
        printf("Pre Order Traversal  : ");
        PreOrderTraversal(p);
        printf("\nPost Order Traversal : ");
        PostOrderTraversal(p);
        printf("\nIn Order Traversal   : ");
        InOrderTraversal(p);
        printf("\n");
}

struct node* CreateNode(int data){
    struct node *n;
    n= (struct node *) malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrderTraversal(struct node *root){
    if (root != NULL) {
        printf("%d ",root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
        }
}

void PostOrderTraversal(struct node *root){
    if (root != NULL) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ",root->data);
        }
}

void InOrderTraversal(struct node *root){
    if (root != NULL) {
        InOrderTraversal(root->left);
        printf("%d ",root->data);
        InOrderTraversal(root->right);
    }
}
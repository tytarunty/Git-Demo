#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void printKDistant(struct node *p, int k)
{
    if (p == NULL || k<0)
        return;
    if (k == 0)
    {
        printf(" %d ", p->data);
        return;
    }

    printKDistant(p->left, k-1);
    printKDistant(p->right, k-1);
}

int main()
{
//                 8
//               /   \
//              3     10
//             / \      \
//            1   6      14
//               / \    /
//              4   7  13

    struct node *p1 = CreateNode(8);
    struct node *p2 = CreateNode(3);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(6);
    struct node *p5 = CreateNode(4);
    struct node *p6 = CreateNode(7);
    struct node *p7 = CreateNode(10);
    struct node *p8 = CreateNode(14);
    struct node *p9 = CreateNode(13);

    p1->left  = p2;
    p1->right = p7;
    p2->left  = p3;
    p2->right = p4;
    p3->left  = NULL;
    p3->right = NULL;
    p4->left  = p5;
    p4->right = p6;
    p5->left  = NULL;
    p5->right = NULL;
    p6->left  = NULL;
    p6->right = NULL;
    p7->left  = NULL;
    p7->right = p8;
    p8->left  = p9;
    p8->right = NULL;
    p9->left  = NULL;
    p9->right = NULL;

    printKDistant(p1,1);
    printf("\n");
    return 0;
}
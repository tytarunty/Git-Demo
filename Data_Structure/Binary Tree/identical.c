#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

struct node * CreateNode(int data)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int Identical(struct node *n1,struct node *n2)
{
    if (n1 == NULL && n2 == NULL)
        return 1;

    if ( n1 != NULL && n2 != NULL)
    {
        int compare = n1->data == n2->data;
        int l = Identical(n1->left, n2->left);
        int r = Identical(n1->right, n2->right);
        return compare && l && r;
        // return n1->data == n2->data && Identical(n1->left, n2->left) && Identical(n1->right, n2->right);
    }

    return 0;
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

    //tree 1
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

    //tree 2
    struct node *n1 = CreateNode(8);
    struct node *n2 = CreateNode(3);
    struct node *n3 = CreateNode(1);
    struct node *n4 = CreateNode(6);
    struct node *n5 = CreateNode(4);
    struct node *n6 = CreateNode(7);
    struct node *n7 = CreateNode(10);
    struct node *n8 = CreateNode(14);
    struct node *n9 = CreateNode(13);

    n1->left  = n2;
    n1->right = n7;
    n2->left  = n3;
    n2->right = n4;
    n3->left  = NULL;
    n3->right = NULL;
    n4->left  = n5;
    n4->right = n6;
    n5->left  = NULL;
    n5->right = NULL;
    n6->left  = NULL;
    n6->right = NULL;
    n7->left  = NULL;
    n7->right = n8;
    n8->left  = n9;
    n8->right = NULL;
    n9->left  = NULL;
    n9->right = NULL;


    if(Identical(p1,n1))
        printf("Identical Trees\n");
    else
        printf("Not Identical Trees\n");
    printf("\nHeight of tree is %d\n", maxDepth(p1));
    return 0;
}
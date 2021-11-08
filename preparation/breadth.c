
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;  /**< left child */
    struct node *right; /**< right child */
    int data;           /**< data of the node */
} node;

node *newNode(int data)
{
    // creates a slug
    node *tmp = (node *)malloc(sizeof(node));

    // initializes the slug
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

node *insert(node *root, int data)
{
    // If the root of the subtree is null, insert key here
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data > root->data)
    {
        // If it isn't null and the input key is greater than the root key,
        // insert in the right leaf
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {  // If it isn't null and the input key is lower than the root key, insert
       // in the left leaf
        root->left = insert(root->left, data);
    }
    // Returns the modified tree
    return root;
}

struct node* brecur(struct node* root, int item);

struct node* breadth(struct node* root, int item)
{
    if(root == NULL || root->data == item) return root;

    root = brecur(root, item);
}

struct node* brecur(struct node* root, int item)
{
    if (root->left != NULL && root->left->data == item) 
        return root->left;
    if (root->right != NULL && root->right->data == item) 
        return root->right;
    brecur(root->left, item);
    brecur(root->right, item);
}

int main(void)
{
    struct node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 10);

    struct node* s = breadth(root, 8);
    if (s != NULL)
        printf("%d\n", s->data);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int item);
void addLeftChild(Node *node, Node *child);
void addRightChild(Node *node, Node *child);
void preOrder(Node *node);
void postOrder(Node *node);
void inOrder(Node *node);
Node *createTree();


int main()
{
    Node *root = createTree();
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    return 0;
}

Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error! Memory not allocated.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addLeftChild(Node *node, Node *child)
{
    node->left = child;
}
void addRightChild(Node *node, Node *child)
{
    node->right = child;
}

/*
    Construct the following binary tree:

                 _2_
                /   \
               7     9
              / \     \
             1   6     8
                / \   / \
               5  10 3   4
*/

Node *createTree()
{
    Node *two = createNode(2);
    Node *seven = createNode(7);
    Node *nine = createNode(9);
    addLeftChild(two, seven);
    addRightChild(two, nine);

    Node *one = createNode(1);
    Node *six = createNode(6);
    Node *eight = createNode(8);
    addLeftChild(seven, one);
    addRightChild(seven, six);
    addLeftChild(nine, eight);

    Node *five = createNode(5);
    Node *ten = createNode(10);
    Node *three = createNode(3);
    Node *four = createNode(4);
    addLeftChild(six, five);
    addRightChild(six, ten);
    addLeftChild(eight, three);
    addRightChild(eight, four);
    return two;
}

void preOrder(Node *node)
{
    printf("%d ",node->data);

    if(node->left != NULL)
    {
        preOrder(node->left);
    }
    if(node->right!= NULL)
    {
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if(node->left!= NULL)
    {
        postOrder(node->left);
    }
    if(node->right!= NULL)
    {
        postOrder(node->right);
    }
    printf("%d ", node->data);
}

void inOrder(Node *node)
{
    if(node->left!= NULL)
    {
        inOrder(node->left);
    }
    printf("%d ", node->data);
    if(node->right!= NULL)
    {
        inOrder(node->right);
    }
}
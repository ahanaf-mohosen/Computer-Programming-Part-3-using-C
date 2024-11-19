#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *createNode(int item);
void addLeftChild(Node *node, Node *child);
void addRightChild(Node *node, Node *child);
Node *BST_insert(Node *root, Node *node);
Node *create_BST();
Node *BST_search(Node *root, int item);
Node *BST_minimum(Node *root);
Node *BST_maximum(Node *root);
void preOrder(Node *node);
void postOrder(Node *node);
void inOrder(Node *node);
Node *BST_delete(Node *root, Node *node);

int main()
{
    Node *root = create_BST();
    Node *node;
    node = BST_minimum(root);
    printf("Minimum value: %d\n", node->data);
    node = BST_maximum(root);
    printf("Maximum value: %d\n", node->data);
    printf("--------------------------------\n");
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("--------------------------------\n");
    printf("\n");
    node = BST_search(root, 7);
    if (node != NULL)
    {
        printf("Item %d found in BST\n", node->data);
    }
    else
    {
        printf("Item not found in BST\n");
    }

    node = BST_search(root, 8);
    if (node != NULL)
    {
        printf("Item %d found in BST\n", node->data);
    }
    else
    {
        printf("Item not found in BST\n");
    }
    printf("\n");
    printf("--------------------------------\n");
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("--------------------------------\n");
    printf("\n");
    node = BST_search(root, 10);
    if (node != NULL)
    {
        printf("Will delete item %d from BST\n", node->data);
        root = BST_delete(root, node);
        printf("\n");
    }
    else
    {
        printf("Item not found in BST\n");
    }
    printf("\n");
    printf("--------------------------------\n");
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("--------------------------------\n");
    printf("\n");
    node = BST_search(root, 5);
    if (node != NULL)
    {
        printf("Will delete item %d from BST\n", node->data);
        root = BST_delete(root, node);
        printf("\n");
    }
    else
    {
        printf("Item not found in BST\n");
    }
    printf("\n");
    printf("--------------------------------\n");
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("--------------------------------\n");
    printf("\n");
    node = BST_search(root, 1);
    if (node != NULL)
    {
        printf("Will delete item %d from BST\n", node->data);
        root = BST_delete(root, node);
        printf("\n");
    }
    else
    {
        printf("Item not found in BST\n");
    }
    printf("\n");
    printf("--------------------------------\n");
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("--------------------------------\n");
    printf("\n");
    return 0;
}
Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void addLeftChild(Node *node, Node *child)
{
    node->left = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}

void addRightChild(Node *node, Node *child)
{
    node->right = child;
    if (child != NULL)
    {
        child->parent = node;
    }
}

Node *BST_insert(Node *root, Node *node)
{
    Node *parentNode = NULL;
    Node *currentNode = root;

    while (currentNode != NULL)
    {
        parentNode = currentNode;

        if (node->data < currentNode->data)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    if (parentNode == NULL)
    {
        // Tree was empty, new node becomes root
        root = node;
    }
    else if (node->data < parentNode->data)
    {
        addLeftChild(parentNode, node);
    }
    else
    {
        addRightChild(parentNode, node);
    }
    return root;
}

/*
    Construct the following binary tree:

                 _10_
                /    \
               5     17
              / \    / \
             3   7  12 19
            / \
           1   4
*/
Node *create_BST()
{
    Node *root, *node;
    int ara[] = {5, 17, 3, 7, 12, 19, 1, 4};
    int size = sizeof(ara) / sizeof(ara[0]);

    root = createNode(10);

    for (int i = 0; i < size; i++)
    {
        node = createNode(ara[i]);
        root = BST_insert(root, node);
    }
    return root;
}

Node *BST_search(Node *root, int item)
{
    Node *node = root;
    while (node != NULL)
    {
        if (node->data == item)
        {
            return node;
        }
        if (item < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

Node *BST_minimum(Node *root)
{
    Node *node = root;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *BST_maximum(Node *root)
{
    Node *node = root;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

Node *BST_transplant(Node *root, Node *currentNode, Node *newNode)
{
    if (currentNode == root)
    {
        root = newNode;
    }
    else if (currentNode == currentNode->parent->left)
    {
        addLeftChild(currentNode->parent, newNode);
    }
    else
    {
        addRightChild(currentNode->parent, newNode);
    }
    return root;
}

Node *BST_delete(Node *root, Node *node)
{
    Node *smallestNode;
    if (node->left == NULL)
    {
        root = BST_transplant(root, node, node->right);
    }
    else if (node->right == NULL)
    {
        root = BST_transplant(root, node, node->left);
    }
    else
    {
        smallestNode = BST_minimum(node->right);
        if (smallestNode->parent != node)
        {
            root = BST_transplant(root, smallestNode, smallestNode->right);
            addRightChild(smallestNode, node->right);
        }
        root = BST_transplant(root, node, smallestNode);
        addLeftChild(smallestNode, node->left);
    }
    free(node);
    return root;
}

void preOrder(Node *node)
{
    printf("%d ", node->data);

    if (node->left != NULL)
    {
        preOrder(node->left);
    }
    if (node->right != NULL)
    {
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if (node->left != NULL)
    {
        postOrder(node->left);
    }
    if (node->right != NULL)
    {
        postOrder(node->right);
    }
    printf("%d ", node->data);
}

void inOrder(Node *node)
{
    if (node->left != NULL)
    {
        inOrder(node->left);
    }
    printf("%d ", node->data);
    if (node->right != NULL)
    {
        inOrder(node->right);
    }
}
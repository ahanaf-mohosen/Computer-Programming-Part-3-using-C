#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};

Node *prepend(Node *head, int item);
Node *append(Node *head, int item);
Node *removeNode(Node *head, Node *node);
Node *createNode(int item, Node *prev, Node *next);
void printList(Node *head);

int main()
{
    Node *head = NULL;

    // Test appending nodes
    printf("Appending 10, 20, 30 to the list:\n");
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    printList(head);

    // Test prepending a node
    printf("Prepending 5 to the list:\n");
    head = prepend(head, 5);
    printList(head);

    // Test removing the head node
    printf("Removing the head node (5):\n");
    head = removeNode(head, head);
    printList(head);

    // Test removing a middle node
    printf("Removing a middle node (20):\n");
    Node *middleNode = head->next; // 20 is now the second node
    head = removeNode(head, middleNode);
    printList(head);

    // Test removing the last node
    printf("Removing the last node (30):\n");
    Node *lastNode = head->next; // 30 is now the last node
    head = removeNode(head, lastNode);
    printList(head);

    return 0;
}

Node *createNode(int item, Node *prev, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = item;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

Node *prepend(Node *head, int item)
{
    Node *newNode = createNode(item, NULL, head);
    newNode->next->prev=newNode; //newNode->next == head 
    return newNode;
}

Node *append(Node *head, int item)
{
    Node *newNode = createNode(item, NULL, NULL);
    if (head == NULL)
    {
        return newNode;
    }
    Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
    return head;
}

Node *removeNode(Node *head, Node *node)
{
    if (node == NULL || head == NULL)
    {
        return head;
    }
    
    if (head == node)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(node);
        return head;
    }

    Node *prevNode = node->prev;
    Node *nextNode = node->next;

    if (prevNode != NULL)
    {
        prevNode->next = nextNode;
    }
    if (nextNode != NULL)
    {
        nextNode->prev = prevNode;
    }
    free(node);
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

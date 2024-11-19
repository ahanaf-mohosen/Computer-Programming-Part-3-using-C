#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *createNode(int item, Node *next);
Node *prepend(Node *head, int item);
Node *append(Node *head, int item);
void printList(Node *head);

int main()
{
    Node *n, *head;
    n = createNode(10, NULL);
    head = n;
    printList(head);
    head = prepend(head, 20);
    head = prepend(head, 5);
    printList(head);
    head = append(head, 30);
    head = append(head, 40);
    printList(head);

    return 0;
}

Node *createNode(int item, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error! Could not create new node.\n");
        return NULL;
    }
    newNode->data = item;
    newNode->next = next;
    return newNode;
}
Node *prepend(Node *head, int item)
{
    Node *newNode;
    if (head == NULL)
    {
        head = createNode(item, NULL);
        return head;
    }
    newNode = createNode(item, head);
    return newNode;
}

Node *append(Node *head, int item)
{
    Node *newNode = createNode(item, NULL);
    Node *current;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("data: %d\n", current->data);
        current = current->next;
    }
    printf("\n");
}
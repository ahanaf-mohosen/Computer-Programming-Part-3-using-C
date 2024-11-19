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
Node *removeNode(Node *head, int item);
void insertNode(Node *head, int target, int item);
void printList(Node *head);
void freeList(Node *head);

int main()
{
    Node *head = NULL;
    while (1)
    {
        int choice, item, target;
        printf("Choose an option:\n");
        printf("1. Prepend\n2. Append\n3. Print List\n4. Remove Node\n5. Insert After Node\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to prepend: ");
            scanf("%d", &item);
            head = prepend(head, item);
            break;
        case 2:
            printf("Enter the value to append: ");
            scanf("%d", &item);
            head = append(head, item);
            break;
        case 3:
            printf("Linked list contents:\n");
            printList(head);
            break;
        case 4:
            printf("Enter the value to remove: ");
            scanf("%d", &item);
            head = removeNode(head, item);
            break;
        case 5:
            printf("Enter the target value after which to insert: ");
            scanf("%d", &target);
            printf("Enter the value to insert: ");
            scanf("%d", &item);
            insertNode(head, target, item);
            break;
        case 6:
            printf("Exiting program and freeing memory.\n");
            freeList(head);
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
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
    Node *newNode = createNode(item, head);
    return newNode;
}

Node *append(Node *head, int item)
{
    Node *newNode = createNode(item, NULL);
    if (head == NULL)
    {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *removeNode(Node *head, int item)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    Node *current = head, *prev = NULL;
    while (current != NULL && current->data != item)
    {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
    {
        printf("Node with value %d not found.\n", item);
        return head;
    }
    
    if (prev == NULL)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    return head;
}

void insertNode(Node *head, int target, int item)
{
    Node *current = head;
    while (current != NULL && current->data != target)
    {
        current = current->next;
    }
    
    if (current == NULL)
    {
        printf("Node with value %d not found.\n", target);
    }
    else
    {
        Node *newNode = createNode(item, current->next);
        current->next = newNode;
    }
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

void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

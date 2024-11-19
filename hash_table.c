#include <stdio.h>
#include <stdlib.h>

// Define a linked list node for storing values
typedef struct ValueNode {
    int data;
    struct ValueNode* next;
} ValueNode;

// Define a linked list node for keys
typedef struct KeyNode {
    int key;
    ValueNode* values; // Head of the linked list for values
    struct KeyNode* next;
} KeyNode;

// Define the hash table structure
typedef struct {
    KeyNode** array; // Array of pointers to key linked lists
    int capacity;    // Maximum capacity of the hash table
    int size;        // Current number of keys
} HashTable;

HashTable* hashTable;

// Function declarations
int hashFunction(int key);
void init_array(int capacity);
KeyNode* createKeyNode(int key);
ValueNode* createValueNode(int data);
void insert(int key, int data);
void remove_element(int key);
void display();
int size_of_hashtable();

int main() {
    int choice, key, data, n;
    int c = 0;

    init_array(10); // Initialize hash table with capacity 10

    do {
        printf("\n1. Insert item in the Hash Table\n"
               "2. Remove item from the Hash Table\n"
               "3. Check the size of the Hash Table\n"
               "4. Display the Hash Table\n"
               "\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insert(key, data);
                break;

            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                remove_element(key);
                break;

            case 3:
                n = size_of_hashtable();
                printf("Size of Hash Table is: %d\n", n);
                break;

            case 4:
                display();
                break;

            default:
                printf("Invalid Input\n");
        }

        printf("\nDo you want to continue? (press 1 for yes): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}

int hashFunction(int key) {
    return key % hashTable->capacity;
}

void init_array(int capacity) {
    hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->capacity = capacity;
    hashTable->size = 0;
    hashTable->array = (KeyNode**)malloc(capacity * sizeof(KeyNode*));

    for (int i = 0; i < capacity; i++) {
        hashTable->array[i] = NULL; // Initialize all array entries to NULL
    }
}

KeyNode* createKeyNode(int key) {
    KeyNode* newKeyNode = (KeyNode*)malloc(sizeof(KeyNode));
    newKeyNode->key = key;
    newKeyNode->values = NULL;
    newKeyNode->next = NULL;
    return newKeyNode;
}

ValueNode* createValueNode(int data) {
    ValueNode* newValueNode = (ValueNode*)malloc(sizeof(ValueNode));
    newValueNode->data = data;
    newValueNode->next = NULL;
    return newValueNode;
}

void insert(int key, int data) {
    int index = hashFunction(key);
    KeyNode* current = hashTable->array[index];

    // Check if the key already exists
    while (current) {
        if (current->key == key) {
            // Append the value to the values list
            ValueNode* newValue = createValueNode(data);
            newValue->next = current->values;
            current->values = newValue;
            printf("\nKey (%d) has been updated with a new value\n", key);
            return;
        }
        current = current->next;
    }

    // If key does not exist, create a new key node
    KeyNode* newKeyNode = createKeyNode(key);
    ValueNode* newValue = createValueNode(data);
    newKeyNode->values = newValue;

    // Insert the new key node at the head of the list for this index
    newKeyNode->next = hashTable->array[index];
    hashTable->array[index] = newKeyNode;
    hashTable->size++;
    printf("\nKey (%d) has been inserted\n", key);
}

void remove_element(int key) {
    int index = hashFunction(key);
    KeyNode* current = hashTable->array[index];
    KeyNode* prev = NULL;

    // Traverse the list to find the key
    while (current) {
        if (current->key == key) {
            // Remove the key node
            if (prev) {
                prev->next = current->next;
            } else {
                hashTable->array[index] = current->next;
            }

            // Free all value nodes
            ValueNode* valueCurrent = current->values;
            while (valueCurrent) {
                ValueNode* temp = valueCurrent;
                valueCurrent = valueCurrent->next;
                free(temp);
            }
            free(current);
            hashTable->size--;
            printf("\nKey (%d) has been removed\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\nThis key does not exist\n");
}

void display() {
    for (int i = 0; i < hashTable->capacity; i++) {
        printf("\narray[%d]: ", i);
        KeyNode* current = hashTable->array[i];
        while (current) {
            printf("Key (%d): ", current->key);
            ValueNode* valueCurrent = current->values;
            while (valueCurrent) {
                printf("[data: %d] ", valueCurrent->data);
                valueCurrent = valueCurrent->next;
            }
            printf(" -> ");
            current = current->next;
        }
    }
    printf("\n");
}

int size_of_hashtable() {
    return hashTable->size;
}

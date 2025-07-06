#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for linked list (chaining)
struct Node {
    int key;
    struct Node* next;
};

// Hash table as array of pointers to Node
struct Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key into hash table using chaining
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        // Empty slot, insert directly
        hashTable[index] = newNode;
    } else {
        // Collision, add at beginning of linked list
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    printf("Inserted %d at index %d\n", key, index);
}

// Search key in hash table
int search(int key) {
    int index = hashFunction(key);
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key)
            return index; // Found at index
        current = current->next;
    }
    return -1; // Not found
}

// Display hash table contents
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:", i);
        struct Node* current = hashTable[i];
        if (current == NULL) {
            printf(" NULL");
        }
        while (current != NULL) {
            printf(" -> %d", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize hash table with NULL
    memset(hashTable, 0, sizeof(hashTable));

    // Example keys to insert
    int keys[] = {98, 55, 38, 69, 58, 78, 95, 49, 70};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys
    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    printf("\nHash Table Contents:\n");
    display();

    // Search keys
    int toSearch = 69;
    int result = search(toSearch);
    if (result != -1)
        printf("\nKey %d found at index %d\n", toSearch, result);
    else
        printf("\nKey %d not found\n", toSearch);

    return 0;
}


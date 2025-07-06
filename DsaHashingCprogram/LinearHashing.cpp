
//Linear Hashing

#include <stdio.h>

#define TABLE_SIZE 10  // Size of the hash table

int hashTable[TABLE_SIZE];  // Hash table array

// Initialize all table slots to -1 (empty)
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function: key % table size
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key using linear probing
void insert(int key) {
    int index = hashFunction(key);

    // Try next slots until we find an empty one
    int i = 0;
    while (i < TABLE_SIZE) {
        int newIndex = (index + i) % TABLE_SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    // If we reach here, table is full
    printf("Hash table is full. Cannot insert %d\n", key);
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    int n, key;

    initialize();  // Set all table slots to empty

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    // Input keys and insert one by one
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }

    // Show final table
    display();

    return 0;
}


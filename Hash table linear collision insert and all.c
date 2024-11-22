#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int isOccupied;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;  
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].isOccupied) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash Table is full, cannot insert key %d\n", key);
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].isOccupied = 1;  
    printf("Inserted key %d at index %d\n", key, index);
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) {
            return index; 
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {  
            break;
        }
    }

    return -1; 
}

int main() {
    int choice, key, index;
    initializeTable();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = search(key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found in the hash table\n", key);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
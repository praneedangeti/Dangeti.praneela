#include <stdio.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[SIZE];

// Hash Function
int hash(int key)
{
    return key % SIZE;
}

// Initialize Hash Table
void initialize()
{
    int i;
    for(i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;
}

// Insert
void insert(int key)
{
    int i, index;

    for(i = 0; i < SIZE; i++)
    {
        index = (hash(key) + i) % SIZE;

        if(hashTable[index] == EMPTY || hashTable[index] == DELETED)
        {
            hashTable[index] = key;
            printf("Key inserted successfully.\n");
            return;
        }
    }

    printf("Hash Table is Full.\n");
}

// Search
void search(int key)
{
    int i, index;

    for(i = 0; i < SIZE; i++)
    {
        index = (hash(key) + i) % SIZE;

        if(hashTable[index] == key)
        {
            printf("Key found at index %d\n", index);
            return;
        }

        if(hashTable[index] == EMPTY)
            break;
    }

    printf("Key not found.\n");
}

// Delete
void deleteKey(int key)
{
    int i, index;

    for(i = 0; i < SIZE; i++)
    {
        index = (hash(key) + i) % SIZE;

        if(hashTable[index] == key)
        {
            hashTable[index] = DELETED;
            printf("Key deleted successfully.\n");
            return;
        }

        if(hashTable[index] == EMPTY)
            break;
    }

    printf("Key not found.\n");
}

// Display
void display()
{
    int i;

    printf("\nHash Table\n");

    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == EMPTY)
            printf("%d --> Empty\n", i);
        else if(hashTable[i] == DELETED)
            printf("%d --> Deleted\n", i);
        else
            printf("%d --> %d\n", i, hashTable[i]);
    }
}

// Main
int main()
{
    int choice, key;

    initialize();

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while(choice != 5);

    return 0;
}

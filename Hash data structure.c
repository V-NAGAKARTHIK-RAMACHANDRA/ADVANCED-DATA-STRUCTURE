#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 10 
 
int hashTable[SIZE]; 
 
void initHashTable() { 
    for (int i = 0; i < SIZE; i++) 
        hashTable[i] = -1; 
} 

int hash1(int key) { 
    return key % SIZE; 
} 
 
int hash2(int key) { 
    return 7 - (key % 7);  
} 

void linearProbing(int key) { 
    int index = hash1(key); 
    while (hashTable[index] != -1) { 
        index = (index + 1) % SIZE; 
    } 
    hashTable[index] = key; 
} 

void quadraticProbing(int key) { 
    int index = hash1(key); 
    int i = 1; 
    while (hashTable[index] != -1) { 
        index = (hash1(key) + i * i) % SIZE; 
        i++; 
    } 
    hashTable[index] = key; 
} 

void doubleHashing(int key) { 
    int index = hash1(key); 
    int step = hash2(key); 
    while (hashTable[index] != -1) { 
        index = (index + step) % SIZE; 
    } 
    hashTable[index] = key; 
} 

void displayHashTable() { 
    for (int i = 0; i < SIZE; i++) { 
        if (hashTable[i] == -1) 
            printf("%d : EMPTY\n", i); 
        else 
            printf("%d : %d\n", i, hashTable[i]); 
    } 
} 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
struct Node* chain[SIZE]; 
 
void initChain() { 
    for (int i = 0; i < SIZE; i++) 
        chain[i] = NULL; 
} 

void separateChaining(int key) { 
    int index = hash1(key); 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = key; 
    newNode->next = chain[index]; 
    chain[index] = newNode; 
} 
 
void displayChain() { 
    for (int i = 0; i < SIZE; i++) { 
        printf("%d :", i); 
        struct Node* temp = chain[i]; 
        while (temp != NULL) { 
            printf(" %d ->", temp->data); 
            temp = temp->next; 
        } 
        printf(" NULL\n"); 
    } 
} 
 
int main() { 
    int choice, key, n; 
 
    printf("Hash Collision Resolution Techniques\n"); 
    printf("1. Linear Probing\n"); 
    printf("2. Quadratic Probing\n"); 
    printf("3. Double Hashing\n"); 
    printf("4. Separate Chaining\n"); 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    switch (choice) { 
        case 1: 
            initHashTable(); 
            printf("Enter elements:\n"); 
            for (int i = 0; i < n; i++) { 
                scanf("%d", &key); 
                linearProbing(key); 
            } 
            displayHashTable(); 
            break; 
 
        case 2: 
            initHashTable(); 
            printf("Enter elements:\n"); 
            for (int i = 0; i < n; i++) { 
                scanf("%d", &key); 
                quadraticProbing(key); 
            } 
            displayHashTable(); 
            break; 
 
        case 3: 
            initHashTable(); 
            printf("Enter elements:\n"); 
            for (int i = 0; i < n; i++) { 
                scanf("%d", &key); 
                doubleHashing(key); 
            } 
            displayHashTable(); 
            break; 
 
        case 4: 
            initChain(); 
            printf("Enter elements:\n"); 
            for (int i = 0; i < n; i++) { 
                scanf("%d", &key); 
                separateChaining(key); 
            } 
            displayChain(); 
            break; 
 
        default: 
            printf("Invalid Choice!\n"); 
    } 
 
    return 0; 
}

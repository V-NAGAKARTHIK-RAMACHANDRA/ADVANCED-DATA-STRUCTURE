#include <stdio.h> 
#include <stdlib.h> 
 
#define SIZE 10 

typedef struct Node { 
    int data; 
    struct Node* next; 
} Node; 

Node* hashTable[SIZE]; 

void init() { 
    for (int i = 0; i < SIZE; i++) 
        hashTable[i] = NULL; 
} 

Node* createNode(int key) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = key; 
    newNode->next = NULL; 
    return newNode; 
} 

void insert(int key) { 
    int index = key % SIZE; 
    Node* newNode = createNode(key); 
    newNode->next = hashTable[index]; 
    hashTable[index] = newNode; 
} 

void display() { 
    for (int i = 0; i < SIZE; i++) { 
        printf("Index %d: ", i); 
        Node* temp = hashTable[i]; 
 
        while (temp != NULL) { 
            printf("%d -> ", temp->data); 
            temp = temp->next; 
        } 
        printf("NULL\n"); 
    } 
} 
 
int main() { 
    int keys[] = {23, 43, 13, 27, 39, 14, 19, 29}; 
    int n = 8; 
 
    init(); 
 
    for (int i = 0; i < n; i++) 
        insert(keys[i]); 
 
    display(); 
 
    return 0; 
}

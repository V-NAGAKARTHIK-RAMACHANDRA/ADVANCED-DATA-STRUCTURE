#include <stdio.h> 
#define SIZE 10 
int hashTable[SIZE]; 

int hash1(int key) { 
    return key % SIZE; 
} 

int hash2(int key) { 
    return 7 - (key % 7); 
} 
 
void init() { 
    for (int i = 0; i < SIZE; i++) 
        hashTable[i] = -1; 
} 
 
void insert(int key) { 
    int index = hash1(key); 
    int step = hash2(key); 
    int i = 0; 
 
    int newIndex = (index + i * step) % SIZE; 
    hashTable[newIndex] = key; 
} 

void display() { 
    printf("\nHash Table:\n"); 
    for (int i = 0; i < SIZE; i++) 
        printf("%d --> %d\n", i, hashTable[i]); 
} 
 
int main() { 
    int keys[] = {23, 43, 13, 27, 39, 14, 18}; 
    int n = 7; 
 
    init(); 
 
    for (int i = 0; i < n; i++) 
        insert(keys[i]); 
 
    display(); 
 
    return 0; 
} 

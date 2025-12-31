#include<stdio.h>
#include<stdlib.h>
// AVL TREE NODE 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Utility functions

int max(int a, int b) {
    return a > b ? a : b;
}
int height(struct Node* node) {
    if (int n == NULL)
        return 0;
    return node->height;
}
// Create New Node

struct Node* newnode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=key;
    node->left = node-> right = NULL;
    node->height = 1;
    return node;
}
// Right Rotation

struct Node* rightrotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height= max(height(x->left), height(x->right)) + 1;
    return x;
}
// LEFT ROTATION

struct Node* leftrotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
// Get Balance Factor

int getbalance(struct Node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
// ----INSERTION FUNCTION----

struct Node* insert(struct Node* node, int key) {
      if (node == NULL)
        return newnode(key);
      if (key < node->data)
        node->left = insert(node->left, key);
      else if (key > node->data)
        node->right = insert(node->right, key);
      else
        return node; // Duplicate keys not allowed OR NO DUPLICATES
      node->height = 1 + max(height(node->left), height(node->right));
      int balance = getbalance(node);

// LL Case
      if(balance > 1 && key < node->left->data)
        return rightrotate(node);

// RR Case
      if(balance < -1 && key > node->right->data)
        return leftrotate(node);
      
// LR Case
      if(balance > 1 && key > node-> left-> data) {
          node->left = leftrotate(node->left);
          return rightrotate(node);
      }   

 // RL Case
      if(balance < -1 && key < node -> right->data){
          node->right = rightrotate(node->right);
          return leftrotate(node);
      }
      return node;
      }       

  // ---- SEARCHING FUNCTION ----

  struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
  }

  // GET NODE WITH MINIMUM KEY VALUE
  struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
  }

  // ---- DELETION FUNCTION ----

  struct Node* deleteNode(struct Node* root, int key) {
      if (root == NULL)
        return root;
  }
  if (key < root->data)
    root->left = deleteNode(root->left, key);
    else if (key > root->data)

    root->right = deleteNode(root->right, key);
     
    else {
        
        // NODE WITH ONE CHILD OR NO CHILD

        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
    }
            else *root = *temp;
            free(temp);
        }
        else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
             }
        }
        if (root == NULL)
        return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getbalance(root);

        // LL Case
        if (balance > 1 && getbalance(root->left) >= 0)
            return rightrotate(root);

        // RR Case
        if (balance < -1 && getbalance(root->right) <= 0)
            return leftrotate(root);

        // LR Case
        if (balance > 1 && getbalance(root->left) < 0) {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }

        // RL Case
        if (balance > -1 && getbalance(root->left) > 0) {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }

        return root;
        
        
        
        }

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// ---------------- MAIN MENU ----------------
int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        printf("\nAVL Tree Operations");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Element FOUND\n");
                else
                    printf("Element NOT FOUND\n");
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}


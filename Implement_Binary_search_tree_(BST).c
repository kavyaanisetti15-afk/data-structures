#include <stdio.h> 
#include <stdlib.h> 
 
// Define node structure 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
// Create a new node 
struct Node* createNode(int value) { 
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
      newNode->data = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
// Insert a node into BST 
struct Node* insert(struct Node* root, int value) { 
    if (root == NULL) { 
        return createNode(value); 
    } 
 
    if (value < root->data) { 
        root->left = insert(root->left, value); 
    } else if (value > root->data) { 
        root->right = insert(root->right, value); 
    } else { 
        printf("Duplicate value %d not inserted.\n", value); 
    } 
 
    return root; 
} 
 
// Find the minimum value node in the tree 
struct Node* findMin(struct Node* root) { 
    while (root && root->left != NULL) { 
        root = root->left; 
    } 
    return root; 
} 
 
// Delete a node from BST 
struct Node* delete(struct Node* root, int value) { 
    if (root == NULL) { 
        printf("Value %d not found in the tree.\n", value); 
        return root; 
    } 
 
    if (value < root->data) { 
        root->left = delete(root->left, value); 
    } else if (value > root->data) { 
        root->right = delete(root->right, value); 
    } else { 
        // Node to be deleted found 
        if (root->left == NULL) { 
            struct Node* temp = root->right;
              free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        // Node with two children 
        struct Node* temp = findMin(root->right); 
        root->data = temp->data; 
        root->right = delete(root->right, temp->data); 
    } 
    return root; 
} 
 
// In-order traversal (Left, Root, Right) 
void inOrder(struct Node* root) { 
    if (root != NULL) { 
        inOrder(root->left); 
        printf("%d ", root->data); 
        inOrder(root->right); 
    } 
} 
 
// Main function 
int main() { 
    struct Node* root = NULL; 
    int choice, value; 
 
    while (1) { 
        printf("\n--- BST Menu ---\n"); 
        printf("1. Insert\n2. Delete\n3. In-order Traversal\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
        case 1: 
            printf("Enter value to insert: "); 
            scanf("%d", &value); 
            root = insert(root, value); 
            break; 
        case 2: 
            printf("Enter value to delete: "); 
            scanf("%d", &value);
              root = delete(root, value); 
            break; 
        case 3: 
            printf("In-order Traversal: "); 
            inOrder(root); 
            printf("\n"); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("Invalid choice. Try again.\n"); 
        } 
    } 
 
    return 0; 
}
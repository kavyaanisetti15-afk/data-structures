#include <stdio.h> 
#include <stdlib.h> 
 
// Node structure 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
// Create a new node 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
// Insert into BST 
struct Node* insert(struct Node* root, int data) { 
    if (root == NULL) 
        return createNode(data); 
 
    if (data < root->data) 
      root->left = insert(root->left, data); 
    else if (data > root->data) 
        root->right = insert(root->right, data); 
 
    return root; 
} 
 
// In-order traversal: Left -> Root -> Right 
void inOrder(struct Node* root) { 
    if (root != NULL) { 
        inOrder(root->left); 
        printf("%d ", root->data); 
        inOrder(root->right); 
    } 
} 
 
// Pre-order traversal: Root -> Left -> Right 
void preOrder(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
 
// Post-order traversal: Left -> Right -> Root 
void postOrder(struct Node* root) { 
    if (root != NULL) { 
        postOrder(root->left); 
        postOrder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
int main() { 
    struct Node* root = NULL; 
    int choice, value; 
 
    // Menu-driven interface 
    while (1) { 
        printf("\n==== Binary Search Tree Menu ====\n"); 
        printf("1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice);
           switch(choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                root = insert(root, value); 
                break; 
            case 2: 
                printf("In-order Traversal: "); 
                inOrder(root); 
                printf("\n"); 
                break; 
            case 3: 
                printf("Pre-order Traversal: "); 
                preOrder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Post-order Traversal: "); 
                postOrder(root); 
                printf("\n"); 
                break; 
            case 5: 
                printf("Exiting program.\n"); 
                exit(0); 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } 
 
    return 0; 
}
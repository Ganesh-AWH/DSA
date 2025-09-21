#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
struct Node* newNode(int data) { 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
// Right Rotation (LL)
struct Node* rightRotate(struct Node* y) { 
    struct Node* x = y->left; 
    y->left = x->right; 
    x->right = y; 
    return x; 
} 
// Left Rotation (RR) 
struct Node* leftRotate(struct Node* x) { 
    struct Node* y = x->right; 
    x->right = y->left; 
    y->left = x; 
    return y; 
} 
// Left-Right Rotation (LR) 
struct Node* leftRightRotate(struct Node* z) { 
    z->left = leftRotate(z->left); 
    return rightRotate(z); 
} 
// Right-Left Rotation (RL) 
struct Node* rightLeftRotate(struct Node* z) { 
    z->right = rightRotate(z->right); 
    return leftRotate(z);
} 
 
// Print preorder 
void preorder(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
int main() { 
    // Example tree for LL (Right Rotation) 
    printf("For LL tree imbalance - Performing Right Right Rotation");
    struct Node* root = newNode(30); 
    root->left = newNode(20); 
    root->left->left = newNode(10); 
    printf("\nBefore LL rotation: "); 
    preorder(root); 
    root = rightRotate(root); 
    printf("\nAfter LL rotation:  "); 
    preorder(root); 
    
    
    printf("\n\nFor RR tree imbalance - Performing Left Left Rotation");
    struct Node* root2 = newNode(10); 
    root2->right = newNode(20); 
    root2->right->right = newNode(30); 
    printf("\nBefore RR rotation: "); 
    preorder(root2); 
    root2 = leftRotate(root2); 
    printf("\nAfter RR rotation:  "); 
    preorder(root2); 


    printf("\n\nPerforming Left right rotation");
    struct Node* root3 = newNode(30); 
    root3->left = newNode(10); 
    root3->left->right = newNode(20); 
    printf("\nBefore LR rotation: "); 
    preorder(root3); 
    root3 = leftRightRotate(root3); 
    printf("\nAfter LR rotation:  "); 
    preorder(root3); 


    printf("\n\nPerforming Right Left rotation");
    struct Node* root4 = newNode(10); //RL 
    root4->right = newNode(30); 
    root4->right->left = newNode(20); 
    printf("\nBefore RL rotation: "); 
    preorder(root4); 
    root4 = rightLeftRotate(root4); 
    printf("\nAfter RL rotation:  "); 
    preorder(root4); 
    return 0; 
} 
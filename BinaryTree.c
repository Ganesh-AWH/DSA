#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
//creates the newNode and returns it
struct Node *createNode(int ele){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main(){
    struct Node *root = NULL;
    root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(1);
    root->left->left = createNode(12);
    root->right->right = createNode(2);
    root->left->left->left = createNode(19);
    root->right->right->right = createNode(25);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
}
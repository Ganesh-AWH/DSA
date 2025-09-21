#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int element){
        struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = element;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
}
struct Node * insertBst(struct Node* root, int element){
    if(root == NULL){
        root = createNode(element);
        return root;
    }
    if(element < root->data){
        root->left =  insertBst(root->left, element);
    }else{
        root->right = insertBst(root->right, element);
    }
    return root;
}
//for avl tree finding the height of the each node
int height(struct Node *root){
    if(root == NULL) return 0;
    
    int left = 1 + height(root->left);
    int right = 1 + height(root->right);
    return left > right ? left : right;
}
//checking the balance factor for the node 
int checkBalanceFactor(struct Node *root){
    if(root == NULL) return 0;
    int left = 1 + height(root->left);
    int right = 1 + height(root->right);
    return left - right;
}
//checking the node is balanced or not
int isBalance(int balanceFactor){
    if(balanceFactor!=0 && balanceFactor!=-1 && balanceFactor!=1) return 1;
    return 0;
}
void preOrderTraversal(struct Node *root){
    if(root == NULL) return;

    //print ele
    printf("Data: %d\t", root->data);
    printf("Height: %d\t", height(root));
    int balanceFactor = checkBalanceFactor(root);
    printf("Balance Factor: %d\t", balanceFactor);
    printf(isBalance(balanceFactor)?"Imbalanced\n":"Balanced\n");
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(struct Node *root){
    if(root == NULL) return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void postOrderTraversal(struct Node *root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
int main(){
    struct Node *root = NULL;

    int n;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int ele;
        scanf("%d", &ele);
        if(root == NULL){
            root = insertBst(root, ele);
        }else{
            insertBst(root, ele);
        }
    }

    // printf("%d", height(root));
    // printf("Inorder traversal: ");
    // inOrderTraversal(root);
    // printf("\n");

    printf("Preorder Traversal: \n");
    preOrderTraversal(root);
    printf("\n");
    
    // printf("PostOrder Traversal: ");
    // postOrderTraversal(root);
    // printf("\n");
}

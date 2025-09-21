#include<stdio.h>
#include<stdlib.h>
//Structure of the node
struct Node{
    int data;
    struct Node *next;
};
struct Node * createNode(int ele){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}
//inserting the element at the end
void insert(struct Node **head, int ele){
    struct Node *newnode = createNode(ele);
    if(*head == NULL){
        newnode->next = newnode;
        *head = newnode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != *head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
}
void delete(struct Node **head){
    if(*head == NULL){
        printf("Deletion is not possible. List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    //For the deletion of only one node
    if(temp->next == temp){
        printf("Deleted element = %d\n", temp->data);
        free(temp);
        *head = NULL;
    } else {
        // Find last node to update it link
        struct Node* last = *head;
        while(last->next != *head){
            last = last->next;
        }

        printf("Deleted element = %d\n", temp->data);
        last->next = temp->next; // Update tail link
        *head = temp->next;      // Move head forward
        free(temp);              // Free old head
    }
}

void display(struct Node **head){
    struct Node *temp = *head;
    if(temp == NULL){
        printf("The list is empty\n");
        return;
    }
    
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp!= *head);
    printf("\n");
}
int main(){
    int is_over = 1;
    struct Node *head = NULL;
    while(is_over){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. press any key to exit\n");
        printf("Enter the below linked list operations: ");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            int ele;
            printf("Enter the element to insert: ");
            scanf("%d", &ele);
            insert(&head, ele);
        }
        else if(choice == 2){
            delete(&head);
        }
        else if(choice == 3){
            display(&head);
        }
        else{
            is_over = 0;
        }
    }
}
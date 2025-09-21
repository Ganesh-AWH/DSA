#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char song[25];
    struct Node *next;
};
//create new node and allocates spaces and return it
struct Node *createNode(char *str){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, str);
    newNode->next = NULL;
    return newNode;
}

//adding new song to the playlist and recent one is first, so insert at head
void insertAtBegin(struct Node **head, char *str){
    struct Node *newNode = createNode(str);
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void displaySong(struct Node **head){
    struct Node *temp = *head;
    while(temp != NULL){
        printf("%s ->", temp->song);
        temp = temp->next;
    }
    printf("Null\n");
}
void deleteSong(struct Node **head){
    if(*head == NULL){
        printf("Playlist is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
int main(){

    int is_over = 1;
    struct Node *head = NULL;
    while(is_over){
        printf("1. Add song ");
        printf("2. Delete song ");
        printf("3. Display ");
        printf("4. press any key to exit from Ipod music\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            char song[50];
            printf("Enter the song name to add in playlist: ");
            scanf("%s", song);
            insertAtBegin(&head, song);
        }else if(choice == 2){
            deleteSong(&head);
        }
        else if(choice == 3){
            displaySong(&head);
        }
        else{
            is_over = 0;
        }
    }
}

// For this scenario, a singly linked list with insertion at the head is an appropriate data structure. In this approach, each newly added song is inserted at the beginning of the linked list, making it the first song in the playlist. Since insertion at the head in a linked list takes constant time O(1), adding songs is efficient. Similarly, deleting the most recently added song is also efficient because it simply involves updating the head pointer to the next node. This method ensures that the playlist always keeps the most recently added song at the top, ready to be played first, without having to rearrange or shift other elements like in an array-based list.
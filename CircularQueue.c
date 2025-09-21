#include<stdio.h>
#define n 2
int c_queue[n];
int front = -1;
int rear = -1;
//enqueue, dequeue, display, isempty, isfull
void enqueue(int ele){
    //queue overflow condition
    if((rear+1)%n == front){
        printf("Queue overflow\n");
        return;
    }
    //this condition for inserting first element
    if(front == -1 && rear == -1){
        front++;
        rear++;
        c_queue[rear] = ele;
    }
    else{
        rear = (rear+1)%n;
        c_queue[rear] = ele;
    }
}

int dequeue(){
    if(front == -1){
        printf("Queue Underflow\n");
        return -1;
    }

    if(front == rear){
        int ele = c_queue[front];
        front = -1;
        rear = -1;
        return ele;
    }else{
        int ele = c_queue[front];
        front = (front+1) % n;
        return ele;
    }
}
void is_empty(){
    if(rear == -1){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }
}

void display(){
    if(rear == -1){
        printf("Queue is empty\n");
        return;
    }

    int i;
    for(i=front; i!=rear; i = (i+1)%n){
        printf("%d ", c_queue[i]);
    }
    printf("%d ", c_queue[i]);
    printf("\n");
}
int main(){
        int is_over = 0;
        int option;
        while(!is_over){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isEmpty\n");
        printf("4. Display\n");
        printf("5. press any key to quit\n");
        printf("Enter the Circular queue operation to perform: ");
        scanf("%d", &option);
        if(option == 1){
            int ele;
            printf("Enter the element to Enqueue: ");
            scanf("%d", &ele);
            enqueue(ele);
        }else if(option == 2){
            int poped = dequeue();
            if(poped != -1){
                printf("Dequeue element = %d\n", poped);
            }
        }else if(option == 3){
            is_empty();
        }else if(option == 4){
            display();
        }else{
            printf("The program is ended\n");
            is_over = 1;
        }
    }
}

#include<stdio.h>
#define n 10
//global variables
int stack[n];
int top = -1;

void push(int ele){
    //checking overflow condition
    if(top == n){
        printf("Overflow\n");
        return;
    }
    stack[++top] = ele;
}
int pop(){
    //checking underflow condition
    if(top == -1){
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}
int peek(){
    if(top == -1){
        printf("The stack is empty\n");
        return -1;
    }
    return stack[top];
}
void display(){
    if(top == -1){
        printf("The stack is empty\n");
        return;
    }
    printf("The stack elements are: ");
    for(int i=top; i>=0; i--){
        printf("%d ", stack[i]);
    }

    printf("\n");
}
int main(){
    int is_over = 0;
    int option;


    while(!is_over){
        printf("Operations\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. press any key to quit\n");
        printf("Enter the stack operation to perform: ");
        scanf("%d", &option);
        if(option == 1){
            int ele;
            printf("Enter the element to push: ");
            scanf("%d", &ele);
            push(ele);
        }else if(option == 2){
            int poped = pop();
            if(poped != -1){
                printf("popped element = %d\n", poped);
            }
        }else if(option == 3){
            int ele = peek();
            if(ele != -1){
                printf("Peek element = %d\n", ele);
            }
        }else if(option == 4){
            display();
        }else{
            printf("The program is ended\n");
            is_over = 1;
        }
    }


}


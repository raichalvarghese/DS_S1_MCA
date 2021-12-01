#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
void push();void pop();void toppest();void display();
int top=-1;
void main(){
    int choice;
    int iter=20;
    while(iter--){
        printf("\n*----------*");
        printf("\nChoices:\n1.push\n2.pop\n3.top\n4.display");
        printf("\nEnter the operation:");
        scanf("%d",&choice);
        switch(choice){
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : toppest();break;
            case 4 : display();break;
            default : printf("\nInvalid choice");
        }
        }
}
void push(){
    int x;
    printf("Enter the data to be pushed:");
    scanf("%d",&x);
    if(top==N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    int item;
    if(top==-1){
        printf("\nUnderflow");
    }
    else{
        item=stack[top];
        printf("\nEnter the popped item:%d",item);
        top--;
    }
}

void toppest(){
    if(top==-1){
        printf("The stack is empty");
    }
    else{
        printf("%d",stack[top]);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("No elements in the stack");
    }
    else{
       for(i=top;i>=0;i--){
          printf("\n %d",stack[i]);
       }
    }   
}
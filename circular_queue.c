#include<stdio.h>
#include<stdlib.h>
# define N 5
int queue[N];
int front=-1,rear=-1;
void enq();void deq();void display();void peek();
void main(){
    int op,iter=20;
    while(iter--){
        printf("\nChoices:\n1.enqueue\n2.dequeue\n3.display\n4.peek\nEnter a choice:");
        scanf("%d",&op);
        switch(op){
            case 1:enq();break;
            case 2:deq();break;
            case 3:display();break;
            case 4:peek();break;
            default:printf("Invalid Choice");
        }
    }
}
void enq(){
    int val,temp;
    printf("Enter the element to be enqueued");
    scanf("%d",&val);
    if((front==0 && rear==(N-1)) || (front==rear+1)){
        printf("Overflow");
    }
    else{
        if(front==-1){
            front=rear=0;
            queue[rear]=val;
        }
        else if(rear==(N-1) && front!=0){
            rear=0;
            queue[rear]=val;
        }
        else if(front!=0 && rear<front){
            temp=rear+1;
            if(temp!=front){
                rear=rear+1;
                queue[rear]=val;
            }
            else{
                printf("Overflow");
            }
        }
        else{
            rear=rear+1;
            queue[rear]=val;
        }
    }
}

void deq(){
    int temp;
    if(front==-1){
        printf("Underflow");
    }
    else{
        if(front==rear){
            temp=queue[front];
            front=-1;
            rear=-1;
        }
        else if(front==(N-1)){
            temp=queue[front];
            front=0;
        }
        else{
            temp=queue[front];
            front=front+1;
        }
    printf("\nThe deleted item was %d",temp);
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("No elements");
    }
    else{
        int i;
        if(front<=rear){
            for(i=front;i<=rear;i++){
                printf("\t%d",queue[i]);
            }
        }
        else{
            for(i=front;i<N;i++){
                printf("\t%d",queue[i]);
            }
            for(i=0;i<=rear;i++){
                printf("\t%d",queue[i]);
            }
        }
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("No elements");
    }
    else{
        printf("%d",queue[front]);
    }
    
}
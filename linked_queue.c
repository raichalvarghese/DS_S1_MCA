#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *temp,*newnode;
struct node *front=NULL;
struct node *rear=NULL;
void enq();void deq();void traverse();
int main(){
    int op;
    int iter=15;
    while(iter--){
        printf("\n\n1.enq\n2.deq\n3.traverse\nEnter a choice:");
        scanf("%d",&op);
        switch(op){
            case 1:enq();break;
            case 2:deq();break;
            case 3:traverse();break;
            default:printf("Invalid choice");
        }
    }    
}
void enq(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be enqueued:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void deq(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty");
    }
    else{
        temp=front;
        front=front->next;
        printf("The deleted value is %d",temp->data);
        free(temp);
    }
}

void traverse(){
    temp=front;
    while(temp!=NULL){
        printf("\t%d",temp->data);
        temp=temp->next;
    }
}

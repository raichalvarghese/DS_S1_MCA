#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *head,*temp,*newnode;
void push();void pop();void peek();void traverse();
int main(){
    int op,iter=15;
    while(iter--){
        printf("\n\n\n1.push\n2.pop\n3.peek\n4.traverse\nEnter a choice:");
        scanf("%d",&op);
        switch(op){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:traverse();break;
            default:printf("Invalid choice");
        }
    }
}

void push(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void pop(){
    if(head==NULL){
        printf("Underflow");
    }
    else{
        temp=head;
        printf("\nItem deleted is %d",temp->data);
        head=head->next;
        free(temp);
    }

}

void peek(){
    if(head==NULL){
        printf("Underflow");
    }
    else{
        printf("%d",head->data);
    }
}

void traverse(){
    temp=head;
    if(head==NULL){
        printf("Underflow");
    }
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }   
}
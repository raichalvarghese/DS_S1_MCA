// singly Linked list:
// insert a node at middle
// delete a node at first
// search element 10 at its position

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *temp,*newnode,*pre,*ptr,*head;
void new();void insert_mid();void delete_first(); void search_10();void traverse();
void main(){
    int op;
    int iter=10;
    while(iter--){
        printf("\nChoices:\n1.New_element\n2.insert_mid\n3.delete_first\n4.search_10\n5.traverse");
        printf("\nEnter the choice:");
        scanf("%d",&op);
        switch(op){
            case 1:new();break;
            case 2:insert_mid();break;
            case 3:delete_first();break;
            case 4:search_10();break;
            case 5:traverse();break;
            default:printf("Invalid Choice");
        }
    }
}

void new(){
    int c=1;
    while(c==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            temp=head=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue?");
        scanf("%d",&c);
    }
}
void insert_mid(){
    newnode=(struct node*)malloc(sizeof(struct node));
    int pos;
    int val;
    printf("\nEnter the value to be inserted:");
    scanf("%d",&val);
    printf("\nEnter the value after which the data to be inserted:");
    scanf("%d",&pos);
    newnode->data=val;
    temp=head;
    while(temp!=0){
        if(temp->data==pos){
            newnode->next=temp->next;
            temp->next=newnode;
        }
        temp=temp->next;
    }
    printf("\nItem Inserted\n");
}

void delete_first(){
    temp=head;
    if(head==NULL){
        printf("\nUnderflow\n");
    }
    head=head->next;
    temp->next=0;
    free(temp);
    printf("\nItem deleted\n");
}

void search_10(){
    temp=head;
    int i=0;
    while(temp!=0){
        if(temp->data==10){
            printf("\n10 is found at %d",i,"\n");
        }
        i++;
        temp=temp->next;
    }
}

void traverse(){
	temp=head;
	while(temp!=0){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}


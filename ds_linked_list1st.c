#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *temp,*head,*newnode;
void new();void traverse();void search();int count();
void main(){
	int op,iter=15;
	while(iter--){
		printf("\n\nChoices:\n1.new\n2.traverse\n3.search\n4.count\n");
		scanf("%d",&op);
		switch(op){
			case 1:new();break;
			case 2:traverse();break;
			case 3:search();break;
			case 4:count();break;
			default:printf("Invalid choice");
		}
	}
}                                              
void new(){
	int c=1;
	while(c==1){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;	
		}
		printf("Do you want to continue(0/1)");
		scanf("%d",&c);	
	}
}

void traverse(){
	temp=head;
	while(temp!=0){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

void search(){
	temp=head;
	int val;
	printf("Enter the value to be searched:");
	scanf("%d",&val);
	int i=0;
	while(temp!=0){
		if(temp->data==val){
			printf("The value is found at %d",i);		
		}
		i++;
		temp=temp->next;
	}
}

int count(){
	temp=head;
	int count=0;
	while(temp!=0){
		temp=temp->next;
		count++;	
	}
	printf("%d",count);
}


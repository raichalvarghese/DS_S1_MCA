#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *temp,*head,*newnode,*pre,*ptr;
void new();void insert_beg();void insert_end();void insert_pos();void delete_beg();void delete_end();void delete_pos();void traverse();
void main(){
	int op,iter=15;
	while(iter--){
		printf("\n\nChoices:\n1.new\n2.insert_beg\n3.insert_end\n4.insert_pos\n5.delete_beg\n6.delete_end\n7.delete_pos\n8.traverse");
		scanf("%d",&op);
		switch(op){
			case 1:new();break;
			case 2:insert_beg();break;
			case 3:insert_end();break;
			case 4:insert_pos();break;
			case 5:delete_beg();break;
			case 6:delete_end();break;
			case 7:delete_pos();break;
			case 8:traverse();break;
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

void insert_beg(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value:");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;	
	printf("\nItem inserted Successfully");
}

void insert_end(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value:");
	scanf("%d",&newnode->data);
	newnode->next=0;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=newnode;
	printf("\nItem inserted");
}

void insert_pos(){
	newnode=(struct node*)malloc(sizeof(struct node));
	int pos;
	printf("Enter the value:");
	scanf("%d",&newnode->data);
	printf("Enter the value after which value to be inserted:");
	scanf("%d",&pos);
	temp=head;
	while(temp!=0){
		if(temp->data==pos){
		    newnode->next=temp->next;
		    temp->next=newnode;	
		}
		temp=temp->next;
	}
	printf("\nItem inserted");
}
void delete_beg(){
	temp=head;
	if(head==NULL){
		printf("Underflow");
	}
	head=head->next;
	temp->next=0;
	free(temp);
	printf("\nItem deleted");
	
}

void delete_end(){
	temp=head;
	if(head==NULL){
		printf("Underflow");
	}
	else{
	while(temp->next!=0){
		pre=temp;
		temp=temp->next;
	}
	pre->next=0;
	free(temp);
	printf("\nItem deleted");	
	}
}
void traverse(){
	if(head==NULL){
		printf("Underflow");
	}
	else{
	temp=head;
	while(temp!=0){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	}
}

void delete_pos(){
	int val;
	if(head==NULL){
		printf("Underflow");
	}
	else{
		temp=head;
		printf("Enter the value after which data to be deleted");
		scanf("%d",&val);
		pre=temp;
		while(temp->data!=val){
			pre=temp;
			temp=temp->next;
		}
		if(temp->next==NULL){printf("No elements after the value entered");}
		else{
		temp=temp->next;
		pre=pre->next;
		ptr=temp;
		pre->next=temp->next;
		printf("Deleted item is:%d",temp->data);
		free(temp);
		}
		}
}
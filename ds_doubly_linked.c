#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*pre;
	int data;
	struct node*next;
};
struct node *temp,*head,*newnode,*ptr;
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
		newnode->pre=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			newnode->pre=temp;
			temp=newnode;	
		}
		printf("Do you want to continue(0/1)");
		scanf("%d",&c);	
	}

}     

void insert_beg(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
    newnode->pre=0;
	newnode->next=head;
    head->pre=newnode;
	head=newnode;
}  

void insert_end(){
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	newnode->next=0;
	while(temp->next!=NULL){
		temp=temp->next;
	}
    newnode->pre=temp;
	temp->next=newnode;
    temp=newnode;
}      

void insert_pos(){
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	int pos;
	printf("Enter the value:");
	scanf("%d",&newnode->data);
	printf("Enter the value after which value to be inserted:");
	scanf("%d",&pos);
	while(temp->data!=pos){
		temp=temp->next;
	}
    newnode->pre=temp;
	newnode->next=temp->next;
	temp->next=newnode;
	temp->next->pre=newnode;
}   

void delete_beg(){
	temp=head;
    if(head==NULL){
        printf("No elements");
    }
    else{
	head=head->next;
	head->pre=NULL;
	free(temp);
    }
}  

void delete_end(){
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;	
	}
	temp->pre->next=NULL;
	free(temp);
} 

void traverse(){
	temp=head;
	while(temp!=0){	
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

void delete_pos(){
	temp=head;
	int val;
	printf("Enter the value after which data to be deleted");	
	scanf("%d",&val);
	while(temp->data!=val){
		temp=temp->next;
	}
	ptr=temp;
	temp=temp->next;
	ptr->next=temp->next;
	temp->next->pre=ptr;
	free(temp);
}                        
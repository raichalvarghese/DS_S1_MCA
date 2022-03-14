#include<stdio.h>
#include<stdlib.h>

struct node{
struct node*left;
int data;
struct node*right;
};
struct node*temp;
struct node *createtree()
	{
	int val;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data(insert 0 if no data to be inserted)");
	scanf("%d",&val);
	if(val==0)
	{
	return NULL;
	}
	temp->data=val;
	printf("\nenter the left child of the node:%d",temp->data);
	temp->left=createtree();
	printf("\nenter the right child of the node:%d",temp->data);
	temp->right=createtree();
	return temp;
}


void preOrder(struct node*temp){
	printf("%d",temp->data);
	preOrder(temp->left);
	preOrder(temp->right);
}
void inOrder(struct node*temp){
	inOrder(temp->left);
	printf("%d",temp->data);
	inOrder(temp->right);
}
void postOrder(struct node*temp){
	postOrder(temp->left);
	postOrder(temp->right);
	printf("%d",temp->data);
}


void main(){
	int ch;
	int iter=15;
	int value;
	struct node*root;
	while(iter--){
		printf("\nEnter a choice:\n1.create\n2.preOrder Traversal\n3.inOrder Traversal\n4.postOrder Traversal:\n");
		scanf("%d",&ch);
		switch(ch){
		
		case 1:createtree();break;

		case 2:preOrder(root);break;

		case 3:inOrder(root);break;

		case 4:postOrder(root);break;

		default:printf("\nInvalid Choice:");

		}
	}	
}


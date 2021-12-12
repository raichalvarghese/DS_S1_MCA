#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left,*right;
};

struct node *createNode(){
    struct node *temp;
    int data;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the node(0 to terminate the branch):");
    scanf("%d",&data);
    if(data!=0){
        temp->data=data;
        printf("For left node of %d\n",data);
        temp->left=createNode();
        printf("For right node of %d\n",data);
        temp->right=createNode();
        return temp;
    }
    else{
        return NULL;
    }   
}

void preOrder(struct node*node){
    if(node!=NULL){
        printf("%d",node->data);
        preOrder(node->left);
        preOrder(node->right);
    }  
}

void inOrder(struct node*node){
    if(node!=NULL){
        inOrder(node->left);
        printf("%d",node->data);
        inOrder(node->right);
    }  
}

void postOrder(struct node*node){
    if(node!=NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d",node->data);
    }  
}

void main(){
    struct node *root;
    root=createNode();
    printf("preOrder:");
    preOrder(root);
    printf("\n");
    printf("inOrder:");
    inOrder(root);
    printf("\n");
    printf("postOrder:");
    postOrder(root);
}
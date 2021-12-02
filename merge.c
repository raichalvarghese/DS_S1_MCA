#include<stdio.h>
#include<stdlib.h>
/* merge sorted arrays */
void merge(int a[],int n,int b[],int m,int c[]){
    int i,j,k;
    i=0;
    j=0;
    k=0;
	while(i<n && j<m){
		if(a[i]<=b[j]){
			c[k]=a[i];
			k++;
            i++;	
		}
		else{
			c[k]=b[j];
			k++;
            j++;	
		}
		
	}
	while(i<n){
		c[k]=a[i];
        k++;
        i++;
	}
	while(j<m){
		c[k]=b[j];
        k++;
        j++;
	}
	
}
int main(){
	int n,m;
    int a[10],b[10];
	printf("Enter the size of array a:");
	scanf("%d",&n);
	printf("Enter the elements of array a:");
    int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the size of array b:");
	scanf("%d",&m);
	printf("Enter the elements of array b:");
	for(j=0;j<m;j++){
		scanf("%d",&b[j]);
	}
    int c[n+m];
	merge(a,n,b,m,c);
    printf("The elements of array c is:");
	for(i=0;i<n+m;i++){
		printf("%d\t",c[i]);
	}
    return 0;
}
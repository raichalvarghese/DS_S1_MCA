#include<stdio.h>
#define N 5
int a[N],i;
int big=0;
int largest();
int smallest();
int reverse();
int sum();
int average();

int main(){
	int i,b;
	printf("Enter the elements of the array:");
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
    int iter=10;
    while(iter--){
        printf("\nEnter the operation:\n1.largest\n2.smallest\n3.reverse\n4.sum\n5.average");
        scanf("%d",&b);
        switch(b){
            case 1:largest();break;	
            case 2:smallest();break;
            case 3:reverse();break;
            case 4:sum();break;
            case 5:average();break;
            default:printf("Invalid");
    }
    }	
}

int largest(){
	for(i=0;i<N;i++){
		if(a[i]>big){
		big=a[i];
		}
	}
	printf("Largest is %d",big);
}


int smallest(){
	int smaller=a[0];
	for(i=0;i<N;i++){
		if(a[i]<smaller){
		smaller=a[i];
		}
	}
	printf("Smallest is %d",smaller);
}


int reverse(){
	printf("Reverse of the array is:");
	for(i=(N-1);i>=0;i--){
	printf("\t%d",a[i]);
	}
}

int sum(){
	int sum=0;
	for(i=0;i<N;i++){
	sum=sum+a[i];
	}
	printf("Sum of the array is %d",sum);
}

int average(){
	int total=0;
	for(i=0;i<N;i++){
		total=total+a[i];
	}
	printf("Average of the array is %d",total/N);
}




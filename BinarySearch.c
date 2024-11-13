#include<stdio.h>
void main()
{
	int n,A[50],i,x,left=0,right,mid,flag=0,t=3;
	printf("Enter the number of elements in the array: ");
	t++;
	scanf("%d",&n);
	t++;
	printf("Enter the array elements: ");
	t++;
	for(i=0;i<n;i++,t++) {
		scanf("%d",&A[i]);
		t++;
	} t++;
	printf("Enter the element to be searched: ");
	t++;
	scanf("%d",&x);
	t++;
	right=n-1;
	t++;
	while(left<=right) {
		t++;
		mid=(left+right)/2;
		t++;
		if(A[mid]==x) {
			t++;
			flag=1;
			t++;
			t++;
			break;
		}
		else if(A[mid]<x) {
			t++;
			left=mid+1;
			t++;
		}
		else {
			t++;
			right=mid-1;
			t++;
		}
	} t++;
	if(flag==0) {
		t++;
		printf("\nElement not found");
		t++;
	}
	else {
		t++;
		printf("\nElement is found at position %d",mid+1);
		t++;
	}
	printf("\nSpace complexity: %d",32+4*n);
	t++;
	t++;
	printf("\nTime complexity: %d\n",t);
}

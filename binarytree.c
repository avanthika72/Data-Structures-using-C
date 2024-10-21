#include<stdio.h>
int main() {
	int i,n,k,pos,tree[20];
	printf("Enter the number of elements in the binary tree: ");
	scanf("%d",&n);
	printf("Enter the tree elements: ");
	for (i=0; i<n; i++) {
		scanf("%d",&tree[i]);
	}
	printf("The given binary tree is: \n");
	for (i=0; i<n; i++) {
		printf("%d \t",tree[i]);
	}
	printf("\nEnter the position to check in the binary tree: ");
	scanf("%d",&pos);
	if (pos<0 || pos>=n) {
		printf("\nInvalid position!");
		return 1;
	} 
	if (pos>0) {
		printf("\nParent of %d is: %d",tree[pos], tree[(pos-1)/2]);
	} else {
		printf("\nNo parent");
	}
	if ((2*pos)+1 >= n) {
		printf("\nNo left child");
	} else {
		printf("\nLeft child of %d is: %d",tree[pos],tree[(2*pos)+1]);
	}
	if ((2*pos)+2 >= n) {
			printf("\nNo right child");
	} else {
		printf("\nRight child of %d is: %d",tree[pos],tree[(2*pos)+2]);
	}
	return 0;
}

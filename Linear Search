#include<stdio.h>
void main()
{	
    int n,i,x,A[50],count=0,t=2;	
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
    for(i=0;i<n;i++,t++) {
        if(A[i]==x) {
            t++;
            count++;
            t++;
            printf("\nElement %d found at position %d",x,i+1);
            t++;
        }
    } t++;
    if(count>0) {
        t++;  
        printf("\nElement %d is found %d time(s)",x,count);
        t++;
    }
    else {
        t++;
        printf("Element not found");
        t++;
    }
    printf("\nSpace complexity: %d",20+4*n);
    t++;
    t++;
    printf("\nTime complexity: %d\n",t);
}

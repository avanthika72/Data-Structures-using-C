#include <stdio.h>
void main()
{
    int n,i,j,temp,a[50],t=1;
    printf("Enter the number of elements of array: ");
    t++;
    scanf("%d",&n);
    t++;
    printf("Enter the array elements: ");
    t++;
    for (i=0; i<n; i++,t++) {
        scanf("%d",&a[i]);
        t++;
    } t++;
    for (i=0; i<n-1; i++,t++) {
        for (j=0; j<n-i-1; j++,t++) {
            if (a[j] > a[j+1]) {
				t++;
                temp = a[j];
                t++;
                a[j] = a[j+1];
                t++;
                a[j+1] = temp;
                t++;
            } 
        } t++;
    } t++;
	printf("\nThe sorted array is: \n");
    t++;
    for (i=0; i<n; i++,t++) {
        printf("%d \t",a[i]);
        t++;
    } t++;
	printf("\nSpace complexity = %d",20+4*n);
    t++;
    t++;
    printf("\nTime complexity = %d",t);
}

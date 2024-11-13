#include <stdio.h>
int a[20];
void swap(int x,int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}
int Partition(int low,int high) {
    int i=low, j=high, pivot=low;
    while (i<j) {
        while (i<=high && a[i]<=a[pivot]) {
            i++;
        } 
        while (j>=low && a[j]>a[pivot]) {
            j--;
        }
        if (i<j) {
            swap(i,j);
        }
    }
    swap(j,pivot);
    return j;
}
void quickSort(int low,int high) {
    if (low<high) {
    int pivot = Partition(low,high);
    quickSort(low,pivot-1);
    quickSort(pivot+1,high);
} }
void main() {
    int n,i;
    printf("Enter the number of elements in the array to be sorted: ");
    scanf("%d",&n); 
    printf("Enter the array elements: ");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("The array before sorting: \n");
    for (i=0; i<n; i++) {
        printf("%d \t",a[i]);
    }
    quickSort(0,n-1);
    printf("\nThe array after sorting: \n");
    for (i=0; i<n; i++) {
        printf("%d \t",a[i]);
    }
}

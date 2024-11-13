#include <stdio.h>
int a[20],b[20];
void merge(int low,int mid,int high) {
    int k,i=low,x=low,y=mid+1;
    while (x<=mid && y<=high) {
        if (a[x]<=a[y]) {
            b[i] = a[x];
            x++;
        } else {
            b[i] = a[y];
            y++;
        }
        i++;
    }
    if (x<=mid) {
        for (k=x; k<=mid; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k=y; k<=high; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for (k=low; k<=high; k++) {
        a[k] = b[k];
    }
}
void mergeSort(int low,int high) {
    if (low<high) {
      int mid=(low+high)/2;
      mergeSort(low,mid);
      mergeSort(mid+1,high);
      merge(low,mid,high);
  }
}
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
    mergeSort(0,n-1);
    printf("\nThe array after sorting: \n");
    for (i=0; i<n; i++) {
        printf("%d \t",a[i]);
    }
}

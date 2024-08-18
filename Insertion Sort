#include<stdio.h>
void main()
{
	int n,i,j,a[50],temp,t=1;
	printf("Enter size of array: ");
	t++;
	scanf("%d",&n);
	t++;
	printf("Enter array elements:");
	t++;
	for(i=0; i<n; i++,t++) {
		scanf("%d",&a[i]);
		t++;
	} t++;
	i=1;
	t++;
	while (i<n) {
		t++;
		temp=a[i];
		t++;
		j=i-1;
		t++;
		while (j>=0 && a[j]>temp) {
			t++;
			a[j+1]=a[j];
			t++;
			j--;
			t++;
		} t++;
		a[j+1]=temp;
		t++;
		i++;
		t++;
	} t++;
	printf("\nSorted array is: ");
	t++;
	for(i=0;i<n;i++,t++) {
		printf("\t%d",a[i]);
		t++;
	} t++;
	printf("\nSpace complexity = %d",20+4*n);
	t++;
	t++;
	printf("\nTime complexity = %d\n",t);
}

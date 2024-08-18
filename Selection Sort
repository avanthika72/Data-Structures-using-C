#include<stdio.h>
void main()
{
	int n,i,j,small,a[50],temp,t=1;
	printf("Enter size of array: ");
	t++;
	scanf("%d",&n);
	t++;
	printf("Enter array elements:");
	t++;
	for(i=0;i<n;i++,t++) {
		scanf("%d",&a[i]);
		t++;
	} t++;
	i=0;
	t++;
	while (i<n) {
		t++;
		j=i+1;
		t++;
		small=i;
		t++;
		while (j<n) {
			t++;
			if(a[j]<a[small]) {
				t++;
				small=j;
				t++;
			}
			j++;
			t++;
		} t++;
		if (i!=small) {
			t++;
			temp=a[i];
			t++;
			a[i]=a[small];
			t++;
			a[small]=temp;
			t++;
		}
		i++;
		t++;
	} t++;
	printf("\nSorted array is: ");
	t++;
	for(i=0;i<n;i++,t++) {
		printf("\t%d",a[i]);
		t++;
	} t++;
	printf("\nSpace complexity = %d",24+4*n);
	t++;
	t++;
	printf("\nTime complexity = %d\n",t);
}

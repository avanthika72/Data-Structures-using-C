#include<stdio.h>
void main()
{
	int m,n,i,j,k=1,a[50][50],b[50][3];
	printf("Enter the number of rows and columns in the sparse matrix: ");
	scanf("%d %d",&m,&n);
	printf("Enter the matrix elements: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nOriginal matrix: ");
	for(i=0;i<m;i++) {
		printf("\n");
		for(j=0;j<n;j++) {
			printf("%d \t",a[i][j]);
		}
	}
	b[0][0]=m;
	b[0][1]=n;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if (a[i][j]!=0) {
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	b[0][2]=k-1;
	printf("\n\nSparse matrix representation is: ");
	printf("\nROW \tCOLUMN \tVALUE");
	for(i=0;i<k;i++) {
		printf("\n");
		for(j=0;j<3;j++) {
			printf("%d \t",b[i][j]);
		}
	}
}

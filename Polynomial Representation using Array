#include <stdio.h>
void main()
{
	int n,i;
	struct polynomial {
			int coeff,expo;
        } poly[10];
	printf("Enter the number of terms in the polynomial: ");
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		printf("Enter coefficient and exponent of term %d: ",i+1);
		scanf("%d %d", &poly[i].coeff, &poly[i].expo);
	}
	printf("The given polynomial expression is: \n");
	for(i=0; i<n; i++) {
		if (poly[i].expo!=0) 
			printf("(%dx^%d)", poly[i].coeff, poly[i].expo);
	    else
			printf("(%d)", poly[i].coeff);
	    if (i!=n-1)
			printf(" + ");
	}
}

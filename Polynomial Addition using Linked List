#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *link;
} *poly1 = NULL, *poly2 = NULL, *psum = NULL;

void insertterm (struct node **p, int coefficient, int exponent) {
    if (coefficient == 0) return; 
    
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp->coeff = coefficient;
    temp->expo = exponent;
    temp->link = NULL;
    
    if (*p == NULL) {
        *p = temp;
    } else {
        struct node *ptr = *p;
        while (ptr->link != NULL) 
            ptr = ptr->link;
        ptr->link = temp;
    }
}

void display (struct node *p) {
    struct node *ptr = p;
    while (ptr != NULL) {        
        if (ptr->expo != 0) 
            printf("(%dx^%d)", ptr->coeff, ptr->expo);
        else 
            printf("(%d)", ptr->coeff);
        
        if (ptr->link != NULL)
            printf(" + ");
        ptr = ptr->link;
    }
}

void computesum (struct node *p1, struct node *p2) {
    while (p1 != NULL && p2 != NULL) {
        if  (p1->expo > p2->expo) {
            insertterm(&psum, p1->coeff, p1->expo);
            p1 = p1->link;
        } else if (p1->expo < p2->expo) {
            insertterm(&psum, p2->coeff, p2->expo);  
            p2 = p2->link;
        } else {
            insertterm(&psum, (p1->coeff + p2->coeff), p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        insertterm(&psum, p1->coeff, p1->expo);
        p1 = p1->link;
    }
    while (p2 != NULL) {
        insertterm(&psum, p2->coeff, p2->expo);
        p2 = p2->link;
    }
}

void main() {
    int i, n1, n2, coefficient, exponent;
    
    printf("Enter First Polynomial -\n");
    printf("Enter number of terms: ");
    scanf("%d", &n1);
    
    for (i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertterm(&poly1, coefficient, exponent);
    }

    printf("\nEnter Second Polynomial -\n");
    printf("Enter number of terms: ");
    scanf("%d", &n2);
    
    for (i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertterm(&poly2, coefficient, exponent);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("\nSecond Polynomial: ");
    display(poly2);

    computesum(poly1, poly2);

    printf("\nSum of the two Polynomials: ");
    display(psum);
}

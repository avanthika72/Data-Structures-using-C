#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int max = 50,top=-1;
char A[100];
void push(char c) {
    A[++top] = c;
}
char pop() {
    return A[top--];
}
int preced(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}
void intopostfix(char infix[], char postfix[]) {
    int i=0,j=0;

    for (i = 0; i < strlen(infix); i++) {
        if (isspace(infix[i])) 
            continue;
        if (isalnum(infix[i])) 
            postfix[j++] = infix[i];
        else if (infix[i] == '(') 
            push(infix[i]);
        else if (infix[i] == ')') {
            while (A[top] != '(') 
                postfix[j++] = pop();
            pop();
        } 
        else {
            while (top != -1 && preced(A[top]) >= preced(infix[i])) 
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1) 
        postfix[j++] = pop();
    postfix[j] = '\0';
}
void main() {
    char infix[max], postfix[max];
    printf("Enter infix expression: ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = 0;
    intopostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}

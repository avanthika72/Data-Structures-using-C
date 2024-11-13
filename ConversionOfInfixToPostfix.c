#include<stdio.h>
#include<ctype.h>
void push(char);
int priority(char);
char pop();
int top = -1;
char stack[50];
void main() {
    char ch, infix[50];
    int i=0,item;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression: ");
    while ( (ch = infix[i]) != '\0') { 
        if (isspace(ch)) 
            continue;
        else if (ch == '(' || ch == '^') 
            push(ch);
        else if (isalnum(ch)) 
            printf("%c", ch);
        else if (ch == ')') {
            while ((item = pop()) != '(') {  
                printf("%c", item);
        } } 
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
        i++;
    }
    while (top != -1) {
        printf("%c", pop());
} }
void push(char ch) {
    if (top >= 49) {
        printf("\nStack Overflow\n");
    } 
   else {
        stack[++top] = ch;
} } 
char pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    } 
    else {
        return stack[top--];
} }
int priority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else 
        return 0;
}

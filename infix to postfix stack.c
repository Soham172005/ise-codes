#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

void infixToPostfix(char* expression) {
    char output[MAX];
    int i, k = 0;

    for (i = 0; i < strlen(expression); i++) {
        char token = expression[i];

        if (isalnum(token)) {
            output[k++] = token;
        }
        else if (token == '(') {
            push(token);
        }
        else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop(); 
        }
        else if (isOperator(token)) {
            while (top != -1 && precedence(stack[top]) >= precedence(token) && token != '^') {
                output[k++] = pop();
            }
            push(token);
        }
    }

    while (top != -1) {
        output[k++] = pop();
    }
    
    output[k] = '\0';
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char expression[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);

    return 0;
}
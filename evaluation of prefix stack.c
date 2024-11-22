#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int evaluatePrefix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i;

    for (i = strlen(expression) - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0'); 
        }
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (expression[i]) {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char expression[100];
    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    printf("Result of evaluation: %d\n", evaluatePrefix(expression));
    return 0;
}
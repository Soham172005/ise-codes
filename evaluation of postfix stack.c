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

int evaluatePostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i;

    for (i = 0; expression[i]; ++i) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0'); 
        }
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (expression[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    printf("Result of evaluation: %d\n", evaluatePostfix(expression));
    return 0;
}

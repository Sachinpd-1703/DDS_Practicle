//Implement Postfix evaluation using Stack.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    Stack s;
    initialize(&s);
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        
        if (isdigit(ch)) {
            // Push operand onto the stack
            push(&s, ch - '0');
        } else if (isspace(ch)) {
            // Ignore whitespace
            continue;
        } else {
            // Pop two operands for the operator
            operand2 = pop(&s);
            operand1 = pop(&s);
            
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            // Push the result onto the stack
            push(&s, result);
        }
    }
    
    // The final result is the only element left in the stack
    return pop(&s);
}

int main() {
    char postfix[] = "3 4 + 2 * 7 /";
    int result = evaluatePostfix(postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", result);
    return 0;
}

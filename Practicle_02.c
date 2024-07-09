#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char item[MAX];
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty 
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element into the stack
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->item[++(s->top)] = item;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->item[(s->top)--];
}

// Function to return the top element of the stack without popping it
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->item[s->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to determine the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initialize(&s);
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    // Pop all remaining operators from stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

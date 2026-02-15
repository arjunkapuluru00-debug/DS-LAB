#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    return stack[top--];
}

// Function to check precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        // If operand, add to postfix
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        // If '(', push to stack
        else if (symbol == '(') {
            push(symbol);
        }
        // If ')', pop until '('
        else if (symbol == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}


char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

     
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
     
        else if (symbol == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
     
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

  
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}


int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

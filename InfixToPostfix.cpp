#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int precedence(char symbol) {
    if(symbol == '^') return 3;
    else if(symbol == '*' || symbol == '/') return 2;
    else if(symbol == '+' || symbol == '-') return 1;
    else return 0;
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

void infixToPostfix(char* infix) {
    char postfix[SIZE] = "";
    int i, k = 0;
    char symbol;
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if(isalnum(symbol)) {
            postfix[k++] = symbol;
        } else if(symbol == '(') {
            push(symbol);
        } else if(symbol == ')') {
            while(peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // pop '('
        } else {
            while(top != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixToPostfix(infix);
    return 0;
}


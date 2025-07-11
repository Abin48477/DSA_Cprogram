#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int precedence(char ch) {
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
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

void reverse(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infixToPrefix(char* infix) {
    char postfix[SIZE] = "", symbol;
    int i, k = 0;

    reverse(infix);

    for(i = 0; i < strlen(infix); i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if(isalnum(symbol)) {
            postfix[k++] = symbol;
        } else if(symbol == '(') {
            push(symbol);
        } else if(symbol == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
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

    reverse(postfix);

    printf("Prefix Expression: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixToPrefix(infix);
    return 0;
}


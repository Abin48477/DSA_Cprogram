#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE][SIZE];
int top = -1;

// Push function with overflow check
void push(char *str) {
    if (top >= SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    strcpy(stack[++top], str);
}

// Pop function with underflow check
char* pop() {
    if (top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Convert postfix to infix
void postfixToInfix(char *postfix) {
    char a[SIZE], b[SIZE], temp[SIZE];

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char str[2] = {ch, '\0'};
            push(str);
        } else {
            if (top < 1) {
                printf("Error: Malformed postfix expression\n");
                return;
            }
            strcpy(a, pop());
            strcpy(b, pop());
            sprintf(temp, "(%s%c%s)", b, ch, a);
            push(temp);
        }
    }

    if (top != 0) {
        printf("Error: Invalid postfix expression\n");
        return;
    }

    printf("Infix Expression: %s\n", pop());
}

int main() {
    char postfix[SIZE];
    printf("Enter Postfix Expression: ");
    if (fgets(postfix, SIZE, stdin)) {
        postfix[strcspn(postfix, "\n")] = '\0'; // remove newline if present
        postfixToInfix(postfix);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}

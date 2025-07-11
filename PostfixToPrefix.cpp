#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
char stack[SIZE][SIZE];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

void postfixToPrefix(char* postfix) {
    char a[SIZE], b[SIZE], temp[SIZE];
    for(int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char str[2] = {ch, '\0'};
            push(str);
        } else {
            strcpy(a, pop());
            strcpy(b, pop());
            sprintf(temp, "%c%s%s", ch, b, a);
            push(temp);
        }
    }
    printf("Prefix Expression: %s\n", pop());
}

int main() {
    char postfix[SIZE];
    printf("Enter Postfix Expression: ");
    gets(postfix);
    postfixToPrefix(postfix);
    return 0;
}


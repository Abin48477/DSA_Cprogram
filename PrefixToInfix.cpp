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

void prefixToInfix(char* prefix) {
    char a[SIZE], b[SIZE], temp[SIZE];
    int len = strlen(prefix);

    for(int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if(isalnum(ch)) {
            char str[2] = {ch, '\0'};
            push(str);
        } else {
            strcpy(a, pop());
            strcpy(b, pop());
            sprintf(temp, "(%s%c%s)", a, ch, b);
            push(temp);
        }
    }

    printf("Infix Expression: %s\n", pop());
}

int main() {
    char prefix[SIZE];
    printf("Enter Prefix Expression: ");
    gets(prefix);
    prefixToInfix(prefix);
    return 0;
}


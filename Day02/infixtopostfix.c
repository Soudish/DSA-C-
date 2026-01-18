#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
};

int isEmpty(struct node* top) {
    return top == NULL;
}

struct node* push(struct node* top, char ch) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = ch;
    p->next = top;
    return p;
}

struct node* pop(struct node* top, char *popped) {
    if (isEmpty(top)) return NULL;
    *popped = top->data;
    struct node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int precedence(char op) {
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

char* intopo(char *infix) {
    struct node *top = NULL;
    char *postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int k = 0;  
    char popped;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch; 
        } 
        else if (ch == '(') {
            top = push(top, ch);
        } 
        else if (ch == ')') {
            while (!isEmpty(top) && top->data != '(') {
                top = pop(top, &popped);
                postfix[k++] = popped;
            }
            if (!isEmpty(top) && top->data == '(') {
                top = pop(top, &popped); 
            }
        } 
        else {]
            while (!isEmpty(top) && precedence(top->data) >= precedence(ch)) {
                top = pop(top, &popped);
                postfix[k++] = popped;
            }
            top = push(top, ch);
        }
    }

    while (!isEmpty(top)) {
        top = pop(top, &popped);
        postfix[k++] = popped;
    }

    postfix[k] = '\0'; 
    return postfix;
}

int main() {
    char infix[200];
    printf("Enter infix expression: ");
    scanf("%199s", infix);

    char *postfix = intopo(infix);
    printf("Postfix: %s\n", postfix);

    free(postfix);
    return 0;
}

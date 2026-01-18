#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *push(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = head;
    return newNode;
}

int pop(struct Node **head) {
    if (*head == NULL) {
        printf("Stack empty\n");
        return 0;
    }
    struct Node *ptr = *head;
    int num = ptr->val;
    *head = ptr->next;
    free(ptr);
    return num;
}

int postfixevaluation(char *postfix) {
    struct Node *head = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            head = push(head, c - '0');
        } else {
            int n1 = pop(&head);
            int n2 = pop(&head);

            switch (c) {
                case '+': head = push(head, n2 + n1); break;
                case '-': head = push(head, n2 - n1); break;
                case '*': head = push(head, n2 * n1); break;
                case '/': head = push(head, n2 / n1); break;
            }
        }
    }
    return pop(&head);
}

int main() {
    char postfix[200];
    printf("Enter postfix expression: ");
    scanf("%199s", postfix);

    int result = postfixevaluation(postfix);
    printf("Result = %d\n", result);

    return 0;
}

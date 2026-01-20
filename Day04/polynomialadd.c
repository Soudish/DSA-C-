#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* create(int c, int p) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->coeff = c;
    n->power = p;
    n->next = NULL;
    return n;
}

void insert(struct Node** head, int c, int p) {
    struct Node* n = create(c, p);
    if (*head == NULL || (*head)->power < p) {
        n->next = *head;
        *head = n;
        return;
    }
    struct Node* t = *head;
    struct Node* prev = NULL;

    while (t != NULL && t->power > p) {
        prev = t;
        t = t->next;
    }

    if (t != NULL && t->power == p) {
        t->coeff += c;
        free(n); // no need to insert duplicate
    } else {
        n->next = t;
        if (prev != NULL)
            prev->next = n;
        else
            *head = n;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        if (head->coeff != 0) {
            printf("%dx^%d", head->coeff, head->power);
            if (head->next != NULL && head->next->coeff >= 0)
                printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

struct Node* add(struct Node* a, struct Node* b) {
    struct Node* res = NULL;
    while (a != NULL && b != NULL) {
        if (a->power > b->power) {
            insert(&res, a->coeff, a->power);
            a = a->next;
        } else if (a->power < b->power) {
            insert(&res, b->coeff, b->power);
            b = b->next;
        } else {
            insert(&res, a->coeff + b->coeff, a->power);
            a = a->next;
            b = b->next;
        }
    }
    while (a != NULL) {
        insert(&res, a->coeff, a->power);
        a = a->next;
    }
    while (b != NULL) {
        insert(&res, b->coeff, b->power);
        b = b->next;
    }
    return res;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    int n, i, c, p;

    printf("Enter number of terms in first polynomial:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        scanf("%d %d", &c, &p);
        insert(&poly1, c, p);
    }

    printf("Enter number of terms in second polynomial:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        scanf("%d %d", &c, &p);
        insert(&poly2, c, p);
    }

    sum = add(poly1, poly2);

    printf("Resultant polynomial:\n");
    display(sum);
    return 0;
}


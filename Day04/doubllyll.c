#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBegin(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos <= 1)
        return insertAtBegin(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return insertAtEnd(head, data);
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* deleteAtBegin(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL)
        return NULL;
    if (pos <= 1)
        return deleteAtBegin(head);
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return head;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL\n");
        temp = temp->next;
    }
}

struct Node* reverse(struct Node* head) {
    struct Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display\n8. Reverse\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBegin(head, data);
                printf("Inserted %d at beginning\n", data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Inserted %d at end\n", data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtPosition(head, data, pos);
                printf("Inserted %d at position %d\n", data, pos);
                break;
            case 4:
                if (head != NULL) {
                    printf("Deleted %d from beginning\n", head->data);
                    head = deleteAtBegin(head);
                } else {
                    printf("List is empty, cannot delete\n");
                }
                break;
            case 5:
                if (head != NULL) {
                    struct Node* temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    printf("Deleted %d from end\n", temp->data);
                    head = deleteAtEnd(head);
                } else {
                    printf("List is empty, cannot delete\n");
                }
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                {
                    struct Node* temp = head;
                    int i;
                    for (i = 1; i < pos && temp != NULL; i++)
                        temp = temp->next;
                    if (temp != NULL) {
                        printf("Deleted %d from position %d\n", temp->data, pos);
                        head = deleteAtPosition(head, pos);
                    } else {
                        printf("Position %d does not exist\n", pos);
                    }
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                head = reverse(head);
                printf("List reversed\n");
                break;
            case 9:
                while (head != NULL)
                    head = deleteAtBegin(head);
                printf("Exited program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

    
                    
            

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};


int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}


int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}


void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot insert.\n");
    } else {
        if (q->front == -1) 
            q->front = 0;
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}


void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot delete.\n");
    } else {
        printf("%d deleted from the queue.\n", q->arr[q->front]);
        q->front++;
    }
}


void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    int choice, value;

    printf("Enter size of the queue: ");
    scanf("%d", &q.size);

    q.arr = (int *)malloc(q.size * sizeof(int));
    if (q.arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    q.front = -1;
    q.rear = -1;

    while (1) {
        printf("\n----- Linear Queue Menu -----\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting program.\n");
                free(q.arr); 
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

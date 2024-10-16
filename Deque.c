#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} Deque;

Deque* createDeque() {
    Deque* q = (Deque*)malloc(sizeof(Deque));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Deque* q) {
    return ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1));
}

int isEmpty(Deque* q) {
    return (q->front == -1);
}

void insertFront(Deque* q, int value) {
    if (isFull(q)) {
        printf("Deque is full!\n");
        return;
    }
    if (q->front == -1) { // Initial condition
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = SIZE - 1; // Wrap around
    } else {
        q->front--;
    }
    q->items[q->front] = value;
    printf("Inserted %d at front\n", value);
}

int deleteRear(Deque* q) {
    int element;
    if (isEmpty(q)) {
        printf("Deque is empty!\n");
        return -1;
    }
    element = q->items[q->rear];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = SIZE - 1; // Wrap around
    } else {
        q->rear--;
    }
    printf("Deleted %d from rear\n", element);
    return element;
}

void display(Deque* q) {
    if (isEmpty(q)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE; // Circular increment
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Delete from rear\n");
        printf("3. Display deque\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;
            case 2:
                deleteRear(dq);
                break;
            case 3:
                display(dq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

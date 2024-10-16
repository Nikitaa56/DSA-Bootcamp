#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int queue[SIZE];
    int front;
    int rear;
} CircularQueue;

int isFull(CircularQueue* q) {
    return ((q->rear + 1) % SIZE == q->front);
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

void enQueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->queue[q->rear] = value;
    printf("Inserted %d\n", value);
}

int deQueue(CircularQueue* q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    element = q->queue[q->front];
    if (q->front == q->rear) {
        // Only one element left in the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Deleted %d\n", element);
    return element;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    int i = q->front;
    printf("Queue elements are: ");
    
    while (i != q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", q->queue[i]); // Print the last element (rear)
}

int main() {
    CircularQueue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;
    
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enQueue(&q, value);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

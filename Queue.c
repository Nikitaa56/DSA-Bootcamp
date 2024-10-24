#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int Queue[MAXSIZE];
int front = 0;
int rear = -1;

// Function to insert an element into the queue
void insert() {
    if (rear == MAXSIZE - 1) {
        printf("\nQueue Overflow\n");
    } else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        rear++;
        Queue[rear] = n;
    }
}

// Function to delete an element from the queue
void delete() {
    if (front > rear) {
        printf("\nQueue Underflow\n");  // Queue is empty
    } else {
        printf("\nDeleted element: %d\n", Queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if (front > rear) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

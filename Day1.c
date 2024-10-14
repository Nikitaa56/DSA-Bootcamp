#include <stdio.h>
#define MAXSIZE 10  // Define MAXSIZE correctly

int stack[MAXSIZE];
int top = -1;

void push();
void pop();
void display();

int main()  // Correct main function signature
{
    int choice;  // `choice` should be a variable, not a function
    do {
        printf("\n1. Push \n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;  // Return from main function
}

void push() {
    int n;
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } else {
        printf("Enter an element: ");
        scanf("%d", &n);
        top++;  // Increment top index
        stack[top] = n;
        printf("Element pushed: %d\n", n);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");  // Stack is empty
    } else {
        int n = stack[top];  // Get the top element
        top--;  // Decrement top index
        printf("Popped element is %d\n", n);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");  // No elements to display
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);  // Display each element
        }
        printf("\n");
    }
}


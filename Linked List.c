#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* add;
};

struct node* start = NULL, *temp, *new1;

void create() {
    int n;
    char ch;
    
    printf("Enter element: ");
    scanf("%d", &n);
    
    start = (struct node*)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;
    
    printf("Want to continue adding nodes (y/n)? ");
    getchar(); // to consume the newline character left by previous input
    ch = getchar(); // replace getche() with getchar()
    
    while (ch == 'y' || ch == 'Y') {
        printf("Enter next element: ");
        scanf("%d", &n);
        
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        
        temp->add = new1;
        temp = new1;
        
        printf("Want to continue adding nodes (y/n)? ");
        getchar(); // to consume the newline
        ch = getchar();
    }
}

void display() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->add;
        }
        printf("NULL\n");
    }
}

void deleteFront() {
    if (start == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }
    
    struct node* temp = start;
    printf("Deleted element: %d\n", temp->data);
    start = start->add;
    
    free(temp);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Delete from Front\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

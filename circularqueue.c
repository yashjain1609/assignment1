#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1;
int rear = -1;


int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}


int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}


void insert(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", value);
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted %d into the queue\n", value);
}


void delete() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot delete\n");
        return;
    }
    
    printf("Deleted %d from the queue\n", queue[front]);
    
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    
    printf("\n");
}


void peep() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Peep\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                peep();
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full!\n");
                } else {
                    printf("Queue is not full!\n");
                }
                break;
            case 6:
                if (isEmpty()) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue is not empty!\n");
                }
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}


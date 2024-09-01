#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    if (rear == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

// Function to insert an element in the queue
void insert(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

// Function to delete an element from the queue
void delete() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot delete\n");
    } else {
        printf("Deleted %d from the queue\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset queue if it becomes empty
        }
    }
}

// Function to traverse the queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to peep (view the front element)
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
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
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
                traverse();
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

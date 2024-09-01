#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int stack[MAX];
int top = -1;


int isFull() {
    if (top == MAX - 1) {
        return 1;
    }
    return 0;
}


int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

void push(int value) {
    if (isFull()) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}


void pop() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot pop\n");
    } else {
        printf("Popped %d from the stack\n", stack[top--]);
    }
}

void peep() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isFull()) {
                    printf("Stack is full!\n");
                } else {
                    printf("Stack is not full!\n");
                }
                break;
            case 6:
                if (isEmpty()) {
                    printf("Stack is empty!\n");
                } else {
                    printf("Stack is not empty!\n");
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

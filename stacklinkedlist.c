#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Stack overflow\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *top_ref;
    *top_ref = new_node;
    printf("%d pushed onto the stack\n", new_data);
}


void pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    printf("%d popped from the stack\n", temp->data);
    free(temp);
}


void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to traverse the stack
void traverse(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void menu() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                traverse(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

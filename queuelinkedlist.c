#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}


void enqueue(struct Queue* queue, int value) {
    struct Node* temp = newNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        printf("%d enqueued to the queue\n", value);
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
    printf("%d enqueued to the queue\n", value);
}


void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty, nothing to dequeue\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("%d dequeued from the queue\n", temp->data);
    free(temp);
}


void peek_front(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue->front->data);
    }
}


void traverse(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void menu() {
    struct Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                peek_front(queue);
                break;
            case 4:
                traverse(queue);
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

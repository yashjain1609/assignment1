#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


void insert_at_front(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
    printf("%d inserted at the front\n", new_data);
}


void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        printf("%d inserted at the end\n", new_data);
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    printf("%d inserted at the end\n", new_data);
}

void delete_last_node(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (temp->next == NULL) {  
        *head_ref = NULL;
        free(temp);
        printf("Last node deleted\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}


void delete_before_position(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 1) {
        printf("Invalid position or no node exists before the specified position\n");
        return;
    }

    struct Node* temp = *head_ref;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("No node exists before the specified position\n");
        return;
    }

    struct Node* node_to_delete = temp->prev;
    if (node_to_delete->prev != NULL) {
        node_to_delete->prev->next = temp;
        temp->prev = node_to_delete->prev;
    } else {
        *head_ref = temp;
        temp->prev = NULL;
    }

    free(node_to_delete);
    printf("Node before position %d deleted\n", position);
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void menu() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Delete the last node\n");
        printf("4. Delete a node before a specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &data);
                insert_at_front(&head, data);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                delete_last_node(&head);
                break;
            case 4:
                printf("Enter the position before which to delete: ");
                scanf("%d", &position);
                delete_before_position(&head, position);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

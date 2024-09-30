#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("%d inserted at the end\n", new_data);
}


void insert_before_position(struct Node** head_ref, int new_data, int pos) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = new_data;

    if (pos == 1 || *head_ref == NULL) {
        new_node->next = *head_ref;

        if (*head_ref != NULL) {
            while (temp->next != *head_ref) {
                temp = temp->next;
            }
            temp->next = new_node;
        } else {
            new_node->next = new_node;
        }
        *head_ref = new_node;
        printf("%d inserted before position %d\n", new_data, pos);
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != *head_ref; i++) {
        temp = temp->next;
    }

    if (temp->next == *head_ref && pos != 2) {
        printf("Position out of range\n");
        free(new_node);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("%d inserted before position %d\n", new_data, pos);
    }
}


void delete_first_node(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head_ref;

    if ((*head_ref)->next == *head_ref) {
        free(*head_ref);
        *head_ref = NULL;
    } else {
        struct Node* last = *head_ref;

        while (last->next != *head_ref) {
            last = last->next;
        }

        last->next = (*head_ref)->next;
        *head_ref = (*head_ref)->next;
        free(temp);
    }

    printf("First node deleted\n");
}


void delete_after_position(struct Node** head_ref, int pos) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < pos && temp->next != *head_ref; i++) {
        temp = temp->next;
    }

    if (temp->next == *head_ref) {
        printf("No node exists after position %d\n", pos);
        return;
    }

    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;

    if (node_to_delete == *head_ref) {
        *head_ref = node_to_delete->next;
    }

    free(node_to_delete);
    printf("Node after position %d deleted\n", pos);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}


void menu() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Insert a node before a specified position\n");
        printf("3. Delete the first node\n");
        printf("4. Delete a node after a specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position before which to insert: ");
                scanf("%d", &pos);
                insert_before_position(&head, data, pos);
                break;
            case 3:
                delete_first_node(&head);
                break;
            case 4:
                printf("Enter position after which to delete: ");
                scanf("%d", &pos);
                delete_after_position(&head, pos);
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

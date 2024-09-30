#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insert_front(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}


void insert_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}


void insert_sorted(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current;

    new_node->data = new_data;

    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_first(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}


void delete_before_position(struct Node** head_ref, int pos) {
    if (*head_ref == NULL || pos <= 1) {
        printf("Invalid position or list is too short\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (pos == 2) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* node_to_delete = prev->next;
    prev->next = node_to_delete->next;
    free(node_to_delete);
}

void delete_after_position(struct Node* head, int pos) {
    struct Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void menu() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert node at front\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node in sorted order\n");
        printf("4. Delete first node\n");
        printf("5. Delete node before specified position\n");
        printf("6. Delete node after specified position\n");
        printf("7. Traverse list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &data);
                insert_front(&head, data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &data);
                insert_sorted(&head, data);
                break;
            case 4:
                delete_first(&head);
                break;
            case 5:
                printf("Enter the position before which to delete: ");
                scanf("%d", &pos);
                delete_before_position(&head, pos);
                break;
            case 6:
                printf("Enter the position after which to delete: ");
                scanf("%d", &pos);
                delete_after_position(head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
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

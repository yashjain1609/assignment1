#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}


void inorder_traversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}


void preorder_traversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


void postorder_traversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}


void menu() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;
            case 5:
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

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory not allocated!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int i;

    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    struct Node *temp = head;

    if (position == 1) {
        head = head->next;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        return;
    }

    struct Node *prev = NULL;

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void cleanupList() {
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("Memory successfully freed.\n");
}

int main() {
    int choice = 0, value, position;

    do {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting program.\n");
                cleanupList();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}

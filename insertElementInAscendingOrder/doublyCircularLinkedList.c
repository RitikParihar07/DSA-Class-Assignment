#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node Node;

Node *createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->info = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertSortedDoublyCircular(Node **front, Node **rear, int key) {
    Node *newNode = createNode(key);

    if (*front == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        *front = newNode;
        *rear = newNode;
    } else if (key <= (*front)->info) {
        Node *tail = *rear;

        newNode->next = *front;
        newNode->prev = tail;

        tail->next = newNode;
        (*front)->prev = newNode;

        *front = newNode;
    } else {
        Node *current = *front;

        while (current->next != *front && key > current->next->info) {
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;

        current->next->prev = newNode;
        current->next = newNode;

        if (current == *rear) {
            *rear = newNode;
        }
    }
}

void displayDoublyCircular(Node *front) {
    if (front == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = front;

    do {
        printf("%d ", current->info);
        current = current->next;
    } while (current != front);

    printf("\n");
}

int main(void) {
    Node *front = NULL;
    Node *rear = NULL;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insertSortedDoublyCircular(&front, &rear, key);
    }

    printf("Sorted doubly circular linked list: ");
    displayDoublyCircular(front);

    return 0;
}

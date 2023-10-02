#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

Node *insertSortedDoubly(Node *head, int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = key;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;

    while (current != NULL) {
        if (key <= current->info) {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                head = newNode;
            }
            current->prev = newNode;
            return head;
        }
        if (current->next == NULL) {
            newNode->prev = current;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    return head;
}

void displayDoubly(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }

    printf("\n");
}

int main(void) {
    Node *head = NULL;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        head = insertSortedDoubly(head, key);
    }

    printf("Sorted doubly linked list: ");
    displayDoubly(head);

    return 0;
}

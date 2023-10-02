#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node Node;

void insertSortedCircular(Node **f, Node **r, int key) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->info = key;

    if (*f == NULL) {
        temp->next = temp;
        *f = temp;
        *r = temp;
    } else if (key < (*f)->info) {
        temp->next = *f;
        (*r)->next = temp;
        *f = temp;
    } else {
        Node *current = *f;
        while (current->next != *f && key >= current->next->info) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        if (current == *r) {
            *r = temp;
        }
    }
}

void displayCircular(Node *f) {
    if (f == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = f;

    do {
        printf("%d ", current->info);
        current = current->next;
    } while (current != f);

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
        insertSortedCircular(&front, &rear, key);
    }

    printf("Sorted circular list: ");
    displayCircular(front);

    return 0;
}

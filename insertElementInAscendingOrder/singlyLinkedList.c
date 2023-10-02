#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node Node;

void insertSorted(Node **head, int key) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->info = key;
    temp->next = NULL;

    if (*head == NULL || key < (*head)->info) {
        temp->next = *head;
        *head = temp;
    } else {
        Node *current = *head;
        while (current->next != NULL && key >= current->next->info) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void display(Node **head) {
    Node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
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
        insertSorted(&head, key);
    }

    printf("Sorted list: ");
    display(&head);

    return 0;
}

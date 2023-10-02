#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expon;
    struct node* next;
};

typedef struct node node;

void enqueue(node** f, node** r, int coefficient, int exponent) {
    node* temp = (node*)malloc(sizeof(node));
    temp->coeff = coefficient;
    temp->expon = exponent;
    temp->next = NULL;

    if (*f == NULL) {
        *f = temp;
        *r = temp;
    } else {
        (*r)->next = temp;
        *r = temp;
    }
}

void comparison(node* f1, node* f2) {
    node* temp1 = f1;
    node* temp2 = f2;
    printf("Result: ");
    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 == NULL) {
            printf("%dx^%d ", temp2->coeff, temp2->expon);
            temp2 = temp2->next;
        } else if (temp2 == NULL) {
            printf("%dx^%d ", temp1->coeff, temp1->expon);
            temp1 = temp1->next;
        } else if (temp1->expon == temp2->expon) {
            int new_coeff = temp1->coeff + temp2->coeff;
            printf("%dx^%d ", new_coeff, temp1->expon);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->expon > temp2->expon) {
            printf("%dx^%d ", temp1->coeff, temp1->expon);
            temp1 = temp1->next;
        } else {
            printf("%dx^%d ", temp2->coeff, temp2->expon);
            temp2 = temp2->next;
        }
    }
    printf("\n");
}

void readPolynomial(node** f, node** r, char* polynomial) {
    int coefficient = 0;
    int exponent = 0;
    int op = 1;
    int len = strlen(polynomial);

    for (int i = 0; i < len; i++) {
        if (polynomial[i] == '-') {
            op = -1;
            i++;
        }

        if (polynomial[i] >= '0' && polynomial[i] <= '9') {
            while (polynomial[i] != 'x') {
                coefficient = (coefficient * 10) + polynomial[i] - '0';
                i++;
            }
            i++;
            i++;

            while (polynomial[i] != '+' && polynomial[i] != '-' && polynomial[i] != '\0') {
                exponent = (exponent * 10) + polynomial[i] - '0';
                i++;
            }
            i--;

            coefficient = coefficient * op;
            enqueue(f, r, coefficient, exponent);
            op = 1;
            coefficient = 0;
            exponent = 0;
        }
    }
}

int main() {
    node* Front1 = NULL;
    node* Rear1 = NULL;
    node* Front2 = NULL;
    node* Rear2 = NULL;
    char string_1[100];
    char string_2[100];

    printf("Enter first polynomial (format: ax^1+bx^2+cx^0): ");
    scanf("%s", string_1);
    printf("Enter second polynomial (format: ax^1+bx^2+cx^0): ");
    scanf("%s", string_2);

    readPolynomial(&Front1, &Rear1, string_1);
    readPolynomial(&Front2, &Rear2, string_2);

    comparison(Front1, Front2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        struct Node* newNode = 
            (struct Node*)malloc(sizeof(struct Node));
        newNode->coef = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coef);
        }
        else if (temp->exp == 1) {
            printf("%dx", temp->coef);
        }
        else {
            printf("%dx^%d", temp->coef, temp->exp);
        }

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}

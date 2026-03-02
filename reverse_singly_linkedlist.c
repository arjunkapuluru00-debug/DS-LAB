#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display(struct Node* temp) {
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    int N, value;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insertBeginning(value);
    }

    display(head);

    head = reverse(head);

    printf("\n");
    display(head);

    return 0;
}

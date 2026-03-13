#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

void insertPosition(struct Node** head, int value, int pos) {
    struct Node* newNode = createNode(value);

    if (pos == 1) {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node* head, int count) {
    struct Node* temp = head;
    for (int i = 0; i < count; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, pos, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    scanf("%d", &value);
    scanf("%d", &pos);

    insertPosition(&head, value, pos);

    display(head, n + 1);

    return 0;
}

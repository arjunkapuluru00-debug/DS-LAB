#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void reverseQueue(int size) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < size; i++)
        stack[++top] = dequeue();

    front = 0;
    rear = -1;

    while (top != -1)
        enqueue(stack[top--]);
}

int main() {
    int capacity, value;

    scanf("%d", &capacity);

    for (int i = 0; i < capacity; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Original queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    reverseQueue(capacity);

    printf("\nReversed queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}

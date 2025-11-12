#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int items[SIZE];
int rear = -1;
int front = -1;

int isFull() {
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("\n Queue is full! \n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n inserted-> %d \n", element);
    }
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\n queue is empty\n");
        return (-1);
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\n deleted element-> %d \n", element);
        return (element);
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\n empty queue\n");
    } else {
        printf("\n front->%d", front);
        printf("\n items-> ");

        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d", items[i]);

        printf("\n rear->%d\n", rear);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();

    enqueue(60);

    display();

    enqueue(70);

    return 0;
}

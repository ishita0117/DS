#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

int isEmptyQ(Queue *q) {
    return (q->front == -1);
}

void enqueue(Queue *q, int x) {
    if (q->rear == q->size - 1) return;

    if (q->front == -1) q->front = 0;
    q->data[++(q->rear)] = x;
}

int dequeue(Queue *q) {
    if (isEmptyQ(q)) return -1;

    int val = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return val;
}

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);

    while (!isEmptyQ(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    Queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    if (isEmptyQ(obj->q1)) return -1;
    return obj->q1->data[obj->q1->front];
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQ(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();

    myStackPush(stack, 10);
    printf("Pushed 10. Top: %d\n", myStackTop(stack));

    myStackPush(stack, 20);
    printf("Pushed 20. Top: %d\n",

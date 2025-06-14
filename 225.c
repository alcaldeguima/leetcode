#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int val) {
    if (q->size == SIZE) return; // Fila cheia
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % SIZE;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    q->size--;
    return val;
}

int frontQueue(Queue* q) {
    if (isEmptyQueue(q)) return -1;
    return q->data[q->front];
}

// ----------------- PILHA ---------------------

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);
    while (!isEmptyQueue(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    // Troca q1 com q2
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return frontQueue(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

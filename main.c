#include <stdio.h>
#include <stdlib.h>
#define max 10000

typedef int item;
struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    item array[max];
};

 void creatqueue (struct Queue *Q) 
{
    Q->front = 0; 
    Q->rear = -1; 
    Q->size = 0; 
};

int isFull(struct Queue *Q) {
    if (Q->size == max) 
        return 1;
    return 0;
};

int isEmpty(struct Queue *Q) {
    
    if (Q->size == 0) 
        return 1;
    return 0;
};

int enqueue(struct Queue *Q,int v) {
    if(isFull(Q)){
		printf("Queue is full");
	}else{
		Q->array[Q->rear++];
        Q->rear=v;
        Q->size++;
	}
    return v;
};

int dequeue(struct Queue  *Q) {
    if(isEmpty(Q)){
		printf("Queue is empty");
	}else{
		item x = Q->array[Q->front];
        for (int i=Q->front; i<Q->rear; i++) 
            Q->array[i] = Q->array[i+1];
        Q->rear--; 
        Q->size--;
        return x; 
	}
};
int GetFront(struct Queue  *Q, int front){
    return Q->array[front];
};
int GetRear(struct Queue  *Q, int rear){
    return Q->array[rear-1];
};

int main() {
    struct Queue Q;
    int front;
    int rear;

    // Thêm phần tử vào Queue
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d dequeued from queue\n", dequeue(&Q));
    printf("%d dequeued from queue\n", dequeue(&Q));

    // Thêm phần tử mới vào Queue
    enqueue(&Q, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("Front item is %d\n",GetFront(&Q,front));
    printf("Rear item is %d\n", GetRear(&Q,rear));

    return 0;
}

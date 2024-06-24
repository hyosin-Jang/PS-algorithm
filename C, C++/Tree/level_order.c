#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// 원형큐 코드
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct QueueType {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error (char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화 함수
void init_queue(QueueType *q){
    q->front = q->rear = 0;
}

// 공백 상태 검출
int is_empty(QueueType *q){
    return (q->front == q->rear);
}

// 포화 상태 검출
int is_full(QueueType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입
void enqueue(QueueType *q, element item){

    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제
element dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_order(TreeNode *ptr){
    QueueType q;

    init_queue(&q);

    if(ptr == NULL) return;
    enqueue(&q, ptr);

    while(!is_empty(&q)){
        ptr = dequeue(&q);
        printf("[%d]", ptr->data);
        if(ptr->left) enqueue(&q, ptr->left);
        if(ptr->right) enqueue(&q, ptr->right);
    }
}

int main(){

    return 0;
}
// 队列与栈的入队入栈程序不同，一个为尾插法一个为头插法，但是出队出栈程序相同，都为删除表头元素

// 带头结点的队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode{
    int data;
    struct QueueNode *next, *front, *rear;
} QueueNode, *LinkQueue;

// 初始化链队
void InitQueue(LinkQueue Q)
{
    Q->front = Q->rear = (QueueNode*)malloc(sizeof(QueueNode)); // 建立头结点
    Q->front->next = NULL;
}

// 判队空
bool isEmpty(LinkQueue Q)
{
    if(Q->front == Q->rear){
        return true;
    }else{
        return false;
    }
}

// 入队（链表尾插法）
void EnQueue(LinkQueue Q)
{
    int x;
    QueueNode* s;
    scanf("%d", &x);
    while(x != 9999){
        s = (QueueNode *)malloc(sizeof(QueueNode));
        s->data = x;
        s->next = NULL;
        Q->rear->next = s;
        Q->rear = s;
        scanf("%d", &x);
    }
}

// 出队
void DeQueue(LinkQueue Q)
{
    QueueNode *s = Q->front->next;
    Q->front->next = s->next;
    free(s);
}

int main(void)
{
    LinkQueue Q;
    Q = (QueueNode*)malloc(sizeof(QueueNode));
    InitQueue(Q);

    bool flag_1 = isEmpty(Q);
    if(flag_1){
        printf("Queue is Empty\n");
        printf("\n");
    }else{
        printf("Queue is not Empty\n");
        printf("\n");
    }

    EnQueue(Q);
    QueueNode* p = Q->front->next;
    printf("LinkQueue:");
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

    DeQueue(Q);
    QueueNode* q = Q->front->next;
    printf("LinkQueue:");
    while(q != NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    printf("\n");

    return 0;
}
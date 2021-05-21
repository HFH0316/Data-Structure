// 顺序队列
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int front, rear;
} SqQueue;

//初始化
void InitQueue(SqQueue* Q)
{
    Q->front = Q->rear = 0;// 循环队列为空时队头队尾指针均为0
}

// 判队空
bool isEmpty(SqQueue Q)
{
    if(Q.front == Q.rear){
        return true;
    }else{
        return false;
    }
}

// 从队尾进 从队首出

// 入队：队不满时，先送值到队尾，再将队尾指针+1
bool EnQueue(SqQueue* Q, int x)
{
    if((Q->rear+1) % MaxSize == Q->front){ // 判断队列是否满
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

// 出队：队不空时，先去取队头元素值，再将队头指针+1
bool DeQueue(SqQueue* Q, int* x)
{
    if(Q->front == Q->rear){
        return false;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

int main(void)
{
    int len = 5;
    int x_1, x_2;
    SqQueue Q;
    InitQueue(&Q);

    bool flag_1 = isEmpty(Q);
    if(flag_1){
        printf("Queue is Empty\n");
        printf("\n");
    }else{
        printf("Queue is not Empty\n");
        printf("\n");
    }

    for (int i = 0; i < len; i++){
        printf("Enter Elems:\n");
        scanf("%d", &x_1);
        bool flag_2 = EnQueue(&Q, x_1);
        if(flag_2){
            printf("Enter Successed\n");
            printf("\n");
        }else{
            printf("Enter Failed\n");
            printf("\n");
        }
    }

    for (int i = 0; i < len; i++){
        bool flag_3 = DeQueue(&Q, &x_2);
        if(flag_3){
            printf("%d ", x_2);
            printf("Dequeue successed\n");
        }else{
            printf("Dequeue Falied\n");
        }
    }
    return 0;
}
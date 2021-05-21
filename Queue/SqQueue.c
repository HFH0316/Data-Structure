# define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

// 初始时：Q.front = Q.rear = 0
// 队首指针进1：Q.front = (Q.front+1) % MaxSize 取余保证了队首队尾指针能够循环
// 队尾指针进1：Q.rear = (Q.rear+1) % MaxSize 
// 队列长度：(Q.rear+MaxSize-Q.front) % MaxSize

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}
// 判队空
bool isEmpty(SqQueue Q)
{
    if(Q.rear == Q.front){
        return true;
    }else{
        return false;
    }
}
//入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if((Q.rear+1) % MaxSize == Q.front){
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
    return true;
}
// 出队
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if(Q.rear == Q.front){
        return false;
    }
    x = Q.data(Q.front);
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
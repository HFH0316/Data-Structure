typedef struct QueueNode{
    ElemType data;
    struct QueueNode* next, front, rear;
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
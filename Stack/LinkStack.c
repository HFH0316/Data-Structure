//带头结点的链栈
typedef struct LinkNode{
    ElemType data;
    struct Linknode *next;
} LinkNode, *LinkStack;

// 初始化链栈
LinkStack Init_Stack(LinkStack StackTop)
{
    StackTop = (LinkStack)malloc(sizeof(StackNode));
    StackTop->next = NULL; // 头结点指向栈顶
    return StackTop;
}
// 判断链栈是否为空
bool StackEmpty(LinkStack StackTop)
{
    if(StackTop->next == NULL){
        return true;
    }else{
        return false;
    }
}
// 入栈（链表头插法）
LinkStack Push(LinkStack StackTop)
{
    int x;
    StackNode* s; // 创建新结点
    scanf("%d", &x);
    while(x != 9999){
        s = (StackNode*)malloc(sizeof(StackNode));
        s->data = x;
        s->next = StackTop->next;
        StackTop->next = s;
        scanf("%d", &x);
    }
    return StackTop;
}
// 出栈
LinkStack Pop(LinkStack Stack)
{
    StackNode* p = Stack->next;
    Stack->next = p->next;
    free(p);
    return Stack;
}
// 获取栈顶元素
int GetTop(LinkStack Stack)
{
    int x;
    x = Stack->next->data;
    return x;
}
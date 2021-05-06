// 带头结点的链栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
} StackNode, *LinkStack;

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

int main(void)
{
    LinkStack Stack;
    Stack = Init_Stack(Stack);

    bool flag = StackEmpty(Stack);
    if(flag == true){
        printf("Stack is Empty\n");
    }else{
        printf("Stack is not Empty\n");
    }
    
    Stack = Push(Stack);
    StackNode* p = Stack->next;
    printf("LinkStack:");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    Stack = Pop(Stack);
    StackNode* q = Stack->next;
    printf("LinkStack:");
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");

    int top = GetTop(Stack);
    printf("Stack top is:%d\n", top);

    return 0;
}
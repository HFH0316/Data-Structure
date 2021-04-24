//顺序栈
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int top;//栈顶指针，初始时S.top = -1
}SqStack;
//初始化
void InitStack(SqStack &S)
{
    S.top = -1;
}
//判栈空
bool StackEmpty(SqStack S)
{
    if(S.top == -1){
        return true;
    }else{
        return false;
    }
}
//进栈
bool Push(SqStack &S,ElemType x)
{
    if(S.top == MaxSize-1){
        return false;
    }
    S.data[++S.top] = x;//栈顶指针先+1，再入栈
    return true;
}
//出栈
bool Pop(SqStack &s,ElemType &x)
{
    if(S.top == -1){
        return flase;
    }
    x = S.data[S.top--];//先出栈，栈顶指针再-1
    return true;
}
//读栈顶元素
bool GetTop(SqStack s,ElemType &x)
{
    if(S.top == -1){
        return flase;
    }
    x = S.data[S.top];
    return true;
}
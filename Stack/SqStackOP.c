#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack* S)
{
    S->top = -1;
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1){
        return true;
    }else{
        return false;
    }
}

bool Push(SqStack* S,int* x)
{
    if(S->top == MaxSize-1){
        return false;
    }
    S->data[++S->top] = *x;
    return true;
}

bool Pop(SqStack* S,int* x)
{
    if(S->top == -1){
        return false;
    }
    *x = S->data[S->top--];
    return true;
}

bool GetTop(SqStack S,int* x)
{
    if(S.top == -1){
        return false;
    }
    *x = S.data[S.top];
    return true;
}

int main(void)
{
    int len = 5;
    int x_1;
    int x_2;
    SqStack S;

    InitStack(&S);

    bool flag_1 = StackEmpty(S);
    if(flag_1){
        printf("Stack is Empty\n");
    }else{
        printf("Stack is not Empty\n");
    }

    for (int i = 0;i < len;i++){
        printf("Enter Elem:\n");
        scanf("%d", &x_1);
        bool flag_2 = Push(&S, &x_1);
        if(flag_2){
            printf("Push Successed\n");
            printf("\n");
        }else{
            printf("Push Failed\n");
        }
    }

    for (int i = 0; i < len;i++){
        bool flag_3 = Pop(&S, &x_2);
        if(flag_3){
            printf("%d ", x_2);
            printf("Pop Successed\n");
        }else{
            printf("Pop Failed\n");
        }
        
    }
    
    return 0;
}
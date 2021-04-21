#include<stdio.h>
#include<stdlib.h>//malloc函数 

typedef struct LNode{
	int data;
	struct LNode* next;//next为下一结点，由于LNode结构体未定义完，故需要用struct LNode来定义next结构体变量 
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList L)//头插法建立单链表
{
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
} 

LinkList List_TailInsert(LinkList L)//尾插法建立单链表
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s;
	LNode* r = L;
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	} 
	r->next = NULL;
	return L;
} 

int ListLength(LinkList L)//求表长
{
	int i = 0;
	LNode* p = L->next;
	if(L->next == NULL){
		return 0;
	}
	while(p != NULL){//注意这里是 p != NULL(p = NULL表示该指针指向NULL，不指向内存中的任意地址)
		p = p->next;//所以出循环条件应该是单链表最后一个结点的后一个 
		i++;//改成 p->next != NULL的出循环条件是单链表最后一个结点，故需return i+1 
	}
	return i;//需要加上最后一个节点 
} 

LNode* GetElem(LinkList L,int i)//按序号查找
{
	int j = 1;
	LNode* p = L->next;
	if(i == 0){
		return L;
	}
	if(i < 1){
		return NULL;
	}
	while(p && j<i){
		p = p->next;
		j++;
	}
	if(p == NULL){
		printf("GetElem Failed\n");
	}
	return p;
} 

LNode* LocateElem(LinkList L,int e)//按值查找
{
	LNode* p = L->next;
	while(p!=NULL && p->data!=e){
		p = p->next;
	}
	if(p == NULL){
		printf("LocateElem Failed\n");
	}
	return p;
}

void ListInsert(LinkList L,int i,int e)//插入
{
	LNode* s;
	//s = (LNode*)malloc(sizeof(LNode));//一定要注意给新结点分配内存！！！ 
	//s->data = e;//如果没有 s = (LNode*)malloc(sizeof(LNode))，此时的指针s是不指向任何东西的 
	LNode* p = GetElem(L,i-1);
	s->next = p->next;
	s->data = e;
	p->next = s;
} 

void ListDelete(LinkList L,int i)//删除 
{
	LNode* p = GetElem(L,i-1);
	LNode* q; 
	q = p->next;
	p->next = q->next;
	free(q);
}

int main(void)
{
	LinkList L;
	//L = List_HeadInsert(L);//头插法
	L = List_TailInsert(L);//尾插法
	LNode* p = L->next;
	printf("LinkList:\n");
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	} 
	printf("\n");
	/* 
	int len = ListLength(L);//求表长 
	printf("ListLength:%d\n",len);
	*/
	/*
	LNode* p_1 = GetElem(L,3);//按序号查找
	LNode* p_1 = LocateElem(L,4);//按值查找
	printf("GetElem:%d\n",p_1->data);
	*/
	/* 
	ListInsert(L,2,99);//插入 
	LNode* p_2 = L->next;
	printf("Inserted LinkList:\n");
	while(p_2 != NULL){
		printf("%d ",p_2->data);
		p_2 = p_2->next;
	} 
	printf("\n");
	*/
	/*
	ListDelete(L,2);//删除 
	LNode* p_3 = L->next;
	printf("Deleted LinkList:\n");
	while(p_3 != NULL){
		printf("%d ",p_3->data);
		p_3 = p_3->next;
	} 
	printf("\n");
	*/
	return 0;
}

#include<stdio.h>
#include<stdlib.h>//malloc���� 

typedef struct LNode{
	int data;
	struct LNode* next;//nextΪ��һ��㣬����LNode�ṹ��δ�����꣬����Ҫ��struct LNode������next�ṹ����� 
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList L)//ͷ�巨����������
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

LinkList List_TailInsert(LinkList L)//β�巨����������
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

int ListLength(LinkList L)//���
{
	int i = 0;
	LNode* p = L->next;
	if(L->next == NULL){
		return 0;
	}
	while(p != NULL){//ע�������� p != NULL(p = NULL��ʾ��ָ��ָ��NULL����ָ���ڴ��е������ַ)
		p = p->next;//���Գ�ѭ������Ӧ���ǵ��������һ�����ĺ�һ�� 
		i++;//�ĳ� p->next != NULL�ĳ�ѭ�������ǵ��������һ����㣬����return i+1 
	}
	return i;//��Ҫ�������һ���ڵ� 
} 

LNode* GetElem(LinkList L,int i)//����Ų���
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

LNode* LocateElem(LinkList L,int e)//��ֵ����
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

void ListInsert(LinkList L,int i,int e)//����
{
	LNode* s;
	//s = (LNode*)malloc(sizeof(LNode));//һ��Ҫע����½������ڴ棡���� 
	//s->data = e;//���û�� s = (LNode*)malloc(sizeof(LNode))����ʱ��ָ��s�ǲ�ָ���κζ����� 
	LNode* p = GetElem(L,i-1);
	s->next = p->next;
	s->data = e;
	p->next = s;
} 

void ListDelete(LinkList L,int i)//ɾ�� 
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
	//L = List_HeadInsert(L);//ͷ�巨
	L = List_TailInsert(L);//β�巨
	LNode* p = L->next;
	printf("LinkList:\n");
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	} 
	printf("\n");
	/* 
	int len = ListLength(L);//��� 
	printf("ListLength:%d\n",len);
	*/
	/*
	LNode* p_1 = GetElem(L,3);//����Ų���
	LNode* p_1 = LocateElem(L,4);//��ֵ����
	printf("GetElem:%d\n",p_1->data);
	*/
	/* 
	ListInsert(L,2,99);//���� 
	LNode* p_2 = L->next;
	printf("Inserted LinkList:\n");
	while(p_2 != NULL){
		printf("%d ",p_2->data);
		p_2 = p_2->next;
	} 
	printf("\n");
	*/
	/*
	ListDelete(L,2);//ɾ�� 
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

typedef struct LNode{
	ElemType data;
	struct LNode* next;//nextΪ��һ��㣬����LNode�ṹ��δ�����꣬����Ҫ��struct LNode������next�ṹ����� 
}LNode,*LinkList;
//ͷ�巨����������
LinkList List_HeadInsert(LinkList &L)
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
//β�巨����������
LinkList List_TailInsert(LinkList &L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s;
	LNode* r = L;
	scanf("%d",x);
	while(x != 9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",x);
	} 
	r->next = NULL;
	return L;
} 
//���
int ListLength(LinkList L)
{
	int i = 0;
	LNode* p = L->next;
	if(L->next == NULL){
		return 0;
	}
	while(p->next != NULL){
		p = p->next;
		i++;
	}
	return i+1;//��Ҫ�������һ���ڵ�
} 
//����Ų���
LNode* GetElem(LinkList L,int i)
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
	return p;
} 
//��ֵ����
LNode* LocateElem(LinkList L,ElemType e)
{
	LNode* p = L->next;
	while(p!=NULL && p->data!=e){
		p = p->next;
	}
	return p;
}
//����
void ListInsert(LinkList &L,int i,ElemType e)
{
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));//һ��Ҫע����½������ڴ棡����
	s->data = e;
	LNode* p = GetElem(L,i-1);
	s->next = p->next;
	p->next = s;
} 
//ɾ�� 
void ListDelete(LinkList &L,int i)
{
	LNode* p = GetElem(L,i-1);
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));//һ��Ҫע����½������ڴ棡���� 
	q = p->next;
	p->next = q->next;
	free(q);
}

typedef struct LNode{
	ElemType data;
	struct LNode* next;//next为下一结点，由于LNode结构体未定义完，故需要用struct LNode来定义next结构体变量 
}LNode,*LinkList;
//头插法建立单链表
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
//尾插法建立单链表
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
//求表长
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
	return i+1;//需要加上最后一个节点
} 
//按序号查找
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
//按值查找
LNode* LocateElem(LinkList L,ElemType e)
{
	LNode* p = L->next;
	while(p!=NULL && p->data!=e){
		p = p->next;
	}
	return p;
}
//插入
void ListInsert(LinkList &L,int i,ElemType e)
{
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));//一定要注意给新结点分配内存！！！
	s->data = e;
	LNode* p = GetElem(L,i-1);
	s->next = p->next;
	p->next = s;
} 
//删除 
void ListDelete(LinkList &L,int i)
{
	LNode* p = GetElem(L,i-1);
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));//一定要注意给新结点分配内存！！！ 
	q = p->next;
	p->next = q->next;
	free(q);
}

//静态分配 
#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int length;
}Sqlist;
//动态分配
#define InitSize 100
typedef struct{
	ElemType* data;
	int MaxSize;//顺序表当初始存储空间，不够可以再分配 
	int length;//顺序表当前长度 
}Seqlist; 
L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);//并不是链式存储，需要stdlib.h
//创建
Seqlist List(Seqlist &L)
{
	int i;
	L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
	L.length = 0;
	L.MaxSize = MaxSize;
	for(i = 0;i < Size;i++){
		L.data[i] = i;
		L.length++;
	}
	return L;
} 
//插入
bool ListInsert(SqList &L,int i,ElemType e)
{
	int j;
	if(i<1 || i>L.length+1){
		return false;
	}
	if(L.length >= MaxSize){
		return false;
	}
	for(j = L.length;j >= i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true
}
//删除
bool ListDelete(SqList &L,int i,ElemType &e)
{
	int j;
	if(i<1 || i>L.length){
		return false;
	}
	e = L.data[i-1];
	for(j = i;j < L.length;j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
} 
//按值查找
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i = 0;i < L.length;i++){
		if(L.date[i] == e){
			return i+1;
		}
	}
	return 0;
} 

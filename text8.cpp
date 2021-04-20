#include<stdio.h>
#include<stdlib.h>//malloc函数 

#define InitSize 5

typedef struct{
	int* data;
	int MaxSize;//顺序表当前初始存储空间，不够可以再分配 
	int length;//顺序表当前长度 
}SeqList; 

void InitList(SeqList* L)//初始化顺序表 ，分配动态存储空间 
{
	L->data = (int*)malloc(InitSize*sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}

void IncreaseSize(SeqList* L,int len)//空间增量分配 
{
	int i;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize+len)*sizeof(int));
	//重新分配更大的空间后，需要将原地址的数据移植过来 
	for(i = 0;i < L->length;i++){
		L->data[i] = p[i];
	}
	L->MaxSize += len;
	free(p);
}

void CreatList(SeqList* L,int Size)//创建顺序表 
{
	int i;
	for(i = 0;i < Size;i++){
		scanf("%d",&L->data[i]);
		L->length++;
	}
}

bool ListInsert(SeqList* L,int i,int e)//插入 
{
	int j;
	if(i<1 || i>L->length+1){
		return false;
	}
	if(L->length >= InitSize){
		return false;
	}
	for(j = L->length;j >= i;j--){
		L->data[j] = L->data[j-1];//i前的元素后移 
	}
	L->data[i-1] = e;//i为位序，对应数组下标时要-1 
	L->length++;
	return true;
}

bool ListDelete(SeqList* L,int i,int* e)//删除 
{
	int j;
	if(i<1 || i>L->length){
		return false;
	}
	*e = L->data[i-1];
	for(j = i;j < L->length;j++){
		L->data[j-1] = L->data[j];
	}
	L->length--;
	return true;
} 

void LocateElem(SeqList L,int e)
{
	int i;
	for(i = 0;i < L.length;i++){
		if(L.data[i] == e){
			printf("%d的位置在%d\n",e,i+1);
			break;
		}
	}
	printf("查找失败"); 
}

int main(void)
{
	int i;
	SeqList L;
	InitList(&L);
	
	/*
	for(i = 0;i < InitSize;i++){
		scanf("%d",&L.data[i]);
		L.length++;
	}
	*/
	
	CreatList(&L,5);
	printf("\n");
	printf("Initial List:");
	for(i = 0;i < L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");

	/*
	IncreaseSize(&L,5);//动态分配空间 
	for(i = InitSize;i < L.MaxSize;i++){
		scanf("%d",&L.data[i]);
		L.length++; 
	}
	printf("\n");
	printf("Increased List:");
	for(i = 0;i < L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");
	*/
	
	/*
	bool flag = ListInsert(&L,2,9);//顺序表插入操作 
	if(flag == 1){
		printf("Insert Successed\n");
		printf("Inserted List:"); 
		for(i = 0;i < L.length;i++){
			printf("%d ",L.data[i]);
		}
	}else{
		printf("Insert Failed\n");
	}
	*/
	
	/*
	int e;//顺序表删除操作 
	bool flag = ListDelete(&L,2,&e);
	if(flag == 1){
		printf("Delete Successed\n");
		printf("Deleted List:");
		for(i = 0;i < L.length;i++){
			printf("%d ",L.data[i]);
		}
	}else{
		printf("Delete Failed\n");
	}
	*/
	
	/*
	LocateElem(L,3);//查找元素 
	*/
	
	return 0;
}

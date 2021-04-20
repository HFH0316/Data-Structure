#include<stdio.h>
#include<stdlib.h>//malloc���� 

#define InitSize 5

typedef struct{
	int* data;
	int MaxSize;//˳���ǰ��ʼ�洢�ռ䣬���������ٷ��� 
	int length;//˳���ǰ���� 
}SeqList; 

void InitList(SeqList* L)//��ʼ��˳��� �����䶯̬�洢�ռ� 
{
	L->data = (int*)malloc(InitSize*sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}

void IncreaseSize(SeqList* L,int len)//�ռ��������� 
{
	int i;
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize+len)*sizeof(int));
	//���·������Ŀռ����Ҫ��ԭ��ַ��������ֲ���� 
	for(i = 0;i < L->length;i++){
		L->data[i] = p[i];
	}
	L->MaxSize += len;
	free(p);
}

void CreatList(SeqList* L,int Size)//����˳��� 
{
	int i;
	for(i = 0;i < Size;i++){
		scanf("%d",&L->data[i]);
		L->length++;
	}
}

bool ListInsert(SeqList* L,int i,int e)//���� 
{
	int j;
	if(i<1 || i>L->length+1){
		return false;
	}
	if(L->length >= InitSize){
		return false;
	}
	for(j = L->length;j >= i;j--){
		L->data[j] = L->data[j-1];//iǰ��Ԫ�غ��� 
	}
	L->data[i-1] = e;//iΪλ�򣬶�Ӧ�����±�ʱҪ-1 
	L->length++;
	return true;
}

bool ListDelete(SeqList* L,int i,int* e)//ɾ�� 
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
			printf("%d��λ����%d\n",e,i+1);
			break;
		}
	}
	printf("����ʧ��"); 
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
	IncreaseSize(&L,5);//��̬����ռ� 
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
	bool flag = ListInsert(&L,2,9);//˳��������� 
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
	int e;//˳���ɾ������ 
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
	LocateElem(L,3);//����Ԫ�� 
	*/
	
	return 0;
}

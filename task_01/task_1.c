#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int DataType;

typedef struct
{
	DataType data[MaxSize];
	int length;
}SeqList;

void InitList(SeqList *L){
	(*L).length=0;
}

void PrintSeq(SeqList L){
	int i;
	for(i=0 ;i<L.length;i++)
		printf("%d\n", L.data[i]);
}

SeqList SeqInsert(SeqList L,int i, int x){
	int j;
	if(L.length==MaxSize){
		printf("Overflow!");exit(0);
	}
	if(i<1||i>L.length+1){
		printf("Positon Error\n");exit(0);
	}
	for(j=L.length;j>=i-1;j--)
		L.data[j+1]=L.data[j];
	L.data[i-1]=x;
	L.length++;
	return L;
}

SeqList SeqDelete(SeqList L,int i){
	int j;
	if(i<1||i>L.length){
		printf("Position Error\n");exit(0);
	}
	if(L.length==0){
		printf("NO Ele to deltete\n");exit(0);
	}
	for(j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return L;
}

int GetElemt(SeqList L,int x){
	int i=1;
	while(i<L.length&&L.data[i-1]!=x)
		i++;
	if(i<=L.length)
		return i;
	else
		return 0;
}

SeqList SeqDel(SeqList L,int x){
	int i = GetElemt(L,x);
	return SeqDelete(L,i);
}

int main(){
	SeqList La,*p;
	p=&La;
	int i,locate;
	int a[5]={10,20,30,40,50};
	InitList(p);
	for(i=0;i<5;i++){
		int loc = i+1;
		La=SeqInsert(La,loc,a[i]);
	}
	printf("列表插入完毕\n");
	PrintSeq(La);
	printf("删除序号为3的元素\n");
	La=SeqDelete(La,3);
	PrintSeq(La);
	printf("删除数值为40的元素\n");
	La=SeqDel(La,40);
	PrintSeq(La);
	locate = GetElemt(La,10);
	printf("元素为10的位置：%d\n",locate);
	return 0;
}

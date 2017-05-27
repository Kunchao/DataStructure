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
	for(i=0;i<L.length;i++)
		printf("%d\n",L.data[i]);
}

SeqList SeqInsert(SeqList L, int i, int x){
	int j;
	if(L.length==MaxSize){
		printf("Overflow\n");exit(0);
	}
	if(i<1||i>L.length+1){
		printf("Position Error\n");exit(0);
	}
	for(j=L.length;j>=i-1;j--)
		L.data[j+1]=L.data[j];
	L.data[i-1]=x;
	L.length++;
	return L;
}

int SeqLength(SeqList L){
	int i=1;
	while(L.data[i])
		i++;
	return i;
}

SeqList Merge(SeqList LA, SeqList LB, SeqList LC){
	int i=0,j=0,k=0;
	while(i<LA.length&&j<LB.length){
		if(LA.data[i]>=LB.data[j]){
			LC.data[k]=LA.data[i];
			i++;k++;LC.length++;
		}
		else{
			LC.data[k]=LB.data[j];
			j++;k++;LC.length++;
		}
	}
	if(i<LA.length){
		LC.data[k++]=LA.data[i++];LC.length++;
	}
	if(j<LB.length){
		LC.data[k++]=LB.data[j++];LC.length++;
	}
	return LC;
}

int main(){
	int i;
	SeqList LA, *p, LB,*q,Lc,*n,L,*m;
	p=&LA;q=&LB,n=&Lc;
	p=&LA;
	q=&LB;
	n=&Lc;
	m=&L;
	InitList(p);
	InitList(q);
	InitList(n);
	InitList(m);
	int a[5]={50,40,30,20,10};
	int b[5]={60,45,30,15,10};
	for(i=0;i<5;i++){
		int loc=i+1;
		LA=SeqInsert(LA,loc,a[i]);
		LB=SeqInsert(LB,loc,b[i]);
	}
	printf("LA顺序表为:\n");
	PrintSeq(LA);
	printf("LB顺序表为:\n");
	PrintSeq(LB);
	L=Merge(LA,LB,Lc);
	printf("L顺序表为:\n");
	PrintSeq(L);
	return 0;

}

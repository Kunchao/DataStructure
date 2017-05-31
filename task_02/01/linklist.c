#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
}LNode,*LinkList;

LinkList LinkInit(){
	LinkList L;
	L=(LinkList)malloc(sizeof(LNode));
	if(L=NULL){
		printf("Memory not enough\n");
		exit(0);
	}
	L->next=NULL;
	return L;
}

LinkList LinkBuild(){
	int x;
	LNode *L,*p,*q;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=L->next;
		L->next=p;
		scanf("%d", &x);
	} 
	return L;

}
int LinkLength(LinkList L){
	LinkList p;
	int i=0;
	p=L->next;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}
void LinkPrint(LinkList L){
	LinkList p;
	p=L->next;
	while(p){
		printf("%d\n", p->data);
		p=p->next;
	}
}
void LinkInsert(LinkList L, int x){
	LinkList s;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=x;
	s->next=L->next;
	L->next=s;
}
void LinkIns(LinkList L, int x, int i){
	LinkList p,s;
	int j=0;
	p=L;
	while(p&&j<i-1){
		p=p->next;j++;
	}
	if(!p&&j>i){
		printf("Error hapened!\n");
		exit(0);
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
}

void LinkDel(LinkList L,int i){
	LinkList p,q;
	int j=0;
	p=L;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p&&j>i){
		printf("Position Error\n");
		exit(0);
	}
	q=p->next;
	p->next=q->next;
	free(q);
}

LinkList LinkInv(LinkList L){
	LinkList p,r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return L;
}
int main(){
	LinkList L;
	L=LinkBuild();
	printf("使用头插法插入1,3,5,7,9\n");
	LinkPrint(L);
	printf("在链表的第1个位置插入元素10\n");
	LinkIns(L,10,3);
	LinkPrint(L);
	printf("删除链表的第3个元素\n");
	LinkDel(L,3);
	LinkPrint(L);
	printf("求链表的长度\n");
	int a=LinkLength(L);
	printf("%d\n",a);
	printf("实现将L逆置\n");
	LinkInv(L);
	LinkPrint(L);
}


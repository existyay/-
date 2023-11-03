#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void visit(int e){
	printf("%d",e);
} 
//初始化单链表 
Status CreateList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode*));
	L->next=NULL;
	return OK;
}

Status InsertList(LinkList L,int i,ElemType &e){
	
}

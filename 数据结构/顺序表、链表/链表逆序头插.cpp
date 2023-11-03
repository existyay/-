#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨ʵ�������������� 
Status head_InsertList(LinkList L,Status x){
	LNode *p;
	L=new LNode;
	L->next=NULL;
	while(cin>>x){
		p=new LNode;
		p->data=x;
		p->next=L->next;
		L->next=p;
	}
	return OK;
}
//���������� 
Status TraveList(LinkList L,void(*visit(ElemType))){
	LinkList p=L->next;
	while(p){
		p=p->next;
		visit(p->data);
	}
	//����һ��p���ӡ���е������� 
	return OK;
}
void visit(int e){
	printf("%d",e);
} 
int main(){
	LinkList L;
	int x,e;
	head_InsertList(L,x);
	return OK;
}

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

//头插法实现链表的逆序输出 
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
//遍历单链表 
Status TraveList(LinkList L,void(*visit(ElemType))){
	LinkList p=L->next;
	while(p){
		p=p->next;
		visit(p->data);
	}
	//遍历一遍p表打印所有的数据域 
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

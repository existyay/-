#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;
typedef struct StackNode {
	ElemType data;
	struct StackNode *next;
} StackNode,*LinkStack;

Status InitStack(LinkStack &S) {
	S=NULL;
	return OK;
}
Status Push(LinkStack &S,ElemType e) {
	StackNode *p;
	p->data=e;
	p->next=S;
	S=p;
	return OK;
}
Status Pop(LinkStack &S,ElemType &e) {
	StackNode *p;
	if(S==NULL) return ERROR;
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return OK;
}
ElemType GetTop(LinkStack S) {
	if(S!=NULL)
		return S->data;
}
int main() {
	return OK;
}

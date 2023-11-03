/*直链式队列*/
#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q){
	Q->front=Q->rear=(QNode*)malloc(sizeof(QNode));
	if(!Q->front) return ERROR;
	Q->front->next=Q->rear->next=NULL;
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
	QNode* p=(QNode*)malloc(sizeof(QNode));
	if(!p) return ERROR;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK; 
}

Status DeQueue(LinkQueue *Q,QElemType *e){
	if(Q->front==Q->rear) return ERROR;
	QNode *p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p) Q->rear=Q->front;
	delete p;
	return OK;
} 

void DestoryQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
} 

QElemType GetHead(LinkQueue Q){
	if(Q.front!=Q.rear)
	return Q.front->next->data;
} 



int main(){
	;
}


/*数组变长型实现的循环队列（循环队列的顺序存储结构）*/
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define INIT_MEMORY_QUEUE 100
#define CREATMENT 50
typedef int Status;
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
} SqQueue;

Status initSqQueue(SqQueue *Q) {
	Q->base=(QElemType*)malloc(INIT_MEMORY_QUEUE*sizeof(QElemType));
	if(!Q->base) return ERROR;
	Q->front=Q->rear=0;
	return OK;
}
Status EnQueue(SqQueue *Q,QElemType e) {
	if((Q->rear+1)%INIT_MEMORY_QUEUE==Q->front) {
		Q->base=new Status[INIT_MEMORY_QUEUE+CREATMENT];
		Q->base[Q->rear]=e;
		Q->rear=(Q->rear+1)%(INIT_MEMORY_QUEUE+CREATMENT);
	}
	else Q->base=new Status[INIT_MEMORY_QUEUE];
		Q->base[Q->rear]=e;
		Q->rear=(Q->rear+1)%(INIT_MEMORY_QUEUE);
	return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e){
	*e=Q->base[Q->front];
	if((Q->rear+1)%INIT_MEMORY_QUEUE==Q->front){
		Q->front=(Q->front+1)%INIT_MEMORY_QUEUE+CREATMENT;
	}
	else Q->front=(Q->front+1)%INIT_MEMORY_QUEUE;
	return OK; 
}
int main() {
	;
}

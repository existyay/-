/*数组定长型实现的循环队列（循环队列的顺序存储结构）*/
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status initSqQueue(SqQueue *Q){
	Q->base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q->base) return ERROR;
	Q->front=Q->rear=0;
	return OK; 
}

Status EnQueue(SqQueue *Q,QElemType e){
	if((Q->rear+1)%MAXSIZE==Q->front)
	return ERROR;
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK; 
}

Status DeQueue(SqQueue *Q,QElemType *e){
	if(Q->rear==Q->front)
	return ERROR;
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return OK; 
}







int main(){
	;
}

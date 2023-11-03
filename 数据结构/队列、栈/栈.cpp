#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0 
#define MAXSIZE 100
typedef int SElemType;
typedef int Status;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S){
	S.base=new SElemType[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize) return ERROR;
	*S.top++=e;
	return OK;
}

Status StackEmpty(SqStack &S){
	if(S.top==S.base) return OK;
	else return ERROR;
}
SElemType GetTop(SqStack S){
	if(S.top!=S.base)
	return *(S.top-1);
}
Status Pop(SqStack &S,SElemType &e){
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
}
int main(){
	return OK;
}

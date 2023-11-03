/*栈的动态分配空间形式*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef int Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

Status InitStack(SqStack *S) {
	S->base=(SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(!S->base) exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty(SqStack S) {
	if(S.top==S.base) return OK;
	else {
		return ERROR;
	}

}
Status StackFull(SqStack S) {
	if(S.top-S.base==S.stacksize) return OK;
	else {
		return ERROR;
	}
}
Status push(SqStack *S,SElemType e) {
	if(S->top-S->base>=S->stacksize) {
		SElemType *newbase=(SElemType*)realloc(S->base,sizeof(SElemType)*(S->stacksize+STACKINCREMENT));
		if(!newbase) return ERROR;
		S->base=newbase;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top++;
	return OK;
}
Status Pop(SqStack *S,SElemType *e){
	if(S->base==S->top) return ERROR;
	S->top--;
	*e=*(S->top);
	return OK;
}
Status GetTop(SqStack S,SElemType *e){
	if(S.base==S.top) return ERROR;
	*e=*(S.top-1);
	return OK; 
}
void StackTraverse(SqStack S,void(*visit)(SElemType)){
	SElemType *p=S.top-1;
	while(p>=S.base){
		visit(*p);
		p--;
	}
}

int main() {
	;
}

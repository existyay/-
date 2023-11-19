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
Status InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode*));
	L->next=NULL;
	return OK;
}
//遍历单链表 
Status TraveList(LinkList L,void(*visit(ElemType))){
	LinkList p=L->next;
	while(p){
		p=p->next;
		visit(p->data);
	}
	//遍历一遍p表格打印所有的数据域 
	return OK;
}

//单链表查找（按值查找）
Status LocateElem(LinkList L,ElemType &e){
	LinkList p=L->next;
	int j=1;
	while(((p->data))!=e&&p){
		p=p->next;
		j++;
	}
	//找前驱，并且用j记录下相同的元素的位序 
	if(!p||j<1) return ERROR;
	return j; 
	//直接返回位序的值 
} 

Status ListEmpty(LinkList L){
	return L->next==NULL?1:0;
	//置空链表 
} 

void DestroyList(LinkList &L){
	LNode *p;
	while(L){
		p=L;
		L=p->next;
		free(p);
		//循环删除指针域的值 
	}
	L=NULL;
	//将链表也置空 
} 

//单链表查找（按位查找）
Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next;
	int j=1;
	while(j<i&&p){
		p=p->next;
		j++;
	}
	//找前驱，j记录位序，找到该位停止否则报错 
	if(!p||i<1) return ERROR;
	e=p->data;
	//取得该位的数据域 
	return OK;
} 
//单链表插入
Status Insert(LinkList &L,int i,ElemType &e){
	LinkList p=L,s;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	//找前驱，j记录位序，插入可以插到表尾后一位所以p&&j<i-1 
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	//插入的结点前后指针连接 
	return OK;
}
//单链表删除
Status Delete(LinkList &L,int i,ElemType &e){
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	//找前驱，j记录位序，删除不可以删到表尾后一位所以p->next&&j<i-1 
	if(!(p->next||i<1))return 0;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	//删除的结点断开连接，并且释放q 
	return OK;
}



int main(){
	
}

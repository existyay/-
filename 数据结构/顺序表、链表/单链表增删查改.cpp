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
//��ʼ�������� 
Status InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode*));
	L->next=NULL;
	return OK;
}
//���������� 
Status TraveList(LinkList L,void(*visit(ElemType))){
	LinkList p=L->next;
	while(p){
		p=p->next;
		visit(p->data);
	}
	//����һ��p����ӡ���е������� 
	return OK;
}

//��������ң���ֵ���ң�
Status LocateElem(LinkList L,ElemType &e){
	LinkList p=L->next;
	int j=1;
	while(((p->data))!=e&&p){
		p=p->next;
		j++;
	}
	//��ǰ����������j��¼����ͬ��Ԫ�ص�λ�� 
	if(!p||j<1) return ERROR;
	return j; 
	//ֱ�ӷ���λ���ֵ 
} 

Status ListEmpty(LinkList L){
	return L->next==NULL?1:0;
	//�ÿ����� 
} 

void DestroyList(LinkList &L){
	LNode *p;
	while(L){
		p=L;
		L=p->next;
		free(p);
		//ѭ��ɾ��ָ�����ֵ 
	}
	L=NULL;
	//������Ҳ�ÿ� 
} 

//��������ң���λ���ң�
Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next;
	int j=1;
	while(j<i&&p){
		p=p->next;
		j++;
	}
	//��ǰ����j��¼λ���ҵ���λֹͣ���򱨴� 
	if(!p||i<1) return ERROR;
	e=p->data;
	//ȡ�ø�λ�������� 
	return OK;
} 
//���������
Status Insert(LinkList &L,int i,ElemType &e){
	LinkList p=L,s;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	//��ǰ����j��¼λ�򣬲�����Բ嵽��β��һλ����p&&j<i-1 
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	//����Ľ��ǰ��ָ������ 
	return OK;
}
//������ɾ��
Status Delete(LinkList &L,int i,ElemType &e){
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	//��ǰ����j��¼λ��ɾ��������ɾ����β��һλ����p->next&&j<i-1 
	if(!(p->next||i<1))return 0;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	//ɾ���Ľ��Ͽ����ӣ������ͷ�q 
	return OK;
}



int main(){
	
}

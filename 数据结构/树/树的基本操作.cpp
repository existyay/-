#include<bits/stdc++.h>
#include<string>
#define TElemType char
#define OK 1
#define ERROR 0
typedef int Status;
using namespace std;
//二叉树的链表实现 （二叉链表）
typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild;
	BiTNode *rchild;
} BiTNode,*BiTree;
typedef struct QNode {
	BiTree data;
	QNode *next;
} QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;
Status InitQueue(LinkQueue *Q) {
	Q->front=Q->rear=(QNode*)malloc(sizeof(QNode));
	if(!Q->front) return ERROR;
	Q->front->next=Q->rear->next=NULL;
	return OK;
}
typedef BiTree QElemType;
Status EnQueue(LinkQueue *Q,BiTree e) {
	QNode* p=(QNode*)malloc(sizeof(QNode));
	if(!p) return ERROR;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e) {
	if(Q->front==Q->rear) return ERROR;
	QNode *p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p) Q->rear=Q->front;
	delete p;
	return OK;
}
Status EmptyQueue(LinkQueue *Q) {
	if(Q->front==Q->rear) return OK;
	else return ERROR;
}
//创建一个二叉树
BiTree CreateBiTree() {
	BiTree T;
	char ch;
	cin>>ch;
	if(ch=='^') T=NULL;
	else {
		T=new BiTNode;
		if(!T) exit(-1);
		T->data=ch;
		T->lchild=CreateBiTree();
		T->rchild=CreateBiTree();
	}
	return T;
}
//求变量L存放结点的层次
void layer(BiTree T,int L) {
	if(T) {
		L++;
		cout<<T->data<<L;
		layer(T->lchild,L);
		layer(T->rchild,L);
	}
}
//Leaf的node数目
void countLeaf(BiTree T,int *sum) {
	if(T) {
		if(!T->lchild&&!T->rchild)
			(*sum)++;
		countLeaf(T->lchild,sum);
		countLeaf(T->rchild,sum);
	}
}
//分别计算二叉树中度为0，度为1，度为2的Node数
void countLeaf(BiTree T,int *s0,int *s1,int *s2) {
	if(T) {
		if(!T->lchild&&!T->rchild)
			(*s0)++;
		else if(T->lchild&&T->rchild)
			(*s2)++;
		else
			(*s1)++;
		countLeaf(T->lchild,s0,s1,s2);
		countLeaf(T->rchild,s0,s1,s2);
	}
}
//求二叉树的深度
void Deepth(BiTree T,int L,int *h) {
	if(T) {
		L++;
		if(L>*h) *h=L;
		Deepth(T->lchild,L,h);
		Deepth(T->rchild,L,h);
	}
}
//先序遍历算法
void PreOrderTraverse(BiTree T,void(*visit)(TElemType e)) {
	if(T) {
		visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
}
//中序遍历算法
void InOrderTraverse(BiTree T,void(*visit)(TElemType e)) {
	if(T) {
		InOrderTraverse(T->lchild,visit);
		visit(T->data);
		InOrderTraverse(T->rchild,visit);
	}
}
//后序遍历算法
void PostOrderTraverse(BiTree T,void(*visit)(TElemType e)) {
	if(T) {
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T->data);
	}
}
void visit(string e) {
	cout<<e;
}
void LayerOrder(BiTree T,void(*visit)(TElemType e)) {
	LinkQueue Q;
	InitQueue(&Q);
	if(T)EnQueue(&Q,T);
	while(!EmptyQueue(&Q)) {
		DeQueue(&Q,&T);	//队首结点出队
		visit(T->data);
		//T的左右孩子入队列
		if(T->lchild) EnQueue(&Q,T->lchild);
		if(T->rchild) EnQueue(&Q,T->rchild);
	}
}

int main() {
	;
}
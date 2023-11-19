#include<bits/stdc++.h>
#include<string>
#define TElemType char
using namespace std;
//二叉树的链表实现 （二叉链表） 
typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild;
	BiTNode *rchild;
} BiTNode,*BiTree;

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
void visit(string e){
	cout<<e;
}
void LayerOrder(BiTree T,void (*visit)(TElemType)) {
	;
}
int main() {
	;
}

/*链表的多项式存储(加减法实现)*/
#include<stdio.h>
#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
typedef struct PNode {
	float coef;
	int expn;
	struct PNode *next;
} PNode,*Polynomial;
/*多项式的创建*/
void CreatePolyn(Polynomial &P,int n) {
	P=new PNode;
	P->next=NULL;
	for(int i=1; i<=n; i++) {
		Polynomial s=new PNode;
		cin>>s->coef>>s->expn;
		Polynomial pre=P;
		Polynomial q=P->next;
		while(q&&q->expn<s->expn) {
			pre=q;
			q=q->next;
		}
		s->next=q;
		pre->next=s;
	}
}
/*多项式的相加*/
void AddPolyn(Polynomial &Pa,Polynomial &Pb) {
	Polynomial p1=Pa->next;
	Polynomial p2=Pb->next;
	Polynomial p3=Pa;
	while(p1&&p2) {
		if(p1->expn==p2->expn) {
			Polynomial r;
			int sum=p1->coef+p2->coef;
			if(sum!=0) {
				p1->coef=sum;
				p3->next=p1;
				p3=p1;
				p1=p1->next;
				r=p2;
				p2=p2->next;
				delete r;
			} else {
				r=p1;
				p1=p1->next;
				delete r;
				r=p2;
				p2=p2->next;
				delete r;
			}
		} else if(p1->expn<p2->expn) {
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		} else {
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;
	delete Pb;
}
void printDxs(Polynomial h) {
	while(h) {
		h=h->next;
		printf("%0.1f*X^%d", h->coef, h->expn);
		if(h->next!=NULL) printf("+");
	}
	printf("\n");
}
int main() {
	Polynomial pa,pb,pc;
	int n,m;
	cin>>n;
	CreatePolyn(pa,n);
	cin>>m;
	CreatePolyn(pb,m);
	AddPolyn(pa,pb);
	printDxs(pa);
	return OK;
}
/*
示例输入
3
1 0 2 2 3 1
4
2 0 -2 2 4 3 3 6
*/ 

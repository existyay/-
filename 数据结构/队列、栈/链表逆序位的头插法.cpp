#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode,*LinkList;

void CreateList(LinkList &head,int n);   //逆位序
void CreateList2(LinkList &head,int n);   //正位序
void TraveList(LinkList &head);         //链表的遍历

void CreateList(LinkList &head,int n) {
	int i;
	LinkList p;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	printf("请输入%d个数值\n",n);
	for(i=1; i<=n; i++) {
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=head->next;
		head->next=p;
	}
}
void CreateList2(LinkList &head,int n) {
	int i;
	LinkList p,q;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	p=q=(LinkList)malloc(sizeof(LNode));
	p=head;
	printf("请输入%d个数值\n",n);
	for(i=1; i<=n; i++) {
		scanf("%d",&q->data);
		p->next=q;
		p=q;
		q=(LinkList)malloc(sizeof(LNode));
	}
	p->next=NULL;
}
void TraveList(LinkList &head) {
	LinkList p=head->next;
	while(p) {
		printf("%2d",p->data);
		p=p->next;
	}
	printf("\n");
}
int main() {
	LinkList head,head2;
	int n,n2;
	
	
	printf("请输入逆序输入的单链表中元素的数量：");
	scanf("%d",&n);
	CreateList(head,n);
	printf("逆序输入的元素为：");
	TraveList(head);
	
	
	printf("\n请输入正序输入的单链表中元素的数量：");
	scanf("%d",&n2);
	CreateList2(head2,n2);
	printf("正序输入的元素为：");
	TraveList(head2);

	return 0;


}


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode,*LinkList;

void CreateList(LinkList &head,int n);   //��λ��
void CreateList2(LinkList &head,int n);   //��λ��
void TraveList(LinkList &head);         //����ı���

void CreateList(LinkList &head,int n) {
	int i;
	LinkList p;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	printf("������%d����ֵ\n",n);
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
	printf("������%d����ֵ\n",n);
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
	
	
	printf("��������������ĵ�������Ԫ�ص�������");
	scanf("%d",&n);
	CreateList(head,n);
	printf("���������Ԫ��Ϊ��");
	TraveList(head);
	
	
	printf("\n��������������ĵ�������Ԫ�ص�������");
	scanf("%d",&n2);
	CreateList2(head2,n2);
	printf("���������Ԫ��Ϊ��");
	TraveList(head2);

	return 0;


}


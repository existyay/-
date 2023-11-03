#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 1000
#define OVERFLOW -2
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;
/*初始化顺序表*/
int InitList(SqList *L) {
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L->elem) return 0;
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return 1;
}
//Status InitList(SqList &L){
//	L.elem=new ElemType[MAXSIZE];
//	if(!L.elem) exit(OVERFLOW);
//	L.length=0;
//	return OK;
//}
/*取值*/
Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}
/*查找*/
int LocateElem(SqList L,ElemType e) {
	for(int i=0; i<L.length; i++)
		if(L.elem[i]==e) return i+1;
	return 0;
}
/*插入*/
int ListInsert_sq(SqList *L,int i,ElemType e) {
	if((i<1)||(i>L->length+1)) return ERROR;
	if(L->length>=L->listsize) {
		ElemType *newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) return ERROR;
		L->elem=newbase;
		L->listsize+=LISTINCREMENT;
	}
	for(int k=L->length-1; k>=i-1; k--) {
		L->elem[k+1]=L->elem[k];
		L->elem[i-1]=e;
		L->length+1;
		return OK;
	}
}
//Status ListInsert(SqList &L,int i,ElemType e){
//	if((i<1)||(i>L.length+1)) return ERROR;
//	if(L.length==LIST_INIT_SIZE) return ERROR;
//	for(int j=L.length-1;j>=i-1;j--)
//		L.elem[j+1]=L.elem[j];
//	L.elem[i-1]=e;
//	++L.length;
//	return OK;
//}
/*删除*/
int ListDelete_sq(SqList *L,int i,ElemType *e) {
	int k;
	if((i<1)||(i>L->length)) return ERROR;
	*e=L->elem[i-1];
	for(k=i; k<L->length; k++)
		L->elem[k-1]=L->elem[k];
	L->length--;
	return OK;
}


//Status ListDelete(SqList &L,int i){
//	if((i<1)||(i>L.length)) return -1;
//	for(int j=i;j<L.length-1;j++)
//	L.elem[j-1]=L.elem[j];
//	--L.length;
//	return 1;
//}

/*查找*/
//1.按值查找
int LocateElem_sq(SqList L,ElemType e,int(*compare)(ElemType,ElemType)) {
	int i;
	for(i=0; i<L.length; i++) {
		if((*compare)(L.elem[i],e))
			break;
	}
	if(i>=L.length||L.length==0)
		return 0;
	else return i+1;
}
//2.按位查找
int GetElem_sq(SqList *L,int i,ElemType *e) {
	if(i<1||i>L->length) return ERROR;
	*e=L->elem[i-1];
	return OK;
}
/*销毁顺序表*/
Status DestoryList(SqList &L){
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
	return OK;
} 
/*置空线性表*/
Status ClearList(SqList *L){
	if(!L->length==0){
		L->length=0;
	}
	return OK;
}
/*访问顺序表*/
Status Travese_sq(SqList L,void(*visit)(ElemType)){
	for(int i=0;i<L.length;i++){
		visit(L.elem[i]); 
	}
}
int main() {
	SqList L[100];
	InitList(L);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
}

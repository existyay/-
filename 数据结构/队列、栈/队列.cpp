//���е�˳��洢�ṹ
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#include<time.h>
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType *base;
    int front;
    int rear;
}cycleQueue;
//��ʼ��
Status initQueue(cycleQueue *q){
    q->base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    if(!q->base){
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    q->front=q->rear=0;
    printf("��ʼ���������\n");
}
//��Ӳ���
Status InsertQueue(cycleQueue *q,ElemType e){
    if((q->rear+1)%MAXSIZE==q->front){
        printf("�����������޷����\n");
        return 0;
    }
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    printf("������\n");
}
//���Ӳ���
Status DeleteQueue(cycleQueue *q,ElemType &e){
    if(q->front==q->rear){
        printf("�ӿգ�����ʧ��\n");
        return 0;
    }
    e=q->base[q->front];
    q->front=(q->front+1)%MAXSIZE;
    printf("����Ԫ��ֵΪ:%d\n",e);
    printf("�������\n");
}
//���ٶ���
Status DestroyQueue(cycleQueue *q){
    if(q->base){
        free(q->base);
    }
    q->base=NULL;
    q->front=q->rear=0;
    printf("�������\n");
}
int main(){
    int choice=0;
    cycleQueue q;
    while(choice!=5){
        printf("**********�˵�**********\n");
        printf("|1.��ʼ������   2.���ٶ���|\n");
        printf("|3.��Ӳ���     4.���Ӳ���|\n");
        printf("|5.�˳�����|\n");
        printf("(ע��:�ڽ��в���ʱ��������ǰ���г�ʼ������)\n");
        printf("���������ѡ��:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                initQueue(&q);
                printf("�����Զ���ת���˵�ҳ��\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 2:{
                DestroyQueue(&q);
                printf("�����Զ���ת���˵�ҳ��\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 3:{
                int e;
                printf("������Ҫ���Ԫ�ص�ֵ:");
                scanf("%d",&e);
                InsertQueue(&q,e);
                printf("�����Զ���ת���˵�ҳ��\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 4:{
                int *e;
                DeleteQueue(&q,*e);
                printf("�����Զ���ת���˵�ҳ��\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 5:{
                printf("�����˳�\n");
                system("cls");
                break;
            }
        }
    }
    return 0;
}



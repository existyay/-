//队列的顺序存储结构
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
//初始化
Status initQueue(cycleQueue *q){
    q->base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    if(!q->base){
        printf("初始化失败\n");
        exit(0);
    }
    q->front=q->rear=0;
    printf("初始化操作完毕\n");
}
//入队操作
Status InsertQueue(cycleQueue *q,ElemType e){
    if((q->rear+1)%MAXSIZE==q->front){
        printf("队列已满，无法入队\n");
        return 0;
    }
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    printf("入队完毕\n");
}
//出队操作
Status DeleteQueue(cycleQueue *q,ElemType &e){
    if(q->front==q->rear){
        printf("队空，出队失败\n");
        return 0;
    }
    e=q->base[q->front];
    q->front=(q->front+1)%MAXSIZE;
    printf("出队元素值为:%d\n",e);
    printf("出队完毕\n");
}
//销毁队列
Status DestroyQueue(cycleQueue *q){
    if(q->base){
        free(q->base);
    }
    q->base=NULL;
    q->front=q->rear=0;
    printf("销毁完毕\n");
}
int main(){
    int choice=0;
    cycleQueue q;
    while(choice!=5){
        printf("**********菜单**********\n");
        printf("|1.初始化操作   2.销毁队列|\n");
        printf("|3.入队操作     4.出队操作|\n");
        printf("|5.退出程序|\n");
        printf("(注意:在进行操作时，必须提前进行初始化操作)\n");
        printf("请输入你的选择:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                initQueue(&q);
                printf("程序将自动跳转到菜单页面\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 2:{
                DestroyQueue(&q);
                printf("程序将自动跳转到菜单页面\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 3:{
                int e;
                printf("请输入要入队元素的值:");
                scanf("%d",&e);
                InsertQueue(&q,e);
                printf("程序将自动跳转到菜单页面\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 4:{
                int *e;
                DeleteQueue(&q,*e);
                printf("程序将自动跳转到菜单页面\n");
                Sleep(1000);
                system("cls");
                break;
            }
            case 5:{
                printf("程序退出\n");
                system("cls");
                break;
            }
        }
    }
    return 0;
}


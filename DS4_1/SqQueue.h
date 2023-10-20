#ifndef HEADER
#define HEADER

#include "public1.h"

typedef int QElemType;

#define MAXQSIZE 40 // �����г���(����ѭ�����У������г���Ҫ��1)

// �˴�����ѭ�����еĶ���
typedef struct {
    QElemType * base;
    int front;
    int rear;
}SqQueue;


 //  ѭ�����еĻ�������(9��)
 Status InitQueue(SqQueue &Q);


 Status DestroyQueue(SqQueue &Q);


 Status ClearQueue(SqQueue &Q);


 Status QueueEmpty(SqQueue Q);


 int QueueLength(SqQueue Q);


 Status GetHead(SqQueue Q,QElemType &e);


 Status EnQueue(SqQueue &Q,QElemType e);


 Status DeQueue(SqQueue &Q,QElemType &e);


 Status QueueTraverse(SqQueue Q,void(*vi)(QElemType));

void PrintElement(QElemType e);

#endif // header guard


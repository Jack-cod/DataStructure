#include "public1.h"
#include "BiTree.h"


typedef BiTree QElemType; 



// �������У����е���ʽ�洢�ṹ��
typedef struct QNode{ 
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue{
	QueuePtr front,rear; // ��ͷ����βָ��
};



Status InitQueue(LinkQueue &Q);

Status DestroyQueue(LinkQueue &Q);

Status ClearQueue(LinkQueue &Q);

Status QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue Q,QElemType &e);

Status QueueTraverse(LinkQueue Q,void(*visit)(QElemType));

Status  EnQueue(LinkQueue &Q,QElemType e);

Status DeQueue(LinkQueue &Q,QElemType &e);

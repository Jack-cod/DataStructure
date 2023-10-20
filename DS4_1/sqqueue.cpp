#include "SqQueue.h"

//  ѭ�����еĻ�������(9��)
Status InitQueue(SqQueue &Q) {
    // ����һ���ն���Q
    Q.base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) {return OVERFLOW;}
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q) {
    // ���ٶ���Q,Q���ٴ���
    //���
    if (!Q.base) {return OK;}
    // �����ͷŶ��е����鲿��,���ÿ�
    free(Q.base);
    Q.base = nullptr;
    Q.front = Q.rear = 0;
    return OK;
}

Status ClearQueue(SqQueue &Q) {
    // ��Q��Ϊ�ն���
    QElemType temp;
    while (!QueueEmpty(Q)) {
        if (DeQueue(Q, temp) != OK) {
            return ERROR; // ��� DeQueue ����ʧ�ܣ����� ERROR
        }
    }
    if (QueueEmpty(Q)) {return OK;}
    return ERROR;
}

Status QueueEmpty(SqQueue Q) {
    // ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE
    if (!Q.base) {return TRUE;}
    if (Q.front == Q.rear) {return TRUE;}
    return FALSE;
}

int QueueLength(SqQueue Q) {
    // ����Q��Ԫ�ظ���,�����еĳ���
    if (Q.base == nullptr) {return 0;}
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue Q,QElemType &e) {
    // �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR
    if (QueueEmpty(Q)) {return ERROR;}
    e = Q.base[Q.front];
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e) {
    // ����Ԫ��eΪQ���µĶ�βԪ��
    // ������
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {return ERROR;}
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e) {
    // �����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK;���򷵻�ERROR
    if (QueueEmpty(Q)) {return ERROR;}
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status QueueTraverse(SqQueue Q,void(*vi)(QElemType)) {
    // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi().һ��viʧ��,�����ʧ��
    for (int  i = Q.front; i < Q.rear; i++) {
        vi(Q.base[i]);
    }
    return OK;
}

void PrintElement(QElemType e) {
    cout << e << '  ';
}

#include "LinkQueue.h"

Status InitQueue(LinkQueue &Q) {
    // ����һ���ն���Q
    Q.front = Q.rear = (QueuePtr ) malloc(sizeof(QNode));
    if (!Q.front) {return OVERFLOW;}
    Q.front->next = nullptr;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    // ���ٶ���Q
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.front->next;
    }
    return OK;
}

Status QueueEmpty(LinkQueue &Q) {
    if (Q.rear == Q.front) {return TRUE;}
    return FALSE;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    // ���
    QueuePtr newnode = (QueuePtr) malloc(sizeof(QNode));
    if (!newnode) {return OVERFLOW;}
    newnode->next = nullptr;
    newnode->data = e;
    Q.rear->next = newnode;
    Q.rear = newnode;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.rear == Q.front) {return ERROR;} // �ӿ�
    QueuePtr temp = Q.front->next;
    e = temp->data;
    Q.front->next = temp->next;
    if (Q.rear == temp) {Q.rear = Q.front;} // ɾ�����һ��Ԫ�غ�,��βָ�붪ʧ��
    free(temp);
    return OK;
}

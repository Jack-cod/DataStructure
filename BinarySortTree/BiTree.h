 // ��̬���ұ�������Ԫ�صĶ���Ͷ������Ķ�������洢��ʾ
#ifndef _BiTree_H
#define _BiTree_H

#define N 10 // ����Ԫ�ظ���
typedef int KeyType; // ��ؼ�����Ϊ����
typedef struct ElemType // ����Ԫ������
 {
   KeyType key;
   int others;
 }ElemType,TElemType;

typedef struct BiTNode
 {
   TElemType data;
   BiTNode *lchild,*rchild; // ���Һ���ָ��
 }BiTNode,*BiTree;

#endif
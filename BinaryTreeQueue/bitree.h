
#include "public1.h"

typedef char TElemType;

//�������Ķ�������洢�ṹ
/*typedef struct BiTNode{
	TElemType data; // ����ֵ
	struct BiTNode *lchild,*rchild; // ���Һ���ָ��
}*BiTree;*/

#ifndef DEF

//�������Ķ�������洢�ṹ��
typedef struct BiTNode{
	TElemType data; // ����ֵ
	BiTNode *lchild,*rchild; // ���Һ���ָ��
}BiTNode,*BiTree;
#endif
#define DEF
//Status CreateBiTree(BiTree &T);
BiTree CreateTree(TElemType A[], TElemType B[],int ha,int la,int hb,int lb);/* ������ȫ�������н��������� */
void visit(TElemType e);
Status LevelOrderTraverse(BiTree T,void(*Visit)(TElemType));   /* ��α��������� */
Status IsCompleteTree(BiTree T); /* �ж�һ�ö������Ƿ�����ȫ������ */
Status PrintTree(BiTree bt, int nLayer);  /* ��������״��ӡ�Ķ����� */
Status DestroyBiTree(BiTree &T); /* ���ٶ����� */












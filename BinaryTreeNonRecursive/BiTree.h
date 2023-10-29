#ifndef HEADER_BITREE
#define HEADER_BITREE

#include "public1.h"

typedef char TElemType ;

//�������Ķ�������洢�ṹ
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T); /* ������ȫ�������н��������� */
void visit(TElemType e);
Status PreOrderTraverse(BiTree T,void(*Visit)(TElemType));/* ������������� */
Status InOrderTraverse(BiTree T,void(*Visit)(TElemType)); /* ������������� */
Status PostOrderTraverse(BiTree T,void(*Visit)(TElemType)); /* ������������� */
void CountLeaf (BiTree T,int &count);/* ͳ�ƶ�����Ҷ���� */
int TreeDepth (BiTree T);/* ��������߶� */
Status PrintTree(BiTree bt, int nLayer);  /* ��������״��ӡ�Ķ����� */
Status DestroyBiTree(BiTree &T); /* ���ٶ����� */
Status CountLayerNodes(BiTree T, int currentLayer, int Layer, int maxDepth, int& count);
void FindParentNode(BiTree T, map<char, char> & parents);
int FindAncestors(BiTree T, map<char, char> & parents, char & desiredAnstNode);
#endif // header guard

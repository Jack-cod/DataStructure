#include "BiTree.h"

int main()
{
	BiTree T;int count=0;

	printf("�밴�������������(�磺AB00C00��ʾAΪ����㡢BΪ���ӡ�CΪ�Һ��ӵĶ�����������0����ո�)��\n");
	CreateBiTree(T); // ����������T

    printf("�������Ϊ��");
	PreOrderTraverse(T,visit);
	printf("\n�������Ϊ��");
	InOrderTraverse(T,visit);
	printf("\n�������Ϊ��");
	PostOrderTraverse(T,visit);
	printf("\n");

	printf("��Ŀ¼��ʽ�����������\n");
	PrintTree(T,1);

	CountLeaf(T,count);
    printf("��������Ҷ�ӽ������ǣ�%d\n",count);

    printf("�������ĸ߶��ǣ�%d\n",TreeDepth (T));

	DestroyBiTree(T); // ���ٶ�����T
	return 1;
}


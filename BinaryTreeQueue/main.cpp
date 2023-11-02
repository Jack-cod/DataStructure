#include "BiTree.h"

int main()
{
	BiTree T;

    int ha=0;  int la=8;
	int hb=0;  int lb=8;
	TElemType A[9]={'A','B','C','D','E','F','G','H','K'};
    TElemType B[9]={'B','D','C','A','E','H','G','K','F'};

	T=CreateTree(A,B,ha,la,hb,lb);// ����������T*/

	printf("�������Ĳ�α������У�\n");
	LevelOrderTraverse(T,visit);
	printf("\n");

	printf("��Ŀ¼��ʽ�����������\n");
	PrintTree(T,0);

        if (IsCompleteTree(T))
        printf("����һ����ȫ������\n");
	else
        printf("�ⲻ��һ����ȫ������\n");

	DestroyBiTree(T); // ���ٶ�����T
	return 1;
}


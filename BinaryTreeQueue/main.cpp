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

    TElemType findElem;
    TElemType findResult;
	cout << "������Ҫ����˫�׵Ľ��:"  << endl;
	cin >> findElem;
	if (FindParent(T, findElem, findResult)) {
        cout << findElem << "�ĸ����Ϊ" << findResult << endl;
	}
	else {
        cout << "������ڵ�򲻴��ڵĽڵ�" << endl;
	}

    TElemType nodeFirst;
    TElemType nodeSecond;
    TElemType nearAncestor;
    map<TElemType, TElemType> parents;
    cout << "������Ҫ����������ȵ��������(A B):" << endl;
    cin >> nodeFirst >> nodeSecond;
    if (FindNearAncestors(T, parents, nodeFirst, nodeSecond, nearAncestor)) {
        cout << nodeFirst << "��" << nodeSecond << "����Ĺ�ͬ����Ϊ" << nearAncestor << endl;
    }
    else {
        cout << "���߿��ܲ�û�й�ͬ����" << endl;
    }
	DestroyBiTree(T); // ���ٶ�����T
	return 1;
}


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

    int desiredLayer;
    int countLayer = 0;
    int depth = TreeDepth(T);
    cout << "������Ҫ���������Ĳ�Σ�" << endl;
    cin >> desiredLayer;
    CountLayerNodes(T, 1, desiredLayer, depth, countLayer);
    cout << "��" << desiredLayer << "��Ľ����Ϊ��" << countLayer << endl;

    // �����ַ���������map�в������ڸ��ڵ㸸�ڵ��ӳ��
    // �ǳ�����ıܿ�����Ŀ����Ҫ�жϵĸ��ڵ�����
    // ������˵map��Ѱ�Ҹ��Ӷ�Ϊlgn
    // �ȵ��������ڵ㴴��������������Խ�Ҫ��
    map<char, char> parents;
    // ��� ֱ�Ӱ����еĸ��ڵ������
    FindParentNode(T, parents);
    char desiredNode;
    cout << "������Ҫ���Ҹ����Ľ�㣺" << endl;
    cin >> desiredNode;
    if (parents[desiredNode]) {
        cout << desiredNode << "�ĸ����Ϊ" << parents[desiredNode] << endl;
    }
    else {
        cout << "����Ϊ���ڵ�򲻴��ڵĽڵ㣡" << endl;
    }

    // ���������ȼ�Ϊ�󸸽ڵ㡢���ڵ�ĸ��ڵ�......
    // ���ǿ���ֱ�ӽ�����һ���е�map
    // ����ĿҪ���д�㷨
    // ����ֱ�ӽ�������һ������
    cout << "������Ҫ�������Ƚ��Ľ�㣺" << endl;
    char desiredAnstNode;
    cin >> desiredAnstNode;
    int ans = FindAncestors(T, parents, desiredAnstNode);
    if (!ans) cout << "����Ϊ���ڵ�򲻴��ڵĽڵ㣡";

	DestroyBiTree(T); // ���ٶ�����T
	return 1;
}


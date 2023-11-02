#include "BiTree.h"
#include "LinkQueue.h"

// ��������Ļ�������

BiTree CreateTree(TElemType A[],TElemType B[],int ha,int la,int hb,int lb) {
    //ha��la�ֱ�������������еĵ�һ�������һ������±꣬ hb��lb�ֱ�������������еĵ�һ�������һ������±꣬
	//��ʼ���ú���ʱ��ha=hb=0,la=lb=n-1,nΪ����������Ԫ�صĸ���
    if (ha > la || hb > lb) return NULL;  // �ݹ���ֹ����

    // �������ڵ�
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = A[ha];

    // ����������������ҵ����ڵ��λ��
    int rootIndex = hb;
    while (rootIndex <= lb && B[rootIndex] != A[ha]) rootIndex++;

    // �������������������Ľڵ�����
    int leftLength = rootIndex - hb;
    int rightLength = lb - rootIndex;

    // �ݹ鹹����������������
    root->lchild = CreateTree(A, B, ha + 1, ha + leftLength, hb, rootIndex - 1);
    root->rchild = CreateTree(A, B, ha + leftLength + 1, la, rootIndex + 1, lb);

    return root;
}


void visit(TElemType e) {
	printf("%c",e);
}

Status LevelOrderTraverse(BiTree T,void(*Visit)(TElemType)) {
    // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
	// �������������ݹ����T(���ö���)����ÿ�������ú���Visitһ���ҽ�һ��
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        BiTree tmp;
        DeQueue(Q, tmp);
        if (tmp) {
            Visit(tmp->data);
            EnQueue(Q, tmp->lchild);
            EnQueue(Q, tmp->rchild);
        }
    }
    return OK;
}


Status PrintTree(BiTree bt,int nLayer)  {
    /* ��������״��ӡ�Ķ����� */
    if (bt != nullptr) {
        PrintTree(bt->lchild, nLayer + 1);
        for (int i = 0; i < nLayer; i++) {
            cout << " -";
        }
        cout << bt->data << endl;
        PrintTree(bt->rchild, nLayer + 1);
    }
    return OK;
}

Status IsCompleteTree(BiTree T) {
    //�ж�һ�ö������Ƿ�����ȫ������
    int flag = 0;
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,  T);
    while (!QueueEmpty(Q)) {
        BiTree tmp;
        DeQueue(Q, tmp);
        if (flag == 1 && tmp != nullptr) {
            return FALSE;
        }
        if (tmp == nullptr) {
            flag = 1;
        }
        else {
            EnQueue(Q, tmp->lchild);
            EnQueue(Q, tmp->rchild);
        }
    }
    return TRUE;
}

Status DestroyBiTree(BiTree &T) {
    // ��ʼ������������T���ڡ�������������ٶ�����T
    if (T == nullptr) return OK;
    else {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        // �ͷŲ��ÿ�
        free(T);
        T = nullptr;
    }
    return OK;
}

#include "BiTree.h"
#include "LinkQueue.h"

// ��������Ļ�������

BiTree CreateTree(TElemType A[],TElemType B[],int ha,int la,int hb,int lb) {
    //ha��la�ֱ�������������еĵ�һ�������һ������±꣬ hb��lb�ֱ�������������еĵ�һ�������һ������±꣬
	//��ʼ���ú���ʱ��ha=hb=0,la=lb=n-1,nΪ����������Ԫ�صĸ���
    BiTree current = (BiTree) malloc(sizeof(BiTNode));
    current->data = A[ha];
    if (hb < 0 || lb < 0 || hb >= lb || ha > la) return nullptr;
    int new_left_hb;
    int new_left_lb;
    int new_right_hb;
    int new_right_lb;
    for (int i = hb; i <= lb; i++)  {
        if (B[i] == A[ha]) {
            new_left_hb = hb;
            new_left_lb = i - 1;
            new_right_hb = i + 1;
            new_right_lb = lb;
        }
    }
    current->lchild = CreateTree(A, B, ha + 1, la, new_left_hb, new_left_lb);
    current->rchild = CreateTree(A, B, ha + 1, la, new_right_hb, new_right_lb);
    return current;
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
    return OK;
}

Status IsCompleteTree(BiTree T) {
    //�ж�һ�ö������Ƿ�����ȫ������
    return OK;

}

Status DestroyBiTree(BiTree &T) {
    // ��ʼ������������T���ڡ�������������ٶ�����T
    return OK;
}

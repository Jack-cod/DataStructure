#include "BiTree.h"
// ��������Ļ�������

Status CreateBiTree(BiTree &T) {
    // ����ȫ������������������н���ֵ
    char ch;
    scanf("%c", &ch);
    if (ch == ' ') T = nullptr;
    else {
        if (!(T = (BiTNode *) malloc(sizeof(BiTNode)))) return (OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

void visit(TElemType e) {
	printf("%c",e);
}

Status PreOrderTraverse(BiTree T,void(*Visit)(TElemType)) {
    // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú�����
	// �������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
	if (T != nullptr) {
        Visit(T->data);
        // ���������ǵ�Visit������û�ж��巵��ֵ
        // ������ʵ�����ǲ�û�а취����Ƿ�ɹ�����
        // �������Ҳ�Ͳ���Ϊ���ӵ�PreOrderTraverse���ü��
        // ����������˿ɶ���
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
	}
    return OK;
}

Status InOrderTraverse(BiTree T,void(*Visit)(TElemType)) {
    // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
	// �������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
	if (T != nullptr) {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
	}
    return OK;
}

Status PostOrderTraverse(BiTree T,void(*Visit)(TElemType)) {
    // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
	// �������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
	if (T != nullptr) {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
	}
    return OK;
}

void CountLeaf (BiTree T,int &count) {
    //ͳ�ƶ�������Ҷ�ӽ����
    if (T == nullptr) return;
    else {
        if (T->lchild == nullptr && T->rchild == nullptr)
            count++;
        else {
            CountLeaf(T->lchild, count);
            CountLeaf(T->rchild, count);
        }
    }
}

int TreeDepth (BiTree T){
    // ���ض����������
   if (T == nullptr) return 0;
   else {
        int depthLeft = TreeDepth(T->lchild);
        int depthRight = TreeDepth(T->rchild);
        return std::max(depthLeft, depthRight) + 1;
   }
}


Status PrintTree(BiTree bt,int nLayer) {
    /* ��������״��ӡ�Ķ����� */
    if (bt != nullptr) {
        PrintTree(bt->lchild, nLayer + 1);
        for (int i = 1; i < nLayer; i++) {
            cout << "-";
        }
        cout << bt->data << endl;
        PrintTree(bt->rchild, nLayer + 1);
    }
    return OK;
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

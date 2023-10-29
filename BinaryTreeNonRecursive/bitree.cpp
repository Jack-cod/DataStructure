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
    stack<BiTree> s;
    s.push(T);
    while (!s.empty()) {
        BiTree p;
        while (p = s.top()) s.push(p->lchild); // �����ߵ���ͷ
        s.pop();
        if (!s.empty()) {
            p = s.top();
            s.pop();
            Visit(p->data);
            s.push(p->rchild);
        }
    }
    return OK;
    /*
    ���߲���TAOCP�и����ķǵݹ���������㷨��

    �㷨 T��������������������� T ��һ��������������һ�����ڵ㣨2����ʾ�Ķ��������㷨���һ�����ӵ��� A�����������ʱ֮����X�������н�㡣
    T1. [��ʼ����] ���� A Ϊ������ʼ������� P �� T��
    T2. [P=A?] ��� P=A����ת������ T4��
    T3. [�� �� P.] ����P ָ���һ��δ���ʹ��ķǿն���������ʼָ��һ��δ���ʹ��ķǿն��������� A��P������ P ��ֵ���� A (�� 2.2.1 ��)��Ȼ�� P �� L.LINK(P)�������ز��� T2��
    T4. [P <= ��.] ����� A Ϊ�գ����㷨��ֹ������ P��A��
    T5. [P ����.] ���� NODE(P)��Ȼ���� P�� R.LINK(P) �����ز��� T2��
    */

    /*
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {s.push(p); p = p->lchild;}
        else {
            s.pop();
            Visit(p->data);
            p = p->rchild
        }
    }
    return OK;
    */
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

Status CountLayerNodes(BiTree T, int currentLayer, int Layer, int maxDepth, int& count) {
    //�Ϸ��Լ���
    if (Layer < 1 || Layer > maxDepth) return ERROR;
    if (T == nullptr || currentLayer > Layer) return OK; // ��֦,����Ѿ����ڲ������Բ����ټ���
    if (currentLayer == Layer) count++;
    CountLayerNodes(T->lchild, currentLayer + 1, Layer, maxDepth,count);
    CountLayerNodes(T->rchild, currentLayer + 1, Layer, maxDepth, count);
    return OK;
}


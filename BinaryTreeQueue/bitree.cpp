#include "BiTree.h"
#include "LinkQueue.h"

// ��������Ļ�������

BiTree CreateTree(TElemType A[],TElemType B[],int ha,int la,int hb,int lb) {
    //ha��la�ֱ�������������еĵ�һ�������һ������±꣬ hb��lb�ֱ�������������еĵ�һ�������һ������±꣬
	//��ʼ���ú���ʱ��ha=hb=0,la=lb=n-1,nΪ����������Ԫ�صĸ���
    if (ha > la || hb > lb) return NULL;  // �ݹ���ֹ����

    // �������ڵ�
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    if (root == nullptr) exit(OVERFLOW);
    root->data = A[ha];

    // ����������������ҵ����ڵ��λ��
    int rootIndex = hb;
    while (rootIndex <= lb && B[rootIndex] != A[ha]) rootIndex++;

    ////////////////////////////////////////////////////////
    //           ����һ�㽡׳��            //
    //////////////////////////////////////////////////////
    if (rootIndex > lb) {
        free(root);
    return NULL;  // ������������
    }

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
    DestroyQueue(Q); // ��������ͷſռ�
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
            DestroyQueue(Q);
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
    DestroyQueue(Q);
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

Status FindParent(BiTree &T, TElemType x, TElemType &parent) {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        BiTree tmp;
        DeQueue(Q, tmp);
        if (tmp) {
            EnQueue(Q, tmp->lchild);
            EnQueue(Q, tmp->rchild);
            // ���ö�·ԭ�����ж������ӽڵ��Ƿ�Ϊ��
            if (tmp->lchild != nullptr && tmp->lchild->data == x) {
                parent = tmp->data;
                // �����к������ڲ��ö�������
                DestroyQueue(Q);
                return OK;
            }
            if (tmp->rchild != nullptr && tmp->rchild->data == x) {
                parent = tmp->data;
                DestroyQueue(Q);
                return OK;
            }
        }
    }
    DestroyQueue(Q);
    return ERROR;
}

// ���븴�� ���ϴ�ʵ��Ĵ���
void FindParentNode(BiTree T, map<TElemType, TElemType> &parents) {
    if (T == nullptr) return;
    // ������Ӵ���
    if (T->lchild) {
        parents[T->lchild->data] = T->data;
        // ������
        FindParentNode(T->lchild, parents);
    }
    if (T->rchild) {
        parents[T->rchild->data] = T->data;
        FindParentNode(T->rchild, parents);
    }
}

Status FindNearAncestors(BiTree T, map<TElemType, TElemType> &parents, TElemType &nodeFirst, TElemType &nodeSecond, TElemType &nearAncestor) {
    // �����Ҹ��ڵ�ĺ���
    // ���
    FindParentNode(T, parents);
    vector<TElemType> prevFirst;
    vector<TElemType> prevSecond;
    // ���Լ��Ž�ȥ
    prevFirst.push_back(nodeFirst);
    prevSecond.push_back(nodeSecond);

    TElemType first = nodeFirst;
    TElemType second = nodeSecond;
    while (parents[first]) {
        prevFirst.push_back(parents[first]);
        first = parents[first];
    }
    while (parents[second]) {
        prevSecond.push_back(parents[second]);
        second = parents[second];
    }
    // ��ʼ����Ƚ�
    for (vector<TElemType>::iterator i = prevFirst.begin(); i < prevFirst.end(); i++) {
        for (vector<TElemType>::iterator j = prevSecond.begin(); j < prevSecond.end(); j++) {
            if (*i == *j) {
                nearAncestor = *i;
                return OK;
            }
        }
    }
    return ERROR;
}

#include "LinkQueue.h"

int flag[30] = {0};
int num = 30;

void AllEnQueue(LinkQueue &Q) {
    for (int i = 0; i < 30; i++) {
            if (!flag[i]) {
                EnQueue(Q, i);
            }
    }
}

int main()
{
    cout << "�����´󺣵�λ������Ϊ:" << endl;
    // �������
    LinkQueue ranks;
    InitQueue(ranks);

    while (num >15) {
        QElemType temp;
        // ��ʼ����
        for (int i = 0; i < 9; i++) {
            // ���ӿ��򲹳�
            //˳�������������
            if (QueueEmpty(ranks)) {
                AllEnQueue(ranks);
            }
            DeQueue(ranks, temp);
        }
        num--; // ����һ��
        flag[temp] = 1;
        cout << temp + 1 << "    ";
    }
    // ���ٶ���
    DestroyQueue(ranks);
	return 1;
}

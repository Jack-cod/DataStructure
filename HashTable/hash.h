 #define NULLKEY 0 // 0Ϊ�޼�¼��־
 #define N 10 // ����Ԫ�ظ���
 typedef int KeyType; // ��ؼ�����Ϊ����
 struct ElemType // ����Ԫ������
 {
   KeyType key;
   int ord;
 };
 //���Ŷ�ַ��ϣ��Ĵ洢�ṹ
 int hashsize[]={11,19,29,37}; // ��ϣ������������һ�����ʵ���������
 int m=0; // ��ϣ�����ȫ�ֱ���
 struct HashTable
 {
   ElemType *elem; // ����Ԫ�ش洢��ַ����̬��������
   int count; // ��ǰ����Ԫ�ظ���
   int sizeindex; // hashsize[sizeindex]Ϊ��ǰ����
 };

 #define SUCCESS 1
 #define UNSUCCESS 0
 #define DUPLICATE -1

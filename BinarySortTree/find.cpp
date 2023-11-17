 #include"public1.h"
 #include"BiTree.h"
 #include"BST.h"

 void print(ElemType c)
 {
   printf("(%d,%d) ",c.key,c.others);
 }

 int main()
 {
   BiTree dt,p;
   int i;
   KeyType j;
   ElemType r[N]={{45,1},{12,2},{53,3},{3,4},{37,5},{24,6},{100,7},{61,8},{90,9},{78,10}};
   InitDSTable(dt); // ����ձ�
   for(i=0;i<N;i++)
     InsertBST(dt,r[i]); // ���β�������Ԫ��
   TraverseDSTable(dt,print);
   printf("\n����������ҵ�ֵ: ");
   scanf("%d",&j);
   p=SearchBST(dt,j);
   if(p)
   {
     printf("���д��ڴ�ֵ��");
     //ѡ����ɾ�����ҵ��Ľ�㣬�������������������鿴ɾ����Ľ��
     printf("\n");
   }
   else
     printf("���в����ڴ�ֵ\n");

    /*
    ʵ�������������ɾ���㷨
    */
    if (p) {
        // ������ҵ��˱�����ɾ��
        KeyType toDelete;
        // ��ĿҪ��ʹ��֮ǰ���ҵ�ֵ
        toDelete = j;
        DeleteBST(dt, toDelete);
        cout << "ɾ����ֵ��" << endl;
        TraverseDSTable(dt, print);
    }
   DestroyDSTable(dt);
   return 1;
 }

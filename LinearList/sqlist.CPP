#include <iostream>
#include <vector>
#include <iomanip>

#include"public1.H"
#include"sqlist.H"

using namespace std;

Status InitList(SqList &L)
{
    //����һ���յ�˳���
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList &L)
{
    //����˳�����Ա�L
    if (L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
    }
    return OK;
}

Status comp(ElemType c1, ElemType c2)
{
    if(c1==c2)
        return TRUE;
    else
        return FALSE;
}

int LocateElem(SqList L, ElemType e,Status (* compare)(ElemType, ElemType))
{
    //��������Ԫ�ص�ֵ�������������Ա�L�е�λ��
    int i=0;
    while ((i<=L.length)&&(!compare(*(L.elem+i-1),e)))
        i++;
    if (i<=L.length)
        return i;
    else
    return(0);
}

Status GetElem(SqList L,int i,ElemType &e)
{
    //��������Ԫ�������Ա�L�е�λ�ã���������ֵ
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

Status ListInsert(SqList &L,int i,ElemType e)
{
    // ��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;
    }

    if (L.length >= L.listsize) //�������Բ����������
    {
        //���·���ռ�
        ElemType * newbase = (ElemType *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
        {
            return OVERFLOW;
        }
        L.elem = newbase;
        L.listsize = L.listsize + LISTINCREMENT;
    }

    //���Բ���
    ElemType * insert_index = L.elem + i - 1;

   // �Ӻ���ǰ�ƶ�Ԫ���Կճ�λ��
    for (ElemType *p = &(L.elem[L.length - 1]); p >= insert_index; p--)
    {
        *(p + 1) = *p;
    }

    *insert_index = e;
    L.length++;

    return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e)
{
    //ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    //����Ƿ�Խ��
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }

    for (ElemType * p = &L.elem[i - 1]; p <= &L.elem[L.length - 2]; p++)
    {
        *p = *(p + 1);
    }

    L.length--; //������

    return OK;
}

void print(ElemType c)
{
    printf("%d ",c);
}

Status ListTraverse(SqList L,void(* visit)(ElemType))
{
    //�������˳���ĸ���Ԫ��ֵ
    int i;
    for(i=1;i<=L.length;i++)
        visit(*(L.elem+i-1));
    cout<<endl;
    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    return OK;
}

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
 {
     // ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
     // �����ʧ��
     if (cur_e == L.elem[0]) //ȷ�����ǵ�һ��
     {
         return ERROR;
     }

     for (int i = 1; i < L.length; i++)
     {
         if (L.elem[i] == cur_e)
         {
             pre_e = L.elem[i - 1]; //�������Ѿ�ȷ������Խ��
             return OK;
         }
     }
     return ERROR; //δ�ҵ�
 }

 Status DeleteAllX(SqList &L, ElemType x)
 {
     int valid_index = 0;
     for (int i = 0; i < L.length; i++)
     {
         if (L.elem[i] != x)
         {
             L.elem[valid_index] = L.elem[i];
             valid_index++;
         }
     }
     L.length = valid_index;
     return OK;
 }

int main(int argc, char *argv[])
{
    //��ʼ�����Ա�
    SqList L;
    ElemType e;
    Status i;
    int j;
    i=InitList(L);
    printf("��ʼ��L��*L.elem=");
    ListTraverse(L,print);

    //�ڱ�ͷ��������
    for(j=1;j<=5;j++)
        i=ListInsert(L,1,j);
    printf("��L�ı�ͷ���β���1��5��*L.elem=");
    ListTraverse(L,print);

    //�ڱ�β��������
    for(j=1;j<=5;j++)
        *(L.elem+L.length+j-1)=j;
    printf("��L�ı�β���β���1��5��*L.elem=");
    L.length=L.length+5;
    ListTraverse(L,print);

    //����ջ���
    ListInsert(L,1,0);
    printf("��L�ı�ͷ����0��*L.elem=");
    ListTraverse(L,print);

    //���Բ�ѯԪ��λ��
    i=LocateElem(L,1,comp);
    printf("ֵΪ1������Ԫ����˳����е�λ����");
    printf("%d \n",i);

    //����
    GetElem(L,5,e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);

    //����ɾ��Ԫ��
    printf("��L��ɾ����3������Ԫ�أ�*L.elem=");
    ListDelete(L,3,e);
    ListTraverse(L,print);

    //���Բ�ѯǰ��Ԫ��
    int test_curent_element = 0;
    int test_prior_element = 0;
    printf("\n\n**���Բ�ѯǰ��Ԫ��**\n");
    printf("������Ҫ��ѯ��Ԫ�أ�");
    scanf("%d", &test_curent_element);
    if (PriorElem(L, test_curent_element, test_prior_element))
    {
        printf("�������Ԫ��ǰ��Ϊ��%d\n", test_prior_element);
    }
    else{
        printf("�����볢���������룡\n");
    }

    //����ɾ������ָ��Ԫ��
    int test_to_delete_element = 0;
    printf("\n\n**����ɾ������ָ��Ԫ��**\n");
    printf("������Ҫɾ����Ԫ�أ�");
    scanf("%d", &test_to_delete_element);
    DeleteAllX(L, test_to_delete_element);
    printf("ɾ�����е�%d֮��", test_to_delete_element);
    ListTraverse(L,print);

    //�������ٱ�
    DestroyList(L);
    printf("����L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);

    return 1;
}

#ifndef HEADER
#define HEADER

 typedef int ElemType;
//������Ĵ洢����
typedef struct LNode
{
    ElemType         data;
    struct LNode   *next;
}LNode, *LinkList;

#endif // header guard


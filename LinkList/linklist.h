#ifndef HEADER_1939BD45238D71C4
#define HEADER_1939BD45238D71C4

 typedef int ElemType;
//单链表的存储定义
typedef struct LNode
{
    ElemType         data;
    struct LNode   *next;
}LNode, *LinkList;
#endif // header guard 


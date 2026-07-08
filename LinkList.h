#ifndef LINKLIST_H
#define LINKLIST_H

#include <cstddef>

#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode* next;		//结构体里面要指向自己，必须有标签名struct LNode，结构体还没定义完，typedef 别名还没生效，只能用 struct 标签名 指代自身类型，所以必须写标签 LNode
} LNode, * LinkList;



int Length(LinkList L);
LinkList Reverse_1(LinkList L);
void LinkeListTraverse(LinkList L);
bool InitList(LinkList &L);
bool InsertList(LinkList& L, int i, ElemType e);
bool DeleteList(LinkList& L, int i, ElemType& e);

#endif // LINKLIST_H

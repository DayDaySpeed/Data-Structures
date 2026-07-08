#if DEMO == LINKLIST
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include "LinkList.h"

int main() {
	LinkList L;
	if (!InitList(L)) {
		std::cout << "InitList failed\n";
		return 1;
	}
	
	int j = 1, i = 2;
	while (j <= 10 && InsertList(L, j, i)) {
		j++; i *= 2;
	}

	std::cout << "Length = " << Length(L) << "\n";
	LinkeListTraverse(L);
	Reverse_1(L);
	LinkeListTraverse(L);
	return 0;
}



int Length(LinkList L) {		//此时L是LNode*类型的指针，指向头结点
	int len = 0;
	LNode* p = L;				//拷贝指针的副本
	while (p != nullptr && p->next != nullptr) {
		p = p->next;
		len++;
	}
	return len;
}

//创建一个空的单链表
bool InitList(LinkList &L) {	//L是LNode*类型的指针，指向头结点，此刻是引用
	L = (LinkList)std::malloc(sizeof(LNode));
	if (!L) {
		return false;
	}
	L->next = nullptr;
	return true;
}

//在单链表的第i个位置插入元素e
bool InsertList(LinkList& L, int i, ElemType e) {
	LNode* p = L;		//指向头结点
	int j = 0;			//头节点为0
	// 非法位置检测：i 必须 >= 1（插入第1个元素表示插入在头结点之后）
	if (i < 1) {
		return false;
	}
	while (p != nullptr && j < i-1) {
		p = p->next;
		j++;
	}
	if (p == nullptr) {	//i小于1或者大于表长+1,说明指针此刻仍指向头节点或指向最后面的空结点
		return false;
	}
	LNode* s = (LNode *)std::malloc(sizeof(LNode));
	if (s == nullptr) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除单链表的第i个位置的元素，并用e返回其值
bool DeleteList(LinkList& L, int i, ElemType& e) {
	LNode* p = L;		//p指向头结点
	int j = 0;			//头节点下标记为0
	// 寻找第i-1个结点
	while (p != nullptr && j < i - 1) {
		p = p->next;	//找到前驱结点
		j++;
	}
	if (p == nullptr || p->next == nullptr) {//多加一个判断条件，防止删除不存在的结点
		return false;
	}
	LNode* q = p->next;	//q指向要删除的节点
	e = q->data;		    //取出被删元素值
	p->next = q->next;	    //摘除结点
	std::free(q);			    //释放内存
	return true;
}

LinkList Reverse_1(LinkList L) {		//原地反转，维护一个r指针
	LNode* p, * r;
	p = L->next;	//p指向第一个结点
	L->next = nullptr;	//头结点的next指针置空
	while (p != nullptr) {
		//将p插入到头结点之后
		r = p->next;	//保存p的下一个结点
		p->next = L->next;	//将p插入到头结点之后
		L->next = p;	//将p插入到头结点之后
		p = r;	//p指向下一个结点
	}
	return L;
}

void LinkeListTraverse(LinkList L) {
	LNode* p = L->next;	//p指向第一个结点
	while (p != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << "\n";
}


#endif
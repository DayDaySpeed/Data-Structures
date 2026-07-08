#include <iostream>
#include "CurrentDemo.h"
#if DEMO == SQSTACK


#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;



void InitStack(SqStack &S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType x);
void StackTraverse(SqStack S);


int main() {
	SqStack S;		//定义一个栈
	InitStack(S);	//初始化栈
	SqStack* s = &S;	//获取栈的指针
	std::cout << "初始化的栈的地址为	" << s << '\n';
	std::cout << "栈顶为	" << s->top << '\n';

	bool a = true;
	int i = 0;
	while (Push(S, i))
	{
		std::cout << "入栈:" << i << '\n';
		i++;
	}
	StackTraverse(S);
}


//初始化栈

void InitStack(SqStack &S) {
	S.top = -1;
}


//判断栈是否为空
bool StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	else {
		return false;
	}
}

//入栈
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;		//栈顶指针加1，元素入栈
	return true;
}

//出栈
bool Pop(SqStack &S, ElemType &x) {	//x返回的是引用，同一个变量
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top--];	//栈顶元素出栈，栈顶指针减1
	return true;
}

//获取栈顶元素
bool GetTop(SqStack S, ElemType &x) {
	if (S.top == -1)return false;	//栈空
	x = S.data[S.top];
	return true;
}

//遍历栈中的元素
void StackTraverse(SqStack S)
{
	if (S.top == -1)
	{
		std::cout << "栈为空！\n";
		return;
	}


	for (int i = S.top; i >= 0; i--)
	{
		std::cout
			<< "第 "
			<< i
			<< " 个元素:"
			<< S.data[i]
			<< '\n';
	}
}











#endif
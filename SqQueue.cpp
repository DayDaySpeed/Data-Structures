#include "CurrentDemo.h"
#if DEMO == SQQUEUE
typedef struct {
	ElemType data[MaxSize];	//存放队列元素的数组
	int front, rear;		//队头指针和队尾指针
}SqQueue;

//循环队列，基于牺牲一个存储单元
/*
	队空条件：front == rear
	队满条件： (rear + 1) % MaxSize == front
	队列中元素个数： (rear - front + MaxSize) % MaxSize
*/

int main() {
	return 0;
}

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;	//初始化队头和队尾指针
}


//判断空
bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {//队空条件
		return true;
	}
	return false;
}

//入队
bool EnQueue(SqQueue& Q, ElemType e) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false;	//队满条件
	}
	Q.data[Q.rear] = e;	//将元素e插入队尾
	Q.rear = (Q.rear + 1) % MaxSize;	//队尾指针加1
	return true;
}


//出队
bool DeQueue(SqQueue &Q, ElemType e) {
	if (Q.front == Q.rear) {
		return false;	//队空
	}
	e = Q.data[Q.front];	//将队头元素赋值给e
	Q.front = (Q.front + 1) % MaxSize;	//队头指针加1
	return true;
}


#endif
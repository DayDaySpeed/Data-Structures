#include "CurrentDemo.h"
#if DEMO == BITNODE

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
#endif
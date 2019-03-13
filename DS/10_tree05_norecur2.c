#include <stdlib.h>
#include <string.h>
#include "07_linkstack.h"
#include "03_linklist.h"


struct BiTNode {
	//void* node;//for link list
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode	BiTNode;
typedef struct BiTNode*	BiTree;

/*
step1:
如果节点有左子树, 该节点入栈
如果节点没有左子树, 访问该节点

step2:
如果节点有右子树, 重复step1
如果节点没有右子树, 根据栈顶指示回退, 访问栈顶元素, 并访问右子树, 重复step1
如果栈为空, 表示遍历结束
*/

//03. link list
//一直向左走, 找到中序遍历的起点
BiTNode* goLeft3(BiTNode* node, LinkList* list) {
	if (node == NULL) {
		return NULL;
	}
	while (node->lchild != NULL) {
		LinkList_Insert(list, (LinkListNode*)node, 0);
		node = node->lchild;
	}
	return node;
}

void inOrder3(BiTNode* node) {
	BiTNode *t = NULL;

	LinkList* list = LinkList_Create();
	if (list == NULL) {
		printf("func LinkList_Create err\n");
		return;
	}

	t = goLeft3(node, list);

	while (t) {
		printf("%d  ", t->data);

		//如果t有右子树 重复step1
		if (t->rchild != NULL) {
			t = goLeft3(t->rchild, list);//右子树中中序遍历的起点
		}
		else if (LinkList_Length(list) > 0) {//如果t没有右子树 根据栈顶指示 回退
			t = (BiTNode*)LinkList_Delete(list, 0);
		}
		else {//如果t没有右子树 并且 栈为空
			t = NULL;
		}
	}
}

//04. link stack
//一直向左走, 找到中序遍历的起点
BiTNode* goLeft4(BiTNode* node, LinkStack* s) {
	if (node == NULL) {
		return NULL;
	}
	while (node->lchild != NULL) {
		LinkStack_Push(s, (void*)node);
		node = node->lchild;
	}
	return node;
}

void inOrder4(BiTNode* node) {
	BiTNode *t = NULL;

	LinkStack* s = LinkStack_Create();
	if (s == NULL) {
		printf("func LinkStack_Create err\n");
		return;
	}

	t = goLeft4(node, s);

	while (t) {
		printf("%d  ", t->data);

		//如果t有右子树 重复step1
		if (t->rchild != NULL) {
			t = goLeft4(t->rchild, s);//右子树中中序遍历的起点
		}
		else if (LinkStack_Size(s) > 0) {//如果t没有右子树 根据栈顶指示 回退
			t = (BiTNode*)LinkStack_Pop(s);
		}
		else {//如果t没有右子树 并且 栈为空
			t = NULL;
		}
	}
}

int main() {
	BiTNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//build tree
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	//printf("inOrder3:\n");
	//inOrder3(&t1);

	printf("\n");
	printf("inOrder4:\n");
	inOrder4(&t1);

	printf("hello...\n");
	system("pause");
	return 0;
}
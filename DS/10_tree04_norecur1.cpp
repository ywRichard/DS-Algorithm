#include <iostream>
#include <stack>

using namespace std;

struct BiTNode {
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

//一直向左走, 找到中序遍历的起点
BiTNode* goLeft(BiTNode* node, stack<BiTNode*>&s) {
	if (node == NULL) {
		return NULL;
	}
	while (node->lchild != NULL) {
		s.push(node);
		node = node->lchild;
	}
	return node;
}

void inOrder2(BiTNode* node) {
	BiTNode *t = NULL;
	stack<BiTNode*> s;

	t = goLeft(node, s);

	while (t) {
		printf("%d  ", t->data);

		//如果t有右子树 重复step1
		if (t->rchild != NULL) {
			t = goLeft(t->rchild, s);//右子树中中序遍历的起点
		}
		else if (!s.empty()) {//如果t没有右子树 根据栈顶指示 回退
			t = s.top();
			s.pop();
		}
		else {//如果t没有右子树 并且 栈为空
			t = NULL;
		}
	}
}

void inOrder(BiTNode* root) {
	if (root == NULL) return;

	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
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

	printf("inOrder2:\n");
	inOrder2(&t1);

	printf("hello...\n");
	system("pause");
	return 0;
}
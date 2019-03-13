#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode	BiTNode;
typedef struct BiTNode*	BiTree;

//LDR
void inOrder(BiTNode* root) {
	if (root == NULL) return;

	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

BiTNode* CopyTree(BiTNode* src) {
	if (src == NULL) {
		return NULL;
	}

	BiTNode* dst = NULL;
	BiTNode* newLp = NULL;
	BiTNode* newRp = NULL;

	if (src->lchild != NULL)
		newLp = CopyTree(src->lchild);
	else
		newLp = NULL;

	if (src->rchild != NULL)
		newRp = CopyTree(src->rchild);
	else
		newRp = NULL;

	dst = (BiTNode*)malloc(sizeof(BiTNode));
	if (dst == NULL)
		return NULL;

	dst->lchild = newLp;
	dst->rchild = newRp;
	dst->data = src->data;
	return dst;
}

int Depth(BiTNode* t) {
	int deptLeft = 0;
	int deptRight = 0;
	int deptVal = 0;

	if (t == NULL) {
		deptVal = 0;
		return deptVal;
	}

	deptLeft = Depth(t->lchild);
	deptRight = Depth(t->rchild);

	//1
	deptVal = 1 + (deptLeft > deptRight ? deptLeft : deptRight);
	return deptVal;
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

	printf("\ndepth:%d\n", Depth(&t1));

	printf("inOrder:\n");
	inOrder(&t1);

	BiTNode* cpy = CopyTree(&t1);
	printf("\ncopy tree inOrder:\n");
	inOrder(&t1);

	printf("\n");
	printf("hello...\n");
	system("pause");
	return 0;
}
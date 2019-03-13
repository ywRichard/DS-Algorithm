#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//01.二叉链表示法
struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode	BiTNode;
typedef struct BiTNode*	BiTree;

//DLR
void preOrder(BiTNode* root) {
	if (root == NULL) return;

	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

//LDR
void inOrder(BiTNode* root) {
	if (root == NULL) return;

	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

//LRD
void postOrder(BiTNode* root) {
	if (root == NULL) return;

	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}

int sum;

void countLeaf(BiTNode* t) {
	if (t != NULL) {
		if (t->lchild == NULL && t->rchild == NULL) {
			sum++;
		}

		if (t->lchild)
			countLeaf(t->lchild);

		if (t->rchild)
			countLeaf(t->rchild);
	}
}

void countLeaf2(BiTNode* t, int* sum) {
	if (t != NULL) {
		if (t->lchild == NULL && t->rchild == NULL) {
			(*sum)++;
		}

		if (t->lchild)
			countLeaf2(t->lchild, sum);

		if (t->rchild)
			countLeaf2(t->rchild, sum);
	}
}

void countLeaf3(BiTNode* t, int* sum) {
	if (t != NULL) {
		if (t->lchild)
			countLeaf3(t->lchild, sum);

		if (t->rchild)
			countLeaf3(t->rchild, sum);

		if (t->lchild == NULL && t->rchild == NULL) {
			(*sum)++;
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

	//建立关系
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	//遍历
	//printf("preOrder:\n");
	//preOrder(&t1);

	//printf("\ninOrder:\n");
	//inOrder(&t1);

	//printf("\npostOrder:\n");
	//postOrder(&t1);

	sum = 0;
	//countLeaf(&t1);
	//countLeaf2(&t1, &sum);
	countLeaf3(&t1, &sum);
	printf("Leaf sum:%d\n", sum);

	printf("\n");
	system("pause");
	return 0;
}


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

//按给定的先序序列建立二叉树
BiTNode* CreateBiThrTree() {
	BiTNode* node = NULL;
	char h;

	printf("input tree expression:\n");
	scanf_s("%c", &h);

	if (h == '#')
	{
		return NULL;
	}
	else
	{
		node = (BiTNode*)malloc(sizeof(BiTNode));
		if (node == NULL) return NULL;

		memset(node, 0, sizeof(BiTNode));
		node->data = h;

		node->lchild = CreateBiThrTree();//recur create tree
		node->rchild = CreateBiThrTree();//recur create tree
	}

	return node;
}

//后续遍历释放树
void FreeTree(BiTNode* node) {
	if (node == NULL) return;

	if (node->lchild != NULL) {
		FreeTree(node->lchild);
		node->lchild = NULL;
	}

	if (node->rchild != NULL) {
		FreeTree(node->rchild);
		node->rchild = NULL;
	}

	if (node != NULL) {
		free(node);
		node = NULL;
	}
}

//LDR
void inOrder(BiTNode* root) {
	if (root == NULL) return;

	inOrder(root->lchild);
	printf("%c ", root->data);
	inOrder(root->rchild);
}

void preOrder(BiTNode* root) {
	if (root == NULL) return;

	printf("%c ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

int main() {
	BiTNode* root = NULL;
	root = CreateBiThrTree();

	printf("preOrder: ");
	preOrder(root);


	printf("hello...\n");
	return 0;
}
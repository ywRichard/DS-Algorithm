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

void BiTNode_Tree() {
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
}

//02.三叉链表示法
typedef struct TriTNode {
	int data;
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;
}TriTNode, *TriTree;


//03.双亲链表
#define MAX_TREE_SIZE 100
typedef struct BPTNode {
	int data;
	int parentPosition;//指向双亲的指针//数组下标
	char LRTag;//左右孩子标志域
}BPTNode;

typedef struct BPTree {
	BPTNode nodes[100];//因为节点之间是分散的, 所以需要把节点储存到数组中
	int num_node;
	int root;
}BPTree;

void BPTNode_Tree() {
	BPTree tree;

	//root, A
	tree.nodes[0].parentPosition = 1000;

	//B
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;

	//C
	tree.nodes[2].parentPosition = 0;
	tree.nodes[2].data = 'C';
	tree.nodes[2].LRTag = 2;
}
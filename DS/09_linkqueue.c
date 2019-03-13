#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "03_linklist.h"
#include "09_linkqueue.h"

typedef struct _tag_LinkQueueNode {
	LinkListNode node;
	void* item;
}TLinkQueueNode;

//create queue ==> create list
LinkQueue* LinkQueue_Create() {
	return LinkList_Create();
}

//destroy queue ===> destroy queue
//节点的内存管理
void LinkQueue_Destroy(LinkQueue* queue) {
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

//清空队列, 队列中所有节点 出列 并释放内存
//因为队列节点的内存是我们malloc的
void LinkQueue_Clear(LinkQueue* queue) {
	while (LinkQueue_Length(queue) > 0) {
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
}

//入列 ===> 向线性表的尾部插入
int LinkQueue_Append(LinkQueue* queue, void* item) {
	int ret = 0;
	TLinkQueueNode* node = NULL;

	node = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if (node == NULL) {
		ret = -1;
		printf("func LinkQueue_Append err: malloc failed");
		return ret;
	}
	memset(node, 0, sizeof(node));

	node->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)node, LinkQueue_Length(queue));
	if (ret != 0) {
		printf("func LinkQueue_Append err: LinkList_Insert() err:%d\n", ret);
		if (node != NULL) free(node);
		return ret;
	}

	return ret;
}

//出列(删除) ===> 从线性表的头部删除
void* LinkQueue_Retrieve(LinkQueue* queue) {
	TLinkQueueNode* node = NULL;
	void* ret = NULL;
	node = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	if (node == NULL) {
		printf("func LinkQueue_Retrieve err: LinkList_Delete() failed\n");
		return NULL;
	}
	ret = node->item;
	if (node != NULL) free(node);

	return ret;
}

//获取队列的头元素 ===> 获取线性表 0号位置的元素
void* LinkQueue_Header(LinkQueue* queue) {
	TLinkQueueNode* node = NULL;
	node = (TLinkQueueNode*)LinkList_Get(queue, 0);
	if (node == NULL) {
		return NULL;
	}

	return node->item;
}

//求队列长度 ===> 求线性表的长度
int LinkQueue_Length(LinkQueue* queue) {
	return LinkList_Length(queue);
}

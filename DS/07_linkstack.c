#include <stdlib.h>
#include <stdio.h>
#include "07_linkstack.h"
#include "03_linklist.h"

typedef struct _tag_LinkStackNode {
	LinkListNode node;//the first linklist node, not linklist head
	void *item;//stack element ---> service node
} TLinkStackNode;

//===> create a linklist 
LinkStack* LinkStack_Create() {
	return LinkList_Create();
}

//===>destroy a linklist
void LinkStack_Destroy(LinkStack *stack) {
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//===>linklist
//need to release the allocated memory in push
void LinkStack_Clear(LinkStack *stack) {
	while (LinkStack_Size(stack) > 0) {
		LinkStack_Pop(stack);
	}
	return;
}

//===> head insert to linklist
//item is service node
int LinkStack_Push(LinkStack *stack, void *item) {
	TLinkStackNode *node = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (node == NULL) {
		printf("malloc stack node failed.\n");
		return -1;
	}
	memset(node, 0, sizeof(TLinkStackNode));
	node->item = item;

	int ret = LinkList_Insert(stack, (LinkListNode *)node, 0);
	if (ret != 0) {
		printf("func LinkList_Insert failed. \n");
		if (node != NULL) {
			free(node);//memory leak
		}
		return ret;
	}

	return ret;
}

//===> get and delete head element from linklist
//return the stack service node
void* LinkStack_Pop(LinkStack* stack) {
	TLinkStackNode* node = NULL;
	node = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (node == NULL) {
		return NULL;
	}
	void* item = NULL;
	item = node->item;

	//manage memory manually
	//release the memory malloc in stack push
	free(node);
	return item;
}

//===> get the head element
void* LinkStack_Top(LinkStack *stack) {
	TLinkStackNode* node = NULL;
	node = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (node == NULL) {
		return NULL;
	}

	return node->item;
}

//===>get linklist length
int LinkStack_Size(LinkStack *stack) {
	return LinkList_Length(stack);
}
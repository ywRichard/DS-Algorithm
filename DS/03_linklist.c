#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "03_linklist.h"

typedef struct _tag_LinkList {
	LinkListNode header;//list head is not the first element even it's not an element.
	int length;
}TLinkList;

LinkList* LinkList_Create() { //O{1}
	TLinkList *ret = NULL;
	ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret == NULL)
	{
		printf("func LinkList_Create err: malloc err.\n");
		return NULL;
	}
	memset(ret, 0, sizeof(TLinkList));
	ret->header.next = NULL;
	ret->length = 0;

	return ret;
}

void LinkList_Destroy(LinkList* list) { //O{1}
	if (list != NULL) {
		free(list);
		list = NULL;
	}
	return;
}

void LinkList_Clear(LinkList* list) { //O{1}
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		printf("func LinkList_Clear err: param err.\n");
		return;
	}
	tList = (TLinkList*)list;

	tList->header.next = NULL;
	tList->length = 0;

	return;
}

int LinkList_Length(LinkList* list) { //O{1}
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		printf("func LinkList_Length err: param err.\n");
		return -1;
	}
	tList = (TLinkList*)list;

	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) { //O{n}
	int ret = 0;
	LinkListNode* current = NULL;
	TLinkList* tList = NULL;

	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func LinkList_Insert err: param err.\n");
		return ret;
	}

	//current = LinkList_Get(list, pos);//reframe
	tList = (TLinkList*)list;
	current = &(tList->header);

	for (int i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	tList->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos) { //O{n}
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Get err: param err.\n");
		return NULL;
	}

	tList = (TLinkList*)list;
	current = &(tList->header);

	for (int i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}

	return current->next; //reframe
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) { //O{n}
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;

	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Delete err: param err.\n");
		return NULL;
	}

	//current = LinkList_Get(list, pos);//reframe
	tList = (TLinkList*)list;
	current = &(tList->header);

	for (int i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}

	ret = current->next;
	current->next = ret->next;

	tList->length--;

	return ret;;
}
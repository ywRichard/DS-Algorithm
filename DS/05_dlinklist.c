#include <stdlib.h>
#include <stdio.h>
#include "05_dlinklist.h"

typedef struct _tag_DLinkList {
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DLinkList* DLinkList_Create() { //O{1}
	TDLinkList *dlist = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (dlist == NULL) {
		printf("func DLinkList_Create() err: malloc err\n");
		return NULL;
	}

	dlist->length = 0;
	dlist->header.next = NULL;
	dlist->slider = NULL;

	return dlist;
}

void DLinkList_Destroy(DLinkList* list) { //O{1}
	if (list != NULL) {
		free(list);
	}

	return;
}

void DLinkList_Clear(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Clear() err: param err\n");
		return;
	}
	TDLinkList* dlist = (TDLinkList*)list;
	dlist->length = 0;
	dlist->header.next = NULL;
	dlist->slider = NULL;

	return;
}

int DLinkList_Length(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Length() err: param err\n");
		return;
	}
	TDLinkList* dlist = (TDLinkList*)list;
	return dlist->length;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos) { //O{n}
	int ret = 0;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func DLinkList_Length() err: param err\n");
		return ret;
	}
	TDLinkList* dlist = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)dlist;
	DLinkListNode* next = NULL;
	int i = 0;

	for (i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}
	next = current->next;

	//step:1,2
	current->next = node;
	node->next = next;

	//step:3-4
	if (next != NULL) {//scenario1, insert the first element
		next->pre = node;
	}
	node->pre = current;

	if (dlist->length == 0) {
		dlist->slider = node;//scenario2, assign slider when insert first element
	}

	if (current == (DLinkListNode*)dlist) {//senario3, head insert
		node->pre = NULL;
	}

	dlist->length++;

	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos) { //O{n}
	if (list == NULL || pos < 0) {
		printf("func DLinkList_Get() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	if (dlist->length < pos) {
		printf("func DLinkList_Get() err: dlist->length < pos\n");
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)dlist;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	return current->next;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos) { //O{n}
	if (list == NULL || pos < 0) {
		printf("func DLinkList_Delete() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	if (dlist->length < pos) {
		printf("func DLinkList_Delete() err: dlist->length < pos\n");
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)dlist;
	DLinkListNode* next = NULL;
	DLinkListNode* ret = NULL;
	int i = 0;

	for (i = 0; (i < pos); i++) {
		current = current->next;
	}
	ret = current->next;
	next = ret->next;

	//step1
	current->next = next;

	//step2
	if (next != NULL) {//take care
		next->pre = current;
		if (current == (DLinkListNode*)dlist) {//locates 0 pos
			next->pre = NULL;
		}
	}

	if (dlist->slider == ret) {
		dlist->slider = next;
	}
	dlist->length--;

	return ret;
}

//Add
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node) { //O{n}
	if (list == NULL || node == NULL) {
		printf("func DLinkList_Delete() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	DLinkListNode *current = (DLinkListNode*)dlist;
	DLinkListNode *ret = NULL;
	int i = 0;

	for (i = 0; i < dlist->length; i++) {
		if (current->next == node) {
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL) {
		DLinkList_Delete(dlist, i);
	}

	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Reset() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	dlist->slider = dlist->header.next;

	return dlist->slider;
}

DLinkListNode* DLinkList_Current(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Current() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	return dlist->slider;
}

// 返回游标, 并后移
DLinkListNode* DLinkList_Next(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Next() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	DLinkListNode* ret = dlist->slider;
	dlist->slider = dlist->slider->next;

	return ret;
}

// 返回游标, 并前移
DLinkListNode* DLinkList_Pre(DLinkList* list) { //O{1}
	if (list == NULL) {
		printf("func DLinkList_Pre() err: param err\n");
		return NULL;
	}

	TDLinkList* dlist = (TDLinkList*)list;
	DLinkListNode* ret = dlist->slider;
	dlist->slider = dlist->slider->pre;

	return ret;
}
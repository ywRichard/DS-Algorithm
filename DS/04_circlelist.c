#include <stdlib.h>
#include <stdio.h>
#include "04_circlelist.h"

typedef struct _tag_CircleList {
	CircleListNode header;
	CircleListNode* slider;
	int length;
} TCircleList;

CircleList *CircleList_Create() {// O(1)
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	if (ret == NULL) {
		printf("func CircleList_Create err: malloc err.\n");
		return ret;
	}

	ret->header.next = NULL;
	ret->length = 0;
	ret->slider = NULL;

	return ret;
}

void CircleList_Destroy(CircleList* list) {// O(1)
	if (list != NULL) {
		free(list);
	}
	return;
}

void CircleList_Clear(CircleList* list) {// O(1)
	TCircleList* sList = NULL;

	if (list == NULL) {
		printf("func CircleList_Clear err: param err.\n");
		return;
	}
	sList = (TCircleList*)list;

	sList->header.next = NULL;
	sList->slider = NULL;
	sList->length = 0;

	return;
}

int CircleList_Length(CircleList* list) {// O(1)
	TCircleList* sList = NULL;

	if (list == NULL) {
		printf("func CircleList_Length err: param err.\n");
		return -1;
	}

	sList = (TCircleList*)list;

	return sList->length;
}

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos) {// O(n)
	TCircleList* sList = NULL;
	CircleListNode* current = NULL;
	int i = 0, ret = 0;

	if (list == NULL || node == NULL || pos < 0) {
		printf("func CircleList_Insert err: param err.\n");
		return -1;
	}

	sList = (TCircleList*)list;
	current = (CircleListNode*)(&(sList->header));

	for (i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}

	//current->next 0 element addr
	node->next = current->next;//1
	current->next = node;//2

	//if insert the first element, assign the slider value
	if (sList->length == 0) {
		sList->slider = node;
	}

	sList->length++;

	//head insert, current point head
	if (current == (CircleListNode*)sList) {//get the header pointer,
		CircleListNode* last = CircleList_Get(sList, sList->length - 1);
		last->next = current->next;//3
	}

	return ret;
}

CircleListNode* CircleList_Get(CircleList *list, int pos) {// O(n)
	if (list == NULL || pos < 0) {
		printf("func CircleList_Get err: param err.\n");
		return NULL;
	}
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* current = (CircleListNode*)sList;

	for (int i = 0; (i < pos) && (current != NULL); i++) {
		current = current->next;
	}

	return current->next;
}

CircleListNode* CircleList_Delete(CircleList *list, int pos) {// O(n)
	if ((list == NULL) || (pos < 0)) {
		printf("func CircleList_Delete err: param err.\n");
		return NULL;
	}

	TCircleList* sList = (TCircleList*)list;
	CircleListNode* current = (CircleListNode*)sList;
	if (sList->length <= 0) {
		printf("func circle list is empty.\n");
		return NULL;
	}

	for (int i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}

	CircleListNode* last = NULL;
	CircleListNode* ret = NULL;

	//如果删除的是第一个元素, head
	if (current == (CircleListNode*)sList) {
		last = CircleList_Get(sList, sList->length - 1);
	}

	ret = current->next;
	current->next = ret->next;
	sList->length--;

	//判断, 删除头节点后链表是否为空
	if (last != NULL) {
		sList->header.next = ret->next;
		last->next = ret->next;
	}

	//若删除的元素为游标所指的元素
	if (sList->slider == ret) {
		sList->slider = ret->next;
	}

	//若删除元素后, 链表长度为0
	if (sList->length == 0) {
		sList->header.next = NULL;
		sList->slider = NULL;
	}

	return ret;
}

//add
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) {// O(n)
	if (list == NULL || node == NULL) {
		printf("func CircleList_DeleteNode err: param err.\n");
		return NULL;
	}

	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	CircleListNode* current = (CircleListNode*)sList;
	int i = 0;

	//search node
	for (i = 0; i < sList->length; i++) {
		if (current->next == node) {
			ret = current->next;
			break;
		}
		current = current->next;
	}

	//delete it by i
	if (ret != NULL) {
		CircleList_Delete(sList, i);
	}

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) {// O(1)
	if (list == NULL) {
		printf("func CircleList_Reset err: param err.\n");
		return NULL;
	}

	TCircleList* sList = (TCircleList*)list;
	sList->slider = sList->header.next;

	return sList->slider;
}

CircleListNode* CircleList_Current(CircleList* list) {// O(1)
	if (list == NULL) {
		return NULL;
	}
	TCircleList* sList = (TCircleList*)list;
	return sList->slider;
}

//return current node, move slider to next
CircleListNode* CircleList_Next(CircleList* list) {// O(1)
	if (list == NULL) {
		return NULL;
	}
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = sList->slider;
	sList->slider = ret->next;

	return ret;
}
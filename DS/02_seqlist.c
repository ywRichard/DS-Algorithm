#include <stdlib.h>
#include <stdio.h>

#include "02_seqlist.h"

//在结构体中套1级指针
typedef struct _tag_SeqList {
	int length;
	int capacity;
	unsigned int **node;//int *node[]
}TSeqList;

SeqList* SeqList_Create(int capacity) { //O{1}
	int ret = 0;
	TSeqList* tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL) {
		ret = -1;
		printf("func SeqList_Create err:%d\n", ret);
		return NULL;
	}

	tmp->node = (unsigned int*)malloc(sizeof(unsigned int)*capacity);
	if (tmp->node == NULL) {
		ret = -2;
		printf("func SeqList_Create err malloc:%d\n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;

	return (SeqList*)tmp;
}

void SeqList_Destroy(SeqList* list) { //O{1}
	TSeqList *tlist = NULL;
	if (list == NULL) {
		printf("SeqList_Destroy() err: list is NULL\n");
		return;
	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL) {
		free(tlist->node);
	}
	free(tlist);

	return;
}

void SeqList_Clear(SeqList* list) { //O{1}
	TSeqList *tlist = NULL;
	if (list == NULL) {
		printf("SeqList_Clear() err: list is NULL\n");
		return;
	}
	tlist = (TSeqList*)list;
	tlist->length = 0;

	return;
}

int SeqList_Length(SeqList* list) { //O{1}
	TSeqList *tlist = NULL;
	if (list == NULL) {
		printf("SeqList_Length() err: list is NULL\n");
		return -1;
	}
	tlist = (TSeqList*)list;

	return tlist->length;
}

int SeqList_Capacity(SeqList* list) { //O{1}
	TSeqList *tlist = NULL;
	if (list == NULL) {
		printf("SeqList_Capacity() err: list is NULL\n");
		return -1;
	}
	tlist = (TSeqList*)list;

	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) { //O{n}
	int i = 0, ret = 0;
	TSeqList *tlist = NULL;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Insert() param err:%d\n", ret);
		goto End;
	}

	tlist = (TSeqList*)list;
	if (tlist->length == tlist->capacity) {
		ret = -2;
		printf("func SeqList_Insert() err:%d, list is full\n", ret);
		goto End;
	}
	if (pos > tlist->length) {
		pos = tlist->length;
	}

	for (i = tlist->length; i < pos; i--) {
		tlist->node[i] = tlist->node[i - 1];
	}

	tlist->node[i] = node;
	tlist->length++;
End:
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) { //O{1}
	SeqListNode *ret = NULL;
	TSeqList *tlist = NULL;

	if (list == NULL || pos < 0) {
		ret = NULL;
		printf("func SeqList_Get() param err:%d\n", -1);
		return ret;
	}

	tlist = (TSeqList*)list;
	ret = (void*)tlist->node[pos];

	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) { //O{n}
	int i = 0;
	SeqListNode *ret = NULL;
	TSeqList *tlist = NULL;

	if (list == NULL || pos < 0) {
		ret = NULL;
		printf("func SeqList_Delete() param err:%d\n", -1);
		return ret;
	}

	tlist = (TSeqList*)list;
	ret = (SeqListNode*)tlist->node[pos];//store the node which needs to be deleted

	for (i = pos + 1; i < tlist->length; i++) {//pos后面的元素前移
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;

	return ret;
}
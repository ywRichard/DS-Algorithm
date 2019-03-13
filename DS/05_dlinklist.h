#pragma once
#ifndef _MY_DLINKLIST_H_
#define _MY_DLINKLIST_H_

typedef void DLinkList;

typedef struct _tag_DLinkListNode {
	struct _tag_DLinkListNode* next;
	struct _tag_DLinkListNode* pre;
} DLinkListNode;

DLinkList* DLinkList_Create();

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//return the deleted node
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

//return the deleted node
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

// reset slider
DLinkListNode* DLinkList_Reset(DLinkList* list);

//get current slider
DLinkListNode* DLinkList_Current(DLinkList* list);

// 返回游标, 并后移
DLinkListNode* DLinkList_Next(DLinkList* list);

// 返回游标, 并前移,
DLinkListNode* DLinkList_Pre(DLinkList* list);

#endif // !_MY_DLINKLIST_H_

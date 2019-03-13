#include <stdlib.h>
#include <stdio.h>
#include "08_seqqueue.h"
#include "02_seqlist.h"

//队列也是一种特殊的线性表
//queue ===> SeqList
SeqQueue* SeqQueue_Create(int capacity) {
	return SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue) {
	return SeqList_Destroy(queue);
}

void SeqQueue_Clear(SeqQueue* queue) {
	return SeqQueue_Clear(queue);
}

//尾插法实现, 顺序表 尾部入列 头部出列;
int SeqQueue_Append(SeqQueue* queue, void* item) {
	return SeqList_Insert(queue, item, SeqList_Length(queue));//end insert
}

//get top
void* SeqQueue_Retrieve(SeqQueue* queue) {
	return SeqList_Delete(queue, 0);
}

/*
//头插法实现, 顺序表 头部入列 尾部出列;
int SeqQueue_Append(SeqQueue* queue, void* item) {
	return SeqList_Insert(queue, item, 0);//end insert
}
void* SeqQueue_Retrieve(SeqQueue* queue) {
	return SeqList_Get(queue,SeqList_Length(queue));
}
*/

void* SeqQueue_Header(SeqQueue* queue) {
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue) {
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue) {
	return SeqList_Capacity(queue);
}
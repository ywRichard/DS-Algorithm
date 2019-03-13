#include <stdlib.h>
#include <stdio.h>
#include "06_seqstack.h"
#include "02_seqlist.h"

//create stack ===> create seq list
SeqStack* SeqStack_Create(int capacity) {
	return SeqList_Create(capacity);
}

//destroy stack ===> destroy seq list
void SeqStack_Destroy(SeqStack* stack) {
	return SeqList_Destroy(stack);
}

//clear stack ===> clear seq list
void SeqStack_Clear(SeqStack* stack) {
	return SeqList_Clear(stack);
}

//push stack ===> end insert to seq list
int SeqStack_Push(SeqStack* stack, void* item) {
	return SeqList_Insert(stack, item, SeqStack_Size(stack));
}

//pop stack ===> end delete from seq list
void* SeqStack_Pop(SeqStack* stack) {
	return SeqList_Delete(stack, SeqStack_Size(stack) - 1);
}

//top stack ===> get the end element from seq list
void* SeqStack_Top(SeqStack* stack) {
	return SeqList_Get(stack, SeqStack_Size(stack) - 1);
}

//stack ===> destroy seq list
int SeqStack_Size(SeqStack* stack) {
	return SeqList_Length(stack);
}

//destroy stack ===> destroy seq list
int SeqStack_Capacity(SeqStack* stack) {
	return SeqList_Capacity(stack);
}

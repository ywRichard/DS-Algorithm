#include <stdlib.h>
#include <stdio.h>
#include "05_dlinklist.h"

struct Value {
	DLinkListNode node;
	int v;
};

int main() {
	DLinkList *list = DLinkList_Create();

	struct Value *pv = NULL;
	struct Value v1, v2, v3, v4, v5;
	v1.v = 1; v2.v = 2; v3.v = 3;
	v4.v = 4; v5.v = 5;

	DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));//end insert
	DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	for (int i = 0; i < DLinkList_Length(list); i++) {
		pv = (struct Value*)DLinkList_Get(list, i);
		printf("%d, ", pv->v);
	}
	printf("\n\n");
	printf("test DLinkList_Delete\n");

	DLinkList_Delete(list, DLinkList_Length(list) - 1);
	DLinkList_Delete(list, 0);

	for (int i = 0; i < DLinkList_Length(list); i++) {
		pv = (struct Value*)DLinkList_Next(list);
		printf("%d,", pv->v);
	}
	printf("\n\n");
	printf("test others\n");

	DLinkList_Reset(list);
	DLinkList_Next(list);
	pv = (struct Value*)DLinkList_Current(list);
	printf("%d\n", pv->v);

	DLinkList_DeleteNode(list, (DLinkListNode*)pv);
	pv = (struct Value*)DLinkList_Current(list);
	printf("%d\n", pv->v);

	DLinkList_Pre(list);
	pv = (struct Value*)DLinkList_Current(list);
	printf("%d\n", pv->v);

	printf("length:%d\n", DLinkList_Length(list));

	return 0;
}
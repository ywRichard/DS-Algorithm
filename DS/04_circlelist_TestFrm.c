#include <stdlib.h>
#include <stdio.h>
#include "04_circlelist.h"

struct Value {
	CircleListNode circleNode;
	int v;
};

int main01() {
	CircleList* list = CircleList_Create();

	struct Value v1, v2, v3, v4, v5, v6, v7, v8;
	v1.v = 1; v2.v = 2; v3.v = 3; v4.v = 4;
	v5.v = 5; v6.v = 6; v7.v = 7; v8.v = 8;

	CircleList_Insert(list, (CircleListNode*)&v1, 0);
	CircleList_Insert(list, (CircleListNode*)&v2, 0);
	CircleList_Insert(list, (CircleListNode*)&v3, 0);
	CircleList_Insert(list, (CircleListNode*)&v4, 0);
	CircleList_Insert(list, (CircleListNode*)&v5, 0);
	CircleList_Insert(list, (CircleListNode*)&v6, 0);
	CircleList_Insert(list, (CircleListNode*)&v7, 0);
	CircleList_Insert(list, (CircleListNode*)&v8, 0);

	for (int i = 0; i < 2 * CircleList_Length(list); i++) {
		struct Value* pv = (struct Value*)CircleList_Get(list, i);
		printf("%d\n", pv->v);
	}

	printf("start delete\n");
	while (CircleList_Length(list) > 0) {
		struct Value* pv = (struct Value*)CircleList_Delete(list, 0);
		printf("%d\n", pv->v);
	}

	return 0;
}
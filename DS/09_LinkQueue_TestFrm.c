#include <stdlib.h>
#include <stdio.h>
#include "09_linkqueue.h"

int main() {
	int a[10];
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create();
	if (queue == NULL) {
		return -1;
	}

	//入列
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	//队列属性
	printf("len:%d\n", LinkQueue_Length(queue));
	printf("header:%d\n", *((int *)LinkQueue_Header(queue)));

	//出列
	while (LinkQueue_Length(queue) > 0) {
		int tmp = 0;
		tmp = *((int *)LinkQueue_Retrieve(queue));
		printf("tmp:%d, ", tmp);
	}

	LinkQueue_Destroy(queue);

	printf("\n");
	printf("hello...\n");
	system("pause");
	return 0;
}
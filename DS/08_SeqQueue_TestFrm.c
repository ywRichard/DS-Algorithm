﻿#include <stdlib.h>
#include <stdio.h>
#include "08_seqqueue.h"

int main() {
	int i = 0;
	int a[10];
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL) {
		return -1;
	}

	//入列
	for (i = 0; i < 5; i++) {
		a[i] = i + 1;
		SeqQueue_Append(queue, &a[i]);
	}

	//出列
	printf("len:%d\n", SeqQueue_Length(queue));
	printf("header:%d\n", *((int *)SeqQueue_Header(queue)));
	printf("capacity:%d\n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0) {
		int tmp = *(int*)SeqQueue_Retrieve(queue);
		printf("tmp:%d ", tmp);
	}
	SeqQueue_Destroy(queue);

	printf("hello...\n");
	system("pause");
	return 0;
}
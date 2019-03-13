#include <stdlib.h>
#include <stdio.h>
#include "06_seqstack.h"

int main() {
	int a[10] = { 0 };
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL) {
		printf("stack create failed\n");
		return;
	}

	//push
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	printf("capacity:%d\n", SeqStack_Capacity(stack));
	printf("size:%d\n", SeqStack_Size(stack));
	printf("SeqStack_Top:%d\n", *((int *)SeqStack_Top(stack)));

	printf("traverse stack\n");
	while (SeqStack_Size(stack) > 0) {
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("%d, ", tmp);
	}

	printf("\n");
	printf("hello...\n");
	system("pause");
	return 0;
}
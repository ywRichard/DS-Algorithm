#include <stdlib.h>
#include <stdio.h>
#include "07_linkstack.h"

int main() {
	int i = 0;
	int a[10] = { 0 };

	LinkStack* stack = LinkStack_Create();
	if (stack == NULL) {
		printf("func LinkStack_Create() error\n");
		return -1;;
	}

	//add element
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		if (LinkStack_Push(stack, &a[i]) < 0) {
			printf("func LinkStack_Push() err:%d\n", i);
			return -1;
		}
	}

	//get stack profile
	printf("len:%d\n", LinkStack_Size(stack));
	printf("top:%d\n", *((int *)LinkStack_Top(stack)));

	//delete
	while (LinkStack_Size(stack) > 0) {
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("%d, ", tmp);
	}

	//destroy stack
	LinkStack_Destroy(stack);

	printf("\n");
	printf("hello...\n");
	system("pause");
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "07_linkstack.h"

//three scenarios of stack usage
//scenario.1 scanner
int isLeft(char c) {
	int ret = 0;

	switch (c)
	{
	case '<':
	case '(':
	case '[':
	case '{':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int isRight(char c) {
	int ret = 0;

	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int match(char left, char right) {
	int ret = 0;

	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int scanner(const char* code) {
	int ret = 0, i = 0;
	LinkStack* stack = LinkStack_Create();
	if (stack == NULL) {
		return -1;
	}

	while (code[i] != '\0') {
		if (isLeft(code[i])) {
			LinkStack_Push(stack, (void*)(code + i));//&code[i]
		}

		if (isRight(code[i])) {
			char* c = (char *)LinkStack_Pop(stack);
			if (c == NULL || !match(*c, code[i])) {
				printf("%c does not match!\n", code[i]);
				break;
			}
		}

		i++;
	}

	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0')) {
		printf("succeed!\n");
		ret = 1;
	}
	else {
		while (LinkStack_Size(stack) > 0) {
			char* c = (char *)LinkStack_Pop(stack);
			printf("%c, ", *c);
			printf("\n");
		}
		printf("Invalid code!\n");
		ret = 0;
	}

	LinkStack_Destroy(stack);

	return ret;
}

int main() {
	const char* str = "if ((LinkStack_Size(stack) == 0) && (code[i] == '0'))";
	scanner(str);

	printf("hello...\n");
	system("pause");
	return 0;
} 
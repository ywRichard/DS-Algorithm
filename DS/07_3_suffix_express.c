#include <stdlib.h>
#include <stdio.h>
#include "07_linkstack.h"

int isNumber(char c) {
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c) {
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c) {
	return c - '0';
}

int express(int left, int right, char op) {
	int ret = 0;

	switch (op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}
int compute(const char* exp) {
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while (exp[i] != '\0') {
		if (isNumber(exp[i])) {
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if ((isOperator(exp[i]))) {
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left, right, exp[i]);

			LinkStack_Push(stack, (void*)result);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if ((LinkStack_Size(stack) == 1) && (exp[i] == '\0')) {
		ret = (int)LinkStack_Pop(stack);
	}
	else {
		printf("Invalid expression!");
	}

	LinkStack_Destroy(stack);

	return ret;
}


int main() {
	printf("8 + (3 - 1) * 5 = %d\n", compute("831-5*+"));

	printf("hello...\n");
	system("pause");
	return 0;
}
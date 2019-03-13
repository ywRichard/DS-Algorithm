#include <stdlib.h>
#include <stdio.h>
#include "03_linklist.h"
/*
	线性表的链式储存
*/
typedef struct _Teacher {
	LinkListNode *node;
	int age;
	char name[64];

} Teacher;

int main() {
	int ret = 0, len = 0;
	LinkList* list = NULL;

	list = LinkList_Create();

	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Create() err: return NULL,%d\n", ret);
		return ret;
	}

	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 123;
	t5.age = 789;


	ret = LinkList_Insert(list, (LinkListNode*)(&t1), 0);//head insert
	ret = LinkList_Insert(list, (LinkListNode*)(&t2), 0);//head insert
	ret = LinkList_Insert(list, (LinkListNode*)(&t3), 0);//head insert
	ret = LinkList_Insert(list, (LinkListNode*)(&t4), 0);//head insert
	ret = LinkList_Insert(list, (LinkListNode*)(&t5), 0);//head insert
	if (ret != 0)
	{
		printf("func LinkList_Insert() err: insert error, %d\n", ret);
		return ret;
	}

	len = LinkList_Length(list);
	//traverse
	for (int i = 0; i < len; i++) {
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp == NULL) {
			return -1;
		}
		printf("tmp->age:%d\n", tmp->age);
	}

	//delete
	printf("start delete.\n");
	while (LinkList_Length(list) > 0) {
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp == NULL) {
			return -1;
		}
		printf("tmp->age:%d\n", tmp->age);
	}

	LinkList_Destroy(list);

	/*
LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list);

LinkListNode* LinkList_Delete(LinkList* list);
	*/

	system("pause");
	return ret;
}

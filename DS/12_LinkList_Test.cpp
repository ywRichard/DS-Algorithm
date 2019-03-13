#include <iostream>
#include "12_LinkList.cpp"

using namespace std;

struct Teacher {
	char name[64];
	int age;
};

void LinkList_Play() {
	Teacher t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	LinkList<Teacher> list;
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	//traverse
	for (int i = 0; i < list.getLen(); i++) {
		list.get(i, tmp);
		cout << tmp.age << " ";
	}

	cout << endl;
	//clean list
	while (list.getLen() > 0) {
		list.del(0, tmp);
		cout << tmp.age << " ";
	}

	list.clear();
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	cout << endl;
	while (list.getLen()>0){
		list.del(0, tmp);
		cout << tmp.age<<" ";
	}
	cout << endl;
}

int main() {
	LinkList_Play();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

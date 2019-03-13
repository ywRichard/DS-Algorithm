#include <iostream>
#include "11_SeqList.cpp"

using namespace std;

struct Teacher {
	char name[64];
	int age;
};

void seqlist_play() {
	Teacher t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	TSeqList<Teacher> list(10);
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
}

void seqlist_play02() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	Teacher *p1, *p2, *p3, *tmp;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	tmp = NULL;


	TSeqList<Teacher*> list(10);
	list.insert(p1, 0);
	list.insert(p2, 0);
	list.insert(p3, 0);

	//traverse
	for (int i = 0; i < list.getLen(); i++) {
		list.get(i, tmp);
		cout << tmp->age << " ";
	}

	cout << endl;
	//clean list
	while (list.getLen() > 0) {
		list.del(0, tmp);
		cout << tmp->age << " ";
	}
}


int main() {
	seqlist_play();

	seqlist_play02();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
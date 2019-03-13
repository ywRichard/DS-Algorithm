#include <iostream>
#include "11_SeqList.h"

using namespace std;

template <typename T>
TSeqList<T>::TSeqList(int capacity) {
	pArray = new T[capacity];
	this->capacity = capacity;
	this->len = 0;
}

template <typename T>
TSeqList<T>::~TSeqList() {
	delete[] pArray;
	pArray = NULL;
	len = 0;
	capacity = 0;
}

template <typename T>
int TSeqList<T>::getLen() {
	return len;
}

template <typename T>
int TSeqList<T>::getCapacity() {
	return capacity;
}

template <typename T>
int TSeqList<T>::insert(T &t, int pos) {
	int i = 0, ret = 0;
	if (pos < 0) {
		ret = -1;
		printf("func insert() param err:%d\n", ret);
		goto End;
	}

	if (len == capacity) {
		ret = -2;
		printf("func insert() err:%d, list is full\n", ret);
		goto End;
	}
	if (pos > len) {
		pos = len;
	}

	for (i = len; i < pos; i--) {
		pArray[i] = pArray[i - 1];
	}

	pArray[i] = t;
	len++;
End:
	return ret;
}

template <typename T>
int TSeqList<T>::get(int pos, T &t) {
	if (pos < 0) {
		printf("func get() param err:%d\n", -1);
		return -1;
	}

	t = pArray[pos];
	return 0;
}

template <typename T>
int TSeqList<T>::del(int pos, T &t) {
	int i = 0;

	if (pos < 0) {
		printf("func del() param err:%d\n", -1);
		return -1;
	}

	t = pArray[pos];//store the node which needs to be deleted

	for (i = pos + 1; i < len; i++) {//pos后面的元素前移
		pArray[i - 1] = pArray[i];
	}
	len--;

	return 0;
}

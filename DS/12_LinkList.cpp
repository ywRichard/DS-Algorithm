#include <iostream>
#include "12_LinkList.h"


template<typename T>
LinkList<T>::LinkList() {
	head = new Node<T>();
	head->next = NULL;
	len = 0;
}

template<typename T>
LinkList<T>::~LinkList() {
	Node<T>* tmp = NULL;

	while (head != 0) {
		tmp = head->next;
		delete head;
		head = tmp;
	}

	head = NULL;
	len = 0;
}

template<typename T>
int LinkList<T>::clear() {
	Node<T>* tmp = NULL;

	while (head != 0) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
	head = NULL;

	head = new Node<T>();
	len = 0;

	return 0;
}

template<typename T>
int LinkList<T>::getLen() {
	return len;
}

template<typename T>
int LinkList<T>::insert(T &t, int pos) {
	if (pos < 0) {
		cout << "func insert(T &t, int pos) err" << endl;
		return -1;
	}

	Node<T>* current = NULL;
	current = head;
	for (int i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}

	Node<T>* node = new Node<T>();
	if (node == NULL) {
		cout << "func insert(T &t, int pos) err: new Node<T>() failed" << endl;
		return -1;
	}
	node->t = t;

	node->next = current->next;
	current->next = node;

	len++;

	return 0;
}

template<typename T>
int LinkList<T>::get(int pos, T &t) {
	if (pos < 0) {
		cout << "func get(int pos, T &t) err" << endl;
		return -1;
	}

	Node<T>* current = NULL;
	current = head;
	for (int i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}

	t = current->next->t;

	return 0;
}

template<typename T>
int LinkList<T>::del(int pos, T &t) {
	if (pos < 0) {
		cout << "func del(int pos, T &t) err" << endl;
		return -1;
	}

	Node<T>* current = NULL;
	current = head;
	for (int i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}

	Node<T>* ret = NULL;
	ret = current->next;
	t = ret->t;

	current->next = ret->next;

	delete ret;
	len--;

	return 0;
}

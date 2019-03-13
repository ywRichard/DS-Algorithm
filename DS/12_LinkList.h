#pragma once
template<typename T>
struct Node {
	T t;
	Node<T> *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	int clear();
	int getLen();
	int insert(T &t, int pos);
	int get(int pos, T &t);
	int del(int pos, T &t);

private:
	Node<T> *head;
	int len;
};


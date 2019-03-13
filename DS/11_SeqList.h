#pragma once
#include "02_seqlist.h"

template <typename T>
class TSeqList
{
public:
	TSeqList(int capacity);
	~TSeqList();
	int getLen();
	int getCapacity();
	int insert(T &t, int pos);
	int get(int pos, T &t);
	int del(int pos, T &t);

private:
	int len;
	int capacity;
	T *pArray; //array
};


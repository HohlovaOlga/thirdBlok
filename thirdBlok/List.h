#pragma once
#include "Iterator.h"
//объ€вление методов
class List {
public:
	virtual void addElem(int elem, Iterator* iter) = 0;
	virtual bool isEmpty() = 0;
	virtual void deleteElem(Iterator* iter) = 0;
	virtual void makeEmpty() = 0;
	virtual int getSize() = 0;
	virtual Iterator* findElem(int elem) = 0;
	virtual Iterator* getIterator() = 0;
	virtual void Print() = 0;
};
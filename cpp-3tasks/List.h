#pragma once
#include "Iterator.h"

class List {
public:
	virtual void addElem(const elem_t& elem, Iterator& iter) = 0;
	virtual void deleteElem(Iterator& iter) = 0;
	virtual void makeEmpty() = 0;
	virtual bool isEmpty() const = 0;
	virtual int getSize() const = 0;
	virtual Iterator* findElem(const elem_t& elem) = 0;
	virtual Iterator* getIterator() = 0;
};

struct BufferException {};
struct NoElemException {};



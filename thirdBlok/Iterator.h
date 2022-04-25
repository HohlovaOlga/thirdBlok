#pragma once
//вспомогательная структура
struct node
{
	int data = 0;
	node* next = nullptr;
	node* prev = nullptr;
};

class Iterator
{
public:
	virtual void start() = 0;
	virtual void next() = 0;
	virtual void prev() = 0;
	virtual bool finish() = 0;
	virtual int getValue() = 0;
	virtual node* getNow() = 0;
};
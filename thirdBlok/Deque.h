#pragma once
#include "List.h"

class Deque : public List
{
private:
    int size_deque = 0;
    node* head = nullptr;
public:
    class DequeIterator : public Iterator
    {
    private:
        Deque* deque;
        node* nowNode;
    public:
        explicit DequeIterator(Deque* list);
        void start() override;
        void prev() override;
        void next() override;
        bool finish() override;
        int getValue() override;
        node* getNow() override;
    };
    Deque();
    Deque(const Deque& copy);
    Deque(Deque&& copy) noexcept;
    ~Deque();
    Deque operator=(const Deque& copy);
    Deque& operator=(Deque&& copy) noexcept;
    void addElem(int elem, Iterator* iter) override;
    bool isEmpty() override;
    void deleteElem(Iterator* iter) override;
    void makeEmpty() override;
    int getSize() override;
    Iterator* findElem(int elem) override;
    Iterator* getIterator() override;
    void Print();
};
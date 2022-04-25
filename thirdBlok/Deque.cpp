#include "Deque.h"
#include <iostream>

// конструктор
Deque::DequeIterator::DequeIterator(Deque* deque) {
    this->deque = deque;
    this->nowNode = deque->head;
}
//методы итератора
void Deque::DequeIterator::start() {
    nowNode = deque->head;
}

void Deque::DequeIterator::next() {
    nowNode = nowNode->next;
}

void Deque::DequeIterator::prev() {
    nowNode = nowNode->prev;
}

bool Deque::DequeIterator::finish() {
    return nowNode->next == deque->head;
}

int Deque::DequeIterator::getValue() {
    return nowNode->data;
}

node* Deque::DequeIterator::getNow() {
    return nowNode;
}

//конструктор по умолчанию

Deque::Deque() {
    size_deque = 0;
    head = new node();
    head->next = head;
    head->prev = head;
}
//конструктор копирования
Deque::Deque(const Deque& copy) {
    size_deque = copy.size_deque;
    node* copyNode = copy.head->next;
    head = new node;
    head->next = head;
    head->prev = head;
    node* Now = head;
    for (int i = 0; i < size_deque; i++) {
        node* temp = new node;
        temp->data = copyNode->data;
        copyNode = copyNode->next;
        Now->next = temp;
        temp->prev = Now;
        Now = Now->next;
    }
    head->prev = Now;
    Now->next = head;
}
//конструктор перемещения
Deque::Deque(Deque&& copy) noexcept {
    size_deque = copy.size_deque;
    std::swap(head, copy.head);
}
//деструктор
Deque::~Deque() {
    makeEmpty();
    delete head;
}
//оператор присваивания
Deque Deque::operator=(const Deque& copy) {
    if (this == &copy) {
        return *this;
    }
    makeEmpty();
    size_deque = copy.size_deque;
    node* copyNode = copy.head->next;
    node* Now = head;
    for (int i = 0; i < size_deque; i++) {
        node* temp = new node;
        temp->data = copyNode->data;
        copyNode = copyNode->next;
        Now->next = temp;
        temp->prev = Now;
        Now = Now->next;
    }
    head->prev = Now;
    Now->next = head;
    return *this;
}
//оператор перемещения
Deque& Deque::operator=(Deque&& copy) noexcept {
    makeEmpty();
    size_deque = copy.size_deque;
    std::swap(head, copy.head);
    delete copy.head;
    return *this;
}
//проверка на пустоту
bool Deque::isEmpty() {
    return size_deque == 0;
}
//добавить элемент
void Deque::addElem(int elem, Iterator* iter) {
    size_deque++;
    node* tempNode = new node;
    tempNode->data = elem;
    tempNode->prev = iter->getNow();
    tempNode->next = iter->getNow()->next;
    iter->getNow()->next->prev = tempNode;
    iter->getNow()->next = tempNode;
}
//удалить элемент
void Deque::deleteElem(Iterator* iter) {
    if (!isEmpty()) {
        node* delElem = iter->getNow();
        iter->next();
        delElem->next->prev = delElem->prev;
        delElem->prev->next = delElem->next;
        delete delElem;
        size_deque--;
    }
}
//сделать пустым список
void Deque::makeEmpty() {
    head = head->next;
    for (int i = 0; i < size_deque; i++) {
        head = head->next;
        delete head->prev;
    }
    head->next = head;
    head->prev = head;
    size_deque = 0;
}
//получить размер списка
int Deque::getSize() {
    return size_deque;
}
//найти элемент
Iterator* Deque::findElem(int elem) {
    auto* listIterator = new Deque::DequeIterator(this);
    while (!listIterator->finish() && listIterator->getValue() != elem) {
        listIterator->next();
    }
    if (listIterator->getValue() != elem) {
        throw std::exception("Not found");
    }
    return listIterator;
}
//взять элемент
Iterator* Deque::getIterator() {
    return new DequeIterator(this);
}
//вывести список
void Deque::Print() {
    // 
    if (!isEmpty()) {
        node* temp = head->next;
        int temp_sz = size_deque;
        while (temp_sz != 0) {
            std::cout << temp->data << " ";
            temp = temp->next;
            temp_sz--;
        }
        std::cout << std::endl;
    }
}
#include <iostream>
#include "Deque.h"

int main()
{
	Deque* deq = new Deque();
	Deque::DequeIterator* deqIt = new Deque::DequeIterator(deq);
	for (int i = 0; i < 10; i++) {
		deq->addElem(i, deqIt);
		deqIt->next();
	}
	deqIt->start();
	while (!deqIt->finish()) {
		deqIt->next();
		std::cout << deqIt->getValue() << " ";
	}
	std::cout << std::endl << "--------------------------------" << std::endl;
	Iterator* itr2 = deq->getIterator();
	itr2->next();
	std::cout << itr2->getValue() << std::endl;
	std::cout << std::endl << "--------------------------------" << std::endl;
	Iterator* itr3 = deq->findElem(3);
	deq->deleteElem(itr3);
	deqIt->start();
	while (!deqIt->finish()) {
		deqIt->next();
		std::cout << deqIt->getValue() << " ";
	}
	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "Size: " << deq->getSize() << std::endl;
	std::cout << "isEmpty: " << deq->isEmpty() << std::endl;
	deq->makeEmpty();
	std::cout << "isEmpty: " << deq->isEmpty() << std::endl;
	return 0;
}

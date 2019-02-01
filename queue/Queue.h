//
// Created by root on 31/01/19.
//

#ifndef TEST_BUILD_QUEUE_H
#define TEST_BUILD_QUEUE_H

#include "./Node.h"

template <typename T>
class Queue {

private:
    int size;
    Node<T> *start;

    void add(T e, Node<T> *n) {
        if (n->next == nullptr) {
            n->next = new Node(e);
            this->size++;
        } else {
            add(e, n->getNext());
        }
    }

public:
    void add(T e) {
        if (this->size == 0) {
            this->start = new Node(e);
            this->size++;
        } else {
            add(e, this->start);
        }
    }

    Node<T> get() {
        Node<T> *tmp = this->start;
        this->start = start->next;
        this->size--;
        return *tmp;
    }

    void print() {
        Node<T> *tmp = this->start;
        while(tmp->next != nullptr) {
            std::cout << tmp->getData() << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    bool is_empty() {
        return this->size == 0;
    };

    int get_size() {
        return size;
    }
};


#endif //TEST_BUILD_QUEUE_H

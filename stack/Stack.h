//
// Created by root on 31/01/19.
//

#ifndef TEST_BUILD_QUEUE_H
#define TEST_BUILD_QUEUE_H

#include "../base/Node.h"

template <typename T>
class Stack {

private:
    int size;
    Node<T> *start;

public:
    void push(T e) {
        if (this->size == 0) {
            this->start = new Node(e);
            this->size++;
        } else {
            Node<T> *tmp = start;
            start = new Node(e);
            start->set_next(tmp);
            this->size++;
        }
    }

    Node<T> pop() {
        Node<T> *tmp = this->start;
        this->start = start->next;
        this->size--;
        return *tmp;
    }

    Node<T> peek() {
        return *this->start;
    }

    void print() {
        Node<T> *tmp = this->start;
        while(tmp->next != nullptr) {
            std::cout << tmp->get_data() << " ";
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

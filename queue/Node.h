//
// Created by root on 31/01/19.
//

#ifndef TEST_BUILD_NODE_H
#define TEST_BUILD_NODE_H

template <typename T>
class Queue;

template <class T>
class Node {
    friend class Queue<T>;

    private:
        T e;
        Node *next;
    public:
        explicit Node(T e) {
            this->e = e;
            this->next = nullptr;
        }

        T getData() {
            return e;
        }

        Node *getNext() {
            return this->next;
        }
};

#endif //TEST_BUILD_NODE_H

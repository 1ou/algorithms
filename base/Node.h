//
// Created by root on 31/01/19.
//

#ifndef TEST_BUILD_NODE_H
#define TEST_BUILD_NODE_H

template <typename T>
class Stack;
template <typename T>
class Queue;

template <class T>
class Node {
    friend class Stack<T>;
    friend class Queue<T>;

    private:
        T e;
        Node<T> *next;

    public:
        explicit Node(T e) {
            this->e = e;
            this->next = nullptr;
        }

        T get_data() {
            return e;
        }

        Node<T> *get_next() {
            return this->next;
        }

        void set_next(Node<T> *next) {
            this->next = next;
        }
};

#endif //TEST_BUILD_NODE_H

#pragma once
#include <cstdio>

#include "dll.h"

class Stack {
    private:
        LinkedList *lst;
        Node *top;
        void getTop();
    public:
        Stack();
        ~Stack();

        void display();
        void push(int value);
        Node *head();
        int pop();
        int peak(int index);
        bool isEmpty();
        bool isFull();
};

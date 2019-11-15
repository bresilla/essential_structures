#pragma once
#include <cstdio>
#include <iostream>

#include "dll.h"

class Stack {
    private:
        Node *top;
        void getTop();
    public:
        LinkedList *lst;
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

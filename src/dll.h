#pragma once
#include <stdio.h>

class Node {
    public:
        Node *next;
        int data;
        Node *prev;
};

class LinkedList {
    private:
        Node *first;
    public:
        LinkedList();
        LinkedList(int A[], int x);
        ~LinkedList();

        void Display();
        void DisplayAddress();
        void Insert(int index, int val);
        void Swap(int index1, int index2);
        int Delete(int index);
        int Get(int index);
        void Set(int index, int val);
        void Sort();
        void Reverse();
        int Length();
};

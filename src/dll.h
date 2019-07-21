#pragma once
#include <cstdio>

struct Node {
    Node *next;
    int *point;
    Node *prev;
};

class LinkedList {
    private:
        Node *first;
        Node *last;
    public:
        LinkedList();
        LinkedList(int x);
        LinkedList(int A[], int x);
        ~LinkedList();
        void Display();
        Node* Head();
        Node* Tail();

        int Length();
        void Insert(int index, int *val);
        void Push(int *val);
        void Top(Node *node);
        void Bot(Node *node);
        void Append(int A[], int x);
        void Set(int index, int *val);
        Node* Get(int index);
        Node* Delete(int index);
        Node* Pop();
        void Clean();
        void Swap(Node *one, Node *two);
        void Reverse();
        void Sort();
        Node* Search(int value);
};

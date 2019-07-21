#include "stk.h"

void Stack::getTop(){
    if (lst->Length() > 0){
        top = lst->Tail();
    } else {
        top = NULL;
    }
}

Stack::Stack(): lst(new LinkedList){
    getTop();
}

Stack::~Stack(){
    Node *p=lst->Tail(), *q;
    while(p){
        q=p->prev;
        delete p;
        p=q;
    }
}

bool Stack::isEmpty(){
    if (top == NULL){return true;}
    return false;
}

void Stack::display(){
    lst->Display();
}

void Stack::push(int value){
    lst->Push(&value);
    getTop();
}

int Stack::pop(){
    if (top == NULL){return -1;}
    int a = *lst->Head()->point;
    lst->Pop();
    getTop();
    return a;
}

int Stack::peak(int index){
    if (top == NULL){return -1;}
    return *lst->Get(index)->point;
}

Node* Stack::head(){
    return top;
}

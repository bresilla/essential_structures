#include <stdlib.h>
#include <stdio.h>

#include "dll.h"


LinkedList::LinkedList(){
    first=NULL;
};

LinkedList::LinkedList(int A[], int x){
    Node *last, *current;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;

    for (int i = 1; i < x; ++i){
        current=new Node;
        current->data=A[i];
        current->next=NULL;
        last->next=current;
        current->prev=last;
        last=current;
    }
}

LinkedList::~LinkedList(){
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

int LinkedList::Length(){
    Node *p = first;
    int size=0;
    while(p){
        p=p->next;
        size++;
    }
    return size;
}

void LinkedList::Display(){
    Node *p = first;
    printf("\n(%d) >> ", Length());
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
}

void LinkedList::DisplayAddress(){
    Node *p = first;
    printf("\n");
    while(p){
        printf("%p  ", p->prev);
        printf("%p  ", p);
        printf("%p\n", p->next);
        p=p->next;
    }
}


int LinkedList::Get(int index){
    if (index < 0 || index > Length()) {
        return -1;
    }
    Node *p = first;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    return p->data;
}

void LinkedList::Set(int index, int val){
    if (index < 0 || index > Length()) {
        return;
    }
    Node *p = first;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    p->data=val;
}

void swap(Node *p, Node *q){
    Node *t = new Node{NULL,0,NULL};
    t->data = p->data;
    p->data = q->data;
    q->data = t->data;
    delete t;
}

void LinkedList::Swap(int index1, int index2){
    int x, i, j;
    if (index1>index2) {
        x = index1;
        index1 = index2;
        index2 = x;
    }
    if (index2-index1==0) {
        return;
    }
    Node *p = first, *q=first;
    for (i = 0; i < index1; ++i) {
        p = p->next;
    }
    q=p;
    for (j = i; j < index2; ++j) {
        q = q->next;
    }
    swap(p,q);
}

void LinkedList::Sort(){
    Node *p = first;
    int length = Length();
    for (int i = 0; i < length-1; ++i) {
        if (p->data > p->next->data) {
            swap(p,p->next);
            p = first;
            i = 0;
        }
        p = p->next;
    }
}

void LinkedList::Insert(int index, int val){
    Node *p = first, *n = new Node {NULL, val, NULL};
    int length = Length();
    if (index >= 0 && index <= length) {
        if (index == 0) {
            n->next = p;
            p->prev = n;
            first = n;
        } else {
            for (int i = 1; i < index; ++i) {
                p = p->next;
            }
            if (index == length){
                p->next = n;
                n->prev = p;
            } else {
                n->next=p->next;
                n->prev=p;
                p->next->prev=n;
                p->next=n;
            }
        }
    } else {
        delete n;
    }
}

void reverse(Node *p, Node *t, Node *first){
    if (p) {
        reverse(p, p->next, first);
        t->next = p->next;
        t->prev = p->prev;
        p->next = t->prev;
        p->prev = t->next;
    } else {
        first = t;
    }
}

void LinkedList::Reverse(){
    Node *p = first, *t = new Node{NULL,0,NULL};
    // reverse(p, t, first);
    int length = Length();
    for (int i = 0; i < length; ++i) {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p != NULL && p->next == NULL){
            first = p;
        }
    }
    delete t;
}

int LinkedList::Delete(int index){
    Node *p = first;
    int length = Length(), x = 0;
    if (index >= 0 && index <= length) {
        if (index == 0) {
            first=p->next;
            first->prev=NULL;
            x = p->data;
        } else {
            for (int i = 1; i < index; ++i) {
                p=p->next;
            }
            if (index == length){
                p->prev->next = NULL;
                p->prev = NULL;
                x = p->data;
            } else {
                p=p->next;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                x = p->data;
            }
        }
        delete p;
    }
    return x;
}

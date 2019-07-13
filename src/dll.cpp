#include <cstdlib>
#include <cstdio>

#include "dll.h"

LinkedList::LinkedList(){
    first=new Node;
    first->point=NULL;
    first->next=NULL;
    first->prev=NULL;
    last=first;
}

LinkedList::LinkedList(int A[], int x){
    Node *current;
    first=new Node;
    first->point=&A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;

    for (int i = 1; i < x; ++i){
        current=new Node;
        current->point=&A[i];
        current->next=NULL;
        last->next=current;
        current->prev=last;
        last=current;
    }
}

LinkedList::LinkedList(int x){
    Node *current;
    first=new Node;
    first->point=&x;
    first->next=NULL;
    first->prev=NULL;
    last=first;

    for (int i = 1; i < x; ++i){
        current=new Node;
        current->point=NULL;
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

Node LinkedList::Head(){
    // return (long)(int *)first;
    return *first;
}

Node LinkedList::Tail(){
    // return (long)(int*)last;
    return *last;
}

int LinkedList::Length(){
    Node *p = first;
    int size=0;
    while(p != NULL && p != last){
        p=p->next;
        size++;
    }
    return size;
}

void LinkedList::Append(int A[], int x){
    Node *current;
    first->point=&A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for (int i = 1; i < x; ++i){
        current=new Node;
        current->point=&A[i];
        current->next=NULL;
        last->next=current;
        current->prev=last;
        last=current;
    }
}

void LinkedList::Nodes(Node *p){
    printf("\n%p ", p->prev);
    printf(" %p ", p);
    printf(" %p", p->next);
}

void LinkedList::Display(){
    if (first->point == NULL){
        return;
    }
    Node *p = first;
    printf("\n(%d) >> ", Length());
    while(p){
        printf("%d ", *p->point);
        p=p->next;
    }
    printf("\n----------\n");
}

void LinkedList::Points(){
    Node *p = first;
    printf("\n(%d) >> ", Length());
    while(p){
        printf("%p ", p->point);
        p=p->next;
    }
    printf("\n----------\n");
}


void LinkedList::Address(){
    Node *p = first;
    while(p){
        printf("%p  ", p->prev);
        printf("%p  ", p);
        printf("%p\n", p->next);
        p=p->next;
    }
    printf("----------\n");
}

Node* LinkedList::Get(int index){
    if (index < 0 || index > Length()) {
        return NULL;
    }
    Node *p = first;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    return p;
}

void LinkedList::Set(int index, int *val){
    if (index < 0 || index > Length()) {
        return;
    }
    Node *p = first;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    p->point = val;
}

void LinkedList::Swap(Node *p, Node *q){
    if (!p || !q) {
        return;
    }
    Node *t;
    t = p->next;
    p->next = q->next;
    q->next = t;
    if (p->next != NULL)
        p->next->prev = p;
    if (q->next != NULL)
        q->next->prev = q;
    t = p->prev;
    p->prev = q->prev;
    q->prev = t;
    if (p->prev != NULL)
        p->prev->next = p;
    if (q->prev != NULL)
        q->prev->next = q;
}

void LinkedList::Sort(){
    Node *p = first;
    int length = Length(), i;
    for (i = 0; i < length-1; ++i) {
        if (*p->point > *p->next->point) {
                Swap(p,p->next);
            p = first;
            i = 0;
        }
        p = p->next;
    }
}

Node* LinkedList::Search(int value){
    Node *p = first;
    int length = Length();
    for (int i = 0; i < length-1; ++i) {
        if (*p->point == value){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void LinkedList::Insert(int index, int *val){
    Node *p = first, *q = last, *n = new Node {NULL, val, NULL};
    int length = Length();
    if (index == 0) {
        p->point = val;
        delete n;
    } else if (index == length){
        q->next = n;
        n->prev = q;
        last = n;
    } else if (index > 0 && index < length) {
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        p->point = val;
        if (index == length){
            p->next = n;
            n->prev = p;
            last = n;
        } else {
            n->next=p->next;
            n->prev=p;
            p->next->prev=n;
            p->next=n;
        }
    } else {
        delete n;
    }
}

// void LinkedList::Insert(int index, int *val){
    // Node *p = first, *n = new Node {NULL, val, NULL};
    // int length = Length();
    // if (index >= 0 && index <= length) {
        // if (index == 0) {
            // n->next = p;
            // p->prev = n;
            // first = n;
        // } else {
            // for (int i = 1; i < index; ++i) {
                // p = p->next;
            // }
            // if (index == length){
                // p->next = n;
                // n->prev = p;
                // last = n;
            // } else {
                // n->next=p->next;
                // n->prev=p;
                // p->next->prev=n;
                // p->next=n;
            // }
        // }
    // } else {
        // delete n;
    // }
// }

void LinkedList::Push(int *val){
    Insert(Length(), val);
}

void LinkedList::Reverse(){
    Node *p = first, *t = new Node{NULL,0,NULL};
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

Node* LinkedList::Delete(int index){
    Node *p = first;
    int length = Length();
    if (index >= 0 && index <= length) {
        if (index == 0) {
            first=p->next;
            first->prev=NULL;
            return p;
        } else {
            for (int i = 1; i < index; ++i) {
                p=p->next;
            }
            if (index == length){
                last = p->prev;
                p->prev->next = NULL;
                p->prev = NULL;
                return p;
            } else {
                p=p->next;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                return p;
            }
        }
        delete p;
    }
    return NULL;
}

Node* LinkedList::Pop(){
    return Delete(Length());
}

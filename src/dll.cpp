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

LinkedList::LinkedList(int x){
    Node *current;
    first=new Node;
    first->point=NULL;
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
    int size=1;
    if (first->point == NULL){
        return 0;
    }
    while(p != NULL && p != last){
        p=p->next;
        size++;
    }
    return size;
}

void LinkedList::Insert(int index, int *val){
    Node *p = first, *q = last, *n = new Node {NULL, val, NULL};
    int length = Length();
    if (index == 0){
        p->point = val;
        delete n;
    } else if (index >= length){
        q->next = n;
        n->prev = q;
        last = n;
    } else {
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        p->point = val;
        n->next=p->next;
        n->prev=p;
        p->next->prev=n;
        p->next=n;
        last = n;
    }
}

void LinkedList::Push(int *val){
    Insert(Length(), val);
}

void LinkedList::Append(int A[], int x){
    Node *current;
    bool skipOne = false;
    if (Length()==0){
        Push(&A[0]);
        skipOne = true;
    }
    for (int i = 0; i < x; ++i){
        if (skipOne){
            skipOne = false;
            continue;
        }
        current=new Node;
        current->point=&A[i];
        current->next=NULL;
        last->next=current;
        current->prev=last;
        last=current;
    }
}

void LinkedList::Display(){
    Node *p = first;
    int i = 0, length = Length();
    printf("\nLength: %d    First: %p \t Last: %p\n\n", length, first, last);
    while(p){
        if (p->point == NULL) {
            printf("%d \t (nil) \t ", i);
        } else {
            printf("%d \t %d  ", i, *p->point);
        }
        printf("%p   \t ", p->point);
        printf("%p  ", p->prev);
        printf("%p  ", p);
        printf("%p\n", p->next);
        p=p->next;
        ++i;
    }
    printf("\n");
}

Node* LinkedList::Get(int index){
    if (index < 0 || index > Length()-1) {return NULL;}
    Node *p = first;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    return p;
}

void LinkedList::Set(int index, int *val){
    if (index < 0 || index > Length()-1) {return;}
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
    if(p == first){
        first = q;
    } else if (q == first){
        first = p;
    }
    if (p == last){
        last = q;
    } else if (q == last){
        last = p;
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

void LinkedList::Top(Node *node){
    if(node == first){
        return;
    } else {
        Swap(node, first);
    }
}

void LinkedList::Bot(Node *node){
    if (node == last){
        return;
    } else {
        Swap(node, last);
    }
}

void LinkedList::Sort(){
    Node *p = first;
    int length = Length(), i;
    for (i = 0; i < length; ++i) {
        if (p->point == NULL || p->next->point == NULL){
            p = p->next;
            continue;
        }
        if (*p->point > *p->next->point) {
            Swap(p,p->next);
            p = first;
            i = 0;
            continue;
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

void LinkedList::Reverse(){
    Node *p = first, *q = first, *t = new Node{NULL,0,NULL};
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
    last=q;
    delete t;
}

Node* LinkedList::Delete(int index){
    Node *p = first, *r = NULL;
    int length = Length();
    if (index == 0 && length <= 1){
        delete(first->next);
        delete(first->prev);
        first->next = NULL;
        first->prev = NULL;
        first->point = NULL;
        r = first;
    } else if (index == 0 && length > 1){
        first = p->next;
        delete(first->prev);
        first->prev = NULL;
        r = p;
    } else if (index == length-1){
        last = last->prev;
        delete(last->next);
        last->next = NULL;
        return last;
    } else {
        for (int i = 1; i < index; ++i) {
            p=p->next;
        }
        p=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        r = p;
    }
    return p;
}

Node* LinkedList::Pop(){
    return Delete(Length()-1);
}

Node* LinkedList::Head(){
    return first;
}

Node* LinkedList::Tail(){
    return last;
}

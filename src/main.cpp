#include <cstdlib>
#include <cstdio>

#include "dll.h"
#include "stk.h"
#include "que.h"

int main(){
    int A[] = {18,666,322,342,112,54,7,12,16,11};
    LinkedList list;
    // LinkedList *list = new LinkedList;
    list.Append(A,10);
    // list.Push(&A[0]);
    list.Sort();
    // list.Pop();
    // list.Pop();
    list.Display();
    Stack stack;
    stack.push(1);
    stack.push(2);
    // stack.push(3);
    // stack.push(4);
    stack.display();
    // printf("%d\n", stack.peak(0));
}

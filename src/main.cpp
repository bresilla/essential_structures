#include <cstdlib>
#include <cstdio>

#include "dll.h"
#include "stack.h"

int main(){
    int A[] = {8,6,2,3,1,5,7,12,16,11};
    LinkedList list;
    list.Insert(0, &A[0]);
    list.Push(&A[0]);
    list.Push(&A[0]);
    list.Push(&A[0]);
    // list.Insert(1, &A[0]);
    // list.Append(A,10);
    printf("%d\n", list.Length());
    // printf("%d\n", *list.Get(0)->point);
    // printf("%d\n", *list.Get(1)->point);
    // printf("%d\n", *list.Get(2)->point);
    // printf("%d\n", *list.Get(3)->point);
    // list.Display();
    list.Address();
}

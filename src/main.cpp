#include <iostream>

#include "dll.h"
#include "stk.h"
#include "que.h"

int main(){
    int A[] = {18,666,322,342,112,54,7,12,16,11};
    // LinkedList list;
    // list.Append(A,5);
    // std::cout << *list.Head()->point << " >> " << list.Head()->point << std::endl;
    // std::cout << *list.Tail()->point << " >> " << list.Tail()->point << std::endl;
    // list.Push(&A[7]);
    // std::cout << *list.Head()->point << " >> " << list.Head()->point << std::endl;
    // std::cout << *list.Tail()->point << " >> " << list.Tail()->point << std::endl;
    // list.Push(&A[8]);
    // std::cout << *list.Head()->point << " >> " << list.Head()->point << std::endl;
    // std::cout << *list.Tail()->point << " >> " << list.Tail()->point << std::endl;
    // list.Pop();
    // std::cout << *list.Head()->point << " >> " << list.Head()->point << std::endl;
    // std::cout << *list.Tail()->point << " >> " << list.Tail()->point << std::endl;
    // list.Display();



    Stack stack;
    stack.push(1);
    std::cout << *stack.head()->point << std::endl;
    stack.push(254);
    std::cout << *stack.head()->point << std::endl;
    stack.pop();
    std::cout << *stack.head()->point << std::endl;
    std::cout << *stack.head()->point << std::endl;
    // stack.push(343);
    // stack.push(4455);
    // // stack.display();
    // std::cout << stack.pop() << std::endl;
    // std::cout << stack.pop() << std::endl;
}


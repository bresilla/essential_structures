#include <stdio.h>
#include <stdlib.h>

#include "dll.h"

int main(){
    int A[] = {8,6,2,3,1,5,7,12,16,11};
    LinkedList list(A,10);
    list.Display();
    list.Sort();
    list.Display();
    list.Reverse();
    list.Display();
}

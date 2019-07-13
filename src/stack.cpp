#include <cstdio>
#include <cstdlib>

#include "dll.h"
#include "stack.h"


Stack::Stack(){
    size = 0;
    LinkedList list(size+1);
}

#include <iostream>
#include <stdlib.h>
#include "multiple_stack.h"

using namespace std;

int main()
{
    MultipleStack<int> A(3);
    int x=3;
    A.Push(x,2);
    x=4;
    A.Push(x,1);
    A.Push(x,1);
    cout<< " "<< A.Pop(2);
    cout<< " "<< A.Pop(1);
    cout<< " "<< A.Pop(1);
    system("pause");
    return 0;
}

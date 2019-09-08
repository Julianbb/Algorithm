#include <iostream>
using namespace std;
#include "stack_with_min.hpp"


void Test(const char* test, const StackWithMin<int>& stack, int expected)
{
    if(test != nullptr)
	cout << test;
    if(stack.min() == expected)
	cout <<" passed" << endl;
    else
	cout << " failed" << endl;
}




int main(void)
{
    StackWithMin<int> stack;
    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(3);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(1);
    Test("Test4", stack, 1);

    stack.pop();
    Test("Test5", stack, 2);

    stack.push(100);
    Test("Test6", stack, 2);

    return 0;
}

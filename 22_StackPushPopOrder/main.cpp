#include <iostream>
#include<stack>
using namespace std;



bool IsPopOrder(const int* pPush, const int* pPop, int length)
{


    return true;
}





// =========================测试代码==========================
void Test(const char* test, const int* pPush, const int* pPop, int length,  bool expected)
{
    if(test != nullptr)
	cout << test << " ";
    if(IsPopOrder(pPush, pPop, length) == expected)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}


void Test1(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] =  {4, 5, 3, 2, 1};
    Test("Test1", push, pop, length, true);

}

void Test2(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {3, 5, 4, 2, 1};
    Test("Test2", push, pop, length, true);

}

void Test3(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 3, 5, 1, 2};
    Test("Test3", push, pop, length, false);

}

void Test4(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {3, 5, 4, 1, 2};
    Test("Test4", push, pop, length, false);

}

void Test5(void)
{
    const int length = 1;
    int push[] = {1};
    int pop[] =  {2};
    Test("Test5", push, pop, length, false);

}

void Test6(void)
{
    const int length = 1;
    int push[] = {1};
    int pop[] = {1};
    Test("Test6", push, pop, length, true);

}

void Test7(void)
{
    Test("Test7", nullptr, nullptr, 0, false);

}

 
int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

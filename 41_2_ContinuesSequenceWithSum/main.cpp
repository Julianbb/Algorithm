#include <iostream>
using namespace std;


void FindContinuousSequence(int sum)
{




}



// ====================测试代码====================



void Test(const char* testName, int sum)
{
    if(testName != nullptr)
	cout << testName << " " << sum << endl;

    FindContinuousSequence(sum);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}

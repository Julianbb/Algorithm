#include <iostream>
using namespace std;


int GetUglyNumber_Solution(int index)
{



}


// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution(index) == expected)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;

    cout << endl;
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}

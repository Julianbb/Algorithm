#include <iostream>
using namespace std;


bool FindNumbersWithSum(int* data, int length, int sum, int* num1, int* num2)
{
    if(data == nullptr || length <=1) return false;
    if(num1 == nullptr || num2 == nullptr) return false;
    bool found = false;


    int index1 = 0;
    int index2 = length-1;

    while(index1 != index2)
    {
	if(data[index1] +data[index2] < sum)
	{
	    index1++;
	}
	else if(data[index1] + data[index2] > sum)
	{
	    index2--;
	}
	else
	{
	    *num1 = data[index1];
	    *num2 = data[index2];
	    found = true; 
	    break;
	}
    }


    return found;
}




// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != nullptr)
	cout << testName << " " ;
    else
       return;	

    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
		cout << "Passed" << endl;
            else
		cout << "failed" << endl;
        }
        else
	    cout << "Passed" << endl;
    }
    else
	cout << "failed" << endl;
}


// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

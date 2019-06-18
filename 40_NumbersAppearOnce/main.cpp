#include <iostream>
using namespace std;


void FindNumsAppearOnce(int* data, int length, int* result1, int* result2)
{
    if(data == nullptr || length < 2) return;
    
    int result = 0;

    for(int i=0; i<length; i++)
    {
	result ^= data[i];
    }


    // 得到result 第一个不为0的位
    int tmp_result = 0;
    int n_bits = 0;
    while(!tmp_result)
    {
	int tmp_num = 1 << n_bits++; 
	tmp_result = tmp_num & result;
    }
    n_bits -- ; // 从第0位开始


    for(int i=0; i<length; i++)
    {
	int tmp_nbits = (data[i] >> n_bits)%2;
	   if(tmp_nbits == 0)
	      *result1 ^= data[i];
	   else
	      *result2 ^= data[i]; 
    }
    
}





// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != nullptr)
	cout << testName << "  ";

    int result1=0, result2=0;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}

void Test1()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = { 4, 6 };
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = { 4, 6, 1, 1, 1, 1 };
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

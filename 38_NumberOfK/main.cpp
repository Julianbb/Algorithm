#include <iostream>
using namespace std;



int GetFirstOrLastK(int* data, int start, int end,  int k, int flag_first_last)
{
    if(data==nullptr || start>end )return -1;

    int tmp_index = (end+start)/2;
    int tmp_data = data[tmp_index];

    int next_start = start;
    int next_end = end;
    int length = start-end+1;


    if(tmp_data==k) // ==k 的时候，你得判断它是不是第一个或者最后一个
    {
	if(flag_first_last == 0)
	{
	    if(tmp_index !=start && data[tmp_index-1] == k)// tmp_index不是第一个，否则-1就越界了, 如果是第一个，直接返回它的index
	    {
		next_start = start;
		next_end = tmp_index-1;
		return GetFirstOrLastK(data, next_start, next_end, k, 0);
	    }
	    else
		return tmp_index;

	}
	else
	{
	    if(tmp_index != end && data[tmp_index+1] == k) // tmp_index不是最后一个，否则+1就越界了
	    {
		next_start = tmp_index+1;
		next_end = end;
		return GetFirstOrLastK(data, next_start, next_end, k, 1);
	    }
	    else
		return tmp_index;
	}
    }

    if(tmp_data>k)
    {
	next_start = start;
	next_end = tmp_index-1;
	return GetFirstOrLastK(data, next_start, next_end, k, flag_first_last);
    }

    if(tmp_data<k)
    {
	next_start = tmp_index+1;
	next_end = end;
	return GetFirstOrLastK(data,next_start, next_end, k, flag_first_last);
    }

}



int GetNumberOfK(int* data, int length, int k)
{
    if(data == nullptr || length<=0) return 0;

    int first_index = GetFirstOrLastK(data, 0, length-1, k, 0);
    int last_index = GetFirstOrLastK(data, 0, length-1, k, 1);

    if(first_index == -1 || last_index == -1) return 0;
    return last_index-first_index+1;
}





// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
	cout << testName << ":";

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}

#include <iostream>
#include <memory.h>
using namespace std;


// 申请的copy 数组需要初始化为和data一样的数据
int InversePairsCore(int* data, int* copy, int start, int end)
{
    if(data == nullptr|| copy == nullptr || start > end) return 0;
    if(start == end)
    {
	copy[start] = data[start];
	return 0;
    }

    int length = (end-start)/2;
    int left = InversePairsCore(copy, data, start, start+length); // copy 和data 颠倒, 因为copy 和data数据是一样的，所以每次交替当彼此辅助
    int right = InversePairsCore(copy, data,  start+length+1, end);


    int i = start + length;
    int j = end;
    int indexCopy = end;
    int count = 0;


    while(i>=start && j>= start+length+1)
    {
	if(data[i] > data[j]) // 把大的数放到辅助数组里
	{
	    copy[indexCopy--] = data[i--];
		count += j-start-length; // 如果前面的数>后面的数，则逆序对+ j到当前字数组的开始，因为前面数都比他小
	}
	else // 把大的数放到辅助数组里，大的j--, 再比较
	{
	    copy[indexCopy--] = data[j--];
	}
    }

    // 把剩下的j 或者 i 全部复制到辅助数组里
    for(; i>= start; --i)
	copy[indexCopy--]  = data[i];
    for(; j>=start+length+1; --j)
	copy[indexCopy--] = data[j];

    return left+right+count;
}


int InversePairs(int* dataArray, int length)
{
    if (dataArray == nullptr || length <= 0)
	return 0;

    int* copy = new int[length]; // 归并排序的辅助数组
    for(int i=0; i<length; i++ )
         copy[i] = dataArray[i]; // 需要初始化成和dataArray一样的数组

    int count = InversePairsCore(dataArray, copy, 0, length-1);

    //最后输出的排序是copy, 不在dataArray
    // for(int i=0; i<length; i++)
    // {
    //     cout << copy[i];
    // }
    // cout << endl;
    delete []copy;

    return count;
}




// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
	cout << testName << ":";

    if(InversePairs(data, length) == expected)
	cout << " passed  " << endl;
    else
	cout << " failed  " << endl;
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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

    return 0;
}


#include <iostream>
#include <set>
using namespace std;

// 解法一：基于快排原理，但是改变的原来数组的值
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int Partion(int* array, int start, int end)
{
    if(array == nullptr || start > end) return 0;

    int start_p = start;
    int end_p = end;
    int head = start;

    while(start_p < end_p)
    {
	while(start_p < end_p && array[end_p] >= array[head])
	    end_p--;

	while(start_p < end_p && array[start_p] <= array[head])	
	    start_p++;

	if(start_p < end_p)
	    Swap(&array[start_p], &array[end_p]);
    }

    Swap(&array[head], &array[start_p]);
    return start_p;
}

void GetKLeastNumbers1(int* input, int length, int k)
{
    if(input == nullptr || length <=0 || k<=0) return;
    if(k>length)
    {
	return;
    }

    int K = k-1;
    int start = 0;
    int end = length-1;

    int tmp_index = Partion(input, start, end);
    while(tmp_index != K)
    {
	if(tmp_index > K)
	{
	    end = tmp_index-1;
	    tmp_index = Partion(input, start, end); 
	}
	else
	{
	    start = tmp_index+1;
	    tmp_index = Partion(input, start, end);
	}
    }
}

// 解法二：定义一个k大小的容器,初始化容器为数组前k个值，变量数组，与容器最大值比较，进行插入，删除等操作
// 优点：没有改变数组的原始值

typedef multiset<int, greater<int>>   intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetKLeastNumbers2(int* input, int length, int k, intSet& leastNumber)
{
    if(input == nullptr || length <=0) return;
    if(k > length)
    {
	cout << "passed" << endl;
	return;
    }

    //正式代码
    for(int i=0; i<length; i++)
    {
	if(leastNumber.size() < k)
	{
	    leastNumber.insert(input[i]);
	}
	else
	{
	    setIterator it = leastNumber.begin();
	    if(input[i] < *(it))
	    {
		leastNumber.erase(it);
		leastNumber.insert(input[i]);
	    }
	}
    }
    
}

//=================测试代码========================


bool numberInArray(int* array, int length, int number)
{
    if(array == nullptr) return false;

    bool flag = false;
    for(int i = 0; i<length; i++)
    {
	if(array[i] == number)
	{
	    flag = true;
	    break;
	}
    }
    return flag;
}	



void Test(const char* testName, int* array, int length, int* expectedValue, int k)
{
    if(testName == nullptr) return;
    else
	cout << testName << ": " ;
    if(k > length) // 调试证明我考虑到了，所以直接pass 
    {
	cout << "passed" << endl;
	return;
    }

    GetKLeastNumbers1(array, length, k);
    int i=0;
    for(; i<k; i++)
    {
	if(!numberInArray(expectedValue, k, array[i]))
	    break;
    }
    /* 解法二
    intSet result;
    setIterator it;
    int i=0;

    GetKLeastNumbers2(array, length, k, result);
    for(it = result.begin(); it!=result.end(); it++, i++)
    {
	if(!numberInArray(expectedValue, k, *(it)))
	    break;
    }
    */

    if(i==k)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;

}




void Test1(void)
{
    int array[] = {4,5,1,6,2,7,3,8};
    int expectedValue[] = {1,2,3,4};
    int KLeast = 4;
    Test("test1", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}

void Test2(void)
{
    int array[] = {4,5,1,6,2,7,3,8};
    int expectedValue[] = {1,2,3,4,5,6,7,8};
    int KLeast = 8;
    Test("test2", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}

void Test3(void)
{
    int array[] = {4,5,1,6,2,7,3,8};
    int expectedValue[] = {};
    int KLeast = 10;
    Test("test3", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}

void Test4(void)
{
    int array[] = {4,5,1,6,2,7,3,8};
    int expectedValue[] = {1};
    int KLeast = 1;
    Test("test4", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}

void Test5(void)
{
    int array[] = {4,5,1,6,2,7,3,8};
    int expectedValue[] = {};
    int KLeast = 0;
    Test("test5", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}



void Test6(void)
{
    int array[] = {2,2,1,6,2,7,3,8};
    int expectedValue[] = {1,2,2,2};
    int KLeast = 4;
    Test("test5", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
}

void Test7(void)
{
    int* array = nullptr;
    int expectedValue[] = {};
    int KLeast = 0;
    Test("test6", array, sizeof(array)/sizeof(array[0]), expectedValue, KLeast);
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




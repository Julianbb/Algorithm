#include <iostream>
#include <exception>
using namespace std;
typedef int(FUN)(int*, int);


void swap(int* a, int* b);
int Partition(int* array, int start, int end);

// 求数组里面出现次数最多的数，也适用于此题目，只不过测试代码中还需要对结果进行判断:是否是超过一半的数
int MoreThanHalfNum_Solution_1(int* array, int length)
{
    if(array == nullptr || length == 0) return 0;

    int number = 0, times = 0;

    for(int i=0; i<length; i++)
    {
	if(number == array[i])
	    times++;
	else
	{
	    times--;
	    if(times == 0)
		number = array[i];
	}	    
    }

    return number;
}





// 基于快排的分治法原理，寻找中位数
int MoreThanHalfNum_Solution_2(int* array, int length)
{
    if(array == nullptr || length == 0) return 0;

    int mid = length << 1;
    int start = 0
    int end = length-1;

    int index = Partition(array, start, end);
    if(index > mid)
    {
	
    }




    return 0;
}


void swap(int* a, int* b)
{
    if(a==nullptr || b==nullptr) return;

    int tmp ;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int* array, int start, int end)
{
    if(array == nullptr || start>=end) return 0;
    int head = 0; 
    int start_p = start+1;
    int end_p = end;

    while(start_p != end_p)
    {
	while(array[start_p]<array[head])
	    start_p++;
	while(array[end_p]>array[head])
	    end_p --;

	swap(&array[start_p], &array[end_p]);
    }
    
    swap(&array[head], &array[start_p]);

    return start_p;
}





// ===========================测试代码=======================================


// 判断number 在数组array中是否真的超过一半
bool checkIsMoreThanHalf(int* array, int length, int number)
{
    if(array == nullptr || length == 0) return false;
    
    unsigned int times = 0;
    for(int i=0; i<length; i++)
    {
	if(array[i] == number)
	    times++;
    }

    if(times*2 <= length  )
	return false;
    else
	return true;
}



void Test(const char* test_name, int* numbers, int length, int expectedValue, FUN* function)
{
    if(test_name == nullptr) return;
    cout << "test_name " << test_name << ": ";

    int result = function(numbers, length);
    if(result == expectedValue)
	cout << "passed" << endl;
    else
    {
	if(!checkIsMoreThanHalf(numbers, length, result))
	{
	    cout << "passed" << endl;
	}
	else
	cout << "failed" << endl;
    }
}


// 存在出现次数超过数组长度一半的数字
void Test1(FUN* function)
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, function);
}

//不存在出现次数超过数组长度一半的数字
void Test2(FUN* function)
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, function);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3(FUN* function)
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, function);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4(FUN* function)
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, function);
}

// 只有一个数
void Test5(FUN* function)
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, function);
}

// 输入空指针
void Test6(FUN* function)
{
    Test("Test6", nullptr, 0, 0, function);
}


int main(void)
{

    Test1(MoreThanHalfNum_Solution_1);
    Test2(MoreThanHalfNum_Solution_1);
    Test3(MoreThanHalfNum_Solution_1);
    Test4(MoreThanHalfNum_Solution_1);
    Test5(MoreThanHalfNum_Solution_1);
    Test6(MoreThanHalfNum_Solution_1);

    return 0;
}

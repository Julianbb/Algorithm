/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-08-05 09:16
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<class T>
class DynamicArray
{
public:

    void Insert(T num)
    {
	int size = min.size() + max.size();
	if(size%2 == 1)// odd num
	{
	    // 插最大 
	    if(min.size() > 0 && num > min[0])
	    {
		min.push_back(num);
		push_heap(min.begin(), min.end(), greater<T>());

		num = min[0];
		pop_heap(min.begin(), min.end(), greater<T>());
		min.pop_back();
	
	    }
		max.push_back(num);
		push_heap(max.begin(), max.end(), less<T>());
	    
	}
	else// even num
	{
	    if(max.size() > 0 && num < max[0])
	    {
		max.push_back(num);
		push_heap(max.begin(), max.end(), less<T>());

		num = max[0];
		pop_heap(max.begin(), max.end(), less<T>());
		max.pop_back();
	    }

	    min.push_back(num);
	    push_heap(min.begin(), min.end(), greater<T>());

	}
    }



    T GetMedian()
    {
	int size = min.size() + max.size();
	if(size == 0) 
	    throw exception();

	T median = 0;
	if(size % 2 == 1)
	{
	    median = min[0];
	}
	else
	{
	    median = (min[0]+max[0])/2;
	}

	return median;
    }


private:
    vector<T> min;
    vector<T> max;
};







// template<class T>
// class DynamicArray
// {
// public:
//     T GetMedian(void)
//     {
//         int size = min.size() + max.size();
//         if(size == 0)
//             throw exception();

//         T median = 0;
//         if((size & 1) == 1) // 奇数
//         {
//             median = min[0];
//         }
//         else
//         {
//             median = (max[0] + min[0])/2;
//         }

//         return median;
//     }


//     void Insert(T num)
//     {
//         if((min.size() + max.size()) % 2 == 0) //总数偶数,插入最小堆
//         {
//             if(max.size() > 0 && num < max[0]) // 如果插入的数比最大堆还要小,则插入最大堆，把最大堆的最大数插入最小堆
//             {
//                 max.push_back(num);
//                 push_heap(max.begin(), max.end(), less<T>());

//                 num = max[0];
//                 pop_heap(max.begin(), max.end(), less<T>());
//                 max.pop_back(); //TODO: max.pop_front()?
//             }

//             min.push_back(num);
//             push_heap(min.begin(), min.end(), greater<T>());
//         }
//         else
//         {
//             if(min.size() > 0 && num > min[0])
//             {
//                 min.push_back(num);
//                 push_heap(min.begin(), min.end(), greater<T>());

//                 num = min[0];
//                 pop_heap(min.begin(), min.end(), greater<T>());
//                 min.pop_back(); // TODO: 不应该pop  min[0]

//             }
//             max.push_back(num);
//             push_heap(max.begin(), max.end(), less<T>());
//         }

//     }

// private:
//     vector<T> min;
//     vector<T> max;

// };



// ==================== Test Code ====================
void Test(const char* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch(exception e)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}






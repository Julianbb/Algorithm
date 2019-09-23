/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-19 11:48
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
using namespace std;

bool Sorting(int* cards, int length, int* num_0)
{
    if(cards == nullptr || length != 5 || num_0 == nullptr) return false;  
    
    int array[14] ={0};
    for(int i=0; i<length; i++)
    {
	array[cards[i]]++;
    }

    int index = 0;

    *num_0 = array[0];
    for(int i=0; i<array[0]; i++)
        cards[index++] = 0; 

    for(int i=1; i<14; i++)
    {
	if(array[i] != 0)
    {
        if(array[i]>1)
	    return false;
	else
	    cards[index++] = i;

        
    }

    }

    return true;
}


bool IsContinuous(int* cards, int length)
{
    if(cards == nullptr || length != 5) return false;

    int num_0 = 0;
    bool sort = Sorting(cards, length, &num_0);
    if(!sort) return false;

    int sum = 0;
    
    if(num_0 == 0)
    {
    for(int i=4; i>=1; --i)
    {
	sum += (cards[i] - cards[i-1]);
    }
    if(sum == 4) return true;
    else return false;
    }


    if(num_0 != 0)
    {
	int tmp = 5 - num_0;
	for(int i=4; i>num_0; --i)
	{
	    sum += (cards[i] - cards[i-1]);
	}
	if(sum - tmp + 1 <= num_0)
	    return true;
	else 
	    return false;
    }
}






// bool Sorting(int*cards, int length, int* num_0)
// {
//     if(cards == nullptr || length != 5)
//         return false;

//     int array[14] = {0};

//     for(int i=0; i<length; i++)
//     {
//         array[cards[i]]++;
//     }

//     int j=0;
//     for(int i=0; i<14; i++)
//     {
//         if(array[i] > 1 && i!=0) //there are same cards
//             return false;
//         while(array[i])
//         {
//             cards[j++] = i;
//             array[i]--;
//             if(i==0)
//                 (*num_0)++;
//         }
//     }
//     return true;

// }


// int CountLack(int* array, int length)
// {
//     if(array== nullptr || length < 1)
//         return 0;

//     int num_lack = 0;
//     for(int i=0; i<length-1; i++)
//     {
//         num_lack += array[length-1-i] - array[length-2-i];
//     }

//     num_lack = num_lack -(length-1); // length-1 : 应该有的空缺

//     return num_lack;
// }


// bool IsContinuous(int* cards, int length)
// {
//     if(cards == nullptr || length != 5)
//         return false;

//     int num_0=0;
//     bool result = Sorting(cards, length, &num_0);
//     if(result == false)
//         return result;


//     int num_lack=0;
//     num_lack = CountLack(cards+num_0, 5-num_0);

//     if(num_0 >= num_lack)
//         return true;
//     else
//         return false;
// }



// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, bool expected)
{
    if(testName == nullptr)
	return;
	

    if(IsContinuous(numbers, length) == expected)
	cout << testName << " passed" << endl;
    else
	cout << testName << " failed" << endl;
}

void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", nullptr, 0, false);
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
    Test12();

    return 0;
}

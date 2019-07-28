/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-28 22:00
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;




bool duplicate(int numbers[], int length, int* duplication) 
{
    if(numbers == nullptr || length <=1 )
	return false;

    if(duplication == nullptr)
	return false;

    for(int i=0; i<length; i++)
    {
	if(numbers[i] > length-1)
	    return false;
    }

    int index = 0;

    for(int i=0; i<length; i++)
    {
	if(numbers[i] == i)
	    continue;
	else
	{
	    if(numbers[i] == numbers[numbers[i]])
	    {
		duplication[index++] = numbers[i];
		return true;
	    }

	    // numbers[i] = numbers[i] + numbers[numbers[i]];    这种交换在a和b 相互影响的时候不可使用,虽然不使用第三者
	    // numbers[numbers[i]] = numbers[i] - numbers[numbers[i]];
	    // numbers[i] = numbers[i] - numbers[numbers[i]];

	    int tmp = numbers[i];
	    numbers[i] = numbers[tmp];
	    numbers[tmp] = tmp;

	    i--;
	    continue;
	}
    }

    return false;

}


//================= Test Code =================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(const char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
            {
                printf("Passed.\n");
            }
            else
            {
                printf("FAILED.\n");
            }
        }
        else
        {
            printf("Passed.\n");
        }
    }
    else
    {
        printf("FAILED.\n");
    }
}

// The duplicated number is the smallest number
static void test1()
{
    int numbers[] = {2, 1, 3, 1, 4};
    int duplications[] = {1};
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// The duplicated number is the greatest number
static void test2()
{
    int numbers[] = {2, 4, 3, 1, 4};
    int duplications[] = {4};
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// There are more than one duplicated number
static void test3()
{
    int numbers[] = {2, 4, 2, 1, 4};
    int duplications[] = {2, 4};
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// no duplicated numbers
static void test4()
{
    int numbers[] = {2, 1, 3, 0, 4};
    int duplications[] = {-1}; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// no duplicated numbers
static void test5()
{
    int numbers[] = {2, 1, 3, 5, 4};
    int duplications[] = {-1}; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}

/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-29 09:24
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <vector>
using namespace std;

void multiply(const vector<double>& array1, vector<double>& array2)
{
    if(array1.size() <= 1 || array2.size() <= 1)
	return;

    if(array1.size() != array2.size())
	return;

    int length = array1.size();

    double tmp = 1;
    array2[0] = 1;
    for(int i=1; i<length; i++)
    {
	tmp *= array1[i-1];
	array2[i] = tmp;
    }

    tmp =1;
    for(int i=length-2; i>=0; i--)
    {
	tmp *= array1[i+1];	
	array2[i] *= tmp;
    }
}



//================= Test Code =================
static bool equalArrays(const vector<double>& array1, const vector<double>& array2)
{
    int length1= array1.size();
    int length2 = array2.size();

    if(length1 != length2)
        return false;
        
    for(int i = 0; i < length1; ++i)
    {
        if(abs(array1[i] - array2[i]) > 0.0000001)
            return false;
    }
        
    return true;
}

static void test(const char* testName, const vector<double>& array1, vector<double> array2, const vector<double>& expected){
    printf("%s Begins: ", testName);
        
    multiply(array1, array2);
    if(equalArrays(array2, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}
    
static void test1()
{
    double array1[] = {1, 2, 3, 4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {120, 60, 40, 30, 24};
        
    test("Test1", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test2()
{
    double array1[] = {1, 2, 0, 4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {0, 0, 40, 0, 0};
        
    test("Test2", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test3()
{
    double array1[] = {1, 2, 0, 4, 0};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {0, 0, 0, 0, 0};
        
    test("Test3", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test4()
{
    double array1[] = {1, -2, 3, -4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {120, -60, 40, -30, 24};
        
    test("Test4", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test5()
{
    double array1[] = {1, -2};
    double array2[] = {0, 0};
    double expected[] = {-2, 1};
        
    test("Test5", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
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

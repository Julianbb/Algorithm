/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-30 10:23
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
using namespace std;


bool scanUnsignedInteger(const char** str)
{
    const char* Before = *str;

    while(**str != 0 && **str >='0' && **str <='9')
	++(*str);

    return *str > Before;
}



bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
	++(*str);
    return scanUnsignedInteger(str);
}



bool isNumeric(const char* str)
{
    if(str == nullptr)
	return false;

    bool numberic = scanInteger(&str);

    if(*str == '.')
    {
	++str;
	numberic = scanUnsignedInteger(&str) || numberic;
    }

    if(*str == 'e' || *str == 'E')
    {
	++str;
	numberic = scanInteger(&str) && numberic;
    }

    return numberic && *str == 0;
}



// ==================== Test Code ====================

void Test(const char* testName, const char* str, bool expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    if (isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "+.", false);

    return 0;
}

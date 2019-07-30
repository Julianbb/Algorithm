/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-30 10:23
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


void scanDigits(const char** str)
{
    while(**str != 0 && **str >='0' && **str <='9')
	++(*str);
}

bool isExponential(const char** str)
{
    if(**str != 'e'&& **str != 'E')
	return false;

    ++(*str);

    if(**str == '+' || **str == '-')
	++(*str);

    if(**str == 0)
	return false;

    scanDigits(str);
    return (**str == 0 ? true : false);
}



bool isNumeric(const char* str)
{
    if(str == nullptr)
	return false;

    if(*str == '+' || *str == '-')
	++str;

    if(*str == 0)
	return false;

    bool numberic = true;
    scanDigits(&str);

    if(*str != 0)
    {
	if(*str == '.')
	{
	    ++str;
	    if(*str < '0' || *str >'9') // .后面没有数字
		return false;
	    scanDigits(&str);
	    if(*str == 'e' || *str == 'E')
		numberic = isExponential(&str);
	}
	else if(*str == 'e' || *str == 'E')
	{
	    numberic = isExponential(&str);
	}
	else
	    numberic = false;
    }

    return numberic && (*str == 0);
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
    Test("Test6", "600.", false);
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

/* ====================================================
#   Copyright (C)2019 All rights reserved.

#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-07 17:00
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <cstring>
using namespace std;


int CalculateBlank(char str[])
{
    if(str == nullptr) return 0;
    int num_blank = 0;

    int length = strlen(str);
    for(int i=0; i<length; i++)
    {
        if(str[i] == ' ')
            num_blank++;
    }

    return num_blank;
}



void ReplaceBlank(char str[], int length)
{
    if(str == nullptr || length == 0) return;

    int num_blank = CalculateBlank(str);
    int i= strlen(str);
    int tmp_len = i;
    int j= i+2*num_blank;

    int count = 0;


    for(int k=0; k<tmp_len; k++)
    {
	i--;
	

	if(str[i] != ' ')
	    count++;

	if(str[i] == ' ')
	{
	    for(int m=count; m>=1; m--)
	    {
		str[--j] =str[i+m]; 
	    }

	    str[--j] = '0';
	    str[--j] = '2';
	    str[--j] = '%';

	    count = 0;

	}

	if(i==0 && k == tmp_len-1)
	{
	    for(int m=count-1; m>=0; m--)
	    {
		str[--j] =str[i+m];
	    }
	}
    }


}



// ====================测试代码====================
void Test(const char* testName, char str[], int length, const char* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
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

    return 0;
}

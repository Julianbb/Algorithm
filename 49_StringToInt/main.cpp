/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-22 19:46
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;

enum
{
    kValid = 0,
    kInvalid 
};



bool g_nStatus = 0;

int StrToInt(const char* str)
{
   g_nStatus = 0;
   if(str == nullptr || str == "") 
   {
       g_nStatus = kInvalid;
       return 0;
   }

   if((*str < '0' || *str > '9') && (*str != '+' && *str != '-'))
   {
       g_nStatus =  kInvalid;
       return 0;
   }
   


long long  int number = 0;
   int index = 0;
   int flag_m = 0;

   while(*str != 0)
   {
       if(*str < '0' || *str > '9' )
       {
	   if(index == 0)
	   {
	       if(*str == '+')
	       {
		   str++;
		   index++;
		   flag_m = 1;
		   continue;
	       }
	       if(*str == '-')
	       {
		   flag_m = 2;
		   index++;
		   str++;
		   continue;
	       }
	   }
	   else
	   {
	       g_nStatus = kInvalid;
	       return 0;
	   }
       }

       number = number*10;
       int num = *str - '0';
       number = number + num ;	   
       str++;
       index++;
   }

   if(flag_m > 0 && index < 2)
   {
       g_nStatus = kInvalid;
       return 0;
   }

   if(flag_m == 2)   
       number = 0-number;

   if(number < -2147483648 || number > 2147483647)
   {
       g_nStatus = kInvalid;
       return 0;
   }
   else
   {
       return (int)number;
   }

}




// ====================测试代码====================
void Test(const char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
     Test(nullptr);

     Test("");

     Test("123");

     Test("+123");

     Test("-123");

     Test("1a33");

     Test("+0");

     Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}

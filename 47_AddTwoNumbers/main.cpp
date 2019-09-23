/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-21 09:32
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
using namespace std;


int Add(int a, int b)
{
    if(b == 0)
	return a;

    unsigned int tmp_data = (unsigned int)a ^ (unsigned int)b;
    unsigned int tmp_con = (unsigned int)a & (unsigned int)b;  

    return Add(tmp_data, tmp_con<<1);
}

















// int Add(int a, int b)
// {
//     if(b==0)
//     {
//         return a;
//     }

//     int sum =0, carry =0;

//     sum = (unsigned int)a ^ (unsigned int)b ;
//     carry = (unsigned int)a & (unsigned int)b;

//    return Add((unsigned int)sum, (unsigned int)carry<<1);

// }


// ====================测试代码====================
void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

int main(int argc, char* argv[])
{
    Test(1, 2, 3);
    Test(111, 899, 1010);

    Test(-1, 2, 1);
    Test(1, -2, -1);

    Test(3, 0, 3);
    Test(0, -4, -4);

    Test(-2, -8, -10);

    return 0;
}

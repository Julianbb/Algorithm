/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-20 10:56
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
using namespace std;



//利用构造函数
class Temp
{
public:
    Temp()
    {
	++N;
	sum += N;
    }

    static void Reset(){N=0; sum = 0;}
    static int getSum(void)
    {
	return sum;
    }

private:
    static int N;
    static int sum;
};

int Temp::N = 0;
int Temp::sum = 0;



int Sum_Solution1(int n)
{
    Temp::Reset();
    Temp* tmp = new Temp[n];
    delete [] tmp;
    tmp = nullptr;
    return Temp::getSum();
}



// 利用虚函数
class A;
A* array[2];

class A
{
    public:
	virtual int sum(int n)
	{
	    return 0;
	}
};

class B : public A
{
    public:
       virtual int sum(int n)
       {
	   return n+array[!!n]->sum(n-1);
       }	   
};


int Sum_Solution2(int n)
{
    class A a;
    class B b;

    array[0] = &a;
    array[1] = &b;

    return array[1]->sum(n);

}


// 利用函数指针
typedef int(*FUN)(int);
int solu3(int n)
{
    return 0;
}

int Sum_Solution3(int n)
{

   static  FUN fun[2] = {solu3, Sum_Solution3};
    return n+fun[!!n](n-1);
}





// 利用模板类预编译
template<unsigned int n> struct Sum_Solution4
{
    enum Value {N = Sum_Solution4<n-1>::N+n};
};

template<> struct Sum_Solution4<1>
{
    enum Value{N=1};
};

template<> struct Sum_Solution4<0>
{
    enum Value{N=0};
};



// ====================测试代码====================
void Test(int n, int expected)
{
    printf("Test for %d begins:\n", n);

    if(Sum_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(Sum_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    if(Sum_Solution3(n) == expected)
        printf("Solution3 passed.\n");
    else
        printf("Solution3 failed.\n");
}

void Test1()
{
    const unsigned int number = 1;
    int expected = 1;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test2()
{
    const unsigned int number = 5;
    int expected = 15;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test3()
{
    const unsigned int number = 10;
    int expected = 55;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test4()
{
    const unsigned int number = 0;
    int expected = 0;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

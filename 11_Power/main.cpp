#include <iostream>
using namespace std;
typedef double CommomPower(double, int);


//设置全局变量，用来表示输入的数据是否有效
bool valueInvalid = false;


//判断两个 浮点数是否相等
bool Equal(double num1, double num2)
{
    if((num1-num2 < 0.000001)&& (num1-num2>-0.000001))
	return true;
    else
	return false;
}


 
double CommomPower_way1(double base, int exponent)
{
    double result = 1.0;
    for(int i=0; i<exponent; i++)
    {
	result *= base;
    }
    return result;
}




// 相对于way1，更加高效的方法
double CommomPower_way2(double base, int exponent)
{
    if(exponent == 1) return base;
    if(exponent == 0) return 1.0;

    double result = CommomPower_way2(base, exponent>>1); // 利用>>相当于　/2
    result *= result;
    if(exponent & 0x1 == 1)
	result *= base;

    return result;
}


// 考虑base为0, exponent<0, 和两者都为0的不合法的输入
double MyPower(double base, int exponent, CommomPower* way)
{

    if(Equal(base, 0.0) && exponent<=0)
    {
	valueInvalid = true;
	return 0.0;
    }
    else
    {
	if(exponent<0)
	{
	    int tmp_exponent = -exponent;
	    double tmp_result = way(base, tmp_exponent);
	    return 1.0/tmp_result;
	}
	else
	{
	    return way(base, exponent);
	}

    }
}






void Test1(void)
{
   if(Equal(MyPower(0, 0, CommomPower_way2), 0.0) && valueInvalid == true)
       cout << "Test1 passed" << endl;
   else
       cout << "Test1 failed" << endl;
}


void Test2(void)
{
   if(Equal(MyPower(-1, 0, CommomPower_way2), 1.0))
       cout << "Test2 passed" << endl;
   else
       cout << "Test2 failed" << endl;
}

void Test3(void)
{
  if(Equal(MyPower(3, 2, CommomPower_way2), 9.0))
       cout << "Test3 passed" << endl;
   else
       cout << "Test3 failed" << endl;
}

void Test4(void)
{
   if(Equal(MyPower(-2, -2, CommomPower_way2), 0.25))
       cout << "Test4 passed" << endl;
   else
       cout << "Test4 failed" << endl;
}


void Test5(void)
{
   if(Equal(MyPower(0, 10, CommomPower_way2), 0.0))
       cout << "Test5 passed" << endl;
   else
       cout << "Test5 failed" << endl;
}


int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

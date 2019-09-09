#include <iostream>
using namespace std;

int Fibonacci(int number)
{
    // if(number <= 0)
    //     return 0;
    // if(number == 1)
    //     return 1;

    // return Fibonacci(number-1) + Fibonacci(number-2);


    if(number < 2)
	return number;

    int num2 =0;
    int num1 =1;
    int result = 0;
    for(int index = 2; index <=number; index++)
    {
	result = num1+num2;
	num2 = num1;
	num1 = result;
    }
    return result;
}

// int Fibonacci(int number)
// {
//     if(number < 2)
//         return number;

//     int Num_2 = 0;
//     int Num_1 = 1;
//     int result = 0;
//     for(int index=2;index<=number; index++)
//     {
//         result = Num_1+Num_2;
//         Num_2 = Num_1;
//         Num_1 = result;
//     }

//     return result;
// }





void Test(void)
{
    if(Fibonacci(0) == 0)
	cout << "number 0 passed" << endl;
    else 
	cout << "number 0 failed" << endl;

    if(Fibonacci(1) == 1)
	cout << "number 1 passed" << endl;
    else 
	cout << "number 1 failed" << endl;
    
    if(Fibonacci(2) == 1)
	cout << "number 2 passed" << endl;
    else 
	cout << "number 2 failed" << endl;

    if(Fibonacci(3) == 2)
	cout << "number 3 passed" << endl;
    else 
	cout << "number 3 failed" << endl;

    if(Fibonacci(4) == 3)
	cout << "number 4 passed" << endl;
    else 
	cout << "number 4 failed" << endl;

    if(Fibonacci(5) == 5)
	cout << "number 5 passed" << endl;
    else 
	cout << "number 5 failed" << endl;
    
    if(Fibonacci(6) == 8)
	cout << "number 6 passed" << endl;
    else
	cout << "number 6 failed" << endl;

}


int main(void)
{
    Test();
    return 0;
}

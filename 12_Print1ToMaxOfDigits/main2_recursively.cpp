#include <iostream>
#include <string.h>

using namespace std;



void PrintNumber(char* number)
{
    if(number == NULL) return;
    int length = strlen(number);
    int flag_pre0 = 1;
    for(int i=0; i<length; i++)
    {
	if(number[i] != '0')
	    flag_pre0 = 0; 
	if(flag_pre0 == 0)
	    cout << number[i] ;
    }
    if(flag_pre0 == 0)//如果全是0，就不打印
    cout << endl;
}





void Print1ToMaxOfNDigitsRecursively(char* number, int index)
{
    // 异常处理
    
    int length = strlen(number);
    if(index ==	length) //当到最后一位的下一位,打印
    {
	PrintNumber(number);
	return;
    }
    
    for(int i=0; i<=9; i++) // 对每一位，遍历0-9
    {
	number[index] = '0'+i;
	Print1ToMaxOfNDigitsRecursively(number, index+1); //执行下一位
    }

}


void Print1ToMaxOfNDigits(int n)
{
    if(n<=0) return;
    char* number = new char [n+1];
    memset(number, '0',n);
    number[n] = '\0';

    int length = strlen(number);
    Print1ToMaxOfNDigitsRecursively(number, 0); //从第0位开始

    delete[]number;
}





void Test(void)
{
     //Print1ToMaxOfNDigits(1);
     Print1ToMaxOfNDigits(2);
     //Print1ToMaxOfNDigits(0);
     //Print1ToMaxOfNDigits(-1);
}


int main(void)
{
    Test();

    return 0;
}

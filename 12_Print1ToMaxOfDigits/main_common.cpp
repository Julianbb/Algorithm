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
    cout << endl;
}



bool Increase(char* number)
{
    if(number == NULL) false;
    int length = strlen(number);

    int n = 1;
    while(n<=length) 
    {
	if(number[length-n]=='9')//如果当前位是９，set to 0, 转到上一位
	{
	    number[length-n]='0';
	    n++;
	}
	else //不是９，直接+１
	{
	    number[length-n] ++;
	    break;
	}
    }
    if(n>length) return false; //大于length 证明所有位都是9

    return true;
}



void Print1ToMaxOfNDigits(int n)
{
    if(n<=0) return;
    char* number = new char [n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(Increase(number))
    {
	PrintNumber(number);
    }
    delete [] number;
}



void Test(void)
{
     //Print1ToMaxOfNDigits(1);
     //Print1ToMaxOfNDigits(2);
     //Print1ToMaxOfNDigits(0);
     //Print1ToMaxOfNDigits(-1);
}


int main(void)
{
    Test();

    return 0;
}

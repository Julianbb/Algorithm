#include <iostream>
#include <string.h>
using namespace std;

// 将数字转成字符串, 数字高位在字符串低位
char* numToCharArray(unsigned int number)
{
    char* pNumber = new char[100];
    int i = 0 ;
    while(number > 0) //从个位开始转，放到字符数组0的位置
    {
	int tmp = number % 10; // 取最低位
	pNumber[i++] = 48+tmp;
	number = number/10; // 得到剩下的
    }
    pNumber[i]=0;

    char array_tmp[i]={0}; // 转化完之后，将高位低位互换，使得数字高位在数字低位
    int counter = i>>1;
    for(int j=0; j<counter; j++)
    {
	char tmp = pNumber[i-1-j];
	pNumber[i-1-j] = pNumber[j];
	pNumber[j] = tmp;
    }
    return pNumber;
}

// 将字符串转成数字
unsigned int CharArrayToNumber(char* pArray, int start, int end)
{
    if(pArray == nullptr || start > end) return 0;
    if(start == end) return (pArray[start] - 48);
    int start_my = start;
    int length = end-start+1;
    unsigned int number = 0;
    while(length)
    {
	int times_10 = length-1;
	int number_tmp = (pArray[start_my++]-48);

	for(int i=0; i<times_10; i++)
	{
	    number_tmp *=10;
	}

	number += number_tmp;
	length--;
    }
   return number; 
}


unsigned int NumberOf1Between1AndN_Solution1(unsigned int number)
{
    if(number == 0) return 0;
    char* pNumber = numToCharArray(number);
    int length =  strlen(pNumber);

    int Total_number = 0;
    for(int i=0; i<length; i++)
    {
	int number_tmp = 0;
	if(pNumber[i] == '1')
	{
	    int number_front = CharArrayToNumber(pNumber,0, i-1);
	    int number_back_length = strlen(pNumber+i+1); 
	    int number_back = 1;
	    while(number_back_length--)
	    {
		number_back *= 10;
	    }
	    number_tmp = CharArrayToNumber(pNumber, i+1, length-1)+number_front*number_back+1;
	}


	if(pNumber[i] == '0')
	{
	    int number_front = CharArrayToNumber(pNumber,0, i-1);
	    int number_back_length = strlen(pNumber+i+1); 
	    int number_back = 1;
	    while(number_back_length--)
	    {
		number_back *= 10;
	    }
	    number_tmp = number_front*number_back;
	}


	if( pNumber[i]<='9' && pNumber[i] >='2')
	{
	    int number_front = CharArrayToNumber(pNumber,0, i-1)+1;
	    int number_back_length = length-1-i; 
	    int number_back = 1;
	    while(number_back_length--)
	    {
		number_back *= 10;
	    }
	    number_tmp = number_front*number_back;
	}

	Total_number += number_tmp;
    }
    return Total_number;
}



// ===================测试代码================


void Test(const char* testName, unsigned int n,unsigned int expected)
{
    if(testName != nullptr)
	cout << testName << " : ";
    
    if(NumberOf1Between1AndN_Solution1(n) == expected)
	cout << "passed" <<endl;
    else
	cout << "failed" << endl;
    
    cout << endl;
}


int main(void)
{

    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);

    return 0;
}

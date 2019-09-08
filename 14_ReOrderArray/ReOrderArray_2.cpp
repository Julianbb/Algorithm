#include <iostream>
using namespace std;

typedef bool Fun(int);


//判断正负数
bool function1(int data)
{
    if(data < 0) 
	return true;
    else 
	return false;
}

//能否被３整除
bool function2(int data)
{
    if(data%3 == 0) 
	return true;
    else
       	return false;

}


void ReOrderArray(int* array, int length, Fun* fun)
{
    if(array == nullptr || length<=1) return;

    int p1 = 0;
    int p2 = length-1;

    while(p1 < p2)
    {
	while(p1 < p2 && fun(array[p1]))
	    p1++;
	while(p1 < p2 && !fun(array[p2]))
	    p2--;

	if(p1<p2)
	{
	    int tmp = array[p1];
	    array[p1] = array[p2];
	    array[p2] = tmp;
	}
    }
}


void PrintArray(int* array, int length)
{
    for(int i=0; i<length; i++)
    {
	cout << array[i] << " " ;
    }
    cout << endl;

}



void Test1(void)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(array)/sizeof(array[1]);
    cout << "before reorder: ";
    PrintArray(array, length);

    ReOrderArray(array, 10, function1);

    cout << "after  reorder: ";
    PrintArray(array, length);

}


int main(void)
{
    Test1();
}

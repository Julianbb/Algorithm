/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-18 22:37
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


// 剑指offer, p189
void MergeSort(int* data, int* copy, int start, int end)
{
    if(data== nullptr || copy == nullptr)return;
    if(start > end)return;
    if(start == end)
    {
	copy[start] = data[start];
	return;
    }

    int length = (end-start)/2;
    MergeSort(copy, data, start, start+length); // 左半
    MergeSort(copy, data, start+length+1, end); // 右半

    int i= start+length;
    int j = end;
    
    int CopyIndex = end;
    
    while(i>=start && j>=start+length+1)
    {
	if(data[i]>data[j])
	    copy[CopyIndex--] = data[i--];
	else
	    copy[CopyIndex--] = data[j--];
    }

    for(; i>=start; --i)
	copy[CopyIndex--] = data[i];
    
    for(; j>=start+length+1; --j)
	copy[CopyIndex--] = data[j];

}


//=========================测试代码=================================

void Print(int* array, int length)
{
    if(array==nullptr || length <= 0) return;
    for(int i=0; i<length; i++)
    {
	cout << array[i] << " ";
    }
    cout << endl;
}


void Test1()
{
    int array[] = {1,1,2,2,3,4,5,6,3,4};
    int length = sizeof(array)/sizeof(array[0]);
    int* copy = new int[length];
    for(int i=0; i<length; i++)
    {
	copy[i] = array[i];
    }

    MergeSort(array, copy, 0, length-1);

    cout << "Test1" << endl;
    Print(array, length);
    Print(copy, length);
    cout << endl;

    delete[]copy;
}


void Test2()
{
    int array[] = {1};
    int length = sizeof(array)/sizeof(array[0]);
    int* copy = new int[length];
    for(int i=0; i<length; i++)
    {
	copy[i] = array[i];
    }


    MergeSort(array, copy, 0, length-1);

    cout << "Test2" << endl;
    Print(array, length);
    Print(copy, length);
    cout << endl;

    delete[]copy;
}


void Test3()
{
    int array[] = {1,-1, 4, 6, 3,3,3,3, 6 ,88};
    int length = sizeof(array)/sizeof(array[0]);
    int* copy = new int[length];
    for(int i=0; i<length; i++)
    {
	copy[i] = array[i];
    }


    MergeSort(array, copy, 0, length-1);

    cout << "Test3" << endl;
    Print(array, length);
    Print(copy, length);
    cout << endl;

    delete[]copy;
}



void Test4()
{
    int array[] = {};
    int length = 0;
    int* copy = new int[1];

    MergeSort(array, copy, 0, length-1);

    cout << "Test4" << endl;
    Print(array, length);
    Print(copy, length);
    cout << endl;

    delete[]copy;
}


void Test5()
{
    int* array = nullptr;
    int length = 0;
    int* copy = new int[1];

    MergeSort(array, copy, 0, length-1);

    cout << "Test5" << endl;
    Print(array, length);
    Print(copy, length);
    cout << endl;

    delete[]copy;
}


int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}

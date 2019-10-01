/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-08 18:34
#   Describe      :
#
# ====================================================*/


#include <iostream>
using namespace std;


void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// 方法1
int Partition(int array[], int start, int end)
{
    if(array == nullptr ||  start > end) return -1; // 不要包含start=end 

    int i=start, j=end; //不要写成 i=start+1
    while(i<j)
    {
	while(array[j] >= array[start] && j>i) //
	    j--;

	while(array[i] <= array[start] && i<j) //
	    i++;
    
	 if(i<j)
	     Swap(&array[i], &array[j]);
    }

    if(array[start]> array[j])
	Swap(&array[j], &array[start]);
    
    return i;
}




//方法2
// int Partition(int data[], int length, int start, int end)
// {
//     if(data == NULL || length <=0 || start<0 || end>=length || end<0)
//         return -1;

//     // 选择start 作为中间
//     int mid = start;
//     for(int index=start+1; index<=end; ++index)// 遍历数组,和start比较
//     {
//         if(data[index] < data[start])
//         {
//             ++ mid;
//             if(mid != index) // 证明上次或者连续好几次的数 > start, 但是这次 data[index] < data[start] , [mid index) 之间都是比start大的数
//                 Swap(&data[mid], &data[index]);
//         }
//     } //结束遍历之后，data[mid] <= data[start]

//     Swap(&data[mid], &data[start]);
//     return mid;
// }



void QuickSort(int array[], int length)
{
    if(array == nullptr || length <= 0)
	return;

    if(length == 1) return;

    int index = Partition(array, 0, length-1);
    
    QuickSort(array, index);
    QuickSort(array+index+1, length-index-1);

}





bool Equal(int array1[], int array2[], int length)
{
    if(array1 == nullptr || array2 == nullptr)
	return false;

    for(int i=0; i<length; i++)
    {
	if(array1[i] != array2[i])
	{
	    return false;
	}
    }

    return true;
}



void Test1(void)
{
    int array[] = {3,4,5,6,3,6,6,22,66};
    QuickSort(array, sizeof(array)/sizeof(array[0]));

    int result[]={3,3, 4, 5,6,6,6,22,66};

    if(Equal(result, array, sizeof(array)/sizeof(array[0])))
    {
	cout << "test1 passed" << endl;
    }
    else
	cout << "test1 failed" << endl;

}


void Test2(void)
{
    int array[] = {3,4,5,6,7,8,9,10,11};
    QuickSort(array, sizeof(array)/sizeof(array[0]));

    int result[]={3,4,5,6,7,8,9,10,11};
    if(Equal(array, result, sizeof(array)/sizeof(array[0])))
    {
	cout << "test2 passed" << endl;
    }
    else
	cout << "test2 failed" << endl;

}

void Test3(void)
{
    int array[] = {1,1,1,1,1,1};
    QuickSort(array, sizeof(array)/sizeof(array[0]));

    int result[]={1,1,1,1,1,1};
    if(Equal(array, result, sizeof(array)/sizeof(array[0])))
    {
	cout << "test3 passed" << endl;
    }
    else
	cout << "test3 failed" << endl;

}

void Test4(void)
{
    int array[] = {1};
    QuickSort(array, sizeof(array)/sizeof(array[0]));

    int result[]={1,};
    if(Equal(array, result, sizeof(array)/sizeof(array[0])))
    {
	cout << "test4 passed" << endl;
    }
    else
	cout << "test4 failed" << endl;

}

int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}

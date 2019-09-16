#include <iostream>
using namespace std;

bool flag_valid = true;

int MaxSumOfSubArray(int* array, int length)
{
    if(array == nullptr || length <= 0) 
    {
	flag_valid = false;
	return 0;
    }

    int max = array[0];
    int sum = array[0];

    for(int i=1; i<length; i++)
    {
	sum += array[i];

	if(sum <= max && sum < 0) // 不仅sum <= max , 还得sum < 0 
	{
	    sum = 0;
	    continue;
	}

	if(sum > max)
	    max = sum;

    }

    return max;
}


// int MaxSumOfSubArray(int* array, int length)
// {
//     if(array == nullptr || length <= 0)
//     {
//         flag_valid = false;
//         return 0;
//     }


//     int sum_now = 0;
//     int sum_pre = 0;
//     int i = 0;

//     while(i < length)
//     {

//         sum_now += array[i];
//         if(i == 0)
//         {
//             sum_pre = sum_now;
//             i++;
//             continue;
//         }

//         if(sum_now > sum_pre) // 当前sum > 之前的最大值
//         {
//             sum_pre = sum_now;
//         }
//         if(sum_now < sum_pre && sum_now < 0) //加了一个数之后，比之前最大小且当前总sum < 0
//             sum_now = 0;
//         i++;
//     }

//     return sum_pre;
// }




//===========================测试代码===========================
//


void Test(const char* testname, int* array, int length, int expectedVal, bool expectedFlag)
{
    if(testname == nullptr) return;
    else
	cout << testname<< ":  ";
    
    int val = MaxSumOfSubArray(array, length);
    if(val == expectedVal && flag_valid == expectedFlag)
	cout << "passed " << endl;
    else
	cout << "failed" << endl;

}


void Test1(void)
{
    int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", array, sizeof(array)/sizeof(array[0]), 18, true);
}

void Test2(void)
{
    int array[] =  {-2, -8, -1, -5, -9}; 
    Test("Test2", array, sizeof(array)/sizeof(array[0]), -1, true);
}

void Test3(void)
{
    int array[] = {2, 8, 1, 5, 9};
    Test("Test3", array, sizeof(array)/sizeof(array[0]), 25, true);
}

void Test4(void)
{
    int array[]={} ;
    Test("Test4", array, sizeof(array)/sizeof(array[0]), 0, false);
}



int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

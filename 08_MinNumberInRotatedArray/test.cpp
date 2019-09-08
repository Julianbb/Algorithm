#include <iostream>
using namespace std;


int MinInOrder(int* numbers, int start, int end)
{
    int min = numbers[start];
    for(int i=start+1; i<=end; i++)
    {
	if(numbers[i]< min)
	    min = numbers[i];
    }
    return min;
}


int Min(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
	return -1;

    int  start = 0; 
    int  end = length-1;
    int mid =(end+start)/2;
    
    while(numbers[start] >= numbers[end])
    {
	if(end - start == 1)
	{
	    break;
	}

	if(numbers[start]==numbers[end] && numbers[mid]==numbers[start])
	    return MinInOrder(numbers, start, end);

	if(numbers[start]<=numbers[mid])
	    start = mid;
	if(numbers[end] >= numbers[mid])
	    end = mid;
	
	mid = (end+start)/2;
    }

    return numbers[end];
}



void Test1(void)
{
    int test1[] = {3,4,5,1,2};
    int min = Min(test1, 5);
    if(min == 1)
	cout << "Test1 passed" << endl;
    else
	cout << "Test1 failed" << endl;
}

void Test2(void)
{
    int test2[] = {1,0,1,1,1};
    int min = Min(test2, 5);
    if(min == 0)
	cout << "Test2 passed" << endl;
    else
	cout << "Test2 failed" << endl;
}

void Test3(void)
{
    int test3[] = {1,1,1,0,1}; 
    int min = Min(test3, 5);
    if(min == 0)
	cout << "Test3 passed" << endl;
    else
	cout << "Test3 failed" << endl;
}

void Test4(void)
{
    int test4[] = {0};
    int min = Min(test4, 1);
    if(min == 0)
	cout << "Test4 passed" << endl;
    else
	cout << "Test4 failed" << endl;
}

void Test5(void)
{
    int test5[] = {};
    int min = Min(test5, 0);
    if(min == -1)
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











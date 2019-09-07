#include <iostream>
using namespace std;

bool FindNumber(int* array, int rows, int cols, int number)
{
    if(array == NULL || rows<=0 || cols<=0) return false;

    int i=3;
    int j=0;

    while(i>=0 && i<=3 && j>=0&& j<=3)
    {
	if(*(array+i*4+j) == number)
	    return true;

	if(*(array+i*4+j) > number)
	    i--;
	if(*(array+i*4+j) < number)
	    j++;
    }

    return false;


}



// bool FindNumber(int* array, int rows, int cols, int number)
// {
//         if(array == NULL || rows<=0 || cols<=0) return false;
//         int i = cols -1;
//         int j = 0;

//         while(i>=0 && i<rows && j>=0 && j<cols)
//         {
//                 if(array[i*cols+j] == number)
//                         return true;

//                 if(number > array[i*cols+j])
//                 {
//                         j++;
//                 }
//                 else
//                 {
//                         i--;
//                 }

//         }
//         return false;
// }

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  数字在数组中
void Test1(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber(&array[0][0], 4, 4, 7);
	if(result == true)
		cout << "Test1 passed" << endl;
	else
		cout << "Test1 failed" << endl;
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  数字不在数组中
void Test2(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber((int*)(&array), 4, 4, 3);
	if(result == false)
		cout << "Test2 passed" << endl;
	else
		cout << "Test2 failed" << endl;
}


//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  数组中最小的数字
void Test3(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber(*array, 4, 4, 1);
	if(result == true)
		cout << "Test3 passed" << endl;
	else
		cout << "Test3 failed" << endl;
}



//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  数组中最大的数字
void Test4(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber((int*)array, 4, 4, 15);
	if(result == true)
		cout << "Test3 passed" << endl;
	else
		cout << "Test3 failed" << endl;
}


//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  比数组中最大的数字还大
void Test5(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber((int*)array, 4, 4, 18);
	if(result == false)
		cout << "Test5 passed" << endl;
	else
		cout << "Test5 failed" << endl;
}




//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
//  比数组中最大的数字还小
void Test6(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber((int*)array, 4, 4, 0);
	if(result == false)
		cout << "Test6 passed" << endl;
	else
		cout << "Test6 failed" << endl;
}



//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 找特殊数字6
void Test7(void)
{
	int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	bool result = FindNumber((int*)array, 4, 4, 6);
	if(result == true)
		cout << "Test7 passed" << endl;
	else
		cout << "Test7 failed" << endl;
}




int main(void)
{


	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}

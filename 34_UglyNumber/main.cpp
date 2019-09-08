#include <iostream>
using namespace std;

typedef int (FUN)(int);

// ===========================solution1, 逐个判断每个整数,效率低===============
bool IsUglyNumber(int num)
{
    while(num%2 == 0)
	num /= 2;
    while(num%3 == 0)
	num /=3;
    while(num%5 == 0)
	num/=5;

    if(num == 1) return true;
    else return false;
}

int GetUglyNumber_Solution1(int index)
{
    if(index <=0 ) return 0;
    int counter = 1;
    int number_tmp = 1;
    while(counter != index)
    {
	number_tmp++;
	if(IsUglyNumber(number_tmp))
	    counter++;
    }

    return number_tmp;
}



//============================solution2:空间换时间==================
int GetUglyNumber_Solution2(int index)
{
    if(index <=0)return 0;
    int* array = new int[index];


    int T2 = 0;
    int T3 = 0;
    int T5 = 0;

    int MinOf235 = 0;
    
    int cun = 0;
    array[cun++] = 1;
    while(cun != index)
    {
	while((2*array[T2])<=MinOf235)
	    T2++;
	int Min2 = 2*array[T2];
	while((3*array[T3])<=MinOf235)
	    T3++;
	int Min3 = 3*array[T3];
	while((5*array[T5])<=MinOf235)
	    T5++;
	int Min5 = 5*array[T5];

	MinOf235 = Min2 > Min3 ? (Min3>Min5?Min5:Min3):(Min2>Min5?Min5:Min2);
	
	array[cun++] = MinOf235;

    }
    int return_tmp = array[index-1];
    delete []array;
    return return_tmp;
}

// ====================测试代码====================
void Test(const char* test_name, int index, int expected, FUN* function)
{
    if(test_name != nullptr) 
	cout << test_name << ":  ";
    else
	return;
    if(function(index) == expected)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;

    cout << endl;
}

int main(int argc, char* argv[])
{
    Test("test1", 1, 1, GetUglyNumber_Solution2);

    Test("test2",2, 2, GetUglyNumber_Solution2);
    Test("test3",3, 3, GetUglyNumber_Solution2);
    Test("test4",4, 4, GetUglyNumber_Solution2);
    Test("test5",5, 5, GetUglyNumber_Solution2);
    Test("test6",6, 6, GetUglyNumber_Solution2);
    Test("test7",7, 8, GetUglyNumber_Solution2);
    Test("test8",8, 9, GetUglyNumber_Solution2);
    Test("test9",9, 10, GetUglyNumber_Solution2);
    Test("test10",10, 12, GetUglyNumber_Solution2);
    Test("test11",11, 15, GetUglyNumber_Solution2);

    Test("test12",1500, 859963392, GetUglyNumber_Solution2);

    Test("test13",0, 0, GetUglyNumber_Solution2);

    return 0;
}

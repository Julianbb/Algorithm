#include <iostream>
using namespace std;




typedef int FUN(int); 


// 每次将tmp 左移１位，再和num做与，是１则num当前位是1, 否则是0
int Numof1InBinaty_way1(int num)
{
    int tmp = 1;
    int count =0;

    while(tmp)
    {
	if(tmp&num)
	count++;
	tmp = tmp << 1;
    }

    return count;
}



// 将tmp的最高位设置为１，每次右移num
int Numof1InBinaty_way2(int num)
{
    int count =0;
    int tmp = 0x80000000;
    while(num)
    {
	if(num & tmp)
	    count++;
	num = num << 1;
    }

    return count;
}



// (num-1) & num 相当于最右边的1变成0, 每个循环相当于删除一个１
int Numof1InBinaty_way3(int num)
{
    int count = 0;
    while(num)
    {
	count++;
	num = (num-1) & num;
    }
    return count;
}




void Test(FUN* Numof1InBinaty_way)
{
    if(Numof1InBinaty_way(0) == 0)
	cout << "number 0 passed" << endl;
    else
	cout << "number 0 failed" << endl;


    if(Numof1InBinaty_way(1) == 1)
	cout << "number 1 passed" << endl;
    else
	cout << "number 1 failed" << endl;


    if(Numof1InBinaty_way(5) == 2)
	cout << "number 5 passed" << endl;
    else
	cout << "number 5 failed" << endl;


    if(Numof1InBinaty_way(-1) == 32) // depends on the type used , for this one (int 32)
	cout << "number -1 passed" << endl;
    else
    {
	cout << Numof1InBinaty_way(-1)<< endl;
	cout << "number -1 failed" << endl;
    }
	
}

int main(void)
{

    Test(Numof1InBinaty_way2);

    return 0;
}

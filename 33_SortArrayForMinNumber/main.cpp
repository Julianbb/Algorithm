#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <deque>
#include <string.h>
using namespace std;
int alredy_index = 0;


bool Compare(int x, int y)
{
    deque<int> a;
    deque<int> b;

    int xx = x;
    int yy = y;

    while(xx != 0)
    {
	int bit = xx%10;
	a.push_front(bit);
	xx = xx/10;
    }

    while(yy != 0)
    {
	int bit = yy%10;
	b.push_front(bit);
	yy = yy/10;
    }

    if(a[0]>b[0])
	return false;
    if(a[0]<b[0])
	return true;

    if(a[0] = b[0])
    {
	int important = a[0];
	while(a.size() > 0 && b.size()>0)
	{
	    if(a[0] = b[0])
	    {
		a.pop_front();
		b.pop_front();
        continue;
	    }
	    if(a[0] < b[0])
		return true;
	    if(a[0] > b[0])
		return false;
	}

	if(a.size() == 0)
	{
	    if(b[0] > important)
		return true;
	    else
		return false;
	}
	else
	{
	    if(a[0] > important)
		return false;
	    else
		return true;
	}
    }
}

void  NumberToStr(deque<int>& array, char* num)
{
    if(num == nullptr)return;
    if(array.size() == 0)return;

    int index = 0;

    while(array.size())
    {
	int tmp = array[0];
	array.pop_front();

	stack<char> cur;
	
	while(tmp != 0)
	{
	    int bb = tmp%10;
	    cur.push(bb);
	    tmp = tmp/10;
	}

	while(cur.size()>0)
	{
	    int c = cur.top();
	    if(c<0 || c>9) return;
	    cur.pop();
	    num[index++] = c+48;
	}
		
    }

}


char* PrintMinNumber(int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
	return nullptr;

    
    deque<int> array;
    for(int i=0; i<length; i++)
    {
	array.push_back(numbers[i]);
    }

    sort(array.begin(), array.end(), Compare);// 从小到大



    char* num = new char[100];
    memset(num, 0, 100);
    NumberToStr(array, num);

    cout << num << endl;

    return num;
}







// 得到数字的某一位
// int GetOneOfNumber(int number, int index)
// {
//     if(number <= 0 || index < 0) return -2;
//     int array[10] = {};

//     int num_local = number;

//     int flag_counter = 0;
//     while(num_local)
//     {
//         int single_num = num_local%10;
//         array[flag_counter++] = single_num; //
//         num_local = num_local/10;
//     }

//     int return_index = flag_counter-1-index;
//     if(return_index<0 || return_index>=flag_counter)
//         return -1;
//     return array[return_index];
// }

// //在已有的字符串后面添加数字
// void NumToStr(int number, char* pStr)
// {
//     if(pStr == nullptr || number <=0)return;
//     int strlength = strlen(pStr);

//     int tmp = 0;
//     int index = 0;
//     while(1)
//     {
//         tmp = GetOneOfNumber(number, index++);
//         if(tmp == -1) break;
//         pStr[strlength++] = 48+tmp;
//     }
//     pStr[strlength] = 0;
// }

// // 如果第一位是重复的数字,那么它得重新排序
// void HandleRepeat(const int* numbers, vector<int>& index, int* result_index, int bit)
// {
//     if(numbers == nullptr || index.size()==1 || result_index == nullptr || bit < 0) return;

//     vector<int> book[10];
//     int length = index.size();
//     int numofMinus1 = 0;
//     for(int i=0; i<length; i++)
//     {
//         int tmp = GetOneOfNumber(numbers[index.back()], bit);
//         if(tmp == -1)
//         {
//             tmp = GetOneOfNumber(numbers[index.back()], 0);  // 如果-1, 证明当前位没有数，用第一位代替
//             numofMinus1++;
//         }

//         book[tmp].push_back(index.back());
//         index.pop_back();

//         if(numofMinus1 == length) //　最长的数字一应遍历完了，居然还是一样,对于Test4()就是这种情况
//         {
//             while(book[tmp].size()) // 顺序就无所谓了
//             {
//                 result_index[alredy_index++] = book[tmp].back();
//                 book[tmp].pop_back();
//             }
//             return;
//         }
//     }

//     for(int i=0; i<10; i++)
//     {
//         if(book[i].size() == 1) // 是一个直接输出
//             result_index[alredy_index++] = book[i].back();

//         if(book[i].size() > 1)// 如果当前位重复，在比较下一位
//         {
//             HandleRepeat(numbers, book[i], result_index, bit+1);
//         }
//     }
// }

// char* PrintMinNumber(int* numbers, int length)
// {
//     if(numbers == nullptr || length <= 0)
//         return nullptr;

//     int final_index[length] = {0};
//     vector<int> index;
//     for(int i=0; i<length; i++)
//     {
//         index.push_back(i);
//     }

//     HandleRepeat(numbers, index, final_index,  0);


//     char* pNum = new char[100];
//     for(int i=0; i<length; i++)
//     {
//         NumToStr(numbers[final_index[i]], pNum);
//     }
//     return pNum;
// }


//=================测试代码=====================


void Test(const char* testName, int* numbers, int length, const char* expectedResult)
{
    if(expectedResult == nullptr || numbers == nullptr || testName == nullptr)return;
    cout << testName << endl;

    char* result = PrintMinNumber(numbers, length);
    if(strcmp(result, expectedResult)==0)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
    
    cout << endl;
}

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
    alredy_index = 0;
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
    alredy_index = 0;
}

void Test3()
{
    int numbers[] = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
    alredy_index = 0;
}

void Test4()
{
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
    alredy_index = 0;
}

// 数组中只有一个数字
void Test5()
{
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
    alredy_index = 0;
}

void Test6()
{
    Test("Test6", nullptr, 0, "Don't print anything.");
    alredy_index = 0;
}

void Test7()
{
    int numbers[] = {197,321,456,1,2,3,4,54,56,7,7};
    Test("Test7",numbers, sizeof(numbers)/sizeof(int), "1197232134456545677");
    alredy_index = 0;
}



int main(int argc, char* argv[])
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

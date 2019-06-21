#include <iostream>
#include <string.h>
using namespace std;

// 翻转从start 到 end之间的字符
void Reverse(char* start, char* end)
{
    if(start == nullptr || end == nullptr)return;
    if(start>=end) return;

    char* index1 = start;
    char* index2 = end;

    while(index1 < index2)
    {
	char tmp;
	tmp = *index1;
	*index1 = *index2;
	*index2 = tmp;

	index1++;
	index2--;
    }
}


char*  LeftRotateString(char* input, int num)
{
    if(input == nullptr) return nullptr;
    if(num < 1) return input;

    char* index1 = input;
    char* index2 = input;
    while(*index2 != 0)
	index2++;

    if(num >= index2-index1) return input;

    Reverse(index1, index1+num-1); // 先翻转　start到start+num-1
    Reverse(index1+num, --index2); // 再翻转  start+num 到结束
    Reverse(index1, index2);  // 再翻转整个字符串

    return input;
}



// ====================测试代码====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
	cout << testName << " ";
    else
	return;

    char* result = LeftRotateString(input, num);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(result, expectedResult) == 0))
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

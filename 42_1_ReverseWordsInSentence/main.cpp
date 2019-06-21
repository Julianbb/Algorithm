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


char*  ReverseSentence(char* input)
{
    if(input == nullptr)return nullptr;
    int length = 0;
    char* index = input;
    while(*index!= 0)
    {
	length++;
	index++;
    }
    index--;

    Reverse(input, index);// 翻转整个句子


    char* index1 = input;
    char* index2 = input;
    while(length)
    {
	if(*index2 == ' ') // 如果遍历到当前是空格，则翻转前面的word
	{
	    char* tmp = index2-1;
	    Reverse(index1, tmp);
	    index2++;
	    index1 = index2;
	    length--;
	    continue;
	}
	index2++;  // 没有遇到空格
	length--;
    }

    Reverse(index1, index2-1); // 结束的时候还剩下最后一个单词
    return input;
}


// ====================测试代码====================
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
	cout << testName << " ";
    else
	return;

    expectedResult = ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(input, expectedResult) == 0))
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

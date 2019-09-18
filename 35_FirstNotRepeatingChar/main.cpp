#include <iostream>
#include <string.h>
using namespace std;

char FirstNotRepeatingChar(const char* p)
{
    if(p == nullptr) return '\0';
    char a[256] = {0};

    for(int i=0; i<strlen(p); i++)
    {
	a[p[i]]++;
    }

    for(int i=0; i<strlen(p); i++)
    {
	if(a[p[i]]==1)
	return p[i];
    }
    return '\0';
}














// char FirstNotRepeatingChar(const char* p)
// {
//     if(p == nullptr) return 0;
//     char array[256] = {0};
//     int length = strlen(p);

//     for(int i=0; i<length; i++)
//     {
//         array[p[i]]++;
//     }


//     for(int i=0; i<length; i++)
//     {
//         if(array[p[i]] == 1)
//             return p[i];
//     }
//     return 0;
// }



// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}

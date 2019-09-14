#include<iostream>
#include <string.h>
using namespace std;



void DFS(int step, char* string, int length, int book[], char result[])
{
    if(step == length)
    {
	for(int i=0; i<length; i++)
	{
	    cout << result[i];
	}
	cout << endl;
	return;
    }


    for(int i=0; i<length; i++)
    {
	if(book[i] == 0)
	{
	    book[i] = 1;
	    result[step] = string[i];
	    DFS(step+1, string, length, book, result);
	    book[i] = 0;
	}
    }
}





void StringPermutation(char* string, int length)
{
    if(string == nullptr || length <= 0) return;

    int book[length]={0};
    char result[length]={0};

    DFS(0, string, length, book, result);
}













// 深度优先算法
// void Dfs(int step, char* string, int length, int* book, int* a)
// {
//     if(step == length)
//     {
//         for(int i=0; i<length; i++)
//         {
//             cout << string[a[i]];
//         }
//         cout << endl;
//         return;
//     }

//     for(int i=0; i<length; i++)
//     {
//         if(book[i] == 0)
//         {
//             book[i] = 1;
//             a[step] = i;
//             Dfs(step+1, string, length, book, a);
//             book[i] = 0;
//         }
//     }
//     return;
// }

// void StringPermutation(char* string, int length)
// {
//     if(string == nullptr || length == 0 )return;

//     int book[length]={0};
//     int a[length] = {0};

//     Dfs(0, string, length, book, a);
// }
//

// void Permutation(char* string, char* pBegin)
// {
//     if(*pBegin == '\0')
//     {
//         cout << string << endl;
//         return;
//     }
//     else
//     {
//         for(char* pCh = pBegin; *pCh!='\0'; ++pCh)
//         {
//             char tmp = *pCh;
//             *pCh = *pBegin;
//             *pBegin = tmp;
//             Permutation(string, pBegin+1); //这里千万不能用++, 否则下面语句的pBegin值就变了

//             // 再进行下一次循环的时候，得保持原来的顺序,所以得再换回来
//             tmp = *pCh;
//             *pCh = *pBegin;
//             *pBegin = tmp;
//         }
//         return;
//     }
// }

// void StringPermutation(char* string, int length)
// {
//     if(string == nullptr || length == 0) return;
//     Permutation(string, string);
// }




// ============================测试代码================================

void Test(char* string, int length)
{
    if(string == nullptr)return;
    else
    {
       StringPermutation(string, length);
    }
    cout << endl;
}

int main(void)
{
	char string1[] = "";
	int tmp = strlen(string1);
	Test(string1, tmp);


	//char string2[] = {'a'};
	char string2[] = "a";
	tmp = strlen(string2);
	Test(string2, tmp);


	// char string3[] = {'a','b'};
	char string3[] = "ab";
	tmp = strlen(string3);
	Test(string3, tmp);


	// char string4[] = {'a','b','c'};
	char string4[] = "abc";
	tmp = strlen(string4);
	Test(string4, tmp);

	return 0;
}

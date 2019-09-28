/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-31 09:24
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;

class CharStatistics
{

public:
    CharStatistics():index(0)
    {
	for(int i=0; i<256; i++)
	    ch[i] = -1;
    }


    void Insert(char c)
    {
	index++;
	if(ch[c] != -1)
	{
	    ch[c] = -99;
	    return;
	}
	ch[c] = index;
    }

    char FirstAppearingOnce(void)
    {
	char firstch = 0;
	int min = 999;
	for(int i=0; i<256; i++)
	{
	    if(ch[i] >= 0)
	    {
		if(ch[i] < min)
		{
		    min = ch[i];
		    firstch = i;
		}
	    }

	}

	return firstch;
    }


private:
    int ch[256];
    int index;

};

// class CharStatistics
// {
// public:
//      CharStatistics():index(0)
//     {
//         for(int i=0; i<256; i++)
//             occurrence[i] = 0;
//     }

//     char FirstAppearingOnce()
//     {
//         int min = 999;
//         char ch = 0;

//         for(int i=0; i<256; i++)
//         {
//             if(occurrence[i]>0 && occurrence[i]<min)
//             {
//                 min = occurrence[i];
//                 ch = i;
//             }
//         }
//         return ch;
//     }

//     void Insert(char ch)
//     {
//         if(occurrence[ch] > 0 || occurrence[ch] < 0 )
//            occurrence[ch] = -1;
//         else
//         {
//             index++;
//             occurrence[ch] = index;
//         }

//     }

// private:
//     int occurrence[256];
//     int index;
// };




// ==================== Test Code ====================
void Test(const char* testName, CharStatistics& chars, char expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

	return 0;
}

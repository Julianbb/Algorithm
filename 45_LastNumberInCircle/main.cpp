/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-19 17:28
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <list>
#include <stdio.h>
#include "../Utilities/List.h"
using namespace std;


ListNode* CreatList(int n)
{  
    ListNode* head = CreateListNode(0);
    ListNode* tmp = head;


    for(int i=1; i<n; i++)
    {
        ListNode* current = CreateListNode(i);
        tmp->m_pNext = current;
        tmp = current;
    }

    tmp->m_pNext = head;
    return head;
}




int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if(n == 1) return 0;
    if(n <=0 ) return -1;
    if(m <=0 ) return -1;

    int size = n;


    ListNode* pMy = CreatList(n);
    
    while(size>1)
    {
        int tmp = m-1;
        while(--tmp)
        {
            pMy = pMy->m_pNext;
        }
        ListNode* pdelet = pMy->m_pNext;
        
        pMy->m_pNext = pMy->m_pNext->m_pNext;//删除结点
        delete pdelet;
        pdelet->m_pNext = nullptr;

        size--;    
        pMy = pMy->m_pNext; //定位到下次开始处  
    }

    return pMy->m_Value;

    // list<unsigned int> array;
    // for(int i=0; i<n; i++)
    // {
	//     array.push_back(i);
    // }

    // auto it_c = array.begin(); 
    // while(array.size() > 1)
    // {
    //     int tmp = m;
    //     while(--tmp)
    //     {
    //         it_c++;
    //         if(it_c == array.end())
    //             it_c = array.begin(); 
            
    //     }
    
    //     it_c = array.erase(it_c);
    // }
    // return array.front();




}



int LastRemaining_Solution2(unsigned int n, unsigned int m)
{

    if(n < 1 || m < 1)
    return -1;

    int last = 0;
    for (int i = 2; i <= n; i ++)
        last = (last + m) % i;

    return last;
}


// ====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(LastRemaining_Solution1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
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

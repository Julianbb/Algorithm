/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-28 09:13
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int GetSum(int x, int y)
{
    int sum1 = 0;
    int sum2 = 0;
    while(x > 0)
    {
	sum1 += x%10;
	x = x/10;
    }
    while( y > 0 )
    {
	sum2 += y%10;
	y = y/10;
    }
    return sum1+sum2;
}


int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void DFS(int threshold, int rows, int cols, int x, int y, int& count, int* book)
{
    count++;

    for(int i=0; i<4; i++)
    {
        x += dir[i][0];
        y += dir[i][1];

        if(x>=0 && y>=0 && x<rows && y<cols && (*(book+x*cols+y)== 0))
        {
            if(GetSum(x, y) <= threshold)
            {
                *(book+x*cols+y) = 1;
                DFS(threshold, rows, cols, x, y, count, book);
            }
        }       
        x -= dir[i][0];
        y -= dir[i][1];        
    }
}



int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <= 0 || cols <=0) return 0;

    int i=0, j=0;

    int book[rows][cols];
    memset(book, 0, sizeof(book));
    int count = 0;
    
    book[0][0] = 1;
    DFS(threshold, rows, cols, 0, 0, count, *book);

    return count;

}







// ================================ test code ================================
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void test1()
{
    test("Test1", 5, 10, 10, 21);
}

void test2()
{
    test("Test2", 15, 20, 20, 359);
}

void test3() 
{
    test("Test3", 10, 1, 100, 29);
}

void test4() 
{
    test("Test4", 10, 1, 10, 10);
}

void test5()
{
    test("Test5", 15, 100, 1, 79);
}

void test6()
{
    test("Test6", 15, 10, 1, 10);
}

void test7()
{
    test("Test7", 15, 1, 1, 1);
}

void test8()
{
    test("Test8", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}

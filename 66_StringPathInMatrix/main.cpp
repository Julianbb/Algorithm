/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-27 09:51
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <string.h>
using namespace std;

int dir[4][2] = {{0,1},{1,0},{0, -1},{-1,0}};


bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, int* book, char* my_str, int step)
{
    bool ret = false;

    char c = *(matrix+row*cols+col);
    my_str[step] = c ;

    if(step+1 == strlen(str))
    {
        my_str[step+1]='\0';
	    if(strcmp(my_str, str) == 0)
	        return true;
        else 
            return false;       
    }


    for(int i=0; i<4; i++)
    {
        row += dir[i][0];
        col += dir[i][1];

        if(row < 0 || row >= rows || col<0 || col >= cols)
        {
            row -= dir[i][0];
            col -= dir[i][1];
            continue;
        }
            

        if(*(book+row*cols+col) == 0)
        {
            *(book+row*cols+col) = 1;
            ret = ret || hasPathCore(matrix, rows, cols, row, col, str, book, my_str, step+1);            
            *(book+row*cols+col) = 0;                   
        }
        row -= dir[i][0];
        col -= dir[i][1];
                        
    }
    return ret;
}



bool hasPath(char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || str == nullptr) return false;
    bool result = false;


    int start_pos[2][rows*cols];
    memset(start_pos, 0, sizeof(start_pos));

    int col = 0 ;
    int row = 0 ;
    int index = 0;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(*(matrix+i*cols+j) == str[0])
            {
                start_pos[0][index] = i;
                start_pos[1][index] = j;   
                index++;                                 
            }
        }
    }

    for(int i=0; i<index; i++)
    {
        row = start_pos[0][i];
        col = start_pos[1][i];

        int book[rows][cols];
        memset(book, 0, sizeof(book));
        char my_str[rows*cols];
        memset(my_str, 0, sizeof(my_str));

        book[row][col] = 1;
        result  = result || hasPathCore(matrix, rows, cols, row, col, str, *book, my_str, 0);
    }

    return result;
}







//==============================测试代码======================================

void Test(const char* testName, char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABCE
//SFCS
//ADEE

//ABCCED
void Test1()
{
    char matrix[] = "ABCESFCSADEE";
    const char* str = "ABCCED";

    Test("Test1", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    char matrix[] = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//ABCB
void Test3()
{
    char matrix[] = "ABCESFCSADEE";
    const char* str = "ABCB";

    Test("Test3", (char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    char matrix[] = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    char matrix[] = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    char matrix[] = "A";
    const char* str = "A";

    Test("Test10", (char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    char matrix[] = "A";
    const char* str = "B";

    Test("Test11", (char*)matrix, 1, 1, str, false);
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
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}

#include <iostream>
using namespace std;



//传递的数组是[100][100] ,flag是原点的标志位，0代表(0,0), 1:(1,1), 2:(2,2)
void PrintArray_Clockwise(int* array, int rows, int cols, int flag=0)
{
    if(array == nullptr || rows <= 0 || cols <=0 )
	return;

    int flag_ud = 0; // 左右移动的标志位，1:向左，0:代表不动，-1:代表向右
    int flag_lr = 1; // 上下移动的标志位, 1:向下，0:代表不动，-1:代表向上

    int i =0; //数组索引,行
    int j =0;

    int tmp = array[(i+flag)*100+(j+flag)];//第一个元素
    cout << tmp << " ";
    
    while(1)
    {
	if(flag_lr == 1) //向右
	{
	    j++;
	    if(j==cols)
	    {
		if(rows == 1) //防止只有一行情况
		    break;
		j--;
		flag_lr = 0;
		flag_ud = 1;
	    }
	}
	if(flag_ud == 1) //向下
	{
	    i++;
	    if(i == rows)
	    {
		if(cols == 1)//防止一列的情况
		    break;
		i--;
		flag_ud = 0;
		flag_lr = -1;
	    }
	}
	if(flag_lr == -1) //向左 
	{
	    j--;
	    if(j == -1)
	    {
		j++;
		flag_lr = 0;
		flag_ud = -1;
	    }
	}
	if(flag_ud == -1) //向上
	{
	    i--;
	    if(i == -1)
	    {
		i++;
		flag_ud = 0;
		flag_lr = 1;
	    }
	}

	if(i==0 && j==0) //回到原点
	    break;
	else
	cout << array[(i+flag)*100+(j+flag)] << " ";
    }
    
       flag++; //原点往右下角移动１
       PrintArray_Clockwise(array, rows-2, cols-2, flag); //递归调用
}





//======================测试代码========================

void Print2DArray(int* array, int rows, int cols)
{
    if(array == nullptr || rows <= 0 || cols <=0 )
	return;

    for(int i=0; i<rows; i++)
    {
	for(int j=0; j<cols; j++)
	{
	    int tmp = array[i*100+j];
	    cout << tmp << " ";
	    
	}
	    cout << endl;
    }
}



//1*1
void Test1()
{
    int array[100][100] = {1};
    Print2DArray(*array, 1, 1);
    cout << endl;
    PrintArray_Clockwise(*array, 1, 1);
    cout << endl;
    cout << endl;
}



//2*2
void Test2()
{
    int array[100][100] = {0};
    int num = 0;
    for(int i=0; i<2; i++)
    {
	for(int j=0; j<2; j++)
	{
	    array[i][j] = ++num;
	}
    }
    Print2DArray(*array, 2, 2);
    cout << endl;
    PrintArray_Clockwise(*array, 2, 2);
    cout << endl;
    cout << endl;
    
}


//3*3
void Test3()
{
    int array[100][100] = {0};
    int num = 0;
    for(int i=0; i<3; i++)
    {
	for(int j=0; j<3; j++)
	{
	    array[i][j] = ++num;
	}
    }

    Print2DArray(*array, 3, 3);
    cout << endl;
    PrintArray_Clockwise(*array, 3, 3);
    cout << endl;
    cout << endl;
}


// 4*4
void Test4()
{
    int array[100][100] = {0};
    int num = 0;
    for(int i=0; i<4; i++)
    {
	for(int j=0; j<4; j++)
	{
	    array[i][j] = ++num;
	}
    }
    Print2DArray(*array, 4, 4);
    cout << endl;
    PrintArray_Clockwise(*array, 4, 4);
    cout << endl;
    cout << endl;
}


// 4*3
void Test5()
{
    int array[100][100]={0};
    int num = 0;
    for(int i=0; i<4; i++)
    {
	for(int j=0; j<3; j++)
	{
	    array[i][j] = ++num;
	}
    }
    Print2DArray(*array, 4, 3);
    cout << endl;
    PrintArray_Clockwise(*array, 4, 3);
    cout << endl;
    cout << endl;
}

//1*10
void Test6()
{
    int array[100][100]={0};
    int num = 0;
    for(int i=0; i<1; i++)
    {
	for(int j=0; j<10; j++)
	{
	    array[i][j] = ++num;
	}
    }
    Print2DArray(*array, 1, 10);
    cout << endl;
    PrintArray_Clockwise(*array, 1, 10);
    cout << endl;
    cout << endl;
}

// 10*1
void Test7()
{
    int array[100][100]={0};
    int num = 0;
    for(int i=0; i<10; i++)
    {
	for(int j=0; j<1; j++)
	{
	    array[i][j] = ++num;
	}
    }
    Print2DArray(*array, 10, 1);
    cout << endl;
    PrintArray_Clockwise(*array, 10, 1);
    cout << endl;
    cout << endl;
}

// 0*0
void Test8()
{
    int array[100][100]={0};
    Print2DArray(*array, 0, 0);
    cout << endl;
    PrintArray_Clockwise(*array, 0, 0);
    cout << endl;
    cout << endl;

}


int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    return 0;
}


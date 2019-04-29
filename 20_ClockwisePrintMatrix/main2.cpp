#include <iostream>
using namespace std;




void PrintArray_Clockwise(int* array, int rows, int cols)
{
    if(array == nullptr || rows <= 0 || cols <=0 )
	return;

    

    PrintArray_Clockwise(array+i*100+j, )

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

    cout << endl;
}



//1*1
void Test1()
{
    int array[100][100] = {1};
    Print2DArray(*array, 1, 1);
    PrintArray_Clockwise(*array, 1, 1);
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
    PrintArray_Clockwise(*array, 2, 2);

    
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
    PrintArray_Clockwise(*array, 3, 3);
    
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
    PrintArray_Clockwise(*array, 4, 4);
}




int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}


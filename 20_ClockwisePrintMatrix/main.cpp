#include <iostream>
using namespace std;




void PrintArray_Clockwise(int* array, int rows, int cols)
{
    if(array == nullptr || rows <= 0 || cols <= 0)
	return;
    int total = rows*cols;
    int tmp_cols = cols;
    int tmp_rows = rows;

    int i = 0;
    int j = 0;
    int flag_lr = 1;
    int flag_ud = 0;
    tmp = array[0][0];
    cout << tmp " " << endl;

    while(total>0)
    {
	if(flag_lr == 1)
	{
	    j++;
	    if(j==tmp_cols-1)
	    {
		flag_lr =0;
		flag_ud == 1;
	    }
		
	    
	}
	if(flag_lr == -1)
	{
	    j--;
	    if(j == 0)
	    {
		flag_lr =0;
		flag_ud == -1;
	    }
	}


	if(flag_ud == 1)
	{
	    i++;
	    if(i == rows-1)
	    {
		flag_ud = 0;
		flag_lr = -1;
	    }
	}
	if(flag_ud == -1)
	{
	    i--;
	    if(i == 0)
	    {
		flag_ud = 0;
		flag_lr = 1;
	    }
	}


	if(array[i*rows+j] == tmp)
	{
	    i++;
	    j++;
	    tmp = array[i*rows+j];
	}
	cout << array[i*rows+j] << " " ;
	total--;
    }
    
    cout << endl;
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
	    int tmp = array[i*rows+j];
	    cout << tmp << " ";
	    
	}
	    cout << endl;
    }

    cout << endl;
}



//1*1
void Test1()
{
    int array[1][1] = {1};
    Print2DArray(*array, 1, 1);
    PrintArray_Clockwise(*array, 1, 1);
}



//2*2
void Test2()
{
    int array[2][2] = {1,2,3,4};
    Print2DArray(*array, 2, 2);
    PrintArray_Clockwise(*array, 2, 2);

    
}


//3*3
void Test3()
{
    int array[3][3] = {1,2,3,4,5,6,7,8,9};
    Print2DArray(*array, 3, 3);
    PrintArray_Clockwise(*array, 3, 3);
    
}


// 4*4
void Test4()
{
    int array[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
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

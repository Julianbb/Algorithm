#include <iostream>
using namespace std; 



void ReOrderArray(int* array, int length)
{
    if(array == nullptr || length <= 0)
	return ;

    int front=0, end=length-1;
    while(front < end)
    {
	while((array[front] & 0x01) && front < end ) //odd number
	    front++;

	while(((array[end] & 0x01) == 0) && front < end) // even number 
	    end--;

	if(front < end)
	{
	    int tmp = array[front];
	    array[front] = array[end];
	    array[end] = tmp;
	}
    }
}




// void ReOrderArray(int* array, int length)
// {
//     if(array == nullptr || length<=1) return;

//     int p1 = 0;
//     int p2 = length-1;

//     while(p1 < p2)
//     {
//         while(array[p1]%2 == 1)
//             p1++;
//         while(array[p2]%2 == 0)
//             p2--;

//         if(p1<p2)
//         {
//             int tmp = array[p1];
//             array[p1] = array[p2];
//             array[p2] = tmp;
//         }
//     }
// }


void PrintArray(int* array, int length)
{
    for(int i=0; i<length; i++)
    {
	cout << array[i] << " " ;
    }
    cout << endl;

}

void Test1(void)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(array)/sizeof(array[1]);
    cout << "before reorder: ";
    PrintArray(array, length);

    ReOrderArray(array, 10);

    cout << "after  reorder: ";
    PrintArray(array, length);

}


int main(void)
{

    Test1();


    return 0;
}

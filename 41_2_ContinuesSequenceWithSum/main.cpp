#include <iostream>
using namespace std;

void MyPrint(int index1, int index2)
{
    if(index1>=index2)return;
    for(int i=index1; i<=index2; i++)
    {
	cout << i << " ";
    }
    cout << endl;
}

void FindContinuousSequence(int sum)
{
    if(sum <=1 )return;
    int p1=1;
    int p2=2;
    int tmp_sum=p1+p2;


    int index_flag = sum/2;
    while(p1<p2 && p1<=index_flag && p2<sum)
    {
	if(tmp_sum == sum)
	{
	    MyPrint(p1, p2);

	    p2++;
	    tmp_sum += p2;
	    continue;
	}
	else if(tmp_sum < sum)
	{
	    p2++;
	    tmp_sum += p2;
	}
	else
	{
	    tmp_sum -= p1;
	    p1++;
	}
    }


}






// void FindContinuousSequence(int sum)
// {
//     if(sum <= 1)return;

//     int index1 = 1;
//     int index2 = 2;
//     int sum_tmp = 3;

//     while(index1<index2)
//     {
//         while(sum_tmp != sum)
//         {
//             if(sum_tmp < sum)
//             {
//                 index2++;
//                 sum_tmp += index2;
//             }
//             if(sum_tmp > sum)
//             {
//                sum_tmp -= index1;
//                index1++;
//             }
//             if(index1==index2)
//                 break;
//         }
//         if(sum_tmp == sum)
//         {
//             Myprint(index1, index2);
//             index2++;
//             sum_tmp += index2;
//         }
//     }

// }



// ====================测试代码====================



void Test(const char* testName, int sum)
{
    if(testName != nullptr)
	cout << testName << " " << sum << endl;

    FindContinuousSequence(sum);
    cout << endl;
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}

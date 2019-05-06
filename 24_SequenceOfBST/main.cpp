#include <iostream>
using namespace std;


bool VerifySequenceOfBST(int sequence[], int length)
{



}







// ===============================测试代码================================

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16

void Test1(void)
{
    int data[] = {4,8,6,12,16,14,10};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == true)
	cout << " Test1 passed "<< endl;
    else
	cout << "Test1 failed" << endl;
}


//           5
//          / \
//         4   7
//            /
//           6
void Test2(void)
{
    int data[] = {4,6,7,5};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == true)
	cout << " Test2 passed "<< endl;
    else
	cout << "Test2 failed" << endl;

}



//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3(void)
{
    int data[] = {1,2,3,4,5};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == true)
	cout << " Test3 passed "<< endl;
    else
	cout << "Test3 failed" << endl;
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5

void Test4(void)
{
    int data[] = {5,4,3,2,1};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == true)
	cout << " Test4 passed "<< endl;
    else
	cout << "Test4 failed" << endl;
   
}

//只有一个结点
void Test5(void)
{
    int data[] = {5};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == true)
	cout << " Test5 passed "<< endl;
    else
	cout << "Test5 failed" << endl;
}


// 反例
void Test6(void)
{
    int data[] = {7,4,6,5};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == false)
	cout << " Test6 passed "<< endl;
    else
	cout << "Test6 failed" << endl;

}


void Test7(void)
{
    int data[] = {4,6,12,8,16,14,10};
    bool flag = VerifySequenceOfBST(data, sizeof(data)/sizeof(data[0]));
    if(flag == false)
	cout << " Test7 passed "<< endl;
    else
	cout << "Test7 failed" << endl;

}


void Test8(void)
{
    bool flag = VerifySequenceOfBST(nullptr, 0);
    if(flag == false)
	cout << " Test8 passed "<< endl;
    else
	cout << "Test8 failed" << endl;

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

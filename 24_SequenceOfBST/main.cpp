#include <iostream>
using namespace std;


bool VerifySequenceOfBST(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0) return false;
    if(length == 1) return true;

    int root = sequence[length-1];

    int Left = 0,  Right = 0;
    for(int i=0; i<length-1; i++)
    {
	if(sequence[i] > root)
	{
	    Left = i-1;
	    Right = i;
	    break;
	}
    }

    if(Right  == 0) //前面的数＜root,  也有可能第一个数>root
    {
	if(sequence[0] < root) // 前面所有数< root
	{
	    Left = length-2;
	    return VerifySequenceOfBST(sequence, Left+1); // 前面都是左子树
	}
	else // 第一个数 > root
	{
	    for(int i=Right; i<length-1; i++) // 判断如果后面有< root 则报错
	    {
		if(sequence[i] < root)
		{
		    return false;
		}
	    }

	    return VerifySequenceOfBST(sequence+Right, length-Right-1); // 前面都是右子树
	}
    }


    for(int i=Right; i<length-1; i++) // 分界点在中间，则判断后面的点都 > root
    {
	if(sequence[i] < root)
	{
	    return false;
	}
    }

    return VerifySequenceOfBST(sequence, Left+1) && VerifySequenceOfBST(sequence+Right, length-Right-1);


}
















// bool verifysequenceofbst(int sequence[], int length)
// {
//         if(sequence == nullptr || length<=0) return false;
//         if(length == 1) return true; // 如果只有一个，直接返回true

//         int tmp_root = sequence[length-1];
//         int index =0;
//         while(index<length-1) // 找到第一个 > tmp_root的 index
//         {
//                 if(sequence[index]<tmp_root)
//                         index++;
//                 else
//                         break;
//         }
//         int tmp = index;
//         while(tmp<length-1) // 遍历index 之后的，如果符合要求，后面应该都>tmp_root
//         {
//                 if(sequence[tmp] < tmp_root) // 如果index之后还有< tmp_root，直接返回false
//                         return false;
//                 else
//                         tmp++;
//         }

//         bool result = true;

//         if(index!=0) // 很重要，if(index == 0),执行的时候直接返回false, 但是有可能符合要求的
//         result = VerifySequenceOfBST(sequence, index); // 递归处理前半部分

//         if(length-index-1 != 0)
//         result = VerifySequenceOfBST(sequence+index, length-index-1); //递归处理后半部分

//         return result;
// }



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

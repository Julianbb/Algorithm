#include <iostream>
#include<stack>
using namespace std;





bool IsPopOrder(const int* pPush, const int* pPop, int length)
{
    if(pPush == nullptr || pPop == nullptr || length <=0) return false;
    int index = 0;

    stack<int> stack_help;
    stack_help.push(pPush[0]);
    index++;

    for(int i=0; i<length; i++) // 处理每个弹出序列
    {
	while(pPop[i] != stack_help.top()) // 只要不等就 push
	{
	    if(index == length) // 已经没有数据再push了
	    {
		return false;
	    }
	    stack_help.push(pPush[index]);
	    index++;
	    
	}
	stack_help.pop();
    }
    return true;
}





















// bool IsPopOrder(const int* pPush, const int* pPop, int length)
// {
//     if(pPop == nullptr || pPush == nullptr || length <= 0) return false;

//     stack<int> stack_help;
//     int push_index = 0;
//     stack_help.push(pPush[push_index]); //先压第一个元素

//     for(int i=0; i<length; i++) // 从弹出序列从前往后逐一处理
//     {
//         while(1)
//         {
//             int tmp = stack_help.top();
//             if(tmp == pPop[i]) //如果辅助栈的顶　==  弹出序列当前元素
//             {
//                 stack_help.pop(); // 弹出辅助栈顶
//                 break;  //该下一个弹出序列的元素
//             }
//             else // 如果辅助栈的顶　!= 弹出序列当前元素
//             {
//                 push_index++;
//                 if(push_index>=length)
//                     return false;
//                 stack_help.push(pPush[push_index]);  // 只要压入序列还有，将剩下元素继续往后压栈
//             }
//         }

//     }

//     if(stack_help.empty())
//         return true;
//     else
//         return false;
// }





// =========================测试代码==========================
void Test(const char* test, const int* pPush, const int* pPop, int length,  bool expected)
{
    if(test != nullptr)
	cout << test << " ";
    if(IsPopOrder(pPush, pPop, length) == expected)
	cout << "passed" << endl;
    else
	cout << "failed" << endl;
}


void Test1(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] =  {4, 5, 3, 2, 1};
    Test("Test1", push, pop, length, true);

}

void Test2(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {3, 5, 4, 2, 1};
    Test("Test2", push, pop, length, true);

}

void Test3(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 3, 5, 1, 2};
    Test("Test3", push, pop, length, false);

}

void Test4(void)
{
    const int length = 5;
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {3, 5, 4, 1, 2};
    Test("Test4", push, pop, length, false);

}

void Test5(void)
{
    const int length = 1;
    int push[] = {1};
    int pop[] =  {2};
    Test("Test5", push, pop, length, false);

}

void Test6(void)
{
    const int length = 1;
    int push[] = {1};
    int pop[] = {1};
    Test("Test6", push, pop, length, true);

}

void Test7(void)
{
    Test("Test7", nullptr, nullptr, 0, false);

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

    return 0;
}

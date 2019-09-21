/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-08-03 10:32
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <vector>
#include <stack>
#include "../Utilities/BinaryTree.h"
using namespace std;


void Print(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr) return;

    int flag = 1;
    BinaryTreeNode* node = pRoot;
    stack<BinaryTreeNode*> array[2];
    array[flag%2].push(node);

    int cur = 1;
    int next = 0;

    while(array[0].size() > 0 || array[1].size() > 0)
    {
	
	BinaryTreeNode* p = array[flag%2].top();
	array[flag%2].pop();
	cout << p->m_nValue << " " ;
	cur--;

	if(flag % 2 == 1)
	{
	    if(p->m_pLeft != nullptr) 
	    {
		array[(flag+1)%2].push(p->m_pLeft);
		next++;
	    }
	    if(p->m_pRight != nullptr)
	    {
		array[(flag+1)%2].push(p->m_pRight);
		next++;
	    }
	}
	else
	{
	    if(p->m_pRight != nullptr)
	    {
		array[(flag+1)%2].push(p->m_pRight);
		next++;
	    }
	    if(p->m_pLeft != nullptr) 
	    {
		array[(flag+1)%2].push(p->m_pLeft);
		next++;
	    }
	}
	
	if(cur == 0)
	{
	    cur = next;
	    next = 0;
	    flag++;
	    cout << endl;
	}
    }

}


// Myself
//
// void Sub_Print(vector<BinaryTreeNode*> array, int* num)
// {
//     int index = 0;
//     int step = 0;

//     int fromRL_flag = 0;

//     while(num[index] != 0)
//     {
//         if(fromRL_flag % 2 == 0)
//         {
//             for(int i=0; i<num[index]; i++)
//             {
//                 cout << array[i+step]->m_nValue << "  ";
//             }
//         }
//         else
//         {
//             for(int i=num[index]-1; i>=0; i--)
//             {
//                 cout << array[i+step]->m_nValue << "  ";
//             }
//         }

//         step += num[index];
//         cout << endl;
//         index++;
//         fromRL_flag++;
//     }
// }


// void Print(BinaryTreeNode* pRoot)
// {
//     if(pRoot == nullptr) return;
//     vector<BinaryTreeNode*> Array;
//     int num[100] = {0};


//     num[0] = 1; // 一层里结点的数量
//     Array.push_back(pRoot);
//     int index = 0; // 层


//     int step = 0; //当前遍历到的结点　

//     while(num[index] != 0)
//     {
//         int tmp = index;
//         index++;
//         for(int i=0; i<num[tmp]; i++) // 遍历当前层每个结点，有子节点就放在Array后面,同时更新当前层结点数
//         {
//             if(Array[step]->m_pLeft != nullptr)
//             {
//                 Array.push_back(Array[step]->m_pLeft);
//                 num[index]++;
//             }
//             if(Array[step]->m_pRight != nullptr)
//             {
//                 Array.push_back(Array[step]->m_pRight);
//                 num[index]++;
//             }
//             step++;
//         }
//     }

//     Sub_Print(Array, num); // 打印
// }


// thought from Offer
// void Print(BinaryTreeNode* pRoot)
// {
//     if(pRoot == nullptr)
//         return;

//     stack<BinaryTreeNode*> s[2];

//     int flag = 0;
//     int tmp = 0;

//     cout << pRoot->m_nValue << endl;
//     if(pRoot->m_pLeft != nullptr) s[0].push(pRoot->m_pLeft);
//     if(pRoot->m_pRight != nullptr) s[0].push(pRoot->m_pRight);


//     while(s[tmp].size()!=0)
//     {
//         int size = s[tmp].size();
//         for(int i=0; i<size; i++)
//         {
//             BinaryTreeNode* node = s[tmp].top();
//             s[tmp].pop();
//             cout << node->m_nValue << " " ;

//             if(tmp == 0)
//             {
//                 if(node->m_pRight != nullptr)
//                 s[tmp+1].push(node->m_pRight);

//                 if(node->m_pLeft != nullptr)
//                 s[tmp+1].push(node->m_pLeft);
//             }
//             else
//             {
//                 if(node->m_pLeft != nullptr)
//                 s[tmp-1].push(node->m_pLeft);

//                 if(node->m_pRight != nullptr)
//                 s[tmp-1].push(node->m_pRight);

//             }
//         }
//         flag++;
//         tmp = flag%2;
//         cout << endl;
//     }

// }


//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    Print(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    Print(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    Print(NULL);
    printf("\n");
}

//        100
//        /
//       50
//         \
//         150
void Test6()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, NULL);
    ConnectTreeNodes(pNode50, NULL, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    Print(pNode100);
    printf("\n");
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);
    BinaryTreeNode* pNode15 = CreateBinaryTreeNode(15);

    ConnectTreeNodes(pNode8, pNode4, pNode12);
    ConnectTreeNodes(pNode4, pNode2, pNode6);
    ConnectTreeNodes(pNode12, pNode10, pNode14);
    ConnectTreeNodes(pNode2, pNode1, pNode3);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    ConnectTreeNodes(pNode14, pNode13, pNode15);

    printf("====Test7 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("12 4 \n");
    printf("2 6 10 14 \n");
    printf("15 13 11 9 7 5 3 1 \n\n");

    printf("Actual Result is: \n");
    Print(pNode8);
    printf("\n");

    DestroyTree(pNode8);
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

	return 0;
}

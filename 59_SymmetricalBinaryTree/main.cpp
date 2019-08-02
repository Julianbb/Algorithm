/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-08-02 09:17
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
#include "../Utilities/BinaryTree.h"
#include <vector>
#include <stack>
#include <deque>
using namespace std;


void GetMidOrder(BinaryTreeNode* pRoot, deque<BinaryTreeNode*>& result, int* num)
{

    if(pRoot->m_pRight == nullptr && pRoot->m_pLeft== nullptr)
    {
        result.push_back(pRoot);
        (*num)++;
        return;
    }

	if(pRoot->m_pLeft == nullptr) 
    {
        (*num)++;
        result.push_back(nullptr); 
 
    }

    if(pRoot->m_pLeft != nullptr)
    GetMidOrder(pRoot->m_pLeft, result, num);



    result.push_back(pRoot);
    (*num)++;



    if(pRoot->m_pRight == nullptr) 
    {
        (*num)++;
        result.push_back(nullptr);
        return;
    }  
    GetMidOrder(pRoot->m_pRight, result, num);
}


bool isSymmetrical(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr) return true;
    
    deque<BinaryTreeNode*> array_tree;
    int number = 0;

    GetMidOrder(pRoot, array_tree, &number);

    int mid = number>>1;

    stack<BinaryTreeNode*> stack_tree;

    for(int i=0; i<mid; i++)
    {
        BinaryTreeNode* node = array_tree.front();
        array_tree.pop_front();
        stack_tree.push(node);
    }

    array_tree.pop_front(); //把中间的pop出去

    for(int i=0; i<mid; i++)
    {
        BinaryTreeNode* node = stack_tree.top();
        stack_tree.pop();

        if(node == nullptr && array_tree[i] == nullptr) 
            continue;
        
        if(node == nullptr || array_tree[i] == nullptr)
        {
            return false;
        }
        if(node->m_nValue != array_tree[i]->m_nValue)
        {
            return false;
        }
    }

    return true;

}



// ==================== Test Code ====================
void Test(const char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isSymmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode9);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, NULL);

    Test("Test3", pNode8, false);

    DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test4", pNode5, true);

    DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode6, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode6, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test5", pNode5, false);

    DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, NULL, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

// Only one node
void Test7()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test7", pNode1, true);

    DestroyTree(pNode1);
}

// No nodes
void Test8()
{
    Test("Test8", NULL, true);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test9", pNode1, true);

    DestroyTree(pNode1);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, pNode42, NULL);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test10", pNode1, false);

    DestroyTree(pNode1);
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

    return 0;
}

#include <iostream>
#include "../Utilities/BinaryTree.h"
#include <string.h>
#include <queue>
using namespace std;


int* PrintTree_TopToBottom(BinaryTreeNode* root)
{
    if(root == nullptr )return nullptr;
    
    int* result = new int[100];
    memset(result, 0, 4*100);
    int index =0;

    queue<BinaryTreeNode*> array;
    array.push(root);

    while(array.size() > 0)
    {
	BinaryTreeNode* tmp = array.front();
	array.pop();

	if(tmp != nullptr)
	    result[index++] = tmp->m_nValue;
	else
	    continue;


	array.push(tmp->m_pLeft);
	array.push(tmp->m_pRight);
    }

    return result;

}

// int* PrintTree_TopToBottom(BinaryTreeNode* root)
// {
//     if(root == nullptr) return nullptr;
//     int* result = new int[100];
//     int index =0;
//     queue<BinaryTreeNode*> queue_tree;
//     queue_tree.push(root);
//     while(!queue_tree.empty())
//     {
//         BinaryTreeNode* root_tmp = queue_tree.front();
//         result[index++] = root_tmp->m_nValue;
//         BinaryTreeNode* left = root_tmp->m_pLeft;
//         BinaryTreeNode* right = root_tmp->m_pRight;
//         queue_tree.pop();

//         if(left != nullptr)
//             queue_tree.push(left);
//         if(right != nullptr)
//             queue_tree.push(right);
//     }
//     return result;
// }



// ================测试代码==========================

bool IsArrayEqual(int* array1, int* array2, int length)
{
    if(array1 == nullptr || array2 == nullptr || length<=0) return false;

    for(int i=0; i<length; i++)
    {
	if(array1[i]!=array2[i])
	    return false;
    }
    return true;
}



//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16


void Test1(void)
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);


    int expected[] = {10,6,14,4,8,12,16};
    int* result =PrintTree_TopToBottom(pNode10);
    if(IsArrayEqual(expected, result, 7))
	cout << "Test1 passed" << endl;
    else
	cout << "Test1 failed" << endl;
    DestroyTree(pNode10);
    delete result;
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


void Test2(void)
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    int expected[] = {5,4,3,2,1};
    int* result =PrintTree_TopToBottom(pNode5);
    if(IsArrayEqual(expected, result, 5))
	cout << "Test2 passed" << endl;
    else
	cout << "Test2 failed" << endl;
    DestroyTree(pNode5);
    delete result;

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

void Test3(void)
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);
    
    int expected[] = {1,2,3,4,5};
    int* result =PrintTree_TopToBottom(pNode1);
    if(IsArrayEqual(expected, result, 5))
	cout << "Test3 passed" << endl;
    else
	cout << "Test3 failed" << endl;
    DestroyTree(pNode1);

    delete result;

}

//一个结点
void Test4(void)
{
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    int expected[] = {1};
    int* result = PrintTree_TopToBottom(node1);
    if(IsArrayEqual(expected, result, 1))
	cout << "Test4 passed" << endl;
    else
	cout << "Test4 failed" << endl;
    DestroyTree(node1);
    delete result;
}


// nullptr

void Test5(void)
{
    int* result = PrintTree_TopToBottom(nullptr);
    if(result == nullptr)
	cout << "Test5 passed" << endl;
    else
	cout << "Test5 failed" << endl;

}


int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

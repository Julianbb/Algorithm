/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-22 22:08
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
#include <list>
#include "../Utilities/BinaryTree.h"
#include <vector>


using namespace std;




void  GetPath( BinaryTreeNode* pRoot,  const BinaryTreeNode* pNode, vector<BinaryTreeNode*>& path, int& find_flag)
{
    if(pRoot == nullptr || pNode == nullptr) return;
    
    
    
    if(pRoot == pNode)
    {
	path.push_back(pRoot);
	find_flag = 1;
	return;
    }
    

    path.push_back(pRoot);

    GetPath(pRoot->m_pLeft, pNode, path, find_flag);
    if(find_flag == 1) return;


    GetPath(pRoot->m_pRight, pNode, path, find_flag);
    if(find_flag == 1) return;

	path.pop_back();

}




BinaryTreeNode* GetLastCommonParent( BinaryTreeNode* pRoot,  const BinaryTreeNode* pNode1,  const BinaryTreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr) return nullptr;

    vector<BinaryTreeNode*> path1;
    vector<BinaryTreeNode*> path2;

    int find_flag = 0;
    GetPath(pRoot, pNode1, path1, find_flag);
    find_flag = 0;
    GetPath(pRoot, pNode2, path2, find_flag);

    BinaryTreeNode* LastParent = nullptr;

    auto it1 = path1.begin();
    auto it2 = path2.begin();
    while(it1 != path1.end()&& it2 != path2.end())
    {
        if(*it1 == *it2)
        {
            LastParent = *it1;
        }
        it1++;
        it2++;
        if((next(it1)) == path1.end() || (next(it2))==path2.end())
        break;
    }

return LastParent;

}

// bool GetNodePath( const TreeNode* pRoot,  const TreeNode* pNode,  list<const TreeNode*>& path)
// {
//     if(pRoot == nullptr || pNode == nullptr)
//         return false;

//     if(pRoot == pNode)
//     {
//         return true;
//     }

//     path.push_back(pRoot);

//     bool found = false;
//     vector<TreeNode*>::const_iterator it = pRoot->m_vChildren.begin();
//     while(!found && it<pRoot->m_vChildren.end())
//     {
//         found = GetNodePath(*it, pNode, path);
//         it++;
//     }
//     if(!found)
//         path.pop_back();

//     return found;
// }


// const TreeNode* GetLastCommonNode(const list<const TreeNode*>& path1,
//                             const list<const TreeNode*>& path2)
// {
//     const TreeNode* pLast = nullptr;
//      list<const TreeNode*>::const_iterator  it1 = path1.begin();
//      list<const TreeNode*>::const_iterator  it2 = path2.begin();

//     while(it1 != path1.end() && it2 != path2.end())
//     {
//         if(*it1 == *it2)
//             pLast = *it1;

//         it1++;
//         it2++;
//     }

//     return pLast;
// }




// const TreeNode* GetLastCommonParent( const TreeNode* pRoot,  const TreeNode* pNode1,  const TreeNode* pNode2)
// {
//     if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
//         return nullptr;

//     list<const TreeNode*> path1;
//     GetNodePath(pRoot, pNode1, path1);

//     list<const TreeNode*> path2;
//     GetNodePath(pRoot, pNode2, path2);

//     return GetLastCommonNode(path1, path2);



// }




// ====================测试代码====================
void Test(const char* testName,  BinaryTreeNode* pRoot, const BinaryTreeNode* pNode1, const BinaryTreeNode* pNode2, BinaryTreeNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    const BinaryTreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == nullptr && pResult == nullptr) ||
        (pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \       
//      4         5     
//     / \      / |     
//    6   7    8  9    
void Test1()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);

    ConnectTreeNodes(pNode1, pNode2, pNode3);

    ConnectTreeNodes(pNode2, pNode4, pNode5);

    ConnectTreeNodes(pNode4, pNode6, pNode7);

    ConnectTreeNodes(pNode5, pNode8, pNode9);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode1, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);

    Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);

    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4()
{
    Test("Test4", nullptr, nullptr, nullptr, nullptr);
}



int main(int argc, char* argv[])
{
    
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

#include <iostream>
#include "../Utilities/BinaryTree.h"
using namespace std;


BinaryTreeNode* Convert(BinaryTreeNode* pHeadOfTree)
{
	if(pHeadOfTree == nullptr) return nullptr;

}




// ===================测试代码==========================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	if(pHeadOfList == nullptr)
		return;
	BinaryTreeNode* pTmp = pHeadOfList;
//从左到右
 	cout << "from left to right: ";
	while(pTmp != nullptr)
	{
		cout << pTmp->m_nValue << " " ;
		if(pTmp->m_pRight != nullptr)
			pTmp = pTmp->m_pRight;
		else
			break;
	}

	
	cout << endl;
//从右到左
	cout << "from right to left: ";
	while(pTmp != nullptr)
	{
		cout << pTmp->m_nValue << " ";
		if(pTmp->m_pLeft != nullptr)
			pTmp = pTmp->m_pLeft;
		else
			break;
	}
	cout << endl;

}



void DestroyList(BinaryTreeNode* pHeadOfList)
{
    if(pHeadOfList == nullptr) return;
    BinaryTreeNode* tmp = pHeadOfList;

    while(tmp != nullptr)
    {
	BinaryTreeNode* pNext = tmp->m_pRight;
	delete tmp;
	tmp = pNext;
    }
}


void Test(char* testname, BinaryTreeNode* pRootOfTree)
{
    if(testname == nullptr) return;
    else
	cout << "testname:" << endl;

    PrintTree(pRootOfTree);
    BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);
    PrintDoubleLinkedList(pHeadOfList);
}



//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
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

    Test("Test1", pNode10);

    DestroyList(pNode4);
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
void Test2()
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

    Test("Test2", pNode5);

    DestroyList(pNode1);
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
void Test3()
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

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

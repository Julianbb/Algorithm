#include <iostream>
#include "../Utilities/BinaryTree.h"
using namespace std;




bool CheckAfterFindBRootInA(BinaryTreeNode* p1, BinaryTreeNode* p2)
{
    if(p2 == nullptr && p1== nullptr) return true; // 两个都是 nullptr
    if(p1 == nullptr && p2 != nullptr) return false;
    if(p1 != nullptr && p2 == nullptr) return true; //p2这时候已经到低了
    if(p2->m_nValue != p1->m_nValue)
	return false;
    
    return CheckAfterFindBRootInA(p1->m_pLeft, p2->m_pLeft)&&CheckAfterFindBRootInA(p1->m_pRight, p2->m_pRight);

}



bool ATreeHasBTree(BinaryTreeNode* A, BinaryTreeNode* B)
{
    if(A == nullptr || B ==nullptr) return false;
    int root = B->m_nValue;
    bool result = false;

    if(A->m_nValue == root)
    {
	result =  CheckAfterFindBRootInA(A, B);
    }
    else
    {
	result = ATreeHasBTree(A->m_pLeft, B);
	if(result == false) // 左边子树也没有，那只剩下右边的了
	result = ATreeHasBTree(A->m_pRight, B);
    }

    return result;
}




//====================测试代码==================


// A是空指针
void Test1()
{
    BinaryTreeNode* A = nullptr;
    BinaryTreeNode* B = CreateBinaryTreeNode(1);
    BinaryTreeNode* b1 = CreateBinaryTreeNode(2);
    BinaryTreeNode* b2 = CreateBinaryTreeNode(3);
    ConnectTreeNodes(B, b1, b2);

    bool result = ATreeHasBTree(A, B);
    if(result == false)
	cout << "A nullptr condition is passed " << endl;
}


// A只存在左结点
//		1                  2
//	       /		  /
//	      2			 3
//	     /
//	    3
//	   /
//	  4
void Test2()
{
    BinaryTreeNode* A = CreateBinaryTreeNode(1);
    BinaryTreeNode* a1 = CreateBinaryTreeNode(2);
    BinaryTreeNode* a2 = CreateBinaryTreeNode(3);
    BinaryTreeNode* a3 = CreateBinaryTreeNode(4);
    ConnectTreeNodes(A, a1, nullptr);
    ConnectTreeNodes(a1, a2, nullptr);
    ConnectTreeNodes(a2, a3, nullptr);

    BinaryTreeNode* B = CreateBinaryTreeNode(2);
    BinaryTreeNode* b1 = CreateBinaryTreeNode(3);
    ConnectTreeNodes(B, b1, nullptr);

    bool result = false;
    result = ATreeHasBTree(A, B);
    if(result == true) 
	cout << "A only has left sons : passed" << endl;

}


//正常

//            1                 2
//          /   \             /   \
//         2     3           4    5 
//       /  \   /                /
//      4    5  5               5 
//          /
//         5 


void Test3()
{
    BinaryTreeNode* A = CreateBinaryTreeNode(1);
    BinaryTreeNode* a1 = CreateBinaryTreeNode(2);
    BinaryTreeNode* a2 = CreateBinaryTreeNode(3);
    BinaryTreeNode* a3 = CreateBinaryTreeNode(4);
    BinaryTreeNode* a4 = CreateBinaryTreeNode(5);
    BinaryTreeNode* a5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* a6 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(A, a1, a2);
    ConnectTreeNodes(a1, a3, a4 );
    ConnectTreeNodes(a2, a5, nullptr);
    ConnectTreeNodes(a4, a6, nullptr);


    BinaryTreeNode* B = CreateBinaryTreeNode(2);
    BinaryTreeNode* b1 = CreateBinaryTreeNode(4);
    BinaryTreeNode* b2 = CreateBinaryTreeNode(5);
    BinaryTreeNode* b3 = CreateBinaryTreeNode(5);
    ConnectTreeNodes(B, b1, b2);
    ConnectTreeNodes(b2, b3, nullptr);

    bool result = false; 
    result = ATreeHasBTree(A, B);
    if(result == true) 
	cout << "normal condition : passed" << endl;
    
}

//反例
//          1                8
//         / \
//        2   3
void Test4(void)
{
    BinaryTreeNode* A = CreateBinaryTreeNode(1);
    BinaryTreeNode* a1 = CreateBinaryTreeNode(2);
    BinaryTreeNode* a2 = CreateBinaryTreeNode(3);
    ConnectTreeNodes(A, a1, a2);

    BinaryTreeNode* B = CreateBinaryTreeNode(8);

    bool result = true; 
    result = ATreeHasBTree(A, B);
    if(result == false);
	cout << "the contrary condition : passed" << endl;

}

int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();

    return 0;   
}

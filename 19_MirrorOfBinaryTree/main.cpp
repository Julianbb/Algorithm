#include <iostream>
#include <stack>
using namespace std;
#include "../Utilities/BinaryTree.h"

typedef int (*FUN)(BinaryTreeNode*);




//二叉树的循环
int MirrorBinaryTree_Loop(BinaryTreeNode* root)
{
    if(root == nullptr) return -1;
    if(root->m_pLeft == nullptr && root->m_pRight == nullptr) return -1;

    stack<BinaryTreeNode*> stackBinaryTree;
    stackBinaryTree.push(root);

    while(stackBinaryTree.size()>0)
    {
	BinaryTreeNode* pNode = stackBinaryTree.top();
	stackBinaryTree.pop();

	BinaryTreeNode* tmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = tmp;

	if(pNode->m_pLeft)
	    stackBinaryTree.push(pNode->m_pLeft);
	if(pNode->m_pRight)
	    stackBinaryTree.push(pNode->m_pRight);
    }
}



//二叉树的递归遍历
int MirrorBinaryTree_Recurse(BinaryTreeNode* root)
{
    if(root == nullptr) return -1;
    if(root->m_pLeft == nullptr && root->m_pRight == nullptr) return -1;

    BinaryTreeNode* tmp = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = tmp;


    MirrorBinaryTree_Recurse(root->m_pLeft);
    MirrorBinaryTree_Recurse(root->m_pRight);

}




//nullptr
void Test1(FUN MirrorBinaryTree)
{
    BinaryTreeNode* node = nullptr;
    int flag = MirrorBinaryTree(node);
    if(flag == -1) //take the nullptr into consideration
	cout << "nullptr condition passed" << endl;
}


//一个结点
void Test2(FUN MirrorBinaryTree)
{
    BinaryTreeNode* node = CreateBinaryTreeNode(1);
    MirrorBinaryTree(node);
    if(node->m_nValue ==1 && node->m_pLeft == nullptr && node->m_pRight == nullptr)
	cout << "only one node condition passed " << endl;
    DestroyTree(node);
    
}


//都是左结点
void Test3(FUN MirrorBinaryTree)
{
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1, node2, nullptr);
    ConnectTreeNodes(node2, node3, nullptr);
    ConnectTreeNodes(node3, node4, nullptr);
    
    MirrorBinaryTree(node1);

    BinaryTreeNode* nodetmp =  node1;
    for(int i=1; i<=4; i++)
    {
	if(nodetmp->m_nValue == i)
	    nodetmp = nodetmp->m_pRight;
	else
	{
	    cout << "all left nodes failed" << endl;
	    break;
	}
	if(i==4)
	cout << "alll left nodes passed" << endl;
    }
    DestroyTree(node1);
}



//正常情况          1                1
//                 / \		    / \
//                2   3            3   2
//               / \ / \          / \ / \
//              4  5 6  7        7  6 5  4
void Test4(FUN MirrorBinaryTree)
{
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* node5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* node6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* node7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(node1, node2, node3);
    ConnectTreeNodes(node2, node4, node5);
    ConnectTreeNodes(node3, node6, node7);

    MirrorBinaryTree(node1);

    BinaryTreeNode* left;
    BinaryTreeNode* right;

    if(node1->m_nValue == 1)
    {
	left = node1->m_pLeft;
	right = node1->m_pRight;
    }
    else
	cout << "commom condition failed" << endl;


    BinaryTreeNode* lleft;
    BinaryTreeNode* lright;
    if(left->m_nValue ==3 && right->m_nValue ==2)
    {
	lleft = left->m_pLeft;
	lright = left->m_pRight;
    }
    else
	cout << "commom condition failed" << endl;

    if(lleft->m_nValue == 7 && lright->m_nValue ==6)
    {
	lleft = right->m_pLeft;
	lright = right->m_pRight;
    }
    else
	cout << "commom condition failed" << endl;

    if(lleft->m_nValue == 5 && lright->m_nValue ==4)
    {
	cout << "commom condition passed" << endl;
    }
    else
	cout << "commom condition failed" << endl;
}





int main(void)
{

    Test1(MirrorBinaryTree_Loop);
    Test2(MirrorBinaryTree_Loop);
    Test3(MirrorBinaryTree_Loop);
    Test4(MirrorBinaryTree_Loop);

    return 0;
}

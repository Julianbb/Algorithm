#include<iostream>
using namespace std;


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};



void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(const BinaryTreeNode* pRoot);
BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* root, BinaryTreeNode* left, BinaryTreeNode* right);

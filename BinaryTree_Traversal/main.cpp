/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-12 11:27
#   Describe      : 记住方法一(三个其实一样) + 方法二的前序(因为简单实用) + 层序遍历 
#
# ====================================================*/

#include <iostream>
#include <stack>
#include <queue>
#include "../Utilities/BinaryTree.h"
using namespace std;

typedef void(Traversal)(BinaryTreeNode*);



// ---------------------------方法一-------------------------------
// 1. 2. 3. 的顺序对应着前中后顺序遍历
void Traversal_Pre_1(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    stack<pair<BinaryTreeNode*, bool>> TreeStack;

    BinaryTreeNode* node = root;
    TreeStack.push(make_pair(node, false));


    while(TreeStack.size() > 0)
    {

	pair<BinaryTreeNode*, bool> tmp = TreeStack.top();
	TreeStack.pop();

	if(tmp.second == false)
	{
	    tmp.second = true;
	    if((tmp.first)->m_pRight != nullptr)              
		TreeStack.push(make_pair((tmp.first)->m_pRight, false)); // 3. 
	    if((tmp.first)->m_pLeft != nullptr)
		TreeStack.push(make_pair((tmp.first)->m_pLeft, false));  // 2.
	    TreeStack.push(tmp);   // 1.
	}
	else
	{
	    cout << (tmp.first)->m_nValue << " ";
	}
    }
} 


void Traversal_In_1(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    stack<pair<BinaryTreeNode*, bool>> TreeStack;

    BinaryTreeNode* node = root;
    TreeStack.push(make_pair(node, false));


    while(TreeStack.size() > 0)
    {

	pair<BinaryTreeNode*, bool> tmp = TreeStack.top();
	TreeStack.pop();

	if(tmp.second == false)
	{
	    tmp.second = true;
	    if((tmp.first)->m_pRight != nullptr)              
		TreeStack.push(make_pair((tmp.first)->m_pRight, false)); // 3. 

	    TreeStack.push(tmp);   // 1.

	    if((tmp.first)->m_pLeft != nullptr)
		TreeStack.push(make_pair((tmp.first)->m_pLeft, false));  // 2.
	}
	else
	{
	    cout << (tmp.first)->m_nValue << " ";
	}
    }
}


void Traversal_Post_1(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    stack<pair<BinaryTreeNode*, bool>> TreeStack;

    BinaryTreeNode* node = root;
    TreeStack.push(make_pair(node, false));


    while(TreeStack.size() > 0)
    {

	pair<BinaryTreeNode*, bool> tmp = TreeStack.top();
	TreeStack.pop();

	if(tmp.second == false)
	{
	    tmp.second = true;

	    TreeStack.push(tmp);   // 1.

	    if((tmp.first)->m_pRight != nullptr)              
		TreeStack.push(make_pair((tmp.first)->m_pRight, false)); // 3. 

	    if((tmp.first)->m_pLeft != nullptr)
		TreeStack.push(make_pair((tmp.first)->m_pLeft, false));  // 2.
	}
	else
	{
	    cout << (tmp.first)->m_nValue << " ";
	}
    }
}

// ---------------------------方法二-------------------------------


void Traversal_Pre_2(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    BinaryTreeNode* node = root;
    stack<BinaryTreeNode*> TreeStack;
    TreeStack.push(node); // 先push root
    
    while(TreeStack.size()>0) 
    {
	BinaryTreeNode* tmp = TreeStack.top(); // 取顶部
	TreeStack.pop();

	cout << tmp->m_nValue << " " ;

	if(tmp->m_pRight != nullptr) // 先push 左节点
	    TreeStack.push(tmp->m_pRight);
	if(tmp->m_pLeft != nullptr) // 再push 右节点
	    TreeStack.push(tmp->m_pLeft);
    }
}



void Traversal_In_2(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    BinaryTreeNode* node = root;
    stack<BinaryTreeNode*> TreeStack;

    while(node != nullptr || TreeStack.size()>0)
    {
	while(node != nullptr) // 先push 到左下角尽头
	{
	    TreeStack.push(node);
	    node = node->m_pLeft;
	}
	
	node = TreeStack.top(); // 再出栈
	TreeStack.pop();
	cout << node->m_nValue << " " ;

	node = node->m_pRight; // 遍历右节点
	
    }
}




void Traversal_Post_2(BinaryTreeNode* root)
{
    if(root == nullptr)return;

    BinaryTreeNode* node = root;
    BinaryTreeNode* last_node = root;
    stack<BinaryTreeNode*> TreeStack;


    while(node != nullptr || TreeStack.size()>0)
    {
	while(node!=nullptr)
	{
	    TreeStack.push(node);
	    node = node->m_pLeft;
	}

	node = TreeStack.top();
	if(node->m_pRight == nullptr || node->m_pRight == last_node)
	{
	    cout << node->m_nValue << " " ;
	    TreeStack.pop();
	    last_node = node;
	    node = nullptr;
	}
	else
	{
	    node = node->m_pRight;
	}
    }


}


//层序遍历
void Traversal_Level(BinaryTreeNode* root)
{
    if(root == nullptr) return;

    BinaryTreeNode* node = root;
    queue<BinaryTreeNode*> array;
    array.push(root);

    while(array.size()>0)
    {
	node = array.front();
	array.pop();
	cout << node->m_nValue << " ";

	if(node->m_pLeft != nullptr)
	    array.push(node->m_pLeft);
	if(node->m_pRight != nullptr)
	    array.push(node->m_pRight);
    }
}



Traversal* FUN_1[4] = {Traversal_Pre_1, Traversal_In_1, Traversal_Post_1, Traversal_Level};
Traversal* FUN_2[4] = {Traversal_Pre_2, Traversal_In_2, Traversal_Post_2, Traversal_Level};


void Test1(Traversal* FUN_ARRAY[] )
{
    cout << "------------------Test1()--------------------------" << endl;

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


    cout << "     1     "<< endl;
    cout << "   /   \\   "<< endl;
    cout << "  2     3  " << endl;
    cout << " / \\   / \\ " << endl;
    cout << "4   5 6   7 " << endl;


    cout << endl;
    cout << " Pre_Order: " ;
    FUN_ARRAY[0](node1);

    cout << endl;
    cout << " In_Order: " ;
    FUN_ARRAY[1](node1);


    cout << endl;
    cout << " Post_Order: " ;
    FUN_ARRAY[2](node1);


    cout << endl;
    cout << " Level_Order: ";
    FUN_ARRAY[3](node1);

    cout << endl;
    cout << endl;
}


// 
void Test2(Traversal* FUN_ARRAY[])
{
    cout << "------------------Test2()--------------------------" << endl;
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1, node2, nullptr);
    ConnectTreeNodes(node2, node3, nullptr);
    ConnectTreeNodes(node3, node4, nullptr);

    cout << "        1      "<< endl;
    cout << "       /       "<< endl;
    cout << "      2	    " << endl;
    cout << "     /	    " << endl;
    cout << "    3	    " << endl;
    cout << "   /	    " << endl;
    cout << "  4	    " << endl;


    cout << endl;
    cout << " Pre_Order: " ;
    FUN_ARRAY[0](node1);

    cout << endl;
    cout << " In_Order: " ;
    FUN_ARRAY[1](node1);


    cout << endl;
    cout << " Post_Order: " ;
    FUN_ARRAY[2](node1);


    cout << endl;
    cout << " Level_Order: ";
    FUN_ARRAY[3](node1);
    cout << endl;
    cout << endl;
 
}



void Test3(Traversal* FUN_ARRAY[] )
{
    cout << "------------------Test3()--------------------------" << endl;
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(node1,  nullptr, node2);
    ConnectTreeNodes(node2,  nullptr, node3);
    ConnectTreeNodes(node3,  nullptr, node4);

    cout << "    1      "<< endl;
    cout << "     \\      "<< endl;
    cout << "      2	    " << endl;
    cout << "       \\	    " << endl;
    cout << "        3	    " << endl;
    cout << "         \\	    " << endl;
    cout << "          4	    " << endl;


    cout << endl;
    cout << " Pre_Order: " ;
    FUN_ARRAY[0](node1);

    cout << endl;
    cout << " In_Order: " ;
    FUN_ARRAY[1](node1);


    cout << endl;
    cout << " Post_Order: " ;
    FUN_ARRAY[2](node1);


    cout << endl;
    cout << " Level_Order: ";
    FUN_ARRAY[3](node1);
    cout << endl;
    cout << endl;
 
}


void Test4(Traversal* FUN_ARRAY[])
{
    cout << "------------------Test4()--------------------------" << endl;
    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);


    cout << "    1      "<< endl;


    cout << endl;
    cout << " Pre_Order: " ;
    FUN_ARRAY[0](node1);

    cout << endl;
    cout << " In_Order: " ;
    FUN_ARRAY[1](node1);


    cout << endl;
    cout << " Post_Order: " ;
    FUN_ARRAY[2](node1);


    cout << endl;
    cout << " Level_Order: ";
    FUN_ARRAY[3](node1);
    cout << endl;
    cout << endl;
 
}



void Test5( Traversal* FUN_ARRAY[] )
{
    cout << "------------------Test5()--------------------------" << endl;

    BinaryTreeNode* node1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* node2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* node3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* node4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* node5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* node6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* node7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(node1, node2, node3);
    ConnectTreeNodes(node2, node4, nullptr);
    ConnectTreeNodes(node3, node5, node6);
    ConnectTreeNodes(node6, nullptr, node7);



    cout << "     1     "<< endl;
    cout << "   /   \\   "<< endl;
    cout << "  2     3  " << endl;
    cout << " /     / \\ " << endl;
    cout << "4     5   6 " << endl;
    cout << "           \\ " << endl;
    cout << "            7 " << endl;


    cout << endl;
    cout << " Pre_Order: " ;
    FUN_ARRAY[0](node1);

    cout << endl;
    cout << " In_Order: " ;
    FUN_ARRAY[1](node1);


    cout << endl;
    cout << " Post_Order: " ;
    FUN_ARRAY[2](node1);


    cout << endl;
    cout << " Level_Order: ";
    FUN_ARRAY[3](node1);

    cout << endl;
    cout << endl;
}



int main(void)
{
    Test1(FUN_1);
    Test2(FUN_1);
    Test3(FUN_1);
    Test4(FUN_1);
    Test5(FUN_1);
    return 0;
}






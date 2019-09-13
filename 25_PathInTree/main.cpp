#include <iostream>
#include <vector>
using namespace std;
#include "../Utilities/BinaryTree.h"



void DFS(BinaryTreeNode* root, int sum, int& cur, vector<vector<int>>& path, vector<int>& tmp_path)
{

    if(root->m_pLeft == nullptr && root->m_pRight == nullptr) //边界
    {
    cur += root->m_nValue;
    tmp_path.push_back(root->m_nValue);
	if(sum == cur)
	{
	    path.push_back(tmp_path);
	}
	return;
    }

    cur += root->m_nValue;
    tmp_path.push_back(root->m_nValue);
    
    if(root->m_pLeft != nullptr) //遍历两种可能， 可能1
    {
    DFS(root->m_pLeft, sum, cur, path, tmp_path);
    cur -= (root->m_pLeft->m_nValue);
    tmp_path.pop_back();
    }

    if(root->m_pRight != nullptr) ////遍历两种可能， 可能2
    {
    DFS(root->m_pRight, sum, cur, path, tmp_path);
    cur -= (root->m_pRight->m_nValue);
    tmp_path.pop_back();
    }


    return;
}



void  FindPath(BinaryTreeNode* root, int sum, vector<vector<int>>& path)
{
    if(root == nullptr) return;

    int tmp_cur = 0;
    vector<int> tmp_path;
    DFS(root, sum, tmp_cur, path, tmp_path);
}




















// void FindPath(BinaryTreeNode* root, int sum, int now_sum, vector<int>& path_tmp, vector<vector<int>>& path)
// {
//     if(root == nullptr) return;
//     now_sum += root->m_nValue;
//     path_tmp.push_back(root->m_nValue);

//     bool isLeaf = root->m_pLeft == nullptr && root->m_pRight == nullptr;
//     if(now_sum == sum && isLeaf)
//     {
//         path.push_back(path_tmp);
//     }

//     if(root->m_pLeft != nullptr)
//     {
//         FindPath(root->m_pLeft, sum, now_sum, path_tmp, path);
//     }
//     if(root->m_pRight != nullptr)
//     {
//         FindPath(root->m_pRight, sum, now_sum, path_tmp, path);
//     }

//     path_tmp.pop_back(); // 很重要，返回的时候需要将当前结点弹出

// }


// void  FindPath(BinaryTreeNode* root, int sum, vector<vector<int>>& path)
// {
//     if(root == nullptr) return;
//     vector<int> path1;
//     int sum_tmp = 0;

//     FindPath(root, sum, sum_tmp, path1, path);
// }






// ====================测试代码===========================





//          10
//         /  \
//        5    12
//       / \
//      4   7     
// 有两条路径上的结点和为22
void Test1(void)
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    vector<vector<int>> path;
    FindPath(pNode10, 22, path);
    if(path.size() == 2)
    {
	vector<int> path1 = path[0];
	vector<int> path2 = path[1];
	if(path1[2] == 7 && path2[1] == 12)
	    cout << "Test1 passed" << endl;	    
	else
	    cout << "Test1 failed" << endl;
    }
    else
    {
	cout << "Test1 failed" << endl;
    }

    DestroyTree(pNode10);
}




//          10
//         /  \
//        5    12
//       / \
//      4   7     
// 没有路径上的结点和为15

void Test2(void)
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);


    vector<vector<int>> path;
    FindPath(pNode10, 15, path);
    if(path.size() == 0)
	cout << "Test2 passed" << endl;
    else
	cout << "Test2 failed" << endl;
    DestroyTree(pNode10);
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
// 有一条路径上面的结点和为15
void Test3(void)
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

    vector<vector<int>> path;
    FindPath(pNode5, 15, path);
    if(path.size() == 1)
    {
	vector<int> path1 = path.front();
	if(path1.back()==1)
	    cout << "Test3 passed" << endl;
	else
	    cout << "Test3 failed" << endl;
    }
    else
	cout << "Test3 failed" << endl;

    DestroyTree(pNode5);
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
// 没有路径上面的结点和为16
void Test4(void)
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


    vector<vector<int>> path;
    FindPath(pNode1, 16, path);
    if(path.size() == 0)
	cout << "Test4 passed" << endl;
    else
	cout << "Test4 failed" << endl;


    DestroyTree(pNode1);
}


// 树只有一个结点
void Test5(void)
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    vector<vector<int>> path;
    FindPath(pNode1, 1, path);
    if(path.size() == 1)
    {
	vector<int> path1 = path.front();
	if(path1[0] == 1)
	    cout << "Test5 passed" << endl;
	else
	    cout << "Test5 failed" << endl;
    }
    else
	cout << "Test4 failed" << endl;

}

void Test6(void)
{
    vector<vector<int>> path;
    FindPath(nullptr, 0, path);
    if(path.size() == 0)
	cout << "Test6 passed" << endl;
    else
	cout << "Test6 failed" << endl;
}


int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

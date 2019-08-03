/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-08-03 19:30
#   Describe      : 剑指Offer
#
# ====================================================*/

#include <iostream>
#include <fstream>
#include "../Utilities/BinaryTree.h"
using namespace std;


void Serialize(BinaryTreeNode* pRoot, ostream& fileOut)
{
    if(pRoot == nullptr)
    {
	fileOut << "$,";
	return;
    }

    fileOut << pRoot->m_nValue << ",";
    Serialize(pRoot->m_pLeft, fileOut);
    Serialize(pRoot->m_pRight, fileOut);
}


bool ReadStream(istream& fin, int* num)
{
    if(fin.eof())
	return false;

    char buffer[32];
    buffer[0] = 0;

    char ch;
    fin >> ch;
    int i=0;

    while(!fin.eof() && ch != ',')
    {
	buffer[i++] = ch;
	fin >> ch;
    }

    bool isNumberic = false;
    if(i>0 && buffer[0]!='$')
    {
	*num = atoi(buffer);
	isNumberic = true;
    }

    return isNumberic;
}


void Deserialize(BinaryTreeNode** pRoot, istream& fileIn)
{
    int number;
    if(ReadStream(fileIn, &number))
    {
	*pRoot = new BinaryTreeNode();
	(*pRoot)->m_nValue = number;
	(*pRoot)->m_pLeft = nullptr;
	(*pRoot)->m_pRight = nullptr;

	Deserialize(&((*pRoot)->m_pLeft), fileIn);
	Deserialize(&((*pRoot)->m_pRight), fileIn);
    }
}





// ==================== Test Code ====================
bool isSameTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot1 == NULL && pRoot2 == NULL)
        return true;

    if(pRoot1 == NULL || pRoot2 == NULL)
        return false;

    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return isSameTree(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
        isSameTree(pRoot1->m_pRight, pRoot2->m_pRight);
}

void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    const char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    Serialize(pRoot, fileOut);
    fileOut.close();

    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pNewRoot = NULL;
    Deserialize(&pNewRoot, fileIn2);
    fileIn2.close();

    PrintTree(pNewRoot);

    if(isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    DestroyTree(pNewRoot);
}

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

    Test("Test1", pNode8);

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

    Test("Test2", pNode5);

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

    Test("Test3", pNode5);

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    Test("Test4", pNode5);

    DestroyTree(pNode5);
}

void Test5()
{
    Test("Test5", NULL);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode71, NULL);
    ConnectTreeNodes(pNode62, NULL, pNode72);

    Test("Test6", pNode1);

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

    return 0;
}

#include <string.h>
#include <stack>
#include <iostream>
#include <exception>

using namespace std;
using namespace cv;


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
	if(startInorder == endInorder && *startPreorder == *startInorder)
	    return root;
	else
	    throw std::exception("Invalid input");
    }

}


void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
	cout << testName << "begins" << endl;

    cout << "the preorder sequence is: " << 
    for(int i=0; i<length; i++)
    {
	cout << preorder[i] << " " 
    }
    cout << endl;

    cout << "the inorder sequence is: " << 
    for(int i=0; i<length; i++)
    {
	cout << inorder[i] << " " 
    }
    cout << endl;

    try
    {
	BinaryTreeNode* root = Construct(preorder, inorder, length);
	
    }
    catch(std::exception& exception)
    {
	cout << " Invalid Input " << endl;
    }

    
}


int mian(void)
{





    return 0;
}



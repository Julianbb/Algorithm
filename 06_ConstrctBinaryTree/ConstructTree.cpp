#include "ConstructTree.h"

using namespace std;



BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
	if(startInorder == endInorder && *startPreorder == *startInorder)//　only one element
	    return root;
	else
	{
	    std::logic_error ex("Invalid input");
	    throw std::exception(ex);
	}
    }

    // to find root in inOrder
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder!=rootValue) 
	++ rootInorder;
    if(rootInorder == endInorder && *rootInorder!=rootValue) //can't find the root in whole inOrder, that means Invalid input
    {
	std::logic_error ex("Invalid input");
	throw std::exception(ex);
    }


    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)  //construct left tree
    {
	root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }
    if(leftLength < endPreorder - startPreorder) //construct right tree
    {
	root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }

    return root;
}



BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length<=0)
	return NULL;
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}



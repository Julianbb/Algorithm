#include <iostream>
#include <exception>
#include <stdexcept>
#include "../Utilities/BinaryTree.h"



BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

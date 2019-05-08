#include "ComplexList.h"

// 先复制next
ComplexListNode* Clone_next(ComplexListNode* pHead)
{
	if(pHead == nullptr) return nullptr;
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClone_nextHead = nullptr;
	ComplexListNode* pClone_nextTail = nullptr;
	int i=0;
	while(pNode!=nullptr)
	{
		ComplexListNode* pTmp = CreateNode(pNode->m_Value);
		if(i==0)
		{
			pClone_nextHead = pTmp;
			pClone_nextTail = pTmp;
		}
		pClone_nextTail->m_pNext = pTmp;
		pClone_nextTail = pTmp;

		pNode = pNode->m_pNext;
	}
}


//找数字，返回ComplexListNode*
ComplexListNode* FindNumber(ComplexListNode* pHead, int target)
{
	if(pHead == nullptr)return nullptr;
	ComplexListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		if(pNode->m_Value == target)
			break;
		pNode = pNode->m_pNext;
	}
	return pNode;
}


//再复制sibling
void  Clone_Sibling(ComplexListNode* pClone, ComplexListNode* pHead)
{
	if(pHead == nullptr || clone == nullptr) return;
	ComplexListNode* pNode_b = pHead;
	ComplexListNode* pNode_c = pClone;
	while(pNode_b!=nullptr||pNode_c!=nullptr)
	{
		if(pNode_b->m_pSibling != nullptr)
		{
			int num = pNode_b->m_pSibling->m_Value;
			ComplexListNode* pTargetNum = FindNumber(pClone, num);	
			pNode_c->m_pSibling = pTargetNum;
		}
		pNode_b = pNode_b->m_pNext;
		pNode_c = pNode_c->m_pNext;
	}
}



ComplexListNode* Clone(ComplexListNode* pHead)
{
	if(pHead == nullptr) return nullptr;
	ComplexListNode* pNode = nullptr;
		
	pNode = Clone_next(pHead);
	 		Clone_Sibling(pNode, pHead);
	return pNode;
}





//==================测试代码===================

void Test(const char* test, ComplexListNode* pHead)
{
    if(test == nullptr) return;
    cout << "origin list is:" << endl;
    PrintList(pHead);

    ComplexListNode* pClone = Clone(pHead);
    cout << "the clone list is:" << endl;
    PrintList(pClone);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}
int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

#include <iostream>
#include "../Utilities/List.h"
using namespace std;


void DeleteNode(ListNode** pHead, ListNode* pNode)
{
    if(*pHead == nullptr || pHead == nullptr ||pNode == nullptr) return;
    if(*pHead == pNode && pNode->m_pNext != nullptr) // 头结点
    {
	*pHead = (*pHead)->m_pNext;  
	delete pNode;
	return;
    }
    else if(*pHead == pNode && pNode->m_pNext == nullptr) //就一个节点
    {
	delete pNode;
	*pHead = nullptr;
	return;
    }

    else if(pNode->m_pNext == nullptr) // 尾节点
    {
	ListNode* node_tmp = *pHead;
	while(node_tmp->m_pNext != pNode)
	{
	    node_tmp = node_tmp->m_pNext;
	}

	node_tmp->m_pNext = nullptr;
	delete pNode;
    }

    else // 中间节点
    {
	ListNode* tmp = pNode->m_pNext;
	pNode->m_pNext = tmp->m_pNext;
	pNode->m_Value = tmp->m_Value;
	delete tmp;
    }


}







// void DeleteNode(ListNode** pHead, ListNode* pNode)
// {
//     if(pHead == nullptr || *pHead == nullptr || pNode == nullptr) return;

//     if(*pHead == pNode && pNode->m_pNext ==nullptr)//一个结点,删除的就是头结点
//     {
//         delete *pHead;
//         *pHead = nullptr;
//         return;
//     }
//     else if(pNode->m_pNext == nullptr) //删除的是尾结点
//     {
//         ListNode* nodeTmp = *pHead;
//         while(nodeTmp->m_pNext != pNode)
//         {
//             nodeTmp = nodeTmp->m_pNext;
//         }
//         nodeTmp->m_pNext = nullptr;
//         delete pNode;
//         //pNode = nullptr; // 无效，不能改变函数外的pNode值, 当执行完此函数的时候，需要在函数外将pNode立即置NULL
//     }
//     else//删除的是中间结点
//     {
//         ListNode* tmp = pNode->m_pNext;
//         pNode->m_Value = pNode->m_pNext->m_Value;
//         pNode->m_pNext = pNode->m_pNext->m_pNext;

//         delete tmp;

//     }
// }

//如果需要改变pHead的值(如只有一个结点，删除头结点,则pHead 将为null),　必须传递二级指针
//有多个结点，删除头结点，如Test2(),并没有改变pHead值，只是删除了头结点的下一个值

void Test(ListNode** pHead, ListNode* pNode)
{
    cout << "origin list is:" ;
    PrintList(*pHead);

    cout << endl;
    PrintListNode(pNode);

    DeleteNode(pHead, pNode);
    cout << "the result is: ";
    PrintList(*pHead);
    cout << endl;
    cout << endl;
}


//有多个结点，删除中间结点
void Test1(void)
{
    ListNode* pHead = CreateListNode(1);
    ListNode* node1 = CreateListNode(2);
    ConnectListNodes(pHead, node1);
    AddToTail(&pHead, 3);
    
    Test(&pHead, node1);
    DestroyList(pHead);
}


//有多个结点，删除头结点
void Test2(void)
{
    ListNode* pHead = CreateListNode(1);
    ListNode* node1 = CreateListNode(2);
    ListNode* node2 = CreateListNode(3);

    ConnectListNodes(pHead, node1);
    ConnectListNodes(node1, node2);

    Test(&pHead, pHead);
    DestroyList(pHead);
}


//有多个结点，删除尾结点
void Test3(void)
{

    ListNode* pHead = CreateListNode(1);
    ListNode* node1 = CreateListNode(2);
    ListNode* node2 = CreateListNode(3);

    ConnectListNodes(pHead, node1);
    ConnectListNodes(node1, node2);

    Test(&pHead, node2);
    DestroyList(pHead);

}



//只有一个结点，删除头结点
void Test4(void)
{

    ListNode* pHead = CreateListNode(1);
    Test(&pHead, pHead);
    DestroyList(pHead);
}


int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}

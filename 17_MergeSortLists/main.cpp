#include <iostream>
#include "../Utilities/List.h"
using namespace std;

typedef ListNode* (*FUN)(ListNode*, ListNode*);

ListNode* MergeLists_Recurse(ListNode* node1, ListNode* node2)
{
    if(node1 == nullptr && node2 == nullptr) return nullptr;
    if(node1 == nullptr && node2 != nullptr) return node2;
    if(node2 == nullptr && node1 != nullptr) return node1;


    ListNode* tmp1 = node1->m_pNext;
    ListNode* tmp2 = node2->m_pNext;


    if(node1->m_Value < node2->m_Value)
    {
	node1->m_pNext = MergeLists_Recurse(tmp1, node2);
	return node1;
    }
    else
    {
	node2->m_pNext = MergeLists_Recurse(node1, tmp2);
	return node2;
    }

}


ListNode* MergeLists_Loop(ListNode* node1, ListNode* node2)
{
     if(node1 == nullptr && node2 == nullptr) return nullptr;
     if(node1 == nullptr && node2 != nullptr) return node2;
     if(node1 != nullptr && node2 == nullptr) return node1;



     ListNode* result = nullptr;
     ListNode* head = nullptr;

     ListNode* tmp1 = node1;
     ListNode* tmp2 = node2;

     while(tmp1 != nullptr && tmp2 != nullptr)
     {
	 if(tmp1->m_Value <= tmp2->m_Value)
	 {
	     if(head == nullptr)
	     {
		 head = node1;
	         result = head;
		 tmp1 = tmp1->m_pNext;
		 continue;
	     }
	     result->m_pNext = tmp1;
	     result = result->m_pNext;
	     tmp1 = tmp1->m_pNext;

	 }
	 else
	 {
	     if(head == nullptr)
	     {
		 head = node2;
	         result = head;
		 tmp2 = tmp2->m_pNext;
		 continue;
	     }
	     result->m_pNext = tmp2;
	     result = result->m_pNext;
	     tmp2 = tmp2->m_pNext;
	 }

     }
     if(tmp1 == nullptr && tmp2 != nullptr)
        result->m_pNext = tmp2;
     if(tmp1 != nullptr && tmp2 == nullptr)
        result->m_pNext = tmp1;

     return head;
}

//递归解法
// ListNode* MergeLists_Recurse(ListNode* node1, ListNode* node2)
// {
//     if(node1 == nullptr && node2 == nullptr) return nullptr;
//     if(node1 == nullptr && node2 != nullptr) return node2;
//     if(node1 != nullptr && node2 == nullptr) return node1;

//     ListNode* head;

//     if(node1->m_Value < node2->m_Value)
//     {
//         head = node1;
//         node1 = node1->m_pNext;
//     }
//     else
//     {
//         head = node2;
//         node2 = node2->m_pNext;
//     }

//     head->m_pNext = MergeLists_Recurse(node1, node2);

//     return head;
// }



//循环解法
// ListNode* MergeLists_Loop(ListNode* node1, ListNode* node2)
// {
//     if(node1 == nullptr && node2 == nullptr) return nullptr;
//     if(node1 == nullptr && node2 != nullptr) return node2;
//     if(node1 != nullptr && node2 == nullptr) return node1;


//     ListNode* p1 = node1;
//     ListNode* p2 = node2;
//     ListNode* head;  // 排序后的链表(总链表)头
//     ListNode* tail; // 排序后的链表(总链表)tail


//     if(p1->m_Value > p2->m_Value)  //获得链表头
//     {
//         head = p2;
//         tail = p2;
//         p2 = p2->m_pNext;
//     }
//     else
//     {
//         head = p1;
//         tail = p1;
//         p1 = p1->m_pNext;
//     }


//     ListNode* tmp;
//     while(p1!=nullptr && p2!=nullptr) // 一直到有一个链表全部比较完了
//     {
//         if(p1->m_Value < p2->m_Value) // 谁小，谁入总链表，然后再往后移一个
//         {
//             tmp = p1;
//             p1 = p1->m_pNext;
//         }
//         else
//         {
//             tmp = p2;
//             p2 = p2->m_pNext;
//         }

//         tail->m_pNext= tmp;  // tail 不断跟新
//         tail = tmp;
//     }


//     if(p1 != nullptr) // 还剩下一个链表直接加到后面
//     {
//         tail->m_pNext = p1;
//     }
//     if(p2 != nullptr)
//     {
//         tail->m_pNext = p2;
//     }

//     return head;
// }



// 有一个是空指针
void Test1(FUN MergeLists)
{
    ListNode* head1 = nullptr;

    ListNode* head2 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ConnectListNodes(head2, node2);

    cout << "before merge: " << endl;
    cout << "list1 : ";
    PrintList(head1);
    cout << "list2 : ";
    PrintList(head2);

    ListNode* tmp = MergeLists(head1, head2);

    cout << "after merge: " << endl;
    PrintList(tmp);
    
    cout << "---------------------" << endl;
}


// 两个链表都是空指针
void Test2(FUN MergeLists)
{
    ListNode* head1 = nullptr;

    ListNode* head2 = nullptr;

    cout << "before merge: " << endl;
    cout << "list1 : nullptr";
    PrintList(head1);
    cout << "list2 : nullptr";
    PrintList(head2);

    ListNode* tmp = MergeLists(head1, head2);

    cout << "after merge: " << endl;
    PrintList(tmp);
    
    cout << "---------------------" << endl;
}


//正常
void Test3(FUN MergeLists)
{
    ListNode* head1 = CreateListNode(1);
    ListNode* node11 = CreateListNode(3);
    ListNode* node12 = CreateListNode(5);
    ListNode* node13 = CreateListNode(7);
    ConnectListNodes(head1, node11);
    ConnectListNodes(node11, node12);
    ConnectListNodes(node12, node13);

    ListNode* head2 = CreateListNode(2);
    ListNode* node21 = CreateListNode(4);
    ListNode* node22 = CreateListNode(6);
    ListNode* node23 = CreateListNode(8);
    ConnectListNodes(head2, node21);
    ConnectListNodes(node21, node22);
    ConnectListNodes(node22, node23);


    cout << "before merge: " << endl;
    cout << "list1 : " ;
    PrintList(head1);
    cout << "list2 : ";
    PrintList(head2);

    ListNode* tmp = MergeLists(head1, head2);

    cout << "after merge: " << endl;
    PrintList(tmp);
    cout << "---------------------" << endl;
 
}


//有一个链表只有一个结点
void Test4(FUN MergeLists)
{
    ListNode* head1 = CreateListNode(100);
    
    ListNode* head2 = CreateListNode(2);
    ListNode* node1 = CreateListNode(4);
    ListNode* node2 = CreateListNode(6);
    ListNode* node3 = CreateListNode(8);
    ConnectListNodes(head2, node1);
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);


    cout << "before merge: " << endl;
    cout << "list1 : ";
    PrintList(head1);
    cout << "list2 : ";
    PrintList(head2);

    ListNode* tmp = MergeLists(head1, head2);

    cout << "after merge: " << endl;
    PrintList(tmp);
    cout << "---------------------" << endl;
}



int main(void)
{

    Test1(MergeLists_Loop);
    Test2(MergeLists_Loop);
    Test3(MergeLists_Loop);
    Test4(MergeLists_Loop);

    return 0;
}

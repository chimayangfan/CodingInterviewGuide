#pragma once
#ifndef __LIST_HPP__
#define __LIST_HPP__

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

/****************************************************************************************************/
/*
功能：应用C++语言实现单链表的各项操作
建立链表的节点结构ListNode，封装一个List类将有效节点链接起来
基本的成员函数：
构造函数、析构函数
**
**单链表的具体操作：
**                  1：从尾到头打印链表
**                  2：输出链表中倒数第k个结点
**                  3：反转链表
**					   反转部分链表
**                  4：合并两个排序链表
**                  5：输出两个链表的第一个公共节点
**                  6：输出链表环入口节点
**                  7：删除链表中重复节点
**                  8：链表排序，快排
**
**                                                             By ：汪亮
**
*/
/*****************************************************************************************************/

class List{
private:
	ListNode* head;		//链表头结点指针
public:
	List(int* &table, int n);	//利用动态数组构造链表
	List(vector<int> vec);	//利用动态数组构造链表

	vector<int> printListFromTailToHead(ListNode* head);				//1：从尾到头打印链表
	ListNode* FindKthToTail(ListNode* p, unsigned int k);				//2：输出链表中倒数第k个结点
	void ReverseList(ListNode* pHead);									//3：反转链表
	void ReversePartList(ListNode* pHead, int from, int to);			//	 反转部分链表
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2);				//4：合并两个排序链表
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);	//5：输出两个链表的第一个公共节点
	ListNode* EntryNodeOfLoop(ListNode* pHead);							//6：输出链表环入口节点
	void DeleteDuplication(ListNode* pHead);							//7：删除链表中重复节点
	void List::QuickSort(ListNode* pBeign, ListNode* pEnd);				//8：链表排序，快排（QuickSort(a.Getfront(), NULL)）

	ListNode* Getfront();			  //获得链表头节点
	void PrintAll();				  //打印整个表
};

/////////////////////////////////////////////////////////
//利用动态数组构造链表
List::List(int* &table, int n)
{
	head = NULL;
	if (n>0)
	{
		head = new ListNode(table[0]);//创建节点  
		ListNode* rear = head;//创建一个指向头节点的指针  
		int i = 1;
		while (i<n)
		{
			rear->next = new ListNode(table[i++]);
			rear = rear->next;
		}
	}
}

//利用vector动态数组构造链表
List::List(vector<int> vec)
{
	head = NULL;
	int n = vec.size();
	if (n>0)
	{
		head = new ListNode(vec[0]);//创建节点  
		ListNode* rear = head;//创建一个指向头节点的指针  
		int i = 1;
		while (i<n)
		{
			rear->next = new ListNode(vec[i++]);
			rear = rear->next;
		}
	}
}
//从尾到头打印链表
vector<int> List::printListFromTailToHead(ListNode* head)
{
	vector <int>  result;
	stack<int> arr;
	ListNode* p = head;
	while (p != NULL)
	{
		arr.push(p->val);
		p = p->next;
	}
	int len = arr.size();
	for (int i = 0; i<len; i++)
	{
		result.push_back(arr.top());
		arr.pop();
	}
	return  result;
}

//输出链表中倒数第k个结点
ListNode* List::FindKthToTail(ListNode* p, unsigned int k) {
	//if(!p) return nullptr;
	auto p1 = p;
	for (int i = 0; i != k; ++i)
		if (!p1)return nullptr;
		else
			p1 = p1->next;
	while (p1) {
		p1 = p1->next;
		p = p->next;
	}
	return p;
}

//反转链表
void List::ReverseList(ListNode* pHead) {
	//利用栈实现
	if (pHead == NULL || pHead->next == NULL)
		return ;
	ListNode* p = pHead;
	stack<ListNode* > s;
	while (p->next)
	{
		s.push(p);
		p = p->next;
	}
	ListNode* newhead = p;
	while (!s.empty())
	{
		p->next = s.top();
		p = p->next;
		s.pop();
	}
	p->next = NULL;
	head = newhead;
	//就地反转
	/*
	if(pHead == NULL || pHead -> next == NULL)
	return pHead;
	ListNode* p = pHead;

	ListNode* q = pHead -> next;

	ListNode* r = NULL;
	pHead -> next = NULL;
	while(q)
	{
	r = q -> next;
	q -> next = p;
	p = q; q = r;
	}
	return p;
	*/

	/*
	if(pHead == NULL || pHead -> next == NULL)
	{
	return pHead;
	}
	ListNode* p = pHead -> next;
	ListNode* q = NULL;
	while(p -> next)
	{
	q = p -> next;
	p -> next = q -> next;
	q -> next = pHead -> next;
	pHead -> next = q;
	}
	p -> next = pHead;
	pHead = p -> next -> next;
	p -> next -> next = NULL;
	return pHead;
	*/
	//递归实现
	/*
	if (pHead == NULL || pHead->next == NULL) 
		return pHead;
	ListNode *p = ReverseList(pHead->next);
	pHead->next->next = pHead;
	pHead->next = NULL;
	return p;
	*/
}

//反转部分链表
void List::ReversePartList(ListNode* pHead, int from, int to) {
	int len = 0;
	ListNode* node1 = pHead;
	ListNode* fpre = NULL;
	ListNode* tpos = NULL;
	while(node1)
	{
		len++;
		fpre = len == from - 1 ? node1 : fpre;//fpre指向待反转部分前一个节点
		tpos = len == to + 1 ? node1 : tpos;//tpos指向待反转部分后一个节点
		node1 = node1->next;
	}
	if (from > to || from < 1 || to > len) return;
	node1 = fpre == NULL ? pHead : fpre->next;
	ListNode* node2 = node1->next;
	node1->next = tpos;

	//就地反转
	ListNode* q = NULL;

	while(node2 != tpos)
	{
		q = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = q;
	}
	if (fpre != NULL)
	{
		fpre->next = node1;
		head = pHead;
	}
	else
		head = node1;

}

//合并两个排序链表
ListNode* List::Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL) return pHead2;
	else if (pHead2 == NULL) return pHead1;
	ListNode* pHead3 = NULL;
	if (pHead1->val<pHead2->val) {
		pHead3 = pHead1;
		pHead3->next = Merge(pHead1->next, pHead2);
	}
	else {
		pHead3 = pHead2;
		pHead3->next = Merge(pHead1, pHead2->next);
	}
	return pHead3;
}

//输出两个链表的第一个公共节点
ListNode* List::FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* p = pHead1;
	ListNode* q = pHead2;

	while (p != q)
	{
		//没有到链表尾部，则继续往后走  			
		if (p != NULL) p = p->next;
		if (q != NULL) q = q->next;
		if (p != q)
		{
			//若已到链表尾，则令其指向另一链表头  				
			if (p == NULL) p = pHead2;
			if (q == NULL) q = pHead1;
		}
	}
	return p;
}

//输出链表环入口节点
ListNode* List::EntryNodeOfLoop(ListNode* pHead)
{
	//set特性:不能插入相同元素
	set<ListNode*> s;
	ListNode* p = pHead;
	if (pHead == NULL) return NULL;
	while (p != NULL)
	{
		if (s.insert(p).second)
			p = p->next;
		else
			return p;
	}
	return p;
	//利用快慢指针
	/*
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			fast = pHead;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			if (slow == fast)
				return slow;
		}
	}
	return NULL;
	*/
}

//删除链表中重复节点(以排序链表)
/*由于头结点有可能被删除，因此需要创建新的头结点pNew；
  遍历链表，每遍历一个结点pCur，且pCur!=NULL，做以下判断：
  如果它的下个结点不为空，且当前结点和下个结点的值相等，
  那么说明这两个是重复的结点，需要继续往下遍历，一直找到不重复的结点为止；
*/
void List::DeleteDuplication(ListNode* pHead)
{
	ListNode* pNew = new ListNode(0);
	ListNode* pTmp = pNew;
	ListNode* pCur = pHead;

	while (pCur)
	{
		if (pCur->next != NULL && pCur->val == pCur->next->val)
		{
			ListNode* pNext = pCur->next;
			while (pNext->next != NULL && pNext->val == pNext->next->val)
			{
				pNext = pNext->next;
			}
			pCur = pNext->next;
		}
		else
		{
			pTmp->next = pCur;
			pTmp = pTmp->next;
			pCur = pCur->next;
		}
	}
	pTmp->next = NULL;
	head = pNew->next;
	pTmp->next = NULL;
}

/*******************************/
//链表排序(快排)
ListNode* GetPartion(ListNode* pBegin, ListNode* pEnd)
{
	int val = pBegin->val;
	ListNode* p = pBegin;
	ListNode* q = p->next;

	while (q != pEnd)
	{
		if (q->val < val)
		{
			p = p->next;
			swap(p->val, q->val);
		}

		q = q->next;
	}
	swap(p->val, pBegin->val);
	return p;
}

void List::QuickSort(ListNode* pBeign, ListNode* pEnd)
{
	if (pBeign != pEnd)
	{
		ListNode* partion = GetPartion(pBeign, pEnd);
		QuickSort(pBeign, partion);
		QuickSort(partion->next, pEnd);
	}
}
/*******************************/

//获得链表头节点
ListNode* List::Getfront()
{
	return this->head;
}

//打印整个链表
void List::PrintAll() {
	ListNode *p = head;
	if (p == NULL)
	{
		cout << "LinkList is NULL" << endl;
		return;
	}
	else {
		int i = 1;
		while (p) {
			cout << p->val << "-->";
			i++;
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

#endif
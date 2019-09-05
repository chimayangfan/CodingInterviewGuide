#pragma once
#ifndef __ZUOCHENGYUN_HPP__
#define __ZUOCHENGYUN_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.3
*   @remark:    程序员代码面试指南配套代码
*   @note:      原书为JAVA版本，整理成C++类版本
****************************************************************************/
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
#include <functional>//仿函数

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

//非成员函数声明
//bool isValid(string str);
//char getCharAt(string str, int k);
//void heapInsert(string &str, int index);
//void heapify(string &str, int index, int heapSize);
//void swap(string &str, int a, int b);
//void reverse(string &str, int start, int end);
//vector<int> value(string str, int i);
//void addNum(deque<string> &deq, int num);
//int getNum(deque<string> deq);

//*************************************************************************//
//							第1章 栈和队列问题
//*************************************************************************//
class Chapter1 {
public:
	void reverseOrderStack(stack<int> stack1);			//题目3：仅用递归函数和栈操作逆序一个栈
	void stacksort(stack<int> &stack1);					//题目4：用一个栈实现另一个栈的排序(大在底)							
	vector<int> getMaxWindow(vector<int> arr, int w);	//题目5：生成窗口最大值,w为窗口大小
	int maxSubMatrixSize(vector<vector<int> > map);		//题目6：求最大子矩阵大小																								
	int getNum(vector<int> arr, int k);					//题目7：最大值减去最小值小于或等于num的数量
};
//////////////////////////////////////////////////////////

//class Chapter1成员函数定义
#ifndef Chapter1Class 
#define Chapter1Class
//设计一个有getMin功能的栈
class GetMinStack {
private:
	stack<int> stackData;//数据栈，压栈的数据
	stack<int> stackMin;//辅助栈，从栈顶到栈底 由小到大有序的数据
public:
	//压入栈中
	void push(int value) {
		//将数据压入栈中
		stackData.push(value);
		//如果辅助栈是空的则直接压入
		if (stackMin.empty()) {
			stackMin.push(value);
		}
		else if (value < stackMin.top()) {
			//value比栈顶元素小
			stackMin.push(value);
		}
	}

	//弹栈
	int pop() {
		//如果数据栈中已空,则 返回 -1
		if (stackData.empty()) {
			return -1;
		}
		//数据栈弹出
		int value = stackData.top();
		stackData.pop();
		if (value == stackMin.top()) {
			stackMin.pop();
		}
		return value;
	}
	//获取最小值
	int getMin() {
		//获取辅助栈顶元素即可
		return stackMin.top();
	}
};

//用两个栈实现队列，可以进行 push、pop、front 操作
class TwostacksQueue {
private:
	stack<int> stack01;//数据栈，压栈的数据
	stack<int> stack02;//辅助栈，stack01的逆序
public:
	//队尾入
	void push(int value) {
		//将辅助栈中的元素转移到 01栈中,保证新的元素在以前元素的后面
		while (!stack02.empty()) {
			stack01.push(stack02.top());
			stack02.pop();
		}
		stack01.push(value);
	}
	//队头出
	int pop() {
		//如果01栈和02栈都为空，则说明队列为空了
		if (stack01.empty() && stack02.empty()) {
			return -1;
		}
		//如果02不为空,则说明是连续的出队列操作，此时所有的元素都在02栈中，直接出02栈即可
		if (!stack02.empty()) {
			int top = stack02.top();
			stack02.pop();
			return top;
		}
		//02栈为空,将01栈中的元素转移到02栈中，保证01最底部的元素在02的栈顶
		while (!stack01.empty()) {
			stack02.push(stack01.top());
			stack01.pop();
		}
		int top = stack02.top();
		stack02.pop();
		return top;
	}
	//查看队头数据
	int front() {
		//如果02栈为空，则说明 队列为空了
		if (stack02.empty()) {
			return -1;
		}
		int top = stack02.top();
		stack02.pop();
		return top;
	}
	bool empty() {
		//如果01栈和02栈都为空，则说明 队列为空了
		return stack01.empty() && stack02.empty();
	}
};

//题目3：仅用递归函数和栈操作逆序一个栈
int getAndRemoveLastnum(stack<int> stack1) {
	int result = stack1.top();
	stack1.pop();
	if (stack1.empty()) {
		return result;
	}
	else {
		int last = getAndRemoveLastnum(stack1);
		stack1.push(result);
		return last;
	}
}
void Chapter1::reverseOrderStack(stack<int> stack1) {
	if (stack1.empty()) {
		return;
	}
	else {
		int i = getAndRemoveLastnum(stack1);
		reverseOrderStack(stack1);
		stack1.push(i);
	}
}

//题目4：用一个栈实现另一个栈的排序
void Chapter1::stacksort(stack<int> &stack1) {
	stack<int> heleStack;//辅助栈
	int vlaue = 0; //辅助变量 暂存栈中弹出的元素
	while (!stack1.empty()) {
		vlaue = stack1.top();
		stack1.pop();
		while (!heleStack.empty() && vlaue< heleStack.top()) {
			stack1.push(heleStack.top());
			heleStack.pop();
		}
		heleStack.push(vlaue);
	}
	// 此时 辅助栈中栈顶到栈底 是从大到小的,再放进原栈中，则元素为从小到大
	while (!heleStack.empty()) {
		stack1.push(heleStack.top());
		heleStack.pop();
	}
}

//题目5：生成窗口最大值
vector<int> Chapter1::getMaxWindow(vector<int> arr, int w) {
	if (arr.size() == 0) {
		return arr;
	}
	//存放最终结果
	int length = arr.size();
	//比如 length =4，w=3, 则有两个窗口最大值
	vector<int> res(length - w + 1);
	int index = 0;
	//存放数组的索引
	deque<int> deq;
	//循环数组
	for (int i = 0; i < arr.size(); ++i) {
		while (!deq.empty() && arr[deq.back()] < arr[i]) {
			deq.pop_back();
		}
		deq.push_back(i);
		//如果 qmax中第一个存放的索引失效，则删除，比如 i=5,w=3,则 5-3=2 索引2和2之前的都是失效的
		if (deq.front() <= i - w) {
			deq.pop_front();
		}
		//最大值结果是从 i>=w-1开始的记录的，例如 i=1 ,w=3 ,3-1=2, 此时还未到第一个窗口
		if (i >= w - 1) {
			res[index++] = arr[deq.front()];
		}
	}
	return res;
}

//题目6：求最大子矩阵大小
int getMatrixMaxSize(vector<int> height) {
	if (height.size() == 0) {
		return 0;
	}
	int maxSize = 0;
	stack<int> stack1;
	for (int i = 0; i < height.size(); i++) {
		while (!stack1.empty() && height[i] <= height[stack1.top()]) {
			int j = stack1.top();
			stack1.pop();
			int k = stack1.empty() ? -1 : stack1.top();
			//例如： i=6,k =4 则 元素的边界为4到6,
			maxSize = max((i - k - 1) * height[j], maxSize);
		}
		stack1.push(i);
	}
	//栈中可能还有未计算完的元素，此时height的长度作为元素的边界
	while (!stack1.empty()) {
		int j = stack1.top();
		stack1.pop();
		int k = stack1.empty() ? -1 : stack1.top();
		maxSize = max((height.size() - k - 1) * height[j], maxSize);
	}
	return maxSize;
}
int Chapter1::maxSubMatrixSize(vector<vector<int> > map) {
	if (map.size() == 0) {
		return 0;
	}
	vector<int> height(map[0].size());
	int maxSize = 0;
	for (int i = 0; i < map.size(); i++) {
		//每一行中，子矩阵的高度
		for (int j = 0; j < map[0].size(); j++) {
			height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
		}
		maxSize = max(getMatrixMaxSize(height), maxSize);
	}
	return maxSize;
}

//题目7：最大值减去最小值小于或等于num的数量
int Chapter1::getNum(vector<int> arr, int k) {
	//存放最大值的索引
	deque<int> qmax;
	//存放最小值的索引
	deque<int> qmin;
	int i = 0;
	int j = 0;
	int res = 0;
	while (i < arr.size()) {
		while (j < arr.size()) {
			while (!qmax.empty() && arr[qmax.back()] < arr[j]) {
				qmax.pop_back();
			}
			qmax.push_back(j);
			while (!qmin.empty() && arr[qmin.back()] > arr[j]) {
				qmin.pop_back();
			}
			qmin.push_back(j);
			//左边界为i 右边界向右能扩展的最大距离
			if (arr[qmax.front()] - arr[qmin.front()] > k) {
				break;
			}
			j++;
		}
		if (i == qmax.front()) {
			qmax.pop_front();
		}
		if (i == qmin.front()) {
			qmin.pop_front();
		}
		res += j - i;
		i++;
	}
	return res;
}
#endif

//*************************************************************************//
//							第2章 链表问题
//*************************************************************************//
//单向节点定义
struct Node {
	int value;
	struct Node *next;
	Node(int x) :
		value(x), next(nullptr) {
	}
};
//双向节点定义
struct DoubleNode {
	int value;
	struct DoubleNode *last;
	struct DoubleNode *next;
	DoubleNode(int x) :
		value(x), last(nullptr), next(nullptr) {
	}
};
//带有随机指针节点定义
struct RandNode {
	int value;
	struct RandNode *rand;
	struct RandNode *next;
	RandNode(int x) :
		value(x), rand(nullptr), next(nullptr) {
	}
};

class Chapter2 {
private:
	Node* Nodehead;					//单向链表头结点指针
	DoubleNode* DoubleNodehead;		//双向链表头结点指针
	RandNode* RandNodehead;			//随机指针链表头结点指针
public:
	Chapter2() {};
	Chapter2(int* &table, int n);	//利用动态数组构造链表
	Chapter2(vector<int> vec);		//利用动态数组构造链表
	Node* GetNodefront();			//获得单向链表头节点

	void printCommonNode(Node* head1, Node* head2);				//题目1：打印两个有序链表公共部分
	void removeKNode(Node* &head, int k);						//题目2：在单链表中删除倒数第K个节点
	void removeKDoubleNode(DoubleNode* &head, int k);			//题目2：在双链表中删除倒数第K个节点
	void removeMidNode(Node* &head);							//题目3：删除中间节点
	void removeNodeByRatio(Node* &head, int a, int b);			//题目3：删除a/b处的节点																							
	void reverseNodeList(Node* &head);							//题目4：反转单向链表
	void reverseDNodeList(DoubleNode* &head);					//题目4：反转双向链表
	void ReversePartList(Node* &pHead, int from, int to);		//题目4：反转部分单向链表
	void josephusKill1(Node* &head, int m);						//题目5：环形单链表约瑟夫问题|方式1：遍历链表m个节点，时间复杂度为O( n * m)																
	void josephusKill2(Node* &head, int m);						//题目5：环形单链表约瑟夫问题|方式2：不删除节点，时间复杂度为O(n)
	bool isPalindrome1(Node* head);								//题目6：判断一个链表是否为回文结构|方式1：利用辅助栈，时间复杂度为O(N),空间复杂度(N)
	bool isPalindrome2(Node* head);								//题目6：判断一个链表是否为回文结构|方式2：利用辅助栈，只压入一半节点，时间复杂度为O(N),空间复杂度(N)
	bool isPalindrome3(Node* head);								//题目6：判断一个链表是否为回文结构|方式3：链表右半区域翻转，时间复杂度为O(N),空间复杂度(1)
	Node* partition(Node* head, int pivot);						//题目7：将单链表按某值划分为左边小，中间相等，右边大的链表															
	RandNode* copyNode(RandNode* head);							//题目8：复制含有随机指针节点的链表
	Node* addList(Node* head1, Node* head2);					//题目9：两个单链表生成相加链表																
	Node* getLoopNode(Node* head);								//题目10：判断链表是否有环，若有则返回环节点|Part1：判断一条链表是否有环，返回环入口节点												
	Node* noLoop(Node* head1, Node* head2);						//题目10：判断链表是否有环，若有则返回环节点|Part2：判断两条无环链表是否相交，返回第一个相交节点
	Node* getIntersectNode(Node* head1, Node* head2);			//题目10：判断链表是否有环，若有则返回环节点|Part3：判断两条有环链表是否相交，返回第一个相交节点
	Node* reverseKNode1(Node* head, int k);						//题目11：将单链表每K个节点之间逆序|方式1：利用辅助栈，时间复杂度为O( n ),空间复杂度为O( n )
	Node* reverseKNode2(Node* head, int k);						//题目11：将单链表每K个节点之间逆序|方式2：利用辅助栈，时间复杂度为O(n), 空间复杂度为O(n)
	Node* reverseKNode3(Node* head, int k);						//题目11：将单链表每K个节点之间逆序|方式3：直接逆序调整
	void removeDuplication1(Node* &head);						//题目12：删除链表中重复节点|第一种：只保留重复节点中的一个，利用set特性
	void removeDuplication2(Node* &head);						//题目12：删除链表中重复节点|第二种：删除有序链表全部重复节点
	void removeValue1(Node* &head, int num);					//题目13：在单链表中删除指定值的节点|方式1：利用辅助栈，时间复杂度为O( n ),空间复杂度为O( n )
	void removeValue2(Node* &head, int num);					//题目13：在单链表中删除指定值的节点|方式2：直接调整,时间复杂度为O( n ),空间复杂度为O( 1 )
	void treeToDubleNode(DoubleNode* &head);					//题目14：将搜索二叉树转换成双向链表
	void selectSort(Node* &head);								//题目15：单链表的选择排序，额外空间复杂度O(1)
	void insertNum(Node* &head, int num);						//题目16：向有序的环形单链表中插入新节点
	Node* meige(Node* head1, Node* head2);						//题目17：合并两个有序单链表|方式1：迭代																
	Node* reverseMeige(Node* head1, Node* head2);				//题目17：合并两个有序单链表|方式2：递归
	void relocate(Node* &head);									//题目18：按照左右半区的方式重新组合单链表
};
////////////////////////////////////////////////////////////////

//class Chapter2成员函数定义
#ifndef Chapter2Class 
#define Chapter2Class
//利用动态数组构造链表
Chapter2::Chapter2(int* &table, int n)
{
	Nodehead = nullptr;
	if (n>0)
	{
		Nodehead = new Node(table[0]);//创建节点  
		Node* rear = Nodehead;//创建一个指向头节点的指针  
		int i = 1;
		while (i<n)
		{
			rear->next = new Node(table[i++]);
			rear = rear->next;
		}
	}
}
//利用vector动态数组构造链表
Chapter2::Chapter2(vector<int> vec)
{
	Nodehead = nullptr;
	int n = vec.size();
	if (n>0)
	{
		Nodehead = new Node(vec[0]);//创建节点  
		Node* rear = Nodehead;//创建一个指向头节点的指针  
		int i = 1;
		while (i<n)
		{
			rear->next = new Node(vec[i++]);
			rear = rear->next;
		}
	}
}
//获得链表头节点
Node* Chapter2::GetNodefront()
{
	return this->Nodehead;
}

//题目1：打印两个有序链表公共部分
void Chapter2::printCommonNode(Node* head1, Node* head2) {
	while (head1 != nullptr && head2 != nullptr) {
		if (head1->value < head2->value) {
			head1 = head1->next;
		}
		else if (head1->value>head2->value) {
			head2 = head2->next;
		}
		else {
			cout << head1->value << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}

//题目2：在单链表中删除倒数第K个节点
void Chapter2::removeKNode(Node* &head, int k) {
	if (head == nullptr || k < 1) {
		return;
	}
	Node* cur = head;
	while (cur != nullptr) {
		k--;
		cur = cur->next;
	}
	//此时k==0，说明原始K等于链表长度;
	if (k == 0) {
		head = head->next;
	}
	if (k < 0) {
		cur = head;
		while (++k != 0) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
}

//题目2：在双链表中删除倒数第K个节点
void Chapter2::removeKDoubleNode(DoubleNode* &head, int k) {
	if (head == nullptr || k < 1) {
		return;
	}
	DoubleNode* cur = head;
	while (cur != nullptr) {
		k--;
		cur = cur->next;
	}
	//此时k==0，说明原始K等于链表长度;
	if (k == 0) {
		head = head->next;
		head->last = nullptr;
	}
	if (k < 0) {
		cur = head;
		while (++k != 0) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		if (cur->next->next != nullptr) {
			cur->next->next->last = cur;
		}
	}
}

//题目3：删除中间节点
void Chapter2::removeMidNode(Node* &head) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	Node* node1 = head;
	Node* node2 = node1->next->next;
	//获取中间节点的前驱节点 ，因为让node2早走一步，当node2走完时，node1刚好是中间节点的前驱节点
	while (node2->next != nullptr && node2->next->next != nullptr) {
		node1 = node1->next;
		node2 = node2->next->next;
	}
	node1->next = node1->next->next;
}

//题目3：删除a/b处的节点
void Chapter2::removeNodeByRatio(Node* &head, int a, int b) {
	if (head == nullptr) {
		return;
	}
	Node* cur = head;
	int len = 0;//节点长度
	while (cur != nullptr) {
		len++;
		cur = cur->next;
	}
	//边界检查
	if (a < 0 || b <= 0) {

	}
	//ceil(x)返回的是大于x的最小整数
	int k = ceil((double)(a* len) / (double)b);
	//如果k==1 说明a/b处是头节点
	if (k == 1) {
		head = head->next;
	}
	if (k>1) {
		cur = head;
		//提前减一，这样当k=1时，节点为 k处的前驱节点
		while (--k != 1) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
}

//题目4：反转单向链表
void Chapter2::reverseNodeList(Node* &head) {
	if (head == nullptr) {
		return;
	}
	Node* pre = nullptr;
	Node* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	head = pre;
}

//题目4：反转双向链表
void Chapter2::reverseDNodeList(DoubleNode* &head) {
	if (head == nullptr) {
		return;
	}
	DoubleNode* pre = nullptr;
	DoubleNode* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		head->last = next;
		pre = head;
		head = next;
	}
	head = pre;
}

//题目4：反转部分单向链表
void Chapter2::ReversePartList(Node* &pHead, int from, int to) {
	int len = 0;
	Node* node1 = pHead;
	Node* fpre = nullptr;
	Node* tpos = nullptr;
	while (node1)
	{
		len++;
		fpre = len == from - 1 ? node1 : fpre;//fpre指向待反转部分前一个节点
		tpos = len == to + 1 ? node1 : tpos;//tpos指向待反转部分后一个节点
		node1 = node1->next;
	}
	if (from > to || from < 1 || to > len) return;
	node1 = fpre == nullptr ? pHead : fpre->next;
	Node* node2 = node1->next;
	node1->next = tpos;

	//就地反转
	Node* q = nullptr;

	while (node2 != tpos)
	{
		q = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = q;
	}
	if (fpre != nullptr)
	{
		fpre->next = node1;
	}
	else
		pHead = node1;
}

//题目5：环形单链表约瑟夫问题
//方式1：遍历链表m个节点，时间复杂度为O( n * m)
void Chapter2::josephusKill1(Node* &head, int m) {
	if (head == nullptr || m < 1)
		return;
	Node* last = head;
	//定位到最后一个节点
	while (head->next != last) {
		head = head->next;
	}
	int count = 0;
	while (head->next != head) {
		if (++count == m) {
			head->next = head->next->next;
			count = 0;
		}
		else {
			head = head->next;
		}
	}
}

//方式2：不删除节点，时间复杂度为O(n)
int getlive(int n, int m) {
	if (n == 1) {
		return 1;
	}
	return (getlive(n - 1, m) + m - 1) % n + 1;
}
void Chapter2::josephusKill2(Node* &head, int m) {
	if (head == nullptr || m < 1)
		return;
	int n = 1;//统计一共有多少个节点
	Node* last = head;
	while (last->next != head) {
		n++;
		last = last->next;
	}
	//直接用递归算出目的编号
	int des = getlive(n, m);
	//把目的节点取出来
	while (--des != 0) {
		head = head->next;
	}
	head->next = head;
}

//题目6：判断一个链表是否为回文结构
//方式1：利用辅助栈，时间复杂度为O(N),空间复杂度(N)
bool Chapter2::isPalindrome1(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;
	stack<Node*> stack;
	Node* cur = head;
	while (cur != nullptr)
	{
		stack.push(cur);
		cur = cur->next;
	}
	cur = head;
	while (!stack.empty())
	{
		if (stack.top()->value != cur->value)
		{
			return false;
		}
		stack.pop();
		cur = cur->next;
	}
	return true;
}
//方式2：利用辅助栈，只压入一半节点，时间复杂度为O(N),空间复杂度(N)
bool Chapter2::isPalindrome2(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;

	stack<Node*> stack;
	Node* fast = head, *slow = head->next;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	while (slow != nullptr)
	{
		stack.push(slow);
		slow = slow->next;
	}

	while (!stack.empty())
	{
		if (stack.top()->value != head->value)
		{
			return false;
		}
		stack.pop();
		head = head->next;
	}
	return true;
}
//方式3：链表右半区域翻转，时间复杂度为O(N),空间复杂度(1)
bool Chapter2::isPalindrome3(Node* head) {
	if (head == nullptr || head->next == nullptr)
		return true;
	Node* fast = head, *slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;//中间节点
		fast = fast->next->next;//尾节点
	}
	fast = slow->next;//fast->右部分第一个节点
	slow->next = nullptr;//中间节点下一个节点->null
	Node* pre = nullptr;
	while (fast != nullptr)//右半区反转
	{
		pre = fast->next;//pre->保存下一节点
		fast->next = slow;//下一个反转节点
		slow = fast;//slow移动
		fast = pre;//fast移动
	}
	pre = slow;//pre->保存最后一个节点
	fast = head;//fast->左边第一个节点
	bool res = true;
	while (slow != nullptr && fast != nullptr)//检查回文
	{
		if (slow->value != fast->value)
		{
			res = false;
			break;
		}
		slow = slow->next;//从左到中部
		fast = fast->next;//从右到中部
	}
	slow = pre->next;
	pre->next = nullptr;
	while (slow != nullptr)
	{
		fast = slow->next;
		slow->next = pre;
		pre = slow;
		slow = fast;
	}
	return res;
}

//题目7：将单链表按某值划分为左边小，中间相等，右边大的链表
//例如 链表 1-2-3-6-7-8-5-4-9-10 ，按5分为左边小,中间相等，右边大的链表，1-2-3-4-5-6-7-8-9-10
Node* Chapter2::partition(Node* head, int pivot) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* sH = nullptr;//小的链表的头节点
	Node* sT = nullptr;//小的链表的尾节点
	Node* eH = nullptr;//相等的链表的头节点
	Node* eT = nullptr;//相等的链表的头节点
	Node* bH = nullptr;//大的链表的头节点
	Node* bT = nullptr;//大的链表的尾节点
	Node* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = nullptr;
		if (head->value < pivot) {
			if (sH == nullptr) {
				sH = head;
				sT = head;
			}
			else {
				sT->next = head;
				sT = head;
			}
		}
		else if (head->value == pivot) {
			if (eH == nullptr) {
				eH = head;
				eT = head;
			}
			else {
				eT->next = head;
				eT = head;
			}
		}
		else {
			if (bH == nullptr) {
				bH = head;
				bT = head;
			}
			else {
				bT->next = head;
				bT = head;
			}
		}
		head = next;
	}
	//重新连接
	if (sT != nullptr) {
		sT->next = eH;
		eT = eT == nullptr ? sT : eT;
	}
	if (eT != nullptr) {
		eT->next = bH;
	}
	return sH != nullptr ? sH : eH != nullptr ? eH : bH;
}

//题目8：复制含有随机指针节点的链表
RandNode* Chapter2::copyNode(RandNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	//复制一份节点
	RandNode* cur = head;
	RandNode* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next->value = cur->value;
		cur->next->next = next;
		cur = next;
	}
	//复制一份随机数节点
	cur = head;
	while (cur != nullptr) {
		next = cur->next;
		next->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
		cur = next->next;
	}
	//拆分
	cur = head;
	RandNode* newNodeHead = head->next;
	RandNode* tail = head->next;
	while (cur != nullptr) {
		next = cur->next->next;
		tail->next = next == nullptr ? nullptr : next->next;
		tail = next == nullptr ? nullptr : next->next;
		cur->next = next;
		cur = next;
	}
	return newNodeHead;
}

//题目9：两个单链表生成相加链表
Node* reverseList(Node* head) {
	Node* pre = nullptr;
	Node* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}
Node* Chapter2::addList(Node* head1, Node* head2) {
	head1 = reverseList(head1);
	head2 = reverseList(head2);
	int n1 = 0;
	int n2 = 0;
	int n = 0;
	int ca = 0;
	Node* node = nullptr;
	Node* pre = nullptr;
	Node* c1 = head1;
	Node* c2 = head2;

	while (c1 != nullptr || c2 != nullptr) {
		n1 = c1 == nullptr ? 0 : c1->value;
		n2 = c2 == nullptr ? 0 : c2->value;
		n = n1 + n2 + ca;
		pre = node;
		node = new Node(n % 10);
		node->next = pre;
		ca = n / 10;
		c1 = c1 != nullptr ? c1->next : nullptr;
		c2 = c2 != nullptr ? c2->next : nullptr;
	}
	if (ca == 1) {
		pre = node;
		node->value = ca;
		node->next = pre;
	}
	//复原
	reverseList(head1);
	reverseList(head2);
	return node;
}

//题目10：判断链表是否有环，若有则返回环节点。
//Part1：判断一条链表是否有环，返回环入口节点
Node* Chapter2::getLoopNode(Node* head) {
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;
	Node* slow = head->next;
	Node* fast = head->next->next;
	while (slow != fast) {
		if (slow->next == nullptr || fast->next->next) {
			return nullptr;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//Part2：判断两条无环链表是否相交，返回第一个相交节点
Node* Chapter2::noLoop(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	Node* cur1 = head1;
	Node* cur2 = head2;
	int n1 = 0, n2 = 0;
	while (cur1->next == nullptr) {
		n1++;
		cur1 = cur1->next;//记录尾节点
	}
	while (cur2->next == nullptr) {
		n2++;
		cur2 = cur2->next;//记录尾节点
	}
	if (cur1 != cur2) {
		return nullptr;
	}
	cur1 = n1 > n2 ? head1 : head2;//指向长链表
	cur2 = cur1 == head1 ? head2 : head1;//指向短链表
	n1 = n1 > n2 ? n1 - n2 : n2 - n1;//链表长度差
	while (n1)
	{
		cur1 = cur1->next;//长链表先走n1步
		n1--;
	}
	while (cur1 != cur2)//同时走到节点
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

//Part2：判断两条有环链表是否相交，返回第一个相交节点
Node* bothLoop(Node* head1, Node* Loop1, Node* head2, Node* Loop2) {
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	Node* cur1 = nullptr;
	Node* cur2 = nullptr;
	if (Loop1 == Loop2) {
		cur1 = head1;
		cur2 = head2;
		int n1 = 0, n2 = 0;
		while (cur1->next == nullptr) {
			n1++;
			cur1 = cur1->next;//记录尾节点
		}
		while (cur2->next == nullptr) {
			n2++;
			cur2 = cur2->next;//记录尾节点
		}
		if (cur1 != cur2) {
			return nullptr;
		}
		cur1 = n1 > n2 ? head1 : head2;//指向长链表
		cur2 = cur1 == head1 ? head2 : head1;//指向短链表
		n1 = n1 > n2 ? n1 - n2 : n2 - n1;//链表长度差
		while (n1)
		{
			cur1 = cur1->next;//长链表先走n1步
			n1--;
		}
		while (cur1 != cur2)//同时走到节点
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else {
		cur1 = Loop1->next;
		while (cur1 != Loop1) {
			if (cur1 == Loop2) {
				return Loop1;
			}
			cur1 = cur1->next;
		}
		return nullptr;
	}
}
Node* Chapter2::getIntersectNode(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	Node* Loop1 = getLoopNode(head1);
	Node* Loop2 = getLoopNode(head2);
	if (Loop1 == nullptr && Loop2 == nullptr) {
		return noLoop(head1, head2);
	}
	if (Loop1 == nullptr && Loop2 == nullptr) {
		return bothLoop(head1, Loop1, head2, Loop2);
	}
	return nullptr;
}

//题目11：将单链表每K个节点之间逆序
//方式1：利用辅助栈，时间复杂度为O( n ),空间复杂度为O( n )
Node* resign(stack<Node* > &s, Node* left, Node* right)
{
	Node* cur = s.top(); s.pop();
	left->next = cur;
	while (!s.empty())
	{
		Node* next = s.top(); s.pop();
		cur->next = next;
		cur = next;
	}
	cur->next = right;
	return cur;
}
Node* Chapter2::reverseKNode1(Node* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2)
		return head;
	Node* newHead = new Node(-1);
	newHead->next = head;
	Node* pre = newHead;
	Node* cur = head;
	stack<Node* > s;
	while (cur != nullptr)
	{
		Node* next = cur->next;
		s.push(cur);
		if (s.size() == k)
		{
			pre = resign(s, pre, next);
		}
		cur = next;
	}
	return newHead->next;
}

//方式2：利用辅助栈，时间复杂度为O( n ),空间复杂度为O( n )
Node* kReverse(Node* head, int k)
{
	Node* cur = head;
	Node* prv = nullptr;
	while (k--)
	{
		Node* next = cur->next;
		cur->next = prv;
		prv = cur;
		cur = next;
	}

	/*
	* 这里比较重要，因为逆序后，prv变成第一个节点，head变成最后一个节点
	* 此时需要改变head的next指向逆序前的第k+1个节点
	* 这个节点正好是cur
	*/
	head->next = cur;
	return prv;
}
int listLen(Node* head)
{
	int n = 0;
	while (head)
	{
		++n;
		head = head->next;
	}

	return n;
}
Node* Chapter2::reverseKNode2(Node* head, int k) {
	if (!head || k <= 1)
		return head;

	/* 计算链表节点数 */
	int n = listLen(head);

	Node* header = new Node(-1);
	header->next = head;

	Node* cur = header;
	while (n >= k)
	{
		/*
		* 记录当前节点的下一个节点，从下一个节点开始逆序k个
		* 返回逆序后的第一个节点，这个next节点变成第k个节点
		* 移动k步
		* 总数-k，判断是否还需要继续逆序
		*/
		Node* next = cur->next;
		cur->next = kReverse(next, k);
		cur = next;
		n -= k;
	}

	Node* res = header->next;
	delete header;
	return res;
}

//方式3：直接逆序调整
void resign(Node* left, Node* start, Node* end, Node* right)
{
	Node* pre = start;
	Node* cur = start->next;
	Node* next = nullptr;
	while (cur != right)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	left->next = end;
	start->next = right;

}
Node* Chapter2::reverseKNode3(Node* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2)
		return head;
	Node* newHead = new Node(-1);
	newHead->next = head;
	Node* pre = newHead;
	Node* start = head;
	Node* cur = head;
	Node* next = nullptr;
	int count = 1;
	while (cur != nullptr)
	{
		next = cur->next;
		if (count == k)
		{
			start = pre->next;
			resign(pre, start, cur, next);
			pre = start;
			count = 0;
		}
		++count;
		cur = next;
	}
	return newHead->next;
}

//题目12：删除链表中重复节点
//第一种：只保留重复节点中的一个，利用set特性
void Chapter2::removeDuplication1(Node* &head) {
	if (head == nullptr)
	{
		return;
	}
	set<int> hash;
	Node* pre = head;
	Node* cur = head->next;

	hash.insert(head->value); //构造hash表，并且检查当前结点是否在hash表中存在
	while (cur != nullptr)
	{
		if (hash.insert(cur->value).second)
		{
			pre->next = cur;
			pre = pre->next;
		}
		cur = cur->next;
	}
}

//第二种：删除有序链表全部重复节点
void Chapter2::removeDuplication2(Node* &head)
{
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* p = dummy;
	while (p->next)
	{
		Node* q = p->next;
		while (q && q->value == p->next->value)
			q = q->next;
		if (p->next->next == q) p = p->next;
		else p->next = q;
	}
}

//题目13：在单链表中删除指定值的节点
//方式1：利用辅助栈，时间复杂度为O( n ),空间复杂度为O( n )
void Chapter2::removeValue1(Node* &head, int num) {
	stack<Node*> list;
	while (head != nullptr)
	{
		if (head->value != num)
		{
			list.push(head);
		}
		head = head->next;
	}
	while (!list.empty())
	{
		list.top()->next = head;
		head = list.top();
		list.pop();
	}
}

//方式3：直接调整
void Chapter2::removeValue2(Node* &head, int num) {
	if (head == nullptr) return;
	while (head != nullptr)
	{
		if (head->value != num) {
			break;
		}
		head = head->next;
	}
	Node* pre = head;
	Node* cur = head;
	while (cur != nullptr)
	{
		if (cur->value == num) {
			pre->next = cur->next;
		}
		else {
			pre = cur;
		}
		cur = cur->next;
	}
}

//题目14：将搜索二叉树转换成双向链表
void recInOrder(DoubleNode* head, queue<DoubleNode*> que) {
	if (head == nullptr) {
		return;
	}
	recInOrder(head->last, que);
	que.push(head);
	recInOrder(head->next, que);
}
void Chapter2::treeToDubleNode(DoubleNode* &head) {
	//用队列存放将树的中序遍历
	queue<DoubleNode*> trees;
	//中序遍历
	recInOrder(head, trees);
	//构造双向链表
	head = trees.front();
	trees.pop();
	DoubleNode* pre = head;
	DoubleNode* cur = nullptr;
	while (!trees.empty()) {
		cur = trees.front();
		trees.pop();
		pre->next = cur;
		cur->last = pre;
		pre = cur;
	}
	pre->next = nullptr;
}

//题目15：单链表的选择排序，额外空间复杂度O(1)
Node* getSmallestPreNode(Node* head) {
	Node* smallPre = nullptr;
	Node* small = head;
	Node* pre = head;
	Node* cur = head->next;
	while (cur != nullptr) {
		if (cur->value < small->value) {
			smallPre = pre;
			small = cur;
		}
		pre = cur;
		cur = cur->next;
	}
	return smallPre;
}
void Chapter2::selectSort(Node* &head) {
	Node* tail = nullptr;//排序部分尾部
	Node* cur = head;//未排序部分头部
	Node* smallPre = nullptr;//最小节点的前一个节点
	Node* small = nullptr;//最小的节点
	while (cur != nullptr) {
		small = cur;
		smallPre = getSmallestPreNode(cur);
		if (smallPre != nullptr) {
			small = smallPre->next;
			smallPre->next = small->next;
		}
		cur = cur == small ? cur->next : cur;
		if (tail == nullptr) {
			head = small;
		}
		else {
			tail->next = small;
		}
		tail = small;
	}
}

//题目16：向有序的环形单链表中插入新节点
void  Chapter2::insertNum(Node* &head, int num) {
	Node* node = new Node(num);
	if (head == nullptr) {
		node->next = node;
		return;
	}
	Node* pre = head;//待插入前节点
	Node* cur = head->next;//待插入后节点
	while (cur != head) {
		if (pre->value < num && cur->value > num) {
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = node;
	node->next = cur;
	head = head->value < num ? head : node;
}

//题目17：合并两个有序单链表
//方式1：迭代
Node* Chapter2::meige(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr)
		return head1 != nullptr ? head1 : head2;
	Node* head = head1->value < head2->value ? head1 : head2;
	Node* cur1 = head == head1 ? head1 : head2;
	Node* cur2 = head == head1 ? head2 : head1;
	Node* pre = nullptr;
	Node* next = nullptr;
	while (cur1 != nullptr && cur2 != nullptr) {
		if (cur1->value <= cur2->value) {
			pre = cur1;
			cur1 = cur1->next;
		}
		else {
			next = cur2->next;
			pre->next = cur2;
			cur2->next = cur1;
			pre = cur2;
			cur2 = next;
		}
	}
	pre->next = cur1 == nullptr ? cur2 : cur1;
	return head;
}
//方式2：递归
Node* Chapter2::reverseMeige(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr)
		return head1 != nullptr ? head1 : head2;
	Node* head = nullptr;
	if (head1->value < head2->value) {
		head = head1;
		head->next = reverseMeige(head1->next, head2);
	}
	else {
		head = head2;
		head->next = reverseMeige(head1, head2->next);
	}
	return head;
}

//题目18：按照左右半区的方式重新组合单链表
//例：链表长度N，前N/2为左半区，后N/2（或N/2+1）为后半区，调整为L1->R1->L2->R2
//1->2->3->4->5->NULL,调整为1->3->2->4->5->NULL
void Chapter2::relocate(Node* &head) {
	if (head == nullptr) return;
	Node* mid = head;
	Node* right = head->next;
	while (right->next != nullptr && right->next->next != nullptr) {
		mid = mid->next;
		right = right->next->next;
	}
	right = mid->next;
	mid->next = nullptr;
	Node* left = head;
	Node* next = nullptr;
	while (left->next != nullptr) {
		next = right->next;
		right->next = left->next;
		left->next = right;
		left = right->next;
		right = next;
	}
	left->next = right;
}
#endif

//*************************************************************************//
//							第3章 二叉树问题
//*************************************************************************//
#define PrevOrderCreat 1	//前序创建
#define LevelOrderCreat 2	//层序创建

#define CreatTreeMethod PrevOrderCreat

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Chapter3 {
private:
	TreeNode* root;//根节点
public:
	Chapter3() :root(NULL) {};//无参的构造函数
	Chapter3(const int* a, size_t size, const int& invalid);//有参构造函数		
	Chapter3(const Chapter3 &t);//拷贝构造
	Chapter3& operator=(Chapter3 t);//赋值运算符的重载
	~Chapter3();//析构函数
	TreeNode* GetTreeRoot();//获得二叉树根节点

	void reservePreOrder(TreeNode* root);				//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式1：递归先序
	void reserveInOrder(TreeNode* root);				//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式2：递归中序
	void reservePosOrder(TreeNode* root);				//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式3：递归后序
	void PreOrder(TreeNode* root);						//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式4：非递归先序
	void InOrder(TreeNode* root);						//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式5：非递归中序
	void PosOrder1(TreeNode* root);						//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式6：非递归后序1，使用双栈
	void PosOrder2(TreeNode* root);						//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式7：非递归后序2，使用单栈														
	void LevelOrder(TreeNode* root);					//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式8：非递归层序遍历
	void printEdge1(TreeNode* root);					//题目2：打印二叉树的边界节点|第一种情况：打印每层最左和最右的节点以及叶子节点
	void printEdge2(TreeNode* root);					//题目2：打印二叉树的边界节点|第二种情况：打印最左和最右的节点以及叶子节点
	string serialTreeByPre(TreeNode* root);				//题目3：二叉树的序列化与反序列化|方式1：根据先序遍历实现序列化
	TreeNode* unSerialTreeByPre(string str);			//题目3：二叉树的序列化与反序列化|方式1：根据先序遍历实现反序列化
	string serialTreeByLevel(TreeNode* root);			//题目3：二叉树的序列化与反序列化|方式2：根据层序遍历实现序列化
	TreeNode* unSerialTreeByLevel(string str);			//题目3：二叉树的序列化与反序列化|方式2：根据层序遍历实现反序列化
	void morrisInOrder(TreeNode* root);					//题目4：遍历二叉树的神级方法|方式1：morris中序
	void morrisPreOrder(TreeNode* root);				//题目4：遍历二叉树的神级方法|方式2：morris前序
	void morrisPostOrder(TreeNode* root);				//题目4：遍历二叉树的神级方法|方式3：morris后序
	int getMaxLength(TreeNode* root, int sum);			//题目5：在二叉树中找到累加和为指定值的最长路径长度

protected:
	TreeNode* _CreatBinaryTree(const int *a, size_t size, const int& invalid, size_t& index);	//创建二叉树TreeNode
	TreeNode* _Copy(TreeNode*  root);	//复制二叉树
	void _Delete(TreeNode*  &root);		//删除

};
/////////////////////////////////////////////////////////

//class Chapter3成员函数定义
#ifndef Chapter3Class 
#define Chapter3Class
//构造函数
Chapter3::Chapter3(const int* a, size_t size, const int& invalid)//有参构造函数	
	:root(NULL)
{
	size_t index = 0;
	root = _CreatBinaryTree(a, size, invalid, index);
}

//拷贝构造
Chapter3::Chapter3(const Chapter3 &t)
	:root(NULL)
{
	root = _Copy(t.root);
}

//赋值运算符的重载
Chapter3& Chapter3::operator=(Chapter3 t)
{
	if (this != &t)//防止自赋值
	{
		swap(root, t.root);
	}
	return *this;
}

//析构函数
Chapter3::~Chapter3()
{
	if (root)
	{
		_Delete(root);
	}
}

//获得二叉树根节点
TreeNode* Chapter3::GetTreeRoot() {
	return this->root;
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//成员函数
//创建二叉树TreeNode
TreeNode* Chapter3::_CreatBinaryTree(const int *a, size_t size, const int& invalid, size_t& index)
{
	TreeNode*  cur = NULL;
	if (index < size && a[index] != invalid)//不能越界
	{
		switch (CreatTreeMethod)
		{
		case PrevOrderCreat:
		{
			cur = new TreeNode(a[index]);//开辟节点
			cur->left = _CreatBinaryTree(a, size, invalid, ++index);//递归创建左子树
			cur->right = _CreatBinaryTree(a, size, invalid, ++index);//递归创建右子树
		}break;
		case LevelOrderCreat:
		{
			if (a[index] == invalid)return NULL;

			cur = new TreeNode(a[index]);//新建一个根结点

			size_t lnode = 2 * index + 1;
			size_t rnode = 2 * index + 2;

			if (lnode > size - 1) cur->left = NULL;
			else cur->left = _CreatBinaryTree(a, size, invalid, lnode);

			if (rnode > size - 1) cur->right = NULL;
			else cur->right = _CreatBinaryTree(a, size, invalid, rnode);
		}break;
		default:break;
		}
	}
	return cur;
}

//复制二叉树
TreeNode* Chapter3::_Copy(TreeNode*  root)
{
	TreeNode* cur = NULL;
	if (root == NULL)
	{
		return NULL;
	}

	cur = new TreeNode(root->val);//创建该节点

	cur->left = _Copy(root->left);
	cur->right = _Copy(root->right);
	return cur;
}

//删除函数
void Chapter3::_Delete(TreeNode* &root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)//该节点没有左右孩子
	{
		delete root;//释放该节点
		root = NULL;
		return;
	}
	_Delete(root->left);
	_Delete(root->right);
}
/////////////////////////////////////////////////////////
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式1：递归先序
void Chapter3::reservePreOrder(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->val << " ";
	reservePreOrder(root->left);
	reservePreOrder(root->right);
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式2：递归中序
void Chapter3::reserveInOrder(TreeNode* root) {
	if (root == nullptr) return;
	reserveInOrder(root->left);
	cout << root->val << " ";
	reserveInOrder(root->right);
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式3：递归后序
void Chapter3::reservePosOrder(TreeNode* root) {
	if (root == nullptr) return;
	reservePosOrder(root->left);
	reservePosOrder(root->right);
	cout << root->val << " ";
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式4：非递归先序
void Chapter3::PreOrder(TreeNode* root) {
	if (root == nullptr) return;
	stack<TreeNode*> stack;
	stack.push(root);
	while (!stack.empty()) {
		root = stack.top();
		stack.pop();
		cout << root->val << " ";
		if (root->right) {
			stack.push(root->right);
		}
		if (root->left) {
			stack.push(root->left);
		}
	}
	cout << endl;
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式5：非递归中序
void Chapter3::InOrder(TreeNode* root) {
	if (root == nullptr) return;
	stack<TreeNode*> stack;
	while (!stack.empty() || root != nullptr) {
		if (root != nullptr) {
			stack.push(root);
			root = root->left;
		}
		else
		{
			root = stack.top();
			stack.pop();
			cout << root->val << " ";
			root = root->right;
		}
	}
	cout << endl;
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式6：非递归后序1，使用双栈
void Chapter3::PosOrder1(TreeNode* root) {
	if (root == nullptr) return;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	while (!s1.empty()) {
		root = s1.top();
		s1.pop();
		s2.push(root);
		if (root->left) {
			s1.push(root->left);
		}
		if (root->right) {
			s1.push(root->right);
		}
	}
	while (!s2.empty()) {
		cout << s2.top()->val << " ";
		s2.pop();
	}
	cout << endl;
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式7：非递归后序1，使用单栈
void Chapter3::PosOrder2(TreeNode* root) {
	if (root == nullptr) return;
	stack<TreeNode*> s1;
	s1.push(root);
	TreeNode* node = nullptr;
	while (!s1.empty()) {
		node = s1.top();
		if (node->left != nullptr && root != node->left && root != node->right) {
			s1.push(node->left);
		}
		else if (node->right != nullptr && root != node->right) {
			s1.push(node->right);
		}
		else {
			cout << s1.top()->val << " ";
			s1.pop();
			root = node;
		}
	}
	cout << endl;
}
//题目1：分别用递归和非递归方式实现二叉树的先序、中序、后序遍历|方式8：非递归层序遍历
void Chapter3::LevelOrder(TreeNode* root) {
	if (root == nullptr) return;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		root = que.front();
		cout << root->val << " ";
		que.pop();
		if (root->left) {
			que.push(root->left);
		}
		if (root->right) {
			que.push(root->right);
		}
	}
	cout << endl;
}

//题目2：打印二叉树的边界节点|第一种情况：打印每层最左和最右的节点以及叶子节点
//获取树所有的最左最右节点
void getEdge(TreeNode* root, int level, vector<vector<TreeNode*> > &edge) {
	if (root == nullptr) {
		return;
	}
	edge[level][0] = edge[level][0] == NULL ? root : edge[level][0];
	edge[level][1] = root;
	getEdge(root->left, level + 1, edge);
	getEdge(root->right, level + 1, edge);
}
//打印最底部非左右边的叶子节点
void printLeaf(TreeNode* root, int level, vector<vector<TreeNode*> > edge) {
	if (root == nullptr) {
		return;
	}
	if (root->left == nullptr && root->right == nullptr && root->val != edge[level][0]->val && root->val != edge[level][1]->val) {
		cout << root->val << " ";
	}
	printLeaf(root->left, level + 1, edge);
	printLeaf(root->right, level + 1, edge);
}
//获取树的深度
int getDep(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftDep = getDep(root->left);
	int rightDep = getDep(root->right);
	return max(leftDep, rightDep) + 1;

}
void Chapter3::printEdge1(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	//获取树的深度，确定存放边节点值得数组的大小
	int dep = getDep(root);
	vector<vector<TreeNode*> > edge(dep, vector<TreeNode*>(2, 0));
	getEdge(root, 0, edge);
	//从上到下打印左边界
	for (int i = 0; i < edge.size(); i++) {
		cout << edge[i][0]->val << " ";
	}
	//用递归从左到右打印叶子节点
	printLeaf(root, 0, edge);
	//打印从下到上打印右边节点
	for (int i = edge.size() - 1; i >= 0; i--) {
		if (edge[i][1] != edge[i][0]) {
			cout << edge[i][1]->val << " ";
		}
	}
	cout << endl;
}

//题目2：打印二叉树的边界节点|第二种情况：打印最左和最右的节点以及叶子节点
//打印左节点
void printLeft(TreeNode* root, bool isPrint) {
	if (root == nullptr) {
		return;
	}
	//如果是左节点或者是叶子节点，则打印
	if (isPrint || (root->left == nullptr && root->right == nullptr)) {
		cout << root->val << " ";
	}
	//打印左节点
	printLeft(root->left, isPrint);
	//如果左节点为空，则打印其有节点
	printLeft(root->right, isPrint && root->left == nullptr ? true : false);
}
//打印右节点
void printRight(TreeNode* root, bool isPrint) {
	if (root == nullptr) {
		return;
	}
	//如果右节点为空先打印左节点
	printRight(root->left, isPrint && root->right == nullptr ? true : false);
	//如果左节点为空，则打印其有节点
	printRight(root->right, isPrint);
	//如果是左节点或者是叶子节点，则打印
	if (isPrint || (root->left == nullptr && root->right == nullptr)) {
		cout << root->val << " ";
	}
}
void Chapter3::printEdge2(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	//先打印根节点
	cout << root->val << " ";
	//如果树不是一个倾斜树
	if (root->left != nullptr && root->right != nullptr) {
		printLeft(root->left, true);
		printRight(root->right, true);
	}
	else {
		printEdge2(root->left == nullptr ? root->right : root->left);
	}
	cout << endl;
}

//题目3：二叉树的序列化与反序列化
//方式1：根据先序遍历实现序列化
string Chapter3::serialTreeByPre(TreeNode* root) {
	if (root == nullptr) {
		return "#!";
	}
	string res = root->val + "!";
	res += serialTreeByPre(root->left);
	res += serialTreeByPre(root->right);
	return res;
}
//方式1：根据先序遍历实现反序列化
void _split(const string &s, char delim,
	vector<string> &elems) {
	stringstream ss(s);
	string item;

	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
TreeNode* recPreOrder(queue<string> queue) {
	string value = queue.front();
	if (!value.compare("#")) {
		return nullptr;
	}

	TreeNode* root = new TreeNode(stoi(value));
	root->left = recPreOrder(queue);
	root->right = recPreOrder(queue);
	return root;
}
TreeNode* Chapter3::unSerialTreeByPre(string str) {
	if (str == "") {
		return nullptr;
	}
	vector<string> elems;
	_split(str, '#', elems);
	queue<string> queue;
	for (int i = 0; i < elems.size(); ++i) {
		queue.push(elems[i]);
	}
	return recPreOrder(queue);
}

//方式2：根据层序遍历实现序列化
string Chapter3::serialTreeByLevel(TreeNode* root) {
	if (root == nullptr) {
		return "#!";
	}
	string res = root->val + "!";
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		root = queue.front();
		if (root->left) {
			res += root->left->val + "!";
			queue.push(root->left);
		}
		else {
			res += "#!";
		}
		if (root->right) {
			res += root->right->val + "!";
			queue.push(root->right);
		}
		else {
			res += "#!";
		}
	}
}
//方式2：根据层序遍历实现反序列化
TreeNode* NodebyString(string s)  //根据s的值
{
	if (s == "#") //若str[i]的值为#，则不创建节点
		return NULL;
	else  //否则，创建节点并返回
	{
		TreeNode* node = new TreeNode(stoi(s));
		return node;
	}
}
TreeNode* Chapter3::unSerialTreeByLevel(string str) {
	if (str == "") {
		return nullptr;
	}
	vector<string> elems;
	_split(str, '#', elems);
	int index = 0;
	TreeNode* T = NodebyString(elems[index++]);
	queue<TreeNode*> Q;
	if (T != NULL)
		Q.push(T);
	TreeNode* cur;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		cur->left = NodebyString(elems[index++]);
		cur->right = NodebyString(elems[index++]);
		if (cur->left)
			Q.push(cur->left);
		if (cur->right)
			Q.push(cur->right);
	}
	return T;
}

//题目4：遍历二叉树的神级方法
//morris中序
void Chapter3::morrisInOrder(TreeNode* root) {
	TreeNode* cur1 = root;
	TreeNode* cur2 = NULL;//左子节点
	while (cur1 != NULL) {
		cur2 = cur1->left;//当前节点的左子节点
		if (cur2 != NULL) {
			//循环遍历到左子节点的最右子节点
			while (cur2->right != NULL && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			//如过最右节点未指向cur1，则使之指向cur1,并略过后续代码;
			if (cur2->right == NULL) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				//如过最右节点已指向cur1，恢复，则使之指向NULL,
				cur2->right = NULL;
			}
		}
		//如果cur1->left 为NULL,则说明没有左子树,则开始打印父节点;
		cout << cur1->val << " ";
		cur1 = cur1->right;
	}
	cout << endl;
}
//morris前序
void Chapter3::morrisPreOrder(TreeNode* root) {
	TreeNode* cur1 = root;
	TreeNode* cur2 = NULL;//左子节点
	while (cur1 != NULL) {
		cur2 = cur1->left;//当前节点的左子节点
		if (cur2 != NULL) {
			//循环遍历到左子节点的最右子节点
			while (cur2->right != NULL && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			//如过最右节点未指向cur1，则使之指向cur1,并略过后续代码;
			if (cur2->right == NULL) {
				cur2->right = cur1;
				cout << cur1->val << " ";//遇见父节点，先打印父节点
				cur1 = cur1->left;
				continue;
			}
			else {
				//如过最右节点已指向cur1，恢复，则使之指向NULL,
				cur2->right = NULL;
			}
		}
		else {
			//如果cur1->left 为NULL,说明没有左子节点,在切换到右子树之前先打印父节点
			cout << cur1->val << " ";
		}
		cur1 = cur1->right;
	}
	cout << endl;
}
//反转节点的右子节点链
TreeNode* reverselist(TreeNode* root) {
	TreeNode* pre = NULL;
	TreeNode* next = NULL;
	while (root != NULL) {
		next = root->right;
		root->right = pre;
		pre = root;
		root = next;
	}
	return pre;
}
//打印节点
void printEdge(TreeNode* root) {
	TreeNode* tail = reverselist(root);
	TreeNode* cur = tail;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->right;
	}
	//恢复链表
	reverselist(tail);
}
//morris后序
void Chapter3::morrisPostOrder(TreeNode* root) {
	TreeNode* cur1 = root;
	TreeNode* cur2 = NULL;//左子节点
	while (cur1 != NULL) {
		cur2 = cur1->left;//当前节点的左子节点
		if (cur2 != NULL) {
			//循环遍历到左子节点的最右子节点
			while (cur2->right != NULL && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			//如过最右节点未指向cur1，则使之指向cur1,并略过后续代码;
			if (cur2->right == NULL) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				//如过最右节点已指向cur1，恢复，则使之指向NULL,
				cur2->right = NULL;
				printEdge(cur1->left);
			}
		}
		cur1 = cur1->right;
	}
	printEdge(root);
	cout << endl;
}

//题目5：在二叉树中找到累加和为指定值的最长路径
int preorder(TreeNode* root, int sum, int presum, int level, int maxlen, map<int, int>&mp) {
	if (root == NULL)
		return maxlen;
	int cursum = presum + root->val;
	if (mp.find(cursum) == mp.end())
		mp[cursum] = level;
	if (mp.find(cursum - sum) != mp.end())
		maxlen = max(maxlen, level - mp[cursum - sum]);
	maxlen = preorder(root->left, sum, cursum, level + 1, maxlen, mp);
	maxlen = preorder(root->right, sum, cursum, level + 1, maxlen, mp);
	if (level == mp[cursum])
		mp.erase(cursum);
	return maxlen;
}

int Chapter3::getMaxLength(TreeNode* root, int sum) {
	map<int, int>mp;
	mp[0] = 0;  //记录目前的路径总和，对应的层数
	return preorder(root, sum, 0, 1, 0, mp);
}

struct Record {
	int l;
	int r;
	Record(int left, int right) : l(left), r(right) {}
};
#endif

//*************************************************************************//
//							第4章 递归和动态规划问题
//*************************************************************************//



//*************************************************************************//
//							第5章 字符串问题
//*************************************************************************//
class Chapter5 {
public:
	bool isDeformation(string str1, string str2);		//题目1：判断两个字符串是否互为变形词
	int numSum(string str);								//题目2：字符串中数字子串的求和									
	string removeKZero(string str, int k);				//题目3：去掉字符串中连续出现k 个0 的子串
	bool isRotation(string str1, string str2);			//题目4：判断两个字符串是否互为旋转词
	int convert(string str);							//题目5：将整数字符串转成整数值													
	string replace(string str, string from, string to);	//题目6：替换字符串中连续出现的指定字符串											
	string getCountstring(string str);					//题目7：字符串的统计字符串
	bool isUnique(string str);							//题目8：判断字符数组中是否所有的字符都只出现过一次|方式1：遍历数组，用map记录每个字符，时间复杂度O(N)
	bool isUnique_heap(string str);						//题目8：判断字符数组中是否所有的字符都只出现过一次|方式2：使用堆排序，时间复杂度O(NLogN)，空间复杂度O(1)
	int getIndex(string* strings, int size, string str);//题目9：在有序但含有空的数组中查找字符串
	string repalce(char* chas, int &size);				//题目10：字符串的调整与替换|Part1:所有空格替换成%20
	void modify(string &str);							//题目10：字符串的调整与替换|Part2:所有*调整到字符串左端
	void rotateword(string &str);						//题目11：翻转字符串|Part1:翻转字符串中的单词	
	void rotateByK(string &str, int k);					//题目11：翻转字符串|Part2:把大小为K的左半区整体移到右半区
	int minDistance(string* strings, int size, string str1, string str2);//题目12：数组中两个字符串的最小距离													 
	int maxBracketsLength(string str);					//题目13：输出括号字符串有效括号子串														
	int FormulaEvalution(string str);					//题目14：公式字符串求值，默认字符串公式是合法公式
	int zeroLeftGetOne1(int N);							//题目15：0左边必有1的二进制字符串数量|方式1：递归，时间复杂度O(2^N)
	int zeroLeftGetOne2(int N);							//题目15：0左边必有1的二进制字符串数量|方式2：斐波那契数列，时间复杂度O(N)，空间复杂度O(1)
	int zeroLeftGetOne3(int N);							//题目15：0左边必有1的二进制字符串数量|//方式3：矩阵乘法，时间复杂度O(LogN)
	string lowest(vector<string> strs);					//题目16：拼接所有字符串产生字典顺序最小的大字符串														
	int maxUnique1(string s);							//题目17：求给定字符串中最长无重复子字符串的长度|方式1：利用Set做划窗来判断字符唯一性
	int maxUnique2(string s);							//题目17：求给定字符串中最长无重复子字符串的长度|方式2：利用HashMap建立{ 字符 - 索引 }的映射，降低找重复时的时间复杂度														
	string pointNewChar(string str, int k);				//题目17：找到被指的新类型字符														
	int getMinUniqueLen(string str1, string str2);		//题目18：最小包含子串的长度															
	int minCut(string str);								//题目19：回文最小分割数
	bool isMatch(string str, string exp);				//题目20：字符串匹配(通配)问题|方式1：暴力递归											   
	bool isMatchdp(string A, string B);					//题目20：字符串匹配(通配)问题|方式2：动态规划
};
/////////////////////////////////////////////////////////

//class Chapter5成员函数定义
#ifndef Chapter5Class 
#define Chapter5Class
//题目1：判断两个字符串是否互为变形词
bool Chapter5::isDeformation(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	if (len1 == 0 || len2 == 0 || len1 != len2) {
		return false;
	}
	int map[256] = {};
	for (int i = 0; i < len1; ++i) {
		map[str1[i]]++;
	}
	for (int i = 0; i < len2; ++i) {
		if (map[str2[i]]-- == 0) {
			return false;
		}
	}
	return true;
}

//题目2：字符串中数字子串的求和
int Chapter5::numSum(string str) {
	int len = str.length();
	if (len == 0) return 0;
	int res = 0;
	int num = 0;
	int cur = 0;
	bool posi = true;
	for (int i = 0; i < len; ++i) {
		cur = str[i] - '0';
		if (cur < 0 || cur > 9) {
			res += num;
			num = 0;
			if (str[i] == '-') {
				if (i > 0 && str[i - 1] == '-') {
					posi = !posi;
				}
				else {
					posi = false;
				}
			}
			else {
				posi = true;
			}
		}
		else {
			num = num * 10 + (posi ? cur : -cur);
		}
	}
	res += num;
	return res;
}

//题目3：去掉字符串中连续出现k 个0 的子串
string Chapter5::removeKZero(string str, int k) {
	int len = str.length();
	if (len == 0) return nullptr;
	int count = 0;
	int start = -1;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '0') {
			count++;
			start = start == -1 ? i : start;
		}
		else {
			if (count == k) {
				while (count-- != 0) {
					str[start++] = ' ';
				}
			}
			count = 0;
			start = -1;
		}
	}
	if (count == k) {
		while (count-- != 0) {
			str[start++] = ' ';
		}
	}
	return str;
}

//题目4：判断两个字符串是否互为旋转词
bool Chapter5::isRotation(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	if (len1 == 0 || len2 == 0 || len1 != len2) {
		return false;
	}
	string str = str2 + str2;
	//KMP
	return str.find(str1);
}

//题目5：将整数字符串转成整数值
bool isValid(string str) {
	int len = str.length();
	if (str[0] != '-' && (str[0] < '0' || str[0] > '9')) {
		return false;
	}
	if (str[0] == '-' && (len == 1 || str[0] == '0')) {
		return false;
	}
	if (str[0] == '0' && (len > 1)) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int Chapter5::convert(string str) {
	int len = str.length();
	if (!isValid(str)) {
		return 0;
	};
	bool posi = str[0] != '-' ? true : false;
	int minq = INT_MAX / 10;
	int minr = INT_MIN % 10;
	int res = 0;
	int cur = 0;
	for (int i = posi ? 0 : 1; i < len; ++i) {
		cur = '0' - str[i];
		if (res < minq || (res == minq && cur < minr)) {
			return 0;
		}
		res = res * 10 + cur;
	}
	if (posi && res == INT_MIN) {
		return 0;
	}
	return posi ? -res : res;
}

//题目6：替换字符串中连续出现的指定字符串
string Chapter5::replace(string str, string from, string to) {
	int len1 = str.length();
	int len2 = from.length();
	int mi = 0;
	int si = 0;
	for (int i = 0; i < len1; ++i) {
		if (str[i] == from[mi++]) {
			if (mi == len2) {
				si = i;
				while (mi-- != 0) {
					str[si--] = '0';
				}
				mi = 0;
			}
		}
		else {
			mi = 0;
		}
	}
	string newstr("");
	for (int i = 0; i < len1; ++i) {
		if (str[i] != '0') {
			newstr += str[i];
		}
		if (str[i] == '0' && (i == 0 || str[i - 1] != '0')) {
			newstr.append(to);
		}
	}
	return newstr;
}

//题目7：字符串的统计字符串
char getCharAt(string str, int k) {
	int len = str.length();
	if (len == 0) return 0;
	char cur = 0;
	int num = 0;
	int sum = 0;
	bool posi = true;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '_') {
			posi = !posi;
		}
		else if (posi) {
			sum += num;
			if (sum > k) {
				return cur;
			}
			num = 0;
			cur = str[i];
		}
		else {
			num = num * 10 + str[i] - '0';
		}
	}
	return cur;
}

string Chapter5::getCountstring(string str) {
	int len = str.length();
	if (len == 0) return 0;
	char cur = str[0];
	string res(1, cur);
	int num = 1;

	for (int i = 1; i < len; ++i) {
		if (str[i] == str[i - 1]) {
			num++;
		}
		else {
			res.append(to_string(num) + '_' + str[i] + '_');
			cur = str[i];
			num = 1;
		}
	}
	res += to_string(num);
	return res;
}

//题目8：判断字符数组中是否所有的字符都只出现过一次
//方式1：遍历数组，用map记录每个字符，时间复杂度O(N)
bool Chapter5::isUnique(string str) {
	int len = str.length();
	if (len == 0) return true;
	bool map[256] = { false };
	for (int i = 0; i<len; ++i)
	{
		if (map[str[i]])
		{
			return false;
		}
		map[str[i]] = true;
	}
	return true;
}
//方式2：使用堆排序，时间复杂度O(NLogN)，空间复杂度O(1)
void swap(string &str, int a, int b) {
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}
void heapInsert(string &str, int index) {
	int parent = 0;
	while (index != 0) {
		parent = (index - 1) / 2;
		if (str[parent] < str[index]) {
			swap(str, parent, index);
			index = parent;
		}
		else {
			break;
		}
	}
}
void heapify(string &str, int index, int heapSize) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	while (left < heapSize) {
		if (str[left] > str[index]) {
			largest = left;
		}
		if (right < heapSize && str[right] > str[largest]) {
			largest = right;
		}
		if (largest != index) {
			swap(str, largest, index);
		}
		else {
			break;
		}
		index = largest;
		left = 2 * index + 1;
		right = 2 * index + 2;
	}
}

bool Chapter5::isUnique_heap(string str) {
	int len = str.length();
	if (len == 0) return true;
	//堆初始化
	for (int i = 0; i < len; ++i) {
		heapInsert(str, i);
	}
	//堆初调整
	for (int i = len - 1; i > 0; --i) {
		swap(str, 0, i);
		heapify(str, 0, i);
	}
	for (int i = 1; i < len; ++i) {
		if (str[i] == str[i - 1]) {
			return false;
		}
	}
	return true;
}

//题目9：在有序但含有空的数组中查找字符串,时间O(N),空间O(1)
int Chapter5::getIndex(string* strings, int size, string str) {
	if (size == 0 || str.length() == 0) {
		return -1;
	}
	int res = -1;
	int mid = 0;
	int left = 0;
	int temp = 0;
	int right = size - 1;

	while (left < right) {
		mid = (left + right) / 2;
		if (strings[mid] != "" && !strings[mid].compare(str)) {
			res = mid;
			right = mid - 1;
		}
		else if (strings[mid] != "") {
			if (strings[mid].compare(str) > 0) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			temp = mid;
			while (strings[temp] == "" && --temp >= left);
			if (temp < left || strings[temp].compare(str) < 0) {
				left = mid + 1;
			}
			else {
				res = strings[temp].compare(str) ? temp : res;
				right = temp - 1;
			}
		}
	}
	return res;
}

//题目10：字符串的调整与替换
//Part1:所有空格替换成%20, size = strlen(chas)
string Chapter5::repalce(char* chas, int &size) {
	if (size == 0) {
		return "";
	}
	int len = 0;
	int num = 0;
	for (len = 0; len < size && chas[len] != 0; ++len) {
		if (chas[len] == ' ') {
			num++;
		}
	}
	size = len + 2 * num;//新数组长度
	char* s = new char[size + 1];
	int j = size - 1;
	for (int i = len - 1; i > -1; --i) {
		if (chas[i] != ' ') {
			s[j--] = chas[i];
		}
		else {
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		}
	}
	string str(s, size);
	delete[] s;
	return str;
}
//Part2:所有*调整到字符串左端,时间O(N),空间O(1).例："12**345"调整为"**12345"
void Chapter5::modify(string &str) {
	int len = str.length();
	if (len == 0) return;
	int j = len - 1;
	for (int i = len - 1; i > -1; i--) {
		if (str[i] != '*') {
			str[j--] = str[i];
		}
	}
	for (; j > -1; j--) {
		str[j] = '*';
	}
}

//题目11：翻转字符串
void reverse(string &str, int start, int end) {
	char temp = ' ';
	while (start < end) {
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}
//Part1:翻转字符串中的单词
void Chapter5::rotateword(string &str) {
	int len = str.length();
	if (len == 0) return;

	reverse(str, 0, len - 1);
	int start = -1;
	int end = -1;
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') {
			start = i == 0 || str[i - 1] == ' ' ? i : start;
			end = i == len - 1 || str[i + 1] == ' ' ? i : end;
		}
		if (start != -1 && end != -1) {
			reverse(str, start, end);
			start = -1;
			end = -1;
		}
	}
}
//Part2:把大小为K的左半区整体移到右半区
void Chapter5::rotateByK(string &str, int k) {
	int len = str.length();
	if (len == 0) return;

	reverse(str, 0, k - 1);
	reverse(str, k, len - 1);
	reverse(str, 0, len - 1);

}

//题目12：数组中两个字符串的最小距离
int Chapter5::minDistance(string* strings, int size, string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	if (len1 == 0 || len2 == 0) {
		return -1;
	}
	if (!str1.compare(str2)) {
		return 0;
	}
	int last1 = -1;
	int last2 = -1;
	int minvalue = INT_MAX;
	for (int i = 0; i < size; ++i) {
		if (!str1.compare(strings[i])) {
			last1 = i;
			minvalue = min(minvalue, last2 == -1 ? minvalue : last1 - last2);
		}
		if (!str2.compare(strings[i])) {
			last2 = i;
			minvalue = min(minvalue, last1 == -1 ? minvalue : last2 - last1);
		}
	}
	return minvalue == INT_MAX ? -1 : minvalue;
}

//题目13：输出括号字符串有效括号子串,动态规划求解，时间O(N),空间O(N).
int Chapter5::maxBracketsLength(string str) {
	int len = str.length();
	if (len == 0) return 0;
	int* dp = new int[len] {0};
	int pre = 0;
	int res = 0;
	for (int i = 1; i < len; ++i) {
		if (str[i] == ')') {
			pre = i - dp[i - 1] - 1;
			if (pre >= 0 && str[pre] == '(') {
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}

//题目14：公式字符串求值，默认字符串公式是合法公式
void addNum(deque<string>& deq, int num) {
	if (!deq.empty())
	{
		int cur = 0;
		string top = deq.back();
		deq.pop_back();
		if (top == "+" || top == "-")
		{
			deq.push_back(top);
		}
		else
		{
			cur = stoi(deq.back());
			deq.pop_back();
			num = top == "*" ? (cur * num) : (cur / num);

		}
	}
	deq.push_back(to_string(num));
}
int getNum(deque<string> &deq) {
	int res = 0;
	bool add = true;
	string cur;
	int num;
	while (!deq.empty())
	{
		cur = deq.front();
		deq.pop_front();
		if (cur == "+")
			add = true;
		else if (cur == "-")
			add = false;
		else
		{
			num = stoi(cur);
			res += add ? num : (-num);
		}
	}
	return res;
}
vector<int> value(string str, int i) {
	deque<string> deq;
	int pre = 0;
	vector<int> bra(2);
	while (i < str.size() && str[i] != ')')
	{
		if (str[i] >= '0' && str[i] <= '9')
			pre = pre * 10 + str[i++] - '0';
		else if (str[i] != '(')
		{
			addNum(deq, pre);
			stringstream stream;
			stream << str[i++];
			string temp = stream.str();
			deq.push_back(temp);
			pre = 0;
		}
		else
		{
			bra = value(str, i + 1);
			pre = bra[0];
			i = bra[1] + 1;
		}
	}
	addNum(deq, pre);
	bra[0] = getNum(deq);
	bra[1] = i;
	return bra;
}
int Chapter5::FormulaEvalution(string str) {
	return value(str, 0)[0];
}

//题目15：0左边必有1的二进制字符串数量
//方式1：递归，时间复杂度O(2^N)
int process(int i, int N)
{
	if (i == N)
		return 1;
	if (i == N - 1)
		return 2;
	return process(i + 1, N) + process(i + 2, N);
}

int Chapter5::zeroLeftGetOne1(int N) {
	if (N < 1)
		return 0;
	return process(1, N);
}
//方式2：斐波那契数列，时间复杂度O(N)，空间复杂度O(1)
int Chapter5::zeroLeftGetOne2(int n) {
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	int pre = 1;
	int cur = 1;
	int temp = 0;
	for (int i = 2; i < n + 1; i++)
	{
		temp = cur;
		cur += pre;
		pre = temp;
	}
	return cur;
}
//方式3：矩阵乘法，时间复杂度O(LogN)
vector<vector<int> > muliMartix(vector<vector<int> > & m1, vector<vector<int> >& m2)
{
	vector<vector<int> > res(m1.size(), vector<int>(m2[0].size()));
	for (int i = 0; i < m1.size(); ++i)
		for (int j = 0; j < m2[0].size(); ++j)
			for (int k = 0; k < m2.size(); ++k)
				res[i][j] += m1[i][k] * m2[k][j];
	return res;
}
vector<vector<int> > matrixPower(vector<vector<int> >& m, int p)
{
	vector<vector<int> > res(m.size(), vector<int>(m[0].size()));
	for (int i = 0; i < res.size(); ++i)
		res[i][i] = 1;
	vector<vector<int> > tmp = m;
	for (; p != 0; p >>= 1)
	{
		if (p & 1)
			res = muliMartix(res, tmp);
		tmp = muliMartix(tmp, tmp);
	}
	return res;
}

int Chapter5::zeroLeftGetOne3(int n) {
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;

	vector<vector<int> > m;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(1);
	m.push_back(tmp);
	tmp[1] = 0;
	m.push_back(tmp);
	m = matrixPower(m, n - 2);
	return 2 * m[0][0] + m[1][0];
}

//题目16：拼接所有字符串产生字典顺序最小的大字符串
//例子：strs["abc","de"],拼接后"abcde"字典顺序小于"deabc"
bool strcompare(string str1, string str2)
{
	return str1 + str2 < str2 + str1 ? true : false;//由小到大排序
}
string Chapter5::lowest(vector<string> strs)
{
	if (strs.size() == 0)
		return "";
	sort(strs.begin(), strs.end(), strcompare);
	string res = "";
	for (int i = 0; i < strs.size(); ++i)
		res += strs[i];
	return res;
}

//题目17：求给定字符串中最长无重复子字符串的长度
//方式1：利用Set做划窗来判断字符唯一性
int Chapter5::maxUnique1(string str) {
	int n = str.length();
	set<char> set;
	int ans = 0, i = 0, j = 0;
	while (i < n && j < n) {
		// try to extend the range [i, j]
		if (!set.count(str[j])) {
			// 此处是根据角标j来遍历，一个一个的往里存
			set.insert(str[j++]);
			ans = max(ans, j - i);//注意这里为什么是j-1而不是j-i+1呢？因为j已经++了
		}
		else {
			set.erase(str[i++]);
		}
	}
	return ans;
}
//方式2：利用HashMap建立{ 字符 - 索引 }的映射，降低找重复时的时间复杂度
int Chapter5::maxUnique2(string str) {
	int len = str.length();
	if (len == 0) return 0;
	int map[256];
	for (int i = 0; i < 256; ++i) {
		map[i] = -1;
	}
	int slen = 0;
	int pre = -1;
	int cur = 0;
	for (int i = 0; i != len; ++i) {
		pre = max(pre, map[str[i]]);
		cur = i - pre;
		slen = max(slen, cur);
		map[str[i]] = i;
	}
	return slen;
}

//题目17：找到被指的新类型字符
string Chapter5::pointNewChar(string str, int k) {
	int len = str.length();
	if (len == 0 || k < 0 || k > len) {
		return "";
	}
	int count = 0;
	for (int i = k - 1; i > -1; --i) {
		if (!isupper(str[i])) {
			break;
		}
		count++;
	}
	if ((count & 1) == 1) {
		return str.substr(k - 1, 2);
	}
	if (isupper(str[k])) {
		return str.substr(k, 2);
	}
	string s(1, str[k]);
	return s;
}

//题目18：最小包含子串的长度
int Chapter5::getMinUniqueLen(string str1, string str2)
{
	if (str1 == "" || str2 == "" || str1.length()<str2.length())
	{
		return 0;
	}
	int map[256] = { 0 };//充当hash表
	for (int i = 0; i<str2.length(); i++)
	{
		map[str2[i]]++;
	}
	int left = 0;
	int right = 0;
	int match = str2.length();
	int minlen = INT_MAX; //匹配到的最短长度
	while (right<str1.length())
	{
		map[str1[right]]--;
		if (map[str1[right]] >= 0)
		{
			match--;
		}
		//匹配到字符串str2
		if (match == 0)
		{
			//匹配了多个
			while (map[str1[left]]<0)
			{
				map[str1[left++]]++;
			}
			minlen = min(minlen, right - left + 1);  //获得最短的长度
			match++;
			map[str1[left++]]++; //str1收回str2匹配到的位置
		}
		right++;
	}
	return minlen == INT_MAX ? 0 : minlen;
}

//题目19：回文最小分割数
int Chapter5::minCut(string str)
{
	if (str == "")
		return 0;
	vector<int> dp(str.size() + 1);
	int len = str.size();
	dp[len] = -1;
	bool** p = new bool*[len];
	for (int i = 0; i < len; ++i)
	{
		p[i] = new bool[len] {false};
	}
	for (int i = len - 1; i > -1; --i)
	{
		dp[i] = INT_MAX;
		for (int j = i; j < len; ++j)
		{
			if (str[i] == str[j] && (j - i < 2 || p[i + 1][j - 1]))
			{
				p[i][j] = true;
				dp[i] = min(dp[i], dp[j + 1] + 1);
			}
		}
	}
	return dp[0];
}

//题目20：字符串匹配(通配)问题
bool isValid(string s, string e) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '*' || s[i] == '.') {
			return false;
		}
	}
	for (int i = 0; i < e.length(); ++i) {
		if (e[i] == '*' && (i == 0 || e[i - 1] == '*')) {
			return false;
		}
	}
	return true;
}
bool process(string s, string e, int si, int ei) {
	if (ei == e.length()) {
		return si == s.length();
	}
	if (ei + 1 == e.length() || e[ei + 1] != '*') {
		return si != s.length() && (e[ei] == s[si] || e[ei] == '.')
			&& process(s, e, si + 1, ei + 1);
	}
	while (si != s.length() && (e[ei] == s[si] || e[ei] == '.')) {
		if (process(s, e, si, ei + 2)) {
			return true;
		}
		si++;
	}
	return process(s, e, si, ei + 2);
}
//方式1：暴力递归
bool Chapter5::isMatch(string str, string exp) {
	if (str == "" || exp == "") {
		return false;
	}
	return isValid(str, exp) ? process(str, exp, 0, 0) : false;
}
//方式2：动态规划
bool Chapter5::isMatchdp(string A, string B)
{
	if (A == "" || B == "") {
		return false;
	}
	int lena = A.length();
	int lenb = B.length();
	// write code here
	vector<vector<bool>> dp(lena + 1, vector<bool>(lenb + 1));
	//初始化
	dp[0][0] = true;
	//一般情况
	for (int i = 1; i <= lena; i++)
	{
		for (int j = 1; j <= lenb; j++)
		{
			if (B[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
			else if (B[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (A[i - 1] == B[j - 1]);
		}
	}
	return dp[lena][lenb];
}
#endif

//*************************************************************************//
//							第7章 位运算
//*************************************************************************//
class Chapter7 {
public:
	int getMax(int a, int b);				//题目1：不用任何比较判断找出两个数中较大的数
	int add(int a, int b);					//题目2：只用位运算不用算术运算实现整数的加减乘除运算|加法
	int minus(int a, int b);				//题目2：只用位运算不用算术运算实现整数的加减乘除运算|减法
	int multi(int a, int b);				//题目2：只用位运算不用算术运算实现整数的加减乘除运算|乘法
	int div(int a, int b);					//题目2：只用位运算不用算术运算实现整数的加减乘除运算|除法不完整版
	int divide(int a, int b);				//题目2：只用位运算不用算术运算实现整数的加减乘除运算|除法											
	int count(int n);						//题目3：整数的二进制表达中有多少个1
	int getOddTimeNum(int* arr, int len);	//题目4：在其他数都出现偶数次的数组中找到出现奇数次的数
	int getOnceNum(int* arr, int len, int k);//题目5：在其他数都出现k 次的数组中找到只出现一次的数
};
/////////////////////////////////////////////////////////

//class Chapter7成员函数定义
#ifndef Chapter7Class 
#define Chapter7Class
int flip(int n) {
	return n ^ 1;
}
//返回整数n的符号
int sign(int n) {
	return flip((n >> 31) & 1);
}
//题目1：不用任何比较判断找出两个数中较大的数
int Chapter7::getMax(int a, int b) {
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int difsab = sa ^ sb;
	int samesab = flip(difsab);
	int returnA = difsab * sa + samesab * sc;
	int returnB = flip(returnA);
	return a * returnA + b * returnB;
}

//题目2：只用位运算不用算术运算实现整数的加减乘除运算
//取负数
int negNum(int n) {
	return ~n + 1;
}
//加法
int Chapter7::add(int a, int b) {
	int sum = a;
	while (b != 0) {
		sum = a ^ b;//无相位相加
		b = (a & b) << 1;//只考虑进位
		a = sum;
	}
	return sum;
}

//减法
int Chapter7::minus(int a, int b) {
	return add(a, negNum(b));
}

//乘法
int Chapter7::multi(int a, int b) {
	int res = 0;
	while (b != 0) {
		if ((b & 1) != 0) {
			res = add(res, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return res;
}

bool isNeg(int n) {
	return n < 0;
}
//除法
int Chapter7::div(int a, int b) {
	int x = isNeg(a) ? negNum(a) : a;
	int y = isNeg(b) ? negNum(b) : b;
	int res = 0;

	for (int i = 31; i > -1; i = minus(i, 1)) {
		if ((x >> i) >= y) {
			res |= (1 << i);
			x = minus(x, y << i);
		}
	}

	return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}
int Chapter7::divide(int a, int b)
{
	if (b == 0)
		cout << "Input Error!" << endl;
	else if (a == INT_MIN && b == INT_MIN)
		return 1;
	else if (b == INT_MIN)
		return 0;
	else if (a == INT_MIN)
	{
		int c = div(a + 1, b);
		return add(c, div(minus(a, multi(c, b)), b));
	}
	else
		return div(a, b);
}

//题目3：整数的二进制表达中有多少个1
int Chapter7::count(int n) {
	int count = 0;
	while (n != 0) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

//题目4：在其他数都出现偶数次的数组中找到出现奇数次的数
int Chapter7::getOddTimeNum(int* arr, int len) {
	int OddTimeNum = 0;
	for (int i = 0; i < len; ++i) {
		OddTimeNum = OddTimeNum ^ arr[i];
	}
	return OddTimeNum;
}

//题目5：在其他数都出现k 次的数组中找到只出现一次的数
int* getKSysNum(int value, int k) {
	int* res = new int[32];
	int index = 0;
	while (value != 0) {
		res[index++] = value % k;
		value = value / k;
	}
	return res;
}

int getFromKSysNum(int* eo, int len, int k) {
	int res = 0;
	for (int i = len - 1; i>-1; i--) {
		res = res * k + eo[i];
	}
	return res;
}
int Chapter7::getOnceNum(int* arr, int len, int k) {
	int* eo = new int[32];
	for (int i = 0; i < len; i++) {
		int* kSys = getKSysNum(arr[i], k);
		for (int j = 0; j < 32; j++) {
			eo[j] = (eo[j] + kSys[j]) % k;
		}
	}
	return getFromKSysNum(eo, len, k);
}
#endif

//*************************************************************************//
//							第7章 位运算
//*************************************************************************//
class Chapter8 {
public:
	void printMatrix(vector<vector<int>>& matrix);				//题目1：旋转打印数组
	void rotate(vector<vector<int>>& matrix);					//题目2：将正方形矩阵顺时针转动90°
	void printMatrixZigZag(vector<vector<int>>& matrix);		//题目3："之"字形打印矩阵
	vector<int> getKMin(vector<int>& arr, int k);				//题目4：找到无序数组中最小的K个数|方式1：利用堆排序，时间复杂度O(NlogK)
	int getMinLength(vector<int>& arr);							//题目5：需要排序的最短子数组长度
};
/////////////////////////////////////////////////////////

//class Chapter7成员函数定义
#ifndef Chapter8Class 
#define Chapter8Class

//题目1：旋转打印数组
void printEdge(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC) {
	if (tR == dR) {
		// 只剩最后一行
		for (int i = tC; i <= dC; ++i) {
			cout << matrix[tR][i] << " ";
		}
	}
	else if (tC == dC) {
		// 只剩最后一列
		for (int i = tR; i <= dR; ++i) {
			cout << matrix[i][tC] << " ";
		}
	}
	else {
		// 一般情况
		int curC = tC;
		int curR = tR;
		while (curC < dC) {
			// 从左到右打印
			cout << matrix[tR][curC] << " ";
			curC++;
		}
		while (curR < dR) {
			// 从上到下打印
			cout << matrix[curR][dC] << " ";
			curR++;
		}
		while (curC > tC) {
			// 从右到左打印
			cout << matrix[dR][curC] << " ";
			curC--;
		}
		while (curR > tR) {
			// 从下到上打印
			cout << matrix[curR][tC] << " ";
			curR--;
		}
	}

}

void Chapter8::printMatrix(vector<vector<int>>& matrix) {
	int tR = 0;
	int tC = 0;
	int dR = matrix.size() - 1;
	int dC = matrix[0].size() - 1;
	while (tR <= dR && tC <= dC) {
		printEdge(matrix, tR++, tC++, dR--, dC--);
	}
}

//题目2：将正方形矩阵顺时针转动90°
void rotateEdge(vector<vector<int>>& matrix, int tR, int dR, int tC, int dC) {
	int times = dC - tC;
	int temp = 0;
	for (int i = 0; i < times; i++) {
		temp = matrix[tR][tC + i];
		matrix[tR][tC + i] = matrix[dR - i][tC];
		matrix[dR - i][tC] = matrix[dR][dC - i];
		matrix[dR][dC - i] = matrix[tR + i][dC];
		matrix[tR + i][dC] = temp;
	}
}

void Chapter8::rotate(vector<vector<int>>& matrix) {
	int tR = 0;
	int tC = 0;
	int dR = matrix.size() - 1;
	int dC = matrix[0].size() - 1;
	while (tR < dR) {
		rotateEdge(matrix, tR++, dR--, tC++, dC--);
	}
}

//题目3："之"字形打印矩阵
void printZigZag(vector<vector<int>>& matrix, bool UToD, int tR, int dR, int tC, int dC) {
	if (UToD) {
		while (tR != dR + 1) {
			cout << matrix[tR++][tC--] << " ";
		}
	}
	else {
		while (tR != dR + 1) {
			cout << matrix[dR--][dC++] << " ";
		}
	}
	cout << endl;
}

void Chapter8::printMatrixZigZag(vector<vector<int>>& matrix) {
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	int endR = matrix.size() - 1;
	int endC = matrix[0].size() - 1;
	bool UToD = false;
	while (tR <= endR) {
		printZigZag(matrix, UToD, tR, dR, tC, dC);
		tR = tC == endC ? tR + 1 : tR;
		tC = tC == endC ? tC : tC + 1;
		dC = dR == endR ? dC + 1 : dC;
		dR = dR == endR ? dR : dR + 1;
		UToD = !UToD;
	}
}

//题目4：找到无序数组中最小的K个数
//方式1：利用堆排序，时间复杂度O（NlogK）
void swap(vector<int>& arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
//堆初始化
void headInsert(vector<int>& arr, int index) {
	int parent = (index - 1) / 2;
	while (index > 0) {
		if (arr[parent] < arr[index]) {
			swap(arr, parent, index);
			index = parent;
		}
		else {
			break;
		}
	}
}
//堆排序
void heapify(vector<int>& arr, int index, int heapSize) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	while (left < heapSize) {
		if (arr[left] > arr[index]) {
			largest = left;
		}
		else if (right < heapSize && arr[left] > arr[right]) {
			largest = right;
		}
		else {
			break;
		}
		swap(arr, largest, index);
		index = largest;
		left = 2 * index + 1;
		right = 2 * index + 2;
	}

}
//使用堆排序
vector<int> Chapter8::getKMin(vector<int>& arr, int k) {
	if (k > arr.size()) {
		return vector<int>{-1};
	}
	vector<int> res(k);
	//手动建堆
	for (int i = 0; i < k; i++) {
		res[i] = arr[i];
		headInsert(res, i);
	}
	//堆调整
	for (int i = k; i < arr.size(); i++) {
		if (arr[i] < res[0]) {
			res[0] = arr[i];
			heapify(arr, 0, k);
		}
	}
	////利用优先队列
	//priority_queue<int, vector<int>> heap;
	////priority_queue<int, vector<int>> heap(less<int>(), arr);//默认大顶堆
	////priority_queue<int, vector<int>， greater<int>()> heap(greater<int>(), arr);//小顶堆
	//for (int i = 0; i < k; i++) {
	//	heap.push(arr[i]);
	//}
	////堆调整
	//for (int i = k; i < arr.size(); i++) {
	//	if (arr[i] < heap.top()) {
	//		heap.pop();
	//		heap.push(arr[i]);
	//	}
	//}
	//vector<int> res;
	//while (!heap.empty()) {
	//	res.push_back(heap.top());
	//	heap.pop();
	//}

	return res;
}

//题目5：需要排序的最短子数组长度
int Chapter8::getMinLength(vector<int>& arr) {
	if (arr.size() < 2) {
		return 0;
	}
	int minIndex = -1;
	int minval = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i > -1; i--) {
		if (arr[i] > minval) {
			minIndex = i;
		}
		else {
			minval = min(minval, arr[i]);
		}
	}
	if (minIndex == -1) {
		return 0;
	}
	int maxIndex = -1;
	int maxval = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < maxval) {
			maxIndex = i;
		}
		else {
			maxval = max(maxval, arr[i]);
		}
	}
	return maxIndex - minIndex + 1;
}


#endif

#endif




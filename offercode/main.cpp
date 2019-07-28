//#include <iostream>
////#include <string>
//
////using namespace std;
//
////string reverseVowels(string s) {
////	int i = 0, j = s.length() - 1;
////	while (i <= j) {
////		char ci = s.at(i);
////		char cj = s.at(j);
////		if (ci != cj) {
////			s[i++] = ci;
////		}
////		else if (!vowels.contains(cj)) {
////			result[j--] = cj;
////		}
////		else {
////			result[i++] = cj;
////			result[j--] = ci;
////		}
////	}
////	return new String(result);
////}
//#include <stdio.h>
//
////char* getstr()
////{
////	char* str;
////	char* _str;
////	int i = 1;
////	str = (char*)malloc(sizeof(char) * (i + 1));
////	while ('\n' != (str[i - 1] = getchar()))
////	{
////		i++;
////		_str = (char*)malloc(strlen(str) + 1);
////		str[i - 1] = '\0';
////		strcpy(_str, str);
////		free(str);
////		str = (char*)malloc(sizeof(char) * (i + 1));
////		if (NULL == str)
////		{
////			free(_str);
////			printf("No enough memory!");
////			return NULL;
////		}
////		strcpy(str, _str);
////		free(_str);
////	}
////	str[i - 1] = '\0';
////	return str;
////}
////
////// 判断麻将是否和牌
////int canSuccess(char* &s) {
////	//字符串长度
////	int len = strlen(s);
////	// 字符串长度不符合
////	if (len < 2 || len >= 15) return false;
////	// 剩下的2张牌为对子则和牌否则不能和牌
////	if (len == 2) return s[0] == s[1];
////	bool flag = false;
////	//auto begin = s.begin(), end = s.end();
////	//while (end - begin > 2)
////	//{
////	//	// 判断是否有刻子
////	//	if (*begin == *(begin + 1) && *begin == *(begin + 2))
////	//	{
////	//		// 去掉刻子后递归处理
////	//		string tmp1(s.begin(), begin);
////	//		string tmp2(begin + 3, end);
////	//		flag |= canSuccess(tmp1 + tmp2);
////	//	}
////	//	// 判断是否有顺子
////	//	else if (*begin + 1 == *(begin + 1)) {
////	//		// 顺子中间的牌可能有多张相同的，遍历找到第一个不同的
////	//		int midSameCount = 0;
////	//		char mid = *(begin + 1);
////	//		auto iter = begin + 1;
////	//		while (*iter == mid)
////	//		{
////	//			midSameCount++;
////	//			// 如果递归到字符串末则标记后退出循环
////	//			if (++iter == end)
////	//			{
////	//				midSameCount = -1;
////	//				break;
////	//			}
////	//		}
////	//		// 处理有顺子的情况
////	//		if (midSameCount > 0 && mid + 1 == *iter) {
////	//			// 去掉顺子后递归处理
////	//			string tmp1(s.begin(), begin);
////	//			string tmp2;
////	//			tmp2.insert(0, midSameCount - 1, mid);
////	//			string tmp3(iter + 1, end);
////	//			flag |= canSuccess(tmp1 + tmp2 + tmp3);
////	//		}
////
////	//	}
////	//	++begin;
////	//}
////	return flag;
////}
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int N = 0, M = 0;
//	scanf("%d %d", &N, &M);
//	vector<int> a(N);
//	vector<int> b(M);
//	int sum = 0;
//	int temp = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	for (int i = 0; i < M; ++i)
//	{
//		if (N % 2 != 0)
//		{
//			temp = sum;
//			sum = a[i] + a[N - i - 2];
//			if (temp > sum)
//			{
//				sum = temp;
//			}
//		}
//		else
//		{
//			temp = sum;
//			sum = a[i] + a[N - i - 1];
//			if (temp > sum)
//			{
//				sum = temp;
//			}
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

//#include<vector>
//#include<string>
//#include<iostream>
//#include"keyboard.h"
//#include"BigNum.h"
//#include"List.h"
//#include"BinaryTree.h"
//
//using namespace std;
//
//void PrintAll(ListNode *head) {
//	ListNode *p = head;
//	if (p == NULL)
//	{
//		cout << "LinkList is NULL" << endl;
//		return;
//	}
//	else {
//		int i = 1;
//		while (p) {
//			cout << p->val << "-->";
//			i++;
//			p = p->next;
//		}
//		cout << "NULL" << endl;
//	}
//}


//int main()
//{
//	keyboard<string> k;
//	keyboard<int> x;
//	//vector<string> a;
//	//vector<int> b{ 1, 2, 3, 5, 8, 5, 7, 8, 9 };
//	string s1("123456");
//	string s2("654321");
//	s1 = k.BigNumAdd(s1, s2);
//
//	BigNum num1("123456");
//	BigNum num2("654321");
//	num1 = num1 * num2;
//	s2 = num1.BigNumToString();
//
//	int* table = new int[6]{ 1,4,3,2,5,2 };
//	vector<int> vec{ 1,2,3,4,5,6 };
//
//	List a(table,6);
//	a.PrintAll();
//	List b(vec);
//	b.PrintAll();
//	b.ReverseList(b.Getfront());
//	b.PrintAll();
//	//b.ReversePartList(b.Getfront(),2,5);
//	b.PrintAll();
//	b.QuickSort(b.Getfront(), NULL);
//	b.PrintAll();
//	
//	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
//	int array2[15] = { 1, 2, 3, '#', '#', 6, 7 , '#', '#', '#', '#', '#', '#', '#', 8 };
//	BinaryTree<int> b1(array1, 10, '#');
//	cout << "PrevOrder:";
//	b1.PrevOrder();
//	cout << "InOrder:";
//	b1.InOrder();
//	cout << "PostOrder:";
//	b1.PostOrder();
//	cout << "LevelOredr:";
//	b1.LevelOredr();
//	cout << endl;
//	cout << "节点数:" << b1.Size() << endl;
//	cout << "深度:" << b1.Depth() << endl;
//	cout << "叶子节点数:" << b1.LeafSize() << endl;
//	cout << endl;
//	//从键盘读入任意长度的数组(int)
//	//1 2 3 4 5 6
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//#include <forward_list>
//#include<string>
//#include<iostream>
//#include<unordered_set>
////#include"Zuochengyun.h"
//#include"keyboard.h"
//#include"BinaryTree.h"
//
//using namespace std;

//void PrintAll(Node *head) {
//	Node *p = head;
//	if (p == NULL)
//	{
//		cout << "LinkList is NULL" << endl;
//		return;
//	}
//	else {
//		int i = 1;
//		while (p) {
//			cout << p->value << "-->";
//			i++;
//			p = p->next;
//		}
//		cout << "NULL" << endl;
//	}
//}
//
//int main()
//{
//	Chapter1 a;
//	vector<int> vec1{ 1, 2, 2 ,3, 5, 7 };
//	vector<int> vec2{ 1, 6, 7 ,3, 6, 7 };
//	vector<vector<int> >map{ { 1,0,1,1 } ,{ 1,1,1,1 } ,{ 1,1,1,1 } };
//
//	Chapter2 b(vec1);
//	Node* p = b.GetNodefront();
//	Node* n1 = new Node(1);
//	Node* n2 = new Node(2);
//	Node* n3 = new Node(3);
//	Node* n4 = new Node(3);
//	Node* n5 = new Node(4);
//	Node* n6 = new Node(4);
//	Node* n7 = new Node(5);
//	Node* n8 = new Node(6);
//	Node* n9 = new Node(7);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = n7;
//	n7->next = n8;
//	n8->next = n9;
//	n9->next = n1;
//	//Node* q =  b.reverseMeige(b.GetNodefront() , c.GetNodefront());
//	//b.relocate(p);
//	//PrintAll(p);
//
//	int array1[10] = { 1, 2, 3, '#', '#', 4, '#' , '#', 5, 6 };
//	int arr[] = {1,2,'#',4,7,'#','#',8,'#',11,13,'#','#',14,'#','#',3,5,9,12,15,'#','#',16,'#','#','#',10,'#','#',6,'#' ,'#' };
//	Chapter3 c(arr, 33, '#');
//	//c.LevelOrder(c.GetTreeRoot());
//	//c.printEdge2(c.GetTreeRoot());
//	c.InOrder(c.GetTreeRoot());
//	c.PreOrder(c.GetTreeRoot());
//	c.PosOrder1(c.GetTreeRoot());
//
//	c.morrisInOrder(c.GetTreeRoot());
//	c.morrisPreOrder(c.GetTreeRoot());
//	c.morrisPostOrder(c.GetTreeRoot());
//
//	Chapter5 e;
//	cout << "请输入字符串" << endl;
//	string str1("abc");
//	string str2("a.c");
//	string str3("aabceb");
//	string* str = new string[7]{"1","3","3","3","2","3","1" };
//	vector<string> strs{ "abc","de" };
//	//cin >> str;
//	char* str4 = "a b  c";
//	int n = strlen(str4);
//
//	return 0;
//}

//int main()
//{
//	int array1[12] = { 1, 2, 3, 5,'#','#','#', 4,'#','#', 5, 6 };
//	BinaryTree<int> b1(array1, 12, '#');
//	cout << "前序遍历：";
//	b1.PrevOrder();
//	cout << "中序遍历：";
//	b1.InOrder();
//	cout << "后序遍历：";
//	b1.PostOrder();
//	cout << "层次遍历：";
//	b1.LevelOredr();
//	cout << endl;
//	vector<string> path;
//	path = b1.binaryTreePaths(b1.GetTreeRoot());
//	vector<vector<int> > paths = b1.FindPath(b1.GetTreeRoot(),7);
//	int sum = b1.FindMaxPath(b1.GetTreeRoot(),12);
//
//	return 0;
//}

//#include <string>
//#include <iostream>
//#include <map>  
//#include <functional>  
//#include <vector>
//#include "sort.h"
//
//using namespace std;
//
//vector<int> CinIntVector() {
//	vector<int>nums;
//	int num;
//	do {
//		cin >> num;
//		nums.push_back(num);
//	} while (getchar() != '\n');
//
//	return nums;
//}
//
//int main(void)
//{
//	//vector<int> A = CinIntVector();
//	//vector<int> B = CinIntVector();
//
//	vector<int> A{ 4,3,7,9,10};
//	vector<int> B{ 2,1,5,8,9 };
//	int index = -1, min, max = INT_MIN;
//	for (int i = 1; i < A.size(); ++i) {
//		if (A[i] > A[i-1]) {
//			index = i;
//			min = A[i - 1];
//			if (i < A.size() - 1)
//				max = A[i + 1];
//			break;
//		}
//	}
//	if (index == -1) {
//		cout << "NO";
//		return 0;
//	}
//	max = INT_MIN;
//	bool flag = false;
//	for (int i = 0; i < B.size(); ++i) {
//		if (B[i] > min && B[i] < max) {
//			max = max > B[i] ? max : B[i];
//			flag;
//		}
//	}
//	if (flag) {
//		A[index] = max;
//		for (auto e : A) {
//			cout << e << " ";
//		}
//	}
//	return 0;
//}

#include <string>
#include <iostream>
#include <map>  
#include <functional>  
#include <vector>

using namespace std;

vector<int> CinIntVector() {
	vector<int>nums;
	int num;
	do {
		cin >> num;
		nums.push_back(num);
	} while (getchar() != '\n');

	return nums;
}

int main(void)
{
	//int n;
	//cin >> n;
	//vector<int> A = CinIntVector();
	//vector<int> B = CinIntVector();

	int n = 10;
	vector<int> A{ 1,2,3,4,5,6,7,8,9,10};
	vector<int> B{ 1,1,1,1,1,1,1,1,1,10 };
	map<int, int> mymap;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (mymap.find(A[i]) == mymap.end()) {
			mymap[A[i]] = B[i];
		}
		else if (mymap.find(A[i]) != mymap.end() && mymap[A[i]] > B[i]) {
			mymap[A[i]] = B[i];
		}
	}
	cout << mymap.size();

	return 0;
}




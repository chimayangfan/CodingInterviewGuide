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
//	int Index = -1, min, max = INT_MIN;
//	for (int i = 1; i < A.size(); ++i) {
//		if (A[i] > A[i-1]) {
//			Index = i;
//			min = A[i - 1];
//			if (i < A.size() - 1)
//				max = A[i + 1];
//			break;
//		}
//	}
//	if (Index == -1) {
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
//		A[Index] = max;
//		for (auto e : A) {
//			cout << e << " ";
//		}
//	}
//	return 0;
//}


//数组中的数按频次排序，相同次数的数以第一次出现为优先
//#include <string>
//#include <iostream>
//#include <map>  
//#include <functional>  
//#include <vector>
//#include <algorithm>
//#include<iterator>
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
//bool greater_cmp(pair<int, int> a, pair<int, int> b) {
//	return  a.second > b.second;  //降序
//};

//int main(void)
//{
//	//int n;
//	//cin >> n;
//	//vector<int> A = CinIntVector();
//	//vector<int> B = CinIntVector();
//
//	int n = 19;
//	vector<int> salaries{ 1,2,4,6,3,3,4,2,5,5,5,5,6,3,6,7,8,9,10};//数组中的数按频次排序，相同次数的数以第一次出现为优先
//
	//map<int, int> mymap;
	//for (int i = 0; i < n; ++i) {
	//	if (mymap.find(salaries[i]) != mymap.end()) {
	//		mymap[salaries[i]]++;
	//	}
	//	else
	//		mymap.insert(make_pair(salaries[i], 1));
	//}
//	vector<int> vec;
//	std::vector<std::pair<int, int>> tmp(mymap.begin(), mymap.end());
//	std::sort(tmp.begin(), tmp.end(), greater_cmp);
//	for (int i = 0; i < tmp.size(); ++i) {
//		for (int j = 0; j < tmp[i].second; ++j) {
//			vec.push_back(tmp[i].first);
//		}
//	}
//
//	std::multimap<int, int, greater<int>> orderedmap;//按valse降序排列
//	//std::transform(mymap.begin(), mymap.end(), std::inserter(orderedmap, orderedmap.begin()), [](std::pair<int, int> a))
//	//{ return std::make_pair(a.second, a.first); });
//
//
//	//orderedmap中将mymap的key与value交换，然后按orderedmap的key排序
//	transform(mymap.begin(), mymap.end(), std::inserter(orderedmap, orderedmap.begin()), [](pair<int, int> a) { return pair<int, int>(a.second, a.first); });
//	
//	for (auto it = mymap.begin(); it != mymap.end(); ++it) {
//		cout << it->first << " ";
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//
//	return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//struct window{
//	int x1, y1;
//	int x2, y2;
//	int num;
//	window(int a = 0, int b = 0, int c = 0, int d = 0, int x = 0) :
//		x1(a), y1(b), x2(a+c), y2(b+d), num(x) {};
//};
//vector<window> v;
//bool check(int x, int y, window& w) {
//	if (x >= w.x1 && y >= w.y1 && x <= w.x2 && y <= w.y2)
//		return true;
//	return false;
//}
//void search(int x, int y) {
//	size_t i = 0;
//	while (i < v.size()) {
//		if (check(x, y, v[i])) {
//			window t = v[i];
//			v.erase(v.begin()+i);
//			v.insert(v.begin(), t);
//			cout << t.num << endl;
//			return;
//		}
//		++i;
//	}
//	cout << "-1";
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	v.resize(n);
//	for (int i = n - 1; i >= 0; --i) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		v[i] = window(x1, y1, x2, y2, n - i);
//	}
//	while (m--) {
//		int x, y;
//		cin >> x >> y;
//		search(x, y);
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
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
//int main() {
//	int n;
//	//cin >> n;
//	//vector<int> vec = CinIntVector();
//	n = 8;
//	vector<int> vec{ 1,6,2,5,4,6,7,4};
//	int len = vec.size();
//	vector<int> A;
//	vector<int> B;
//
//	int timeA = 1;
//	int timeB = 1;
//	int i = 0, j = len - 1;
//	while (len > 0) {
//		if (len > 1) {
//			if (timeA % 2 == 1 && vec[i] >= vec[j]) {
//				A.push_back(vec[i]);
//				timeA++;
//				i++;
//			}
//			else if (timeA % 2 == 1 && vec[i] < vec[j]) {
//				A.push_back(vec[j]);
//				timeA++;
//				j--;
//			}
//			else if (timeA % 2 == 0 && vec[i] <= vec[j]) {
//				A.push_back(vec[i]);
//				timeA++;
//				i++;
//			}
//			else if (timeA % 2 == 0 && vec[i] > vec[j]) {
//				A.push_back(vec[j]);
//				timeA++;
//				j--;
//			}
//			len--;
//		}
//		else {
//			A.push_back(vec[i]);
//			len--;
//		}
//		if (len > 1) {
//			if (timeB % 2 == 1 && vec[i] >= vec[j]) {
//				B.push_back(vec[i]);
//				timeB++;
//				i++;
//			}
//			else if (timeB % 2 == 1 && vec[i] < vec[j]) {
//				B.push_back(vec[j]);
//				timeB++;
//				j--;
//			}
//			else if (timeB % 2 == 0 && vec[i] <= vec[j]) {
//				B.push_back(vec[i]);
//				timeB++;
//				i++;
//			}
//			else if (timeB % 2 == 0 && vec[i] > vec[j]) {
//				B.push_back(vec[j]);
//				timeB++;
//				j--;
//			}
//			len--;
//		}
//		else {
//			B.push_back(vec[i]);
//			len--;
//		}
//	}
//	int sorceA = 0, sorceB = 0;
//	int preA = 0, preB = 0;
//	for (int i = 0; i < A.size(); ++i) {
//		sorceA += abs(A[i] - preA);
//		preA = A[i];
//	}
//	for (int i = 0; i < B.size(); ++i) {
//		sorceB += abs(B[i] - preB);
//		preB = B[i];
//	}
//	cout << sorceA << " " << sorceB << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//struct emoji{
//	int x, y;
//};
//
//int main() {
//	int W, XE, YE, XC, YC, PX, PY;
//	cin >> W >> XE >> YE >> XC >> YC >> PX >> PY;
//	vector<emoji> emojiVec(20);
//	for (int i = 0; i < 20; ++i) {
//		cin >> emojiVec[i].x >> emojiVec[i].y;
//	}
//	int row = 0, col = 0;
//	int x = 0, y = 0;
//	bool rflag = false;//转义符标志位
//	bool emo = false;//10~19表情标志
//	string str;
//	cin >> str;
//	for (int i = 0; i < str.length(); i += 2) {
//		//换行
//		if (x >= W) {
//			x -= W;
//			row ++;
//		}
//		string temp = str.substr(i, 2);
//		if (rflag) {
//			int num = stoi(temp);
//			//"#"
//			if (temp == "23") {
//				rflag = true;
//				continue;
//			}
//			//表情
//			if (rflag && 31 == num) {
//				emo = true;
//			}
//			else if (emo = true && 30 <= num && num <= 39) {
//				x += emojiVec[num - 20].x;
//			}
//			else if (rflag && 30 <= num && num <= 39) {
//				x += XC;
//			}
//		}
//		//汉字
//		else if (temp[0] == 'E') {
//			x += XC;
//			i += 4;
//		}
//		else {
//			x += XE;
//		}
//	}
//
//	return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//bool greater_cmp(pair<int, int> a, pair<int, int> b) {
//	double ave1 = (double)a.first / (double)a.second;
//	double ave2 = (double)b.first / (double)b.second;
//	return  ave1 > ave2;  //降序
//};
//
//int main() {
//	int n;
//	cin >> n;
//	pair<int, int> game;
//	for (int i = 0; i < n; ++i) {
//		int N, X;
//		//cin >> N >> X;
//		N = 3, X = 4;
//		vector<pair<int, int>> vec(N);
//		for (int j = 0; j < N; ++j) {
//			cin >> game.first >> game.second;
//			vec[j] = game;
//		}
//		sort(vec.begin(), vec.end(), greater_cmp);
//		int sum = 0;
//		for (auto it = vec.begin(); it != vec.end(); ++it) {
//			if (it->second <= X) {
//				sum += it->first;
//				X -= it->second;
//			}
//			else{
//				sum += (it->first / it->second) * X;
//			}
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//网易互娱第三题，没ac
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const char* g_str1 = 0;
const char* g_str2 = 0;

static void  foo1(void) {
	g_str1 = "hello1";
}

static void  foo2(void) {
	char p[] = "hello2";
	g_str2 = p;
}

int main() {
	foo1(); foo2();
	printf("foo1(%p): %s\n", g_str1, g_str1);
	printf("foo2(%p): %s\n", g_str2, g_str2);

	return 0;
}





























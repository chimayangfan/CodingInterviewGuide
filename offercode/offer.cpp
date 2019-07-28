﻿/***************************************************************************
*   @author:    汪亮
*   @date:      2019.3
*   @remark:    this code is used to record written test programming
*   @note:      
****************************************************************************/
//1、二叉树打印节点
//2、两组有序数组对比
//3、字符串中数字子串求和
//4、两个数组交替输出
//5、字符串序列去重旋转后排列
//6、字符串分割

//题号：1
//输入：按层序排列的数值和'#'
//输出：
//1、二叉树结构
//2、打印每层最左节点
//2、打印每层最右节点
//***************************************************************************
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//typedef struct BiTNode//二叉树的结点数据结构
//{
//	char data;
//	BiTNode *lchild, *rchild;
//};
//
//BiTNode *CreateBiTree(vector<char> a, int n, int start)//按层序输入，结点为空时，输入'#'
//{
//	if (a[start] == '#')return NULL;
//
//	BiTNode* root = new BiTNode;//新建一个根结点
//	root->data = a[start];//给根结点 root 的 成员变量 data、lchild、rchild 赋初值
//	root->lchild = NULL;
//	root->rchild = NULL;
//
//	int lnode = 2 * start + 1;
//	int rnode = 2 * start + 2;
//
//	if (lnode > n - 1) root->lchild = NULL;
//	else root->lchild = CreateBiTree(a, n, lnode);
//
//	if (rnode > n - 1) root->rchild = NULL;
//	else root->rchild = CreateBiTree(a, n, rnode);
//
//	return root;
//}
//
////先序遍历函数
//void PreOrderTraverse(BiTNode *T)
//{
//	if (T) {
//		cout << T->data << " ";
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
//	}
//}
//
////层序遍历--队列
//void LevelOrderTraverse(BiTNode *T)
//{
//	queue<BiTNode *> Q;
//	if (T == NULL) return;
//	Q.push(T);//入队根指针
//	while (!Q.empty()) {
//		BiTNode *cur = Q.front();
//		Q.pop();
//		cout << cur->data << " ";
//		if (cur->lchild) Q.push(cur->lchild);
//		if (cur->rchild) Q.push(cur->rchild);
//	}
//	cout << endl;
//}
//
////打印每层最左节点
//void printLeftNode(BiTNode *root)
//{
//	queue<BiTNode*> q1, q2;
//	BiTNode *tmp;
//	if (root == NULL) {
//		return;
//	}
//	q1.push(root);
//	//只要两队列都不为空
//	bool flag = false;//层标志位，每层执行一次
//	while (!(q1.empty() && q2.empty())) {
//		while (!q1.empty()) {
//			tmp = q1.front();
//			q1.pop();
//			if (!flag)
//			{
//				cout << tmp->data << endl;
//				flag = true;
//			}
//			if (tmp->lchild != NULL) {
//				q2.push(tmp->lchild);
//			}
//			if (tmp->rchild != NULL) {
//				q2.push(tmp->rchild);
//			}
//		}
//		while (!q2.empty()) {
//			tmp = q2.front();
//			q2.pop();
//			if (flag)
//			{
//				cout << tmp->data << endl;
//				flag = false;
//			}
//			if (tmp->lchild != NULL) {
//				q1.push(tmp->lchild);
//			}
//			if (tmp->rchild != NULL) {
//				q1.push(tmp->rchild);
//			}
//		}
//	}
//}
//
////打印每层最右节点
//void printRightNode(BiTNode *root) 
//{
//	queue<BiTNode*> q1, q2;
//	BiTNode *tmp;
//	if (root == NULL) {
//		return;
//	}
//	q1.push(root);
//	//只要两队列都不为空
//	while (!(q1.empty() && q2.empty())) {
//		while (!q1.empty()) {
//			tmp = q1.front();
//			q1.pop();	
//			if (tmp->lchild != NULL) {
//				q2.push(tmp->lchild);
//			}
//			if (tmp->rchild != NULL) {
//				q2.push(tmp->rchild);
//			}
//			if (q1.empty()) {
//				cout << tmp->data << endl;
//			}
//		}
//		while (!q2.empty()) {
//			tmp = q2.front();
//			q2.pop();
//			if (tmp->lchild != NULL) {
//				q1.push(tmp->lchild);
//			}
//			if (tmp->rchild != NULL) {
//				q1.push(tmp->rchild);
//			}
//			if (q2.empty()) {
//				cout << tmp->data << endl;
//			}
//		}
//	}
//}
//
//int main()
//{
//	vector<char> v;
//	BiTNode *t;
//	char ch;
//	do {
//		cin >> ch;
//		v.push_back(ch);
//	} while (getchar() != '\n');
//	//前序遍历：1 2 4 5 7 8 3 6
//	t = CreateBiTree(v, v.size(), 0);
//	LevelOrderTraverse(t);
//	printRightNode(t);
//
//	return 0;
//}
//***************************************************************************

//题号：2
//输入序列长度:7
//输入序列：2,3,5,7,8,9,11
//输入步长：1(根据步长应该得到的输出序列为4,5,6,7,8,9,10,11)
//输出：对比输入输出序列，用二进制表示输入序列数的缺失
//		如上，输出二进制为01011101(表示4,6,10缺失)
//最终输出：93(01011101转成十进制数)
//思路：由输入序列最后一个数和步长得到输出序列，
//		对比两个序列，输出序列与缺失位异或得出二进制数
//***************************************************************************
//#include<stack>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n, num, step;
//	cin >> n;
//	stack<int> nums;
//	do {
//		cin >> num;
//		nums.push(num);
//	} while (getchar() != '\n');
//	cin >> step;
//
//	int res = 0xff;
//	int bit = 1;
//	int temp = nums.top();
//
//	while (!nums.empty() && bit <= 0xff)
//	{
//		if (temp == nums.top())
//		{
//			nums.pop();
//			temp -= step;
//			bit = bit << 1;
//		}
//		else if (temp < nums.top())
//		{
//			nums.pop();
//		}
//		else
//		{
//			temp -= step;
//			res ^= bit;
//			bit = bit << 1;
//		}
//	}
//
//	cout << res;
//	return 0;
//}
//***************************************************************************

//题号：3
//输入：一行字符串中混合部分数字(正负整数)
//输出:字符串中所有数字之和
//例子：输入“A235BBB-1CC”，输出234
//思路：提取字符串中所有整数放入数组，
//		遍历数组求和
//***************************************************************************
//#include<string>
//#include<iostream>
//
//using namespace std;
//
//int GetNum(string str)
//{
//	int len = str.length();
//	if (len == 0) return 0;
//	int res = 0;
//	int num = 0;
//	int cur = 0;
//	bool posi = true;
//	for (int i = 0; i < len; i++) {
//		cur = str[i] - '0';
//		if (cur < 0 || cur > 9) {
//			res += num;
//			num = 0;
//			if (str[i] == '-') {
//				if (i > 0 && str[i - 1] == '-') {
//					posi = !posi;
//				}
//				else {
//					posi = false;
//				}
//			}
//			else {
//				posi = true;
//			}
//		}
//		else {
//			num = num * 10 + (posi ? cur : -cur);
//		}
//	}
//	res += num;
//	return res;
//}
//
//int main()
//{
//	cout << "请输入字符串" << endl;
//	string str("A235BBB-1CC");
//	//cin >> str;
//
//	cout << GetNum(str);
//	return 0;
//}
//***************************************************************************

//题号：4
//输入：两个数组
//输出：交替打印的序列
//例子：输入
//		3
//		1,2,3,4,5,6,7
//		a,b,c,d
//		输出：1,2,3,a,b,c,4,5,6,d,7
//***************************************************************************
//#include<string>
//#include<vector>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int count = 3;
//	cin >> count;
//	vector<int>arr1;
//	vector<int>arr2;
//	int num;
//	do {
//		cin >> num;
//		arr1.push_back(num);
//	} while (getchar() != '\n');
//	do {
//		cin >> num;
//		arr2.push_back(num);
//	} while (getchar() != '\n');
//	bool flag = true;
//	int i = 0, j = 0;
//	while (i != arr1.size() || j != arr2.size()) {
//		if (flag == true)
//		{
//			flag = false;
//			for (; i < arr1.size(); ++i) {
//				cout << arr1[i];
//				if (i != arr1.size() - 1 || j != arr2.size()) {
//					cout << ",";
//				}
//				if ((i + 1) % count == 0)
//				{
//					i++;
//					break;
//				}
//			}
//		}
//		if (flag == false)
//		{
//			flag = true;
//			for (; j < arr2.size(); ++j) {
//				cout << arr2[j];
//				if (i != arr1.size() || j != arr2.size() - 1) {
//					cout << ",";
//				}
//				if ((j + 1) % count == 0)
//				{
//					j++;
//					break;
//				}
//			}
//		}
//	}
//
//	return 0;
//}
//***************************************************************************

//题号：5
//输入：按行输入字符串，空白行终止
//输出：去重后的合法字符串序列、非法字符串序列、合法旋转的字符串序列、合法旋转排序的字符串序列
//说明：'0'-'9','a'-'z','A'-'Z'为合法字符，
//例子：输入：
//		第一行:abc		第四行：acd1243		第七行:ad--s
//		第二行:def		第五行：44234tjg	第八行:abd
//		第三行:==		第六行：aga'-=		第九行:abc
//		输出：
//		第一行:abc def acd123 44234tig abd
//		第二行:== aga'-= ad--s
//		第三行:bca efd 23acd1 234tig44 bda bca
//		第四行：234tig44 23acd1 bca bda efd
//***************************************************************************
//#include<string>
//#include<vector>
//#include<set>
//#include<unordered_set>
//#include<iostream>
//
//using namespace std;
//
//void left_1(string &str, int length)
//{
//	char c = str[0];
//	int i = 0;
//	for (i = 0; i<length - 1; i++)
//	{
//		str[i] = str[i + 1];
//	}
//	str[i] = c;
//}
//
//void left_n(string &str, int length, int time)
//{
//	for (int i = 0; i<time; i++)
//		left_1(str, length);
//}
//
//bool judg(string &str) {
//	int len = str.length();
//	for (int i = 0; i < len; ++i) {
//		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
//			continue;
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	string str;
//	bool end, flag;
//	unordered_set<string> arr;//原合法
//	vector<string> vec;//原合法
//	vector<string> vec1;//原非法
//	vector<string> vec2;//旋转不排序
//	set<string> arr1;//旋转排序
//
//	while (getline(cin, str)) {
//		if (str.size() == 0)//则为空行
//			break;
//		flag = judg(str);
//		if (flag) {
//			if (arr.insert(str).second)
//			{
//				vec.push_back(str);
//			}
//			left_n(str, str.length(), 10);
//			vec2.push_back(str);
//			arr1.insert(str);
//		}
//		else {
//			vec1.push_back(str);
//		}
//	}
//	for (auto s : vec) {
//		cout << s << " ";
//	}
//	cout << endl;
//	for (auto s : vec1) {
//		cout << s << " ";
//	}
//	cout << endl;
//	for (auto s : vec2) {
//		cout << s << " ";
//	}
//	cout << endl;
//	for (auto s : arr1) {
//		cout << s << " ";
//	}
//
//
//	return 0;
//}
//***************************************************************************

//题号：6
//输入：字符串规则A:45,C:35,D:9,F:43,M:10,G:90
//输出：<=20:2,21~50:3,51~70:,>70:1
//说明：区间计数，按数降序排序
//例子：输入：
//		字符串：A:45,C:35,D:9,F:43,M:10,G:90
//		Step1:按','分割字符串子串数组"A:45"...
//		Step2:创建键值对数组vector<pair<string,int> >,如：<"<=20:",0>...
//		Step3:按':'分割字符串到键值对pair<string,int>,如：<"A",45>...
//		Step3:按pair.second数值区间计数并排序
//***************************************************************************
//#include<string>
//#include<iostream>
//#include<unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//bool greater_second(const pair<string, int> & m1, const pair<string, int> & m2) {
//	return m1.second > m2.second;
//}
//
//int main()
//{
//	string cinstr;
//	cin >> cinstr;
//	vector<string> strvec;
//	string str;
//	pair<string, int> p;
//	unordered_map<string, int> map;
//	vector<double> Intervalsint{ 21, 51, 71, 100 };
//	vector<int> count{ 0, 0, 0, 0 };
//	vector<string>  Intervalsstr{ "<=20:","21~50:","51~70:",">70:" };
//	vector<pair<string, int>> res;
//	for (int i = 0; i < cinstr.size(); ++i) {
//		if (cinstr[i] != ',') {
//			str += cinstr[i];
//		}
//		else {
//			strvec.push_back(str);
//			str.clear();
//		}
//		if (i == cinstr.size() - 1) {
//			strvec.push_back(str);
//			str.clear();
//		}
//	}
//	str.clear();
//	for (int i = 0; i < strvec.size(); ++i) {
//		for (int j = 0; j < strvec[i].size(); ++j) {
//			if (strvec[i][j] != ':') {
//				str += strvec[i][j];
//			}
//			else
//			{
//				p.first = str;
//				str.clear();
//			}
//			if (j == strvec[i].size() - 1) {
//				p.second = stoi(str);
//				str.clear();
//				map.insert(p);
//				for (int k = 0; k < Intervalsint.size(); k++) {
//					if (p.second < Intervalsint[k]) {
//						count[k]++;
//						break;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i < Intervalsstr.size(); ++i) {
//		p.first = Intervalsstr[i];
//		p.second = count[i];
//		res.push_back(p);
//	}
//	sort(res.begin(), res.end(), greater_second);
//	for (int i = 0; i < res.size(); ++i) {
//		cout << res[i].first << res[i].second;
//		if (i != res.size() - 1) {
//			cout << ",";
//		}
//	}
//	return 0;
//}

#include<vector>
#include<string>
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int count;
	cin >> count;
	vector<string> strvec;
	string str;
	int len;
	for (int i = 0; i < count; ++i) {
		cin >> str;
		len = str.length();
		if (len < 8) {
			for (int j = 0; j < 8 - len; ++j) {
				str.append("0");
			}
			strvec.push_back(str);
		}
		else if (len > 8) {
			while (len > 8) {
				strvec.push_back(str.substr(0, 8));
				str = str.substr(8);
				len -= 8;
			}
			for (int j = 0; j < 8 - len; ++j) {
				str.append("0");
			}
			strvec.push_back(str);
		}
		else {
			strvec.push_back(str);
		}
	}
	sort(strvec.begin(), strvec.end());
	for (auto str : strvec) {
		cout << str << " ";
	}
	return 0;
}

//#include<vector>
//#include<stack>
//#include<string>
//#include<iostream>
//#include <algorithm>
//using namespace std;
//
//vector<char> Mystr(const char *pt, int &index)
//{
//	vector<char> output;
//	int num = pt[index] - '0';//获取数字
//	index++;
//	int begin = index;
//	for (int i = 0; i < num; ++i)
//	{
//		index = begin;
//		vector<char>str;
//		while (pt[index] != ')')
//		{
//			//若为字母
//			if ((pt[index] >= 'a'&&pt[index] <= 'z') || (pt[index] >= 'A'&&pt[index] <= 'Z'))
//				output.push_back(pt[index]);
//			//若为数字
//			if (pt[index] >= '1'&&pt[index] <= '9')
//			{
//				str = Mystr(pt, index);
//				if (str.size() > 0)
//				{
//					auto it = str.begin();
//					while (it != str.end())
//					{
//						output.push_back(*it);
//						it++;
//					}
//				}
//			}
//			index++;
//		}
//	}
//	return output;
//}
//
//string MyNewString(string str)
//{
//	const char *pt = str.c_str();
//	stack<char>m_reverse;
//	for (int i = 0; i < str.length(); i++)
//	{
//		//若遇到数字，则处理数字
//		if (pt[i] >= '0'&&pt[i] <= '9')
//		{
//			vector<char>temp;
//			temp = Mystr(pt, i);
//			auto it = temp.begin();
//			while (it != temp.end())
//			{
//				m_reverse.push(*it);
//				it++;
//			}
//			continue;
//		}
//		//若是字母，则直接push
//		if ((pt[i] >= 'a'&&pt[i] <= 'z') || (pt[i] >= 'A'&&pt[i] <= 'Z'))
//			m_reverse.push(pt[i]);
//	}
//	//反转输出
//	string output;
//	while (m_reverse.size() > 0)
//	{
//		output.insert(output.end(), m_reverse.top());
//		m_reverse.pop();
//	}
//	return output;
//}
//
//int main() {
//	string cinstr;
//	cin >> cinstr;
//	string coutstr = MyNewString(cinstr);
//	cout << coutstr;
//	return 0;
//}

//题号：8
//输入：整数N 1<= N <=10^18
//输出：整数M 表示小于等于N的非负整数中二进制回文数个数
//例子：输入：
//		6
//		输出：
//		4
//***************************************************************************
//#include<bits/stdc++.h>
//#include <forward_list>
//#include<string>
//#include<iostream>
//#include<unordered_set>
//
//using namespace std;
//
//string dectobin(int dec) {
//	string str;
//	long res = 0;
//	while (dec) {
//		res = dec % 2;
//		dec = dec / 2;
//		str = str + to_string(res);
//	}
//	return str;
//}
//
//bool ispalindrome(string binstr) {
//	int len = binstr.length();
//	for (int i = 0; i < len / 2; ++i) {
//		if (binstr[i] != binstr[len - 1 - i])
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	long long decnum, count = 0;
//	cin >> decnum;
//
//	for (long long i = 0; i <= decnum; ++i) {
//		string str = dectobin(i);
//		if (ispalindrome(str)) {
//			count++;
//		}
//	}
//	cout << count;
//
//	return 0;
//}

//题号：9
//输入：超长字符串数组
//输出：字符串数组中词频最高的前k个
//***************************************************************************
//#include <vector>
//#include <string>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <functional>   
//
//#define K 5
//
//using namespace std;
//
//void wordFreq(const vector<string> &word, map<string, long long> &map) {
//	for (auto e : word) {
//		++map[e];
//	}
//}
//
//struct Cmp {
//	bool operator()(const pair<int, string> &x, const pair<int, string> &y) const {
//		return x.first>y.first || (x.first == y.first && x.second<y.second);
//	}
//};
//
//int main(void)
//{
//	//海量待统计数据
//	vector<string> strarray = { "ab","ccc","b","ab","ccc" ,"ab","cdc","ba","asb","ccd" ,"ab" ,"ccc","b","ab","ccc" ,"ab" ,"cdc","b","ab","cdc" ,"asb" };
//	//vector<string> strarray = { "i", "love", "leetcode", "i", "love", "coding" };
//	//哈希映射统计频率
//	map<string, long long> wordmap;
//	wordFreq(strarray, wordmap);
//
//	priority_queue<pair<long long, string>, vector<pair<long long, string>>, greater<pair<long long, string>>> queueK;
//	for (map<string, long long>::iterator iter = wordmap.begin(); iter != wordmap.end(); iter++)
//	{
//		queueK.push(make_pair(iter->second, iter->first));
//		if (queueK.size() > K)
//			queueK.pop();
//	}
//
//	pair<long long, string> maxFreq;
//	while (!queueK.empty())
//	{
//		maxFreq = queueK.top();
//		queueK.pop();
//		cout << maxFreq.second << "\t" << maxFreq.first << endl;
//	}
//
//	return 0;
//}

//题号：9
//输入：两个字符串s，t
//输出：s中包含t子串的数量，其中'？'通配任何字符
//例：输入"a?a?a" "abab" 输出 1
//***************************************************************************
//#include <string>
//#include <iostream>
//#include <vector>  
//
//using namespace std;
//
//int strmatch(string s, string t) {
//	int len1 = s.size();
//	int len2 = t.size();
//	if (len1 < len2) return 0;
//	vector<string> vec;
//	for (int i = 0; i <= (len1 - len2); ++i) {
//		string str(s, i, i + len2);
//		vec.push_back(str);
//	}
//	int count = 0;
//	bool match;
//	for (int i = 0; i < vec.size(); ++i) {
//		match = true;
//		for (int j = 0; j < vec[i].size(); ++j) {
//			if (vec[i][j] != '?' && vec[i][j] != t[j]) {
//				match = false;
//				break;
//			}
//		}
//		if (match) {
//			count++;
//		}
//	}
//	return count;
//}
//
//int main(void)
//{
//
//	string s, t;
//	cin >> s >> t;
//	strmatch(s, t);
//
//	return 0;
//}
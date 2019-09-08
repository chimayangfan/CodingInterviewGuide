/***************************************************************************
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

//贝壳找房第一题
//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main() {
//	long n, m;
//	cin >> n >> m;
//	long var1 = 0, var2 = 0, abs = LONG_MAX;
//	for (int i = 1; i < n; ++i) {
//		long tmp;
//		cin >> tmp;
//		if (labs(tmp - m) < abs) {
//			abs = labs(tmp - m);
//			var1 = m;
//			var2 = tmp;
//		}
//		m = tmp;
//	}
//	cout << var1 << " "<< var2 << endl;
//	return 0;
//}

//贝壳找房第二题
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int n;
//	while (cin >> n) {
//		int MAX = 0;
//		vector<int> input(n + 1, 0);
//		vector<int> dp(n + 1, 0);
//		for (int i = 1; i <= n; i++) {
//			cin >> input[i];
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j<i; j++) {
//				if (input[j]<input[i]) {
//					dp[i] = max(dp[i], dp[j] + 1);
//					MAX = max(MAX, dp[i]);
//				}
//			}
//		}
//		cout << MAX + 1 << endl;
//	}
//}

//贝壳找房第三题
//#include<bits/stdc++.h>
//
//using namespace std;
//
//vector<double> CindoubleVector(int n) {
//	vector<double>nums;
//	int num;
//	for (int i = 0; i < n; ++i) {
//		cin >> num;
//		nums.push_back(num);
//	}
//
//	return nums;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<double> vec = CindoubleVector(n);
//	sort(vec.begin(), vec.end());
//	int maxcout = 0;
//
//	for (int i = n - 1; i > 0; --i) {
//		for (int j = i - 1; j >= 0; --j) {
//			if (vec[j] >= vec[i] * 0.9)
//				maxcout++;
//			else
//				break;
//		}
//	}
//	cout << maxcout << endl;
//	return 0;
//}

//贝壳找房第四题
#include <bits/stdc++.h>

using namespace std;

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
}

int main() {
	int n;
	cin >> n;
	//n = 5;
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> nums = CinIntVector(n);
	//vector<int> nums{ 1,4,3,2,5 };
	int Maxvar = -1;
	int mbegin = 0;
	for (int i = 0; i < n; ++i) {
		if (nums[i] > nums[i + 1]) {
			mbegin = i;
			break;
		}
	}
	int mend = n - 1;
	for (int i = n - 1; i>0; --i) {
		if (nums[i] > nums[i - 1]) {
			mend = i;
			break;
		}
	}
	if (mbegin == mend) {
		cout << 0 << endl;
		return 0;
	}
}

//网易互娱第一题，ac
//#include<bits/stdc++.h>
//#include<unordered_map>
//using namespace std;
//
//vector<int> CinIntVector(int n) {
//	vector<int>nums;
//	int num;
//	for (int i = 0; i < n; ++i) {
//		cin >> num;
//		nums.push_back(num);
//	}
//	return nums;
//}
//
//int main() {
//	int n = 10, m = 6, num;
//	for (int i = 0; i < n; ++i) {
//		unordered_map<int, int> res;
//		cin >> m;
//		for (int j = 0; j < m; ++j) {
//			cin >> num;
//			bitset<32> bits(num);
//			int count = bits.count();
//			res.insert(make_pair(count, num));
//		}
//		cout << res.size() << endl;
//	}
//	return 0;
//}

//网易互娱第二题，没ac
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n = 5;
//	//cin >> n;
//	//vector<int> m(n, 0);
//	//vector<int> t(n, 0);
//	//vector<int> m1(n, 0);
//	//vector<int> t1(n, 0);
//	//vector<int> m2(n, 0);
//	//vector<int> t2(n, 0);
//	vector<int> cap(n, 0);
//	vector<int> m{ 10,10,10,10,10 };
//	vector<int> t{ 2,2,2,100,1000 };
//	vector<int> m1{ 1,10,3,3,10 };
//	vector<int> t1{ 5,5,5,4,5 };
//	vector<int> m2{ 2,2,2,4,5 };
//	vector<int> t2{ 5,5,5,3,3 };
//
//	//for (int i = 0; i < n; ++i) {
//	//	cin >> m[i] >> t[i] >> m1[i] >> t1[i] >> m2[i] >> t2[i];
//	//}
//	for (int i = 0; i < n; ++i) {
//		int water = 0;
//		for (int time=0; time < t[i]; ++time) {
//			if ((time / t1[i] % 2) == 0) {
//				water += m1[i];
//				if (water > m[i]) {
//					water = m[i];
//				}
//			}
//			if ((time / t2[i] % 2) == 0) {
//				water -= m2[i];
//				if (water < 0) {
//					water = 0;
//				}
//			}
//		}
//		cap[i] = water;
//	}
//	for (auto e : cap) {
//		cout << e << endl;
//	}
//	return 0;
//}

//网易互娱第三题，没ac
#include<bits/stdc++.h>
using namespace std;

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}

int characterReplacement(string s, int k) {
	int max_count = 0, l = 0, r;
	vector<int> count(128, 0);
	for (r = 0; r<s.size(); r++)
	{
		//双指针范围内重复字符数
		max_count = max(max_count, ++count[s[r]]);
		//双指针范围内-重复字符数 > 可修改字符数
		if (r - l + 1 - max_count>k)
			count[s[l++]]--;
	}
	return r - l;
}

int main() {
	int n = 3;
	vector<string> strvec(n);
	vector<int> same;
	vector<int> dif;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> strvec[i];
		cout << characterReplacement(strvec[i], 2) << endl;
	}
	return 0;
}

//网易互娱第四题，没ac
#include<bits/stdc++.h>
using namespace std;

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}

int main() {
	int n = 10, m = 6;
	vector<int> arr{ 6,12,20,14,15,15,7,19,16,13 };
	vector<int> flood{ 15,24,19,6,17,24 };
	//cin >> n;
	//vector<int> arr = CinIntVector(n);
	//vector<int> flood = CinIntVector(m);
	vector<int> res;

	for (int i = 0; i < m; ++i) {
		vector<vector<int>> out;
		vector<int> tower;
		for (int j = 0; j < n; ++j) {
			if (arr[j] > flood[i]) {
				tower.push_back(arr[j]);
			}
			else {
				if (tower.size() != 0)
					out.push_back(tower);
				tower.clear();
			}
			if (j == n - 1 && tower.size() > 0) {
				out.push_back(tower);
				tower.clear();
			}
		}
		res.push_back(out.size());
	}
	for (auto e : res) {
		cout << e << endl;
	}
	return 0;
}

//字节跳动8.11第三题，ac
#include<bits/stdc++.h>

using namespace std;

void fun(vector<int> vec, vector<int> &arr, int index) {
	while (index > 0 && vec[index] < vec[index - 1]) {
		arr[index - 1] += 100;
		index--;
	}
	return;
}

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}


int main() {
	int n;
	cin >> n;
	vector<int> vec = CinIntVector(n);
	vector<int> wage{ 100 };

	for (int i = 1; i < n; ++i) {
		if (vec[i] > vec[i - 1]) {
			wage.push_back(wage[i - 1] + 100);
		}
		else if (vec[i] == vec[i - 1]) {
			wage.push_back(wage[i - 1]);
		}
		else {
			wage.push_back(100);
		}
		fun(vec, wage, i);
	}
	for (int i = 1; i < n - 1; ++i) {
		if (wage[i] > wage[i - 1] && wage[i] > wage[i + 1]) {
			wage[i] = wage[i - 1] > wage[i + 1] ? (wage[i - 1] + 100) : (wage[i + 1] + 100);
		}
	}
	for (auto e : wage) {
		cout << e << " ";
	}
	return 0;
}

//360第一题
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> contain;
	int num;
	int sum = 0;
	for (int n = 0; n < N; n++)
	{
		vector<int> temp;
		for (int m = 0; m < M; m++)
		{
			cin >> num;
			temp.push_back(num);
		}
		contain.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (contain[i][j] == 1)
				sum += 6;
			else if (contain[i][j] > 1)
				sum += 6 + (contain[i][j] - 1) * 4;

			if (i + 1 < N && contain[i + 1][j] != 0)
			{
				int small = contain[i + 1][j] > contain[i][j] ? contain[i][j] : contain[i + 1][j];
				sum -= small;
			}
			if (i - 1 >= 0 && contain[i - 1][j] != 0)
			{
				int small = contain[i - 1][j] > contain[i][j] ? contain[i][j] : contain[i - 1][j];
				sum -= small;
			}
			if (j + 1 < M && contain[i][j + 1] != 0)
			{
				int small = contain[i][j + 1] > contain[i][j] ? contain[i][j] : contain[i][j + 1];
				sum -= small;
			}
			if (j - 1 >= 0 && contain[i][j - 1] != 0)
			{
				int small = contain[i][j - 1] > contain[i][j] ? contain[i][j] : contain[i][j - 1];
				sum -= small;
			}
		}

	}
	cout << sum << endl;
}

//Zoom第一题：两数之和等于目标值
#include<bits/stdc++.h>

using namespace std;

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}

vector<int> findnumssum(const vector<int> &arr, int target) {
	vector<int> res;
	if (arr.size() < 2) return res;
	int a = 0, b = 1;
	int index = 0;
	while (a < b)
	{
		a = arr[index];
		for (int i = index + 1; i<arr.size(); ++i)
		{
			b = arr[i];
			if (target == (a + b))
			{
				res.push_back(index);
				res.push_back(i);
				return res;
			}
		}
		index++;
	}
	return res;
}

int main() {
	int tar = 9, n = 4;
	//cin >> tar >> n;
	vector<int> arr = CinIntVector(n);
	vector<int> back = findnumssum(arr, tar);
	for (auto e : back) {
		cout << e << " ";
	}

	return 0;
}


//Zoom第二题：没看懂
#include<bits/stdc++.h>

using namespace std;
typedef int KeyType;

typedef struct qNode {
	KeyType val;
	struct qNode *next;
}qNode, *Linkqueue;

typedef struct {
	int size;
	Linkqueue rear;
}que;

int enqueue(que* q, KeyType new_elem)
{
	qNode* p;
	p = (qNode*)malloc(sizeof(qNode));
	if (!p)
		return 0;
	p->val = new_elem;
	if (q->rear) {
		p->next = q->rear->next;
		//(___)
		q->rear->next = p;
	}
	else {
		p->next = p;
	}
	//(__)
	q->size++;
	return 1;
}

//int dequeue(que*q, KeyType*elem)
//{
//	 qNode*p;
//	if (0 == q ->size)
//		return 0;
//	//p = (__)
//	*elem = p ->val;
//	q ->rear ->next = (__)
//	if (__)
//		q ->rear = NULL;
//	free(p);
//	q ->size--;
//	return 1;
//}

int main(void)
{
	int n, m;
	cin >> n >> m;
	que test_q;
	test_q.size = 0;
	test_q.rear = NULL;
	enqueue(&test_q, 3);

}

//华为第一题
#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	string input, str, output;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		input = input + str + " ";
	}
	map<string, string> hexmap{ { "A","12 34" },{ "B","AB CD" } };
	int index = 0;
	int count = N;
	bool flag = true;
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == ' ') {
			string temp = input.substr(index, i - index);
			if (hexmap.find(temp) != hexmap.end()) {
				output = output + " " + hexmap[temp];
				count++;
			}
			else
				output = output + " " + temp;
			index = i + 1;
		}
	}

	cout << setiosflags(ios::uppercase) << hex << count;
	cout << output << endl;

	return 0;
}

//华为第三题
#include<bits/stdc++.h>

using namespace std;

int main() {
	string name;
	cin >> name;
	int N;
	cin >> N;
	vector<set<string>> namevec;
	set<string> res;

	for (int i = 0; i < N; ++i) {
		set<string> namelist;
		string list;
		cin >> list;
		list += ',';
		int index = 0;
		for (int j = 0; j < list.length(); j++) {
			if (list[j] == ',') {
				namelist.insert(list.substr(index, j - index));
				index = j + 1;
			}
		}
		if (namelist.find(name) != namelist.end())
			res.insert(namelist.begin(), namelist.end());
		namevec.push_back(namelist);
	}
	for (int i = 0; i < N; ++i) {
		for (auto it = namevec[i].begin(); it != namevec[i].end(); ++it) {
			if (res.find(*it) != res.end()) {
				for (auto it = namevec[i].begin(); it != namevec[i].end(); ++it) {
					res.insert(*it);
				}
			}
		}
	}
	cout << res.size() << endl;

	return 0;
}

//完美世界第一题 | 有向图的最短距离
#include<iostream>
#include <vector>
using namespace std;
const int inf = 999999;
const int n = 6;
int L[n][n] = { 0,  1,  12,inf,inf, inf,
inf,  0, 9, 3,inf,inf,
inf, inf,  0,  inf,  5, inf,
inf, inf,  4,   0,  13, 15,
inf, inf, inf, inf,  0,  9,
inf, inf, inf, inf,  inf,  0
};               //存储图中的路径
int dis[n];        //存储源点到各个顶点的最短路径

vector<int> path[n];
int main()
{
	//for (int i = 0; i < 6; ++i)
	//	for (int j = 0; j < 6; ++j)
	//		cin >> L[i][j];
	for (int i = 0; i < n; i++)              //初始化
	{
		dis[i] = L[0][i];
		path[i].push_back(1);
		path[i].push_back(i + 1);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//dis[i] = min(dis[i],dis[j] + L[j][i]);
			if (dis[i] > dis[j] + L[j][i])               //求源点到节点的最短路径，利用现有的L矩阵
			{
				dis[i] = dis[j] + L[j][i];

				path[i].clear();                         //保存并更新路径
				path[i].insert(path[i].end(), path[j].begin(), path[j].end());
				path[i].push_back(i + 1);
			}

		}
		for (int m = 0; m < i; m++)              //更新节点最短路径
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[m] > dis[j] + L[j][m])
				{
					dis[m] = dis[j] + L[j][m];
					path[m].clear();                     //保存并更新路径
					path[m].insert(path[m].end(), path[j].begin(), path[j].end());
					path[m].push_back(m + 1);
				}
			}
		}
	}
	//vector<int>::iterator ite;
	for (int i = 1; i < n; i++)
	{
		cout << dis[i] << endl;
		//cout << "V1到V" << i + 1 << "的最短路径长度：" << dis[i] << endl << "Path：";
		//for (ite = path[i].begin(); ite != path[i].end(); ++ite) {
		//	if (ite == path[i].begin())
		//		cout << *ite;
		//	else
		//		cout << "->" << *ite;
		//}
		//cout << endl;
	}

	return 0;
}

//字节跳动第一题
#include<bits/stdc++.h>

using namespace std;

void dfs(int y, vector<int>& label, int N, vector<vector<int>>& input)
{
	for (int i = 0; i < N; i++)
	{
		if (label[i] == 0 && input[y][i] > 3)
		{
			label[i] = 1;
			dfs(i, label, N, input);
		}
	}
}

int main()
{
	vector<vector<int>> input;
	int N;

	cin >> N;
	int i, j, data;
	for (i = 0; i < N; i++)
	{
		vector<int> temp;
		for (j = 0; j < N; j++)
		{
			cin >> data;
			temp.push_back(data);
		}
		input.push_back(temp);
	}



	int sum = 0;
	vector<int> label(N, 0);
	for (int k = 0; k < N; k++)
	{
		if (label[k] == 0)
		{
			sum++;
			label[k] = 1;
			dfs(k, label, N, input);
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

//字节跳动第二题
#include<bits/stdc++.h>

using namespace std;

long long sum = 0;
long long i = 1;

long long fun(long long n) {
	if (n == 0)
		return 0;
	else if (n == 2)
		return 1;
	else if (n == 4)
		return 2;
	else if (n == 6)
		return 5;
	else if (n == 8)
		return 14;
	else if (n == 10)
		return 42;
	else {
		sum += 2 * fun(n - 2);
		n -= 2;
		while (n > 2) {
			sum += fun(n - 2) * fun(2 * i);
			n -= 2;
			i++;
		}
		return sum;
	}
}

int main() {
	long long n;
	while (cin >> n) {
		if (n % 2 != 0) {
			cout << 0 << endl;
		}
		else {
			cout << fun(n);
		}
	}

	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 2)
	{
		cout << 1;
		return 0;
	}
	long long* num = new long long[1001]();
	num[0] = 1;
	for (int i = 2; i <= n; i = i + 2)
	{
		for (int j = 2; j <= i; j = j + 2)
		{
			long long temp = (num[j - 2] * num[i - j]) % 1000000007;

			num[i] = (num[i] + temp) % 1000000007;
		}

	}
	cout << num[n];

	return 0;
}

//字节跳动第三题
int main()
{
	int dir;
	cin >> dir;
	int arr[4][4];
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	int output[4][4];

	bool flag = false;
	if (dir == 1)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < 3; ++i)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j])
				{
					arr[i][j] = arr[i + 1][j] * 2;
					arr[i + 1][j] = 0;
					flag = true;
				}
			}
			//调整位置
			if (flag)
			{
				for (int i = 0; i < 4; ++i)
				{
					if (arr[i][j] == 0)
					{
						for (int k = i + 1; k < 4; ++k)
						{
							if (arr[k][j] != 0)
							{
								arr[i][j] = arr[k][j];
								arr[k][j] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
	else if (dir == 2)//下
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 3; i >0; --i)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i - 1][j])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[i - 1][j] = 0;
					flag = true;
				}
			}
			//调整位置
			if (flag)
			{
				for (int i = 3; i >= 0; --i)
				{
					if (arr[i][j] == 0)
					{
						for (int k = i - 1; k >= 0; --k)
						{
							if (arr[k][j] != 0)
							{
								arr[i][j] = arr[k][j];
								arr[k][j] = 0;
								break;
							}
						}
					}
				}
			}

		}
	}
	else if (dir == 3)//左
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[i][j + 1] = 0;
					flag = true;
				}
			}
			//调整位置
			if (flag)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (arr[i][j] == 0)
					{
						for (int k = j + 1; k < 4; ++k)
						{
							if (arr[i][k] != 0)
							{
								arr[i][j] = arr[i][k];
								arr[i][k] = 0;
								break;
							}
						}
					}
				}
			}

		}
	}
	else if (dir == 4)// 右
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 3; j >0; --j)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[i][j - 1] = 0;
					flag = true;
				}
			}
			//调整位置
			if (flag)
			{
				for (int j = 3; j >= 0; --j)
				{
					if (arr[i][j] == 0)
					{
						for (int k = j - 1; k >= 4; --k)
						{
							if (arr[i][k] != 0)
							{
								arr[i][j] = arr[i][k];
								arr[i][k] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i][0] << " ";
		cout << arr[i][1] << " ";
		cout << arr[i][2] << " ";
		cout << arr[i][3] << " " << endl;
	}
	return 0;
}

//字节跳动第四题
int gcd(int data1, int data2)
{
	if (data1 == data2)
	{
		return data1;
	}
	if (data1 < data2)											//为了保证较大的数始终在前面，减少了代码
	{
		gcd(data2, data1);
	}
	else
	{															//与1操作是为了判断奇偶
		if (!(data1 & 1) && !(data2 & 1))						//两数都是偶数
		{
			return gcd(data1 >> 1, data2 >> 1) << 1;
		}
		else if (!(data1 & 1) && (data2 & 1))					//data1为偶数，data2为奇数
		{
			return gcd(data1 >> 1, data2);
		}
		else if ((data1 & 1) && !(data2 & 1))					//data1为奇数，data2为偶数
		{
			return gcd(data1, data2 >> 1);
		}
		else                                                   //当两个数都为奇数时，应用更相减损法
		{
			return gcd(data2, data1 - data2);
		}
	}
}






void dfs(int y, vector<int>& label, int N, vector<vector<int>>& input, int& sum)
{
	for (int i = 0; i < N; i++)
	{
		if (label[i] == 0 && input[y][i] > 1)
		{
			label[i] = 1;
			sum++;
			dfs(i, label, N, input, sum);
		}
	}
}



int main()
{
	vector<int> data_vector;
	vector<vector<int>> input;
	int N;

	cin >> N;
	int i, j, data, factorize;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		data_vector.push_back(data);
	}


	for (i = 0; i < N; i++)
	{
		vector<int> temp;
		for (j = 0; j < N; j++)
		{
			temp.push_back(0);
		}
		input.push_back(temp);
	}
	for (i = 0; i < N; i++)
	{
		vector<int> temp;
		for (j = i + 1; j < N; j++)
		{
			factorize = gcd(data_vector[i], data_vector[j]);
			input[i][j] = factorize;
			input[j][i] = factorize;
		}
	}



	int sum = 0;
	vector<int> label(N, 0);
	for (int k = 0; k < N; k++)
	{
		if (label[k] == 0)
		{
			label[k] = 1;
			dfs(k, label, N, input, sum);
		}
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}

//360第一题
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int maxcount = INT_MIN;
	map<char, int> mymap;
	for (int i = 0; i < str.length(); ++i) {
		mymap[str[i]]++;
	}
	for (auto it = mymap.begin(); it != mymap.end(); ++it) {
		maxcount = maxcount > it->second ? maxcount : it->second;
	}
	cout << maxcount << endl;
	return 0;
}

//360第二题
#include<bits/stdc++.h>

using namespace std;

void isOrigin(vector<int>&vecD, int Index, int currentPos, vector <bool>&flag)
{
	if (currentPos<0 || currentPos >= vecD.size()) return;
	if (Index >= vecD.size())
	{
		flag[currentPos - 1] = true;
	}
	//向前走
	isOrigin(vecD, Index + 1, currentPos + vecD[Index], flag);
	//向后走
	isOrigin(vecD, Index + 1, currentPos - vecD[Index], flag);
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int>vecD(M);
	vector<bool>flag(M, false);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecD[i];
	}
	for (int i = 0; i < N; ++i)
	{
		isOrigin(vecD, 0, i, flag);
	}
	int count = 0;
	for (int i = 0; i < flag.size(); ++i)
	{
		if (flag[i])
			count++;
	}

	cout << count << endl;
	return 0;
}

//pdd第1题
#include<bits/stdc++.h>

using namespace std;
//字符串分割
vector<string> split(string str, string pattern) {
	string::size_type pos;
	vector<string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);//从位置i开始，返回第一个pattern子串索引
		if (pos<size)
		{
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
//按奇偶排序
void sortarr(vector<int> &A, vector<int> &even, vector<int> &odd) {
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] % 2 != 0) {
			odd.push_back(A[i]);
		}
		else {
			even.push_back(A[i]);
		}
	}
	sort(even.begin(), even.end(), greater<int>());
	sort(odd.begin(), odd.end(), greater<int>());
}

int main() {
	string str = "555503,772867,756893,339138,399447,40662,859037,628085,855723,974471,599631,636153,581541,174761,948135,411485,554033,858627,402833,546467,574367,360461,566480,755523,222921,164287,420256,40043,977167,543295,944841,917125,331763,188173,353275,175757,950417,284578,617621,546561,913416,258741,260569,630583,252845;10";
	//cin >> str;
	vector<string> arr = split(str, ";");
	vector<string> num = split(arr[0], ",");

	int N = stoi(arr[1]);
	vector<int> vec;
	for (auto e : num) {
		vec.push_back(stoi(e));
	}
	vector<int> even;
	vector<int> odd;
	sortarr(vec, even, odd);
	string out;
	for (int i = 0; i < N; ++i) {
		if (i < even.size() && i != N - 1) {
			cout << even[i] << ",";
		}
		else if (i < even.size() && i == N - 1) {
			cout << even[i] << endl;
		}
		else if (i != N - 1) {
			cout << odd[i - even.size()] << ",";
		}
		else {
			cout << odd[i - even.size()] << endl;
		}
	}

	return 0;
}

//pdd第2题
#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		bool flag = false;
		string mei, bai;
		cin >> mei >> bai;
		cout << "{" << endl;
		for (int i = 0; i < bai.length(); ++i) {
			if (mei.find(bai[i]) == mei.npos) {
				cout << "}" << endl;
				flag = true;
				break;
			}
		}
		if (!flag) {

		}
	}

	return 0;
}

//pdd第4题
#include<bits/stdc++.h>
using namespace std;

double Expect(vector<int> m, int n, int max = 1, int index = 0) {//求期望值
	double E = 1;//最后一次掷得得值为m
	if (n != 1) {//不止掷一次
		for (int i = 1; i < max; i++) {
			E += (1.0 / m[index])*Expect(m, n - 1, max, index);//最后一次掷得的骰子数为1--max
		}
		for (int j = max; j < m[index]; j++) {
			E += (1.0 / m[index])*Expect(m, n - 1, j, index);//最后一次掷得的骰子数为max--m-1
		}
	}
	else {//掷一次，这也是给递归赋了一个初值
		for (int i = 1; i < max; i++) {
			E += (1.0 / m[index])*max;
		}
		for (int j = max; j < m[index]; j++) {
			E += (1.0 / m[index])*j;
		}
		index++;
	}
	return E;
}
int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	float Exp = 1.0f;
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		//Exp *= Expect(X[i], 1, 1);
	}
	cout << Expect(X, N, 1, 0);
	cout << endl;
	return 0;
}

//pdd第4题
#include<bits/stdc++.h>
using namespace std;

int findKthValue(int rows, int cols, int k) {
	int i, j;
	int min = 1;
	//int minOfRows[rows];
	vector<int> minOfRows;
	minOfRows.resize(rows);

	for (i = 0; i < rows; i++)
		minOfRows[i] = 0;

	//记录寻找过程中，各行最小值的所在列
	minOfRows[0] = 1;

	int r;
	//找k个数
	for (i = 1; i < k; i++)
	{
		min = INT_MAX;
		//找到最小值所在的行，每次执行都能找到一个最小值，并且记录最小值所在行
		for (j = 0; j < rows; j++)
		{
			if (minOfRows[j] < cols)
			{
				if ((j + 1) * (minOfRows[j] + 1) < min)
				{
					min = (j + 1) * (minOfRows[j] + 1);
					r = j;
				}
			}
		}
		minOfRows[r]++;  //最小值在该行，下次访问时从下一值开始
	}
	return min;
}


int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int number = n * m + 1 - k;
		int kth = findKthValue(m, n, number);

		cout << kth << endl;
	}
	return 0;
}

//云从第1题
#include<bits/stdc++.h>

using namespace std;

vector<int> CinIntVector(int n) {
	vector<int>nums;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	return nums;
}

bool queright(queue<bool> que, int me, int ms) {
	int counts = 0, counte = 0;
	while (!que.empty) {
		if (que.front() == true) {
			counts++;
		}
		if (que.front() == false) {
			counte++;
		}
		if (counts > ms || counte > me) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, k, ms, me;
	cin >> n >> k >> ms >> me;
	//vector<int> sleep = CinIntVector(n);
	//vector<int> eat = CinIntVector(n);
	vector<int> sleep{ 4,8,6,2,2 };
	vector<int> eat{ 4,6,9,6,0 };
	vector<int> minus(n);
	queue<bool> que;
	vector<bool> choose(n, false);
	int happyval = 0;
	string str;
	for (int i = 0; i < n; ++i) {
		if (sleep[i] > eat[i] && ) {
			happyval += sleep[i];
			str += "S";
		}
		else {
			happyval += eat[i];
			str += "E";
		}
	}
	cout << happyval << endl;
	cout << str;

	return 0;
}
//云从第2题
void minDistance(vector<int>X, vector<int>cur, const int m, int&min, int index)
{
	if (cur.size() == m)
	{
		int dis = INT_MAX;
		//求当前位置的最小距离
		for (int i = 0; i < cur.size() - 1; ++i)
		{
			int temp = cur[i + 1] - cur[i];
			dis = dis < temp ? dis : temp;
		}
		min = min < dis ? dis : min;
		return;
	}
	if (index >= X.size()) return;
	minDistance(X, cur, m, min, index + 1);
	cur.push_back(X[index]);
	minDistance(X, cur, m, min, index + 1);
}

int main() {


	int n, m;
	cin >> n >> m;
	vector<int>x(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	sort(x.begin(), x.end());

	vector<int>cur;
	int output = 0;
	minDistance(x, cur, m, output, 0);
	cout << output << endl;
	return 0;
}

int happyval = 0;
int counte = 0, counts = 0;
int index = 0;
for (int i = 0; i < n; ++i) {
	if (sleep[i] > eat[i]) {
		happyval += sleep[i];
		choose[i] = true;
		if (que.size() < 4) {
			que.push(choose[i]);
		}

	}
	else if (sleep[i] < eat[i]) {
		happyval += eat[i];
	}
}

//云从第3题
#include<stdio.h>

int strlen(const char*IpszBuffer) {
	return *IpszBuffer ? (strlen(++IpszBuffer) + 1) : 0;
}

int main() {
	char str[1000];
	gets(str);
	int len = strlen(str);
	printf("%d", len);
}

//爱奇艺 36%
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	if (n <= 1 || n > 1000)
		return 0;
	vector<int>A(n - 1), B(n);
	for (int i = 0; i < n - 1; ++i) {
		B[i] = i + 1;
		cin >> A[i];
	}
	B[n - 1] = n;
	do {
		int numb = 1;
		for (int i = 0; i < n - 1; ++i) {
			if ((A[i] == 1) && B[i] > B[i + 1] || !((A[i] == 0 && B[i] < B[i + 1]))) {
				numb = 0;
				break;
			}
		}
	} while (next_permutation(B.begin(), B.end()));
	int out = pow(10, 9) + 7;
	cout << res % out;
	return 0;
}

//爱奇艺 45%
#include<bits/stdc++.h>

using namespace std;

void backTracking(vector<int> ints, vector<int>& subset, set<vector<int>>& resSet, vector<bool> used) {
	if (ints.size() == subset.size()) {
		resSet.insert(subset);
		return;
	}
	for (int i = 0; i < ints.size(); i++) {
		if (used[i] || (i > 0 && ints[i] == ints[i - 1] && !used[i - 1]))
			continue;
		used[i] = true;
		subset.push_back(ints[i]);
		backTracking(ints, subset, resSet, used);
		used[i] = false;
		subset.pop_back();
	}
}
set<vector<int>> permuteUnique(vector<int> nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	set<vector<int>> resSet;
	vector<bool> used(n, false);
	vector<int> subset;
	backTracking(nums, subset, resSet, used);
	return resSet;
}

int main() {
	int Red, Blue;
	////cin >> Red >> Blue;
	Red = 1, Blue = 1;

	vector<int> nums(Red + Blue);
	for (int i = 0; i < Red + Blue; ++i) {
		if (i < Red)
			nums[i] = 1;
		else
			nums[i] = 0;
	}
	set<vector<int>> vec = permuteUnique(nums);
	int count = 0;
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		for (int i = 0; i < nums.size(); ++i) {
			if (i % 3 == 0 && *(it->begin() + i) == 1) {
				count++;
				break;
			}
			if (i % 3 == 1 && *(it->begin() + i) == 1) {
				break;
			}
		}
	}

	float Awin = (float)count / (float)vec.size();
	cout << setprecision(5) << Awin;

	return 0;
}
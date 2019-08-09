#pragma once
#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__

#include<iostream>
#include<ctime>
#include <cstdlib>
#include<vector>
#include<string>
#include<deque>
#include<sstream>

using namespace std;
/*
* 键盘输入模板
* 功能：用于将键盘读取数据存入指定容器中。
* 输入：cin >>
*/

//模板类使用实例
//keyboard<T> template;
//T* a = new T[n]; a = template.CinIntArray(n);
//vector<string> b; b = template.CinIntVector();

/**************************  声明  ****************************/
//模板类声明
template <class T>
class keyboard {
public:
	//keyboard();
	T* CinIntArray(T n);								//1:从键盘读入任意长度的数组,n为数组长度
	vector<T> CinIntVector();							//2:从键盘读入任意长度的数组，不需要先确定数组长度
	T CinRandonZeroToN(T N);							//3:从键盘读入N,生成0~N的随机数
	int GetGCD(int M, int N);							//4:从键盘读入两个数M和N,返回两个数的最大公约数
	string BigIntNumAdd(string& str1, string& str2);	//5:从键盘读入两个超大数M和N,返回两个数之和(整数)方式1
	void BigIntNumAdd2(string& ans, string& b);			//5:从键盘读入两个超大数M和N,返回两个数之和(整数)方式2
	string BigFloatNumAdd(string a, string b);			//5:从键盘读入两个超大数M和N,返回两个数之和(浮点数)
	string subtract(string ans, string b);				//6:从键盘读入两个超大数M和N,返回两个数之差(整数)
	string BigNumMultiply(string& s1, string& s2);		//6:从键盘读入两个超大数M和N,返回两个数之积(整数)
	void CinVectorMatN(vector<vector<T> > &vec, int n);	//7:从键盘读入N阶矩阵，vector<vector<T> >形式
	void CinArrayMatN(int** &arr, int n);				//8:从键盘读入N阶矩阵，int**形式														
	vector<string> split(string str, string pattern);	//9:从键盘读入字符串，按指定字符分割成子串数组														
	void extractuintarray(string _str, vector<int> &_num);//10:从键盘读入字符串，提取无符号整型数组(不判断符号、小数点)
	void extractintarray(string _str, vector<int> &_num);//11:从键盘读入字符串，提取整型数组(不判断小数点)
};

/**************************  定义  ****************************/

//1:从键盘读入任意长度的数组,n为数组长度
//输入方式：1 2 3 4 5 6
template <typename T>
T* keyboard<T>::CinIntArray(T n) {   
	T* arr = new T[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	return arr;
}

//2:从键盘读入任意长度的数组
//T为char,输入方式：a b c d e f
//T为int,输入方式：1 2 3 4 5 6
//T为string,输入方式：hello world!
template <typename T>
vector<T> keyboard<T>::CinIntVector() {
	vector<T>nums;
	T num;
	do {
		cin >> num;
		nums.push_back(num);
	} while (getchar() != '\n');

	return nums;
}

//3:从键盘读入N,生成0~N的随机数
template <typename T>
T keyboard<T>::CinRandonZeroToN(T N)
{
	srand(time(0)); // 随机数的初始化函数，为随机数播下种子
	T num = rand() % (N + 1);

	return num;
}

//4:从键盘读入两个数M和N,返回两个数的最大公约数
template <typename T>
int keyboard<T>::GetGCD(int M, int N){
	if (N == 0)
		return M;
	int r = M % N;
	return GetGCD(N, r);//欧几里得算法digui
}

//5:从键盘读入两个超大数M和N,返回两个数之和(整数)
//思路：先转成字符串数组，再按位相加
template <typename T>
string keyboard<T>::BigIntNumAdd(string& str1, string& str2)
{
	int a[1000] = { 0 };//定义数长不超过1000位
	int b[1000] = { 0 };
	//逆序存入
	for (int i = str1.length() - 1, j = 0; i >= 0; i--)
		a[j++] = str1[i] - '0';
	for (int i = str2.length() - 1, j = 0; i >= 0; i--)
		b[j++] = str2[i] - '0';
	//相加和进位
	for (int i = 0; i < 1000; i++)
	{
		b[i] += a[i];
		//进位操作
		if (b[i] >= 10)
		{
			b[i + 1] += b[i] / 10;
			b[i] %= 10;
		}
	}
	//字符串清空
	str1.clear();
	//输出结果
	int i;
	//串流，用于拼接字符
	ostringstream ss;
	//过滤掉前置0
	for (i = 1000 - 1; i >= 0 && b[i] == 0; i--);
	if (i >= 0)
		for (; i >= 0; i--)
		{
			//字符串尾部添加字符
			ss << b[i];
		}
	//如果保存结果的数组中全部为0，上面的操作会过滤掉所有的0，不会有输出，所以这里输出一个0
	else
		cout << 0;
	str1 = ss.str();

	return str1;
}

//5:从键盘读入两个超大数M和N,返回两个数之和(整数)
template <typename T>
void keyboard<T>::BigIntNumAdd2(string& ans, string& b) {
	if (ans.length()<b.length()) ans.swap(b);
	for (int i = ans.length() - 1, j = b.length() - 1; i >= 0; i--, j--) {
		ans[i] = ans[i] + (j >= 0 ? b[j] - '0' : 0);
		if (ans[i]>'9') {
			ans[i] -= 10;
			if (i>0) ans[i - 1]++;
			else ans.insert(0, "1");
		}
	}
	//return ans;
}

//5:从键盘读入两个超大数M和N,返回两个数之和(浮点数)
string big_plus(string a, string b, int& op, bool point_flag)
{
	string reusult = "";
	if (a.length()<b.length())
	{
		std::swap(a, b);
	}
	if (point_flag)
	{
		//小数部分的加法在后面补零
		for (int i = a.length() - b.length(); i>0; i--)
		{
			b = b + "0";
		}
	}
	else
	{
		//整数部分的加法，在前面补零
		for (int i = a.length() - b.length(); i>0; i--)
		{
			b = "0" + b;
		}
	}
	int i, j, t;
	for (i = a.length() - 1; i >= 0; i--)
	{
		t = a[i] - '0' + b[i] - '0' + op;
		reusult += '0' + t % 10;
		op = t / 10;
	}

	reverse(reusult.begin(), reusult.end());
	return reusult;
}

template <typename T>
string keyboard<T>::BigFloatNumAdd(string a, string b)
{
	string a_point_part;
	string b_point_part;
	string result_point_part;
	string result_int_part;

	string a_int_part;
	string b_int_part;

	int a_p = find(a.begin(), a.end(), '.') - a.begin();
	int b_p = find(b.begin(), b.end(), '.') - b.begin();

	a_int_part = a.substr(0, a_p);
	a_point_part = a.substr(a_p + 1, a.length());

	b_int_part = b.substr(0, b_p);
	b_point_part = b.substr(b_p + 1, b.length());

	int op = 0;

	//小数部分相加
	result_point_part = big_plus(a_point_part, b_point_part, op, true);
	//整数部分的加法
	result_int_part = big_plus(a_int_part, b_int_part, op, false);


	return result_int_part + "." + result_point_part;
}

//6:从键盘读入两个超大数M和N,返回两个数之差
template <typename T>
string keyboard<T>::subtract(string ans, string b) {
	int flag = 0;
	if (ans.length()<b.length() || ans.length() == b.length() && ans<b) {
		flag = 1;
		ans.swap(b);
	}
	for (int i = ans.length() - 1, j = b.length() - 1; i >= 0; i--, j--) {
		ans[i] = ans[i] - (j >= 0 ? b[j] - '0' : 0);
		if (ans[i]<'0') {
			ans[i] += 10;
			--ans[i - 1];
		}
	}
	while (ans.length() && ans[0] == '0') ans.erase(ans.begin());
	if (flag) ans.insert(0, "-");
	if (ans.empty()) return "0";
	return ans;
}

//7:从键盘读入两个超大数M和N,返回两个数之积
//思路：先转成字符串数组，再按位相加
template <typename T>
string keyboard<T>::BigNumMultiply(string& s1, string& s2) {
	//使用deque是因为出现进位时可以在队列前插入数据，效率比vector高，大小设为最小
	deque<int> vec(s1.size() + s2.size() - 1, 0);
	for (int i = 0; i<s1.size(); ++i) {
		for (int j = 0; j<s2.size(); ++j) {
			vec[i + j] += (s1[i] - '0')*(s2[j] - '0');//记录相乘结果
		}
	}
	//进位处理
	int addflag = 0;
	//倒序遍历，是因为最左边的值为最高位，最右边的值在最低位，进位运算要从低位开始
	for (int i = vec.size() - 1; i >= 0; --i) {
		int temp = vec[i] + addflag;//当前值加上进位值
		vec[i] = temp % 10;//当前值
		addflag = temp / 10;//进位值
	}
	//如果有进位，将进位加到队列头部
	while (addflag != 0) {
		int t = addflag % 10;
		vec.push_front(t);
		addflag /= 10;
	}
	//串流，用于拼接字符
	ostringstream ss;
	for (auto c : vec) {
		ss << c;
	}
	s1 = ss.str();

	return s1;
}

//8:从键盘读入N阶矩阵，vector<vector<T> >形式
template <typename T>
void keyboard<T>::CinVectorMatN(vector<vector<T> > &vec, int n) {
	if (n == 0) return ;
	vector<T> row(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> row[j];
		}
		vec.push_back(row);
	}
}

//9:从键盘读入N阶矩阵,int**形式
template <typename T>
void keyboard<T>::CinArrayMatN(int** &arr, int n) {
	if (n == 0) return;
	arr = new int*[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

//10:从键盘读入字符串，按指定字符分割成子串数组
template <typename T>
vector<string> keyboard<T>::split(string str, string pattern) {
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

//11:从键盘读入字符串，提取无符号整型数组(不判断符号、小数点)
template <typename T>
void keyboard<T>::extractuintarray(string _str, vector<int> &_num)
{
	int sum = 0;
	bool flag = false;//判断是否有新数
	unsigned int i = 0;

	while (i < _str.length())
	{
		if ('0' <= _str.at(i) && _str.at(i) <= '9') {
			//还原连续的数字
			sum = sum * 10 + (_str.at(i) - '0');
			flag = true;
		}
		else
		{
			if (flag) {
				_num.push_back(sum);
				flag = false;
			}
			sum = 0;
		}
		i++;
	}

	//判断最后一个字符是否是数字
	if (0 != sum)
		_num.push_back(sum);
}

//12:从键盘读入字符串，提取整型数组(不判断小数点)
template <typename T>
void keyboard<T>::extractintarray(string str, vector<int> &_num)
{
	int len = str.length();
	if (len == 0) return;
	//int res = 0;
	int num = 0;
	int cur = 0;
	bool posi = true;
	bool flag = false;//判断是否有新数
	for (int i = 0; i < len; i++) {
		cur = str[i] - '0';
		if (cur < 0 || cur > 9) {
			//res += num;
			if (flag) {
				_num.push_back(num);
				flag = false;
			}
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
			flag = true;
		}
	}
	_num.push_back(num);
	//res += num;
	//return res;
}

#endif
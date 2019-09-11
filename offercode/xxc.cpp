#include<bits/stdc++.h>

using namespace std;

void maxPrefenceVal(vector<int>&movieSize, vector<int>&moviePrefenceVal, int i, int curPrefenceVal, int curWight, int& PrefenceVal)
{
	if (i >= movieSize.size() || curWight == 0)
	{
		PrefenceVal = PrefenceVal > curPrefenceVal ? PrefenceVal : curPrefenceVal;
		return;
	}
	maxPrefenceVal(movieSize, moviePrefenceVal, i + 1, curPrefenceVal, curWight, PrefenceVal);
	if (curWight - movieSize[i] >= 0)
	{
		curPrefenceVal = curPrefenceVal + moviePrefenceVal[i];
		curWight = curWight - movieSize[i];
		maxPrefenceVal(movieSize, moviePrefenceVal, i + 1, curPrefenceVal, curWight, PrefenceVal);
	}
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

void findMinStr(string&str, int *cCount, vector<char>&mChar, int index, int curB, int curE, int &minB, int &minE)
{
	if (index >= mChar.size())
	{
		if (minB == -1)
		{
			minB = curB;
			minE = curE;
		}
		if ((minE - minB) > (curE - curB))
		{
			minE = curE;
			minB = curB;
		}
		return;
	}
	char p = mChar[index];
	int count = cCount[p];
	int b = 0;
	int c = str.size() - 1;
	vector<int>mIndex;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == p)
			mIndex.push_back(i);
	}

	if (mIndex.size() < count)
	{
		return;
	}
	for (int i = 0; i < mIndex.size() - count + 1; ++i)
	{
		int left = mIndex[i];
		int right = mIndex[i + count - 1];
		curB = curB < left ? curB : left;
		curE = curE > right ? curE : right;
		findMinStr(str, cCount, mChar, index + 1, curB, curE, minB, minE);
	}
}
int main()
{
	string str;
	string m;
	cin >> str;
	cin >> m;
	if (m.size() == 0)
	{
		cout << str << endl;
		return 0;
	}
	int cCount[128];//统计某个字符数目
	vector<char>mChar;//存有那些字符
	for (int i = 0; i < 128; ++i)
	{
		cCount[i] = 0;
	}
	//统计匹配字符数目
	for (int i = 0; i < m.size(); ++i)
	{
		if (cCount[m[i]] == 0)
			mChar.push_back(m[i]);
		cCount[m[i]]++;
	}
	int left = -1;
	int right = -1;
	findMinStr(str, cCount, mChar, 0, str.size(), 0, left, right);
	if (left == -1)
		cout << "" << endl;
	else
	{
		string a = str.substr(left, right);
		cout << a << endl;
	}
	return 0;
}
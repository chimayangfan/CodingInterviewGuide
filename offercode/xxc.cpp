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
string find_longest_num_str(string input)
{
	if (input.size() == 0)
		return "0/";
	input = input + " ";
	int maxLength = 0;
	int maxIndex = 0;
	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] >= '0'&&input[i] <= '9')
		{
			count++;
		}
		else
		{
			if (maxLength < count)
			{
				maxLength = count;
				maxIndex = i - 1;
			}
			count = 0;
		}
	}
	string output = input.substr(maxIndex - maxLength + 1, maxLength);
	return  output;
}
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


void allStr(string &str, int i, set<string>&output, string curStr)
{
	if (i >= str.size())
	{
		output.insert(curStr);
		return;
	}
	char p = str[i];
	++i;
	switch (p)
	{
	case'2':
	{
		allStr(str, i, output, curStr + "a");
		allStr(str, i, output, curStr + "b");
		allStr(str, i, output, curStr + "c");
		break;
	}
	case'3':
	{
		allStr(str, i, output, curStr + "d");
		allStr(str, i, output, curStr + "e");
		allStr(str, i, output, curStr + "f");
		break;
	}
	case'4':
	{
		allStr(str, i, output, curStr + "g");
		allStr(str, i, output, curStr + "h");
		allStr(str, i, output, curStr + "i");
		break;
	}
	case'5':
	{
		allStr(str, i, output, curStr + "j");
		allStr(str, i, output, curStr + "k");
		allStr(str, i, output, curStr + "l");
		break;
	}
	case'6':
	{
		allStr(str, i, output, curStr + "m");
		allStr(str, i, output, curStr + "n");
		allStr(str, i, output, curStr + "o");
		break;
	}
	case'7':
	{
		allStr(str, i, output, curStr + "p");
		allStr(str, i, output, curStr + "q");
		allStr(str, i, output, curStr + "r");
		allStr(str, i, output, curStr + "s");
		break;
	}
	case'8':
	{
		allStr(str, i, output, curStr + "t");
		allStr(str, i, output, curStr + "u");
		allStr(str, i, output, curStr + "v");
		break;
	}
	case'9':
	{
		allStr(str, i, output, curStr + "w");
		allStr(str, i, output, curStr + "x");
		allStr(str, i, output, curStr + "y");
		allStr(str, i, output, curStr + "z");
		break;
	}
	default:
		break;
	}
}
int mainA3()
{
	string str;
	cin >> str;
	set<string>output;
	int index = 0;
	allStr(str, 0, output, "");
	cout << "[";
	for (auto it = output.begin(); it != output.end(); ++it)
	{

		cout << *it;
		auto it2 = it;
		it2++;
		if (it2 != output.end())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	return 0;
}
int main()
{
	int N;
	int M;
	cin >> N >> M;
	set<int>val;
	map<int, int>num;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		if (val.count(temp) == 0)
		{
			val.insert(temp);
			num[temp] = 1;
		}
		else
		{
			num[temp] = num[temp] + 1;
		}
	}
	int k = 8 * M / N;//每个数的bit位
	int numKind = pow(2, k);
	if (numKind == 0)
	{
		cout << N - 1 << endl;
	}
	else if (val.size() <= numKind)
	{
		cout << 0 << endl;
	}
	else
	{
		vector<int>mChange;
		auto it = num.begin();
		while (it != num.end())
		{
			mChange.push_back(it->second);
			it++;
		}
		int sumCount = 0;
		sort(mChange.begin(), mChange.end());
		for (int i = 0; i < numKind; ++i)
		{
			sumCount += mChange[i];
		}
		cout << sumCount << endl;
	}
	return 0;
}
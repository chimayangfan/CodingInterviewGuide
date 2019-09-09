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

int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> movieSize = CinIntVector(N);
	vector<int> moviePrefenceVal = CinIntVector(N);

	int res = 0;
	maxPrefenceVal(movieSize, moviePrefenceVal, 0, 0, M, res);

	cout << res << endl;
	return 0;
}

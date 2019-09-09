#include<iostream>
#include<vector>
using namespace std;

void maxLove(vector<int>&mSize, vector<int>&mLove, int i, int curLove, int curWight, int& loveValue)
{
	if (i >= mSize.size() || curWight == 0)
	{
		loveValue = loveValue > curLove ? loveValue : curLove;
		return;
	}
	maxLove(mSize, mLove, i + 1, curLove, curWight, loveValue);
	if (curWight - mSize[i] >= 0)
	{
		curLove = curLove + mLove[i];
		curWight = curWight - mSize[i];
		maxLove(mSize, mLove, i + 1, curLove, curWight, loveValue);
	}
}
int main1()
{
	int M, N;
	cin >> M;
	cin >> N;
	vector<int>veSize(N);
	vector<int>veLove(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> veSize[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> veLove[i];
	}
	int output = 0;
	maxLove(veSize, veLove, 0, 0, M, output);
	cout << output << endl;
	return 0;
}

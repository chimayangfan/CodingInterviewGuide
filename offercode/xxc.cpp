#include<iostream>
#include<vector>
#include<stack>
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

int main2() 
{
	int N;
	cin >> N;
	vector<int>mTree;
}
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
TreeNode* createBT(vector<int>& a, size_t size, const int& invalid, size_t& index)
{
	TreeNode*  cur = NULL;
	if (index < size && a[index] != invalid)//不能越界
	{
		if (a[index] == '#')return NULL;

		cur = new TreeNode(a[index]);//新建一个根结点

		size_t lnode = 2 * index + 1;
		size_t rnode = 2 * index + 2;

		if (lnode > size - 1) cur->left = NULL;
		else cur->left = createBT(a, size, invalid, lnode);

		if (rnode > size - 1) cur->right = NULL;
		else cur->right = createBT(a, size, invalid, rnode);
	}
	return cur;
}

void midOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	midOrder(root->left);
	cout << root->val << endl;
	midOrder(root->right);
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

int main11() {
	
	int n;
	cin >> n;
	int	m = pow(2, n) - 1;
	vector<int>nums;
	nums.push_back(-1);
	int num;
	for (int i = 0; i < m; ++i) {
		cin >> num;
		nums.push_back(num);
	}
	size_t index = 1;
	stack<int>mMid;
	while (mMid.size() > 0 || index < mMid.size())
	{
		while (index < mMid.size())
		{
			cout << nums[index] << endl;
			index = 2 * index;
		}
		if (mMid.size() > 0)
		{
			index = mMid.top();
			mMid.pop();

			index = 2 * index + 1;
		}

	}
	return 0;
}


int main()
{
	int n;
	cin >> n;
	vector<int>m(n);
	for (int i = 0; i < n; ++i)
	{

		cin >> m[i];
	}
	sort(m.begin(), m.end());
	if (n % 2 == 0)
	{
		cout << m[n / 2 - 1] << endl;
	}
	else
	{
		cout << m[n / 2] << endl;
	}
	return 0;
}
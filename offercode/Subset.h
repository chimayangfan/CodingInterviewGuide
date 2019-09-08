#pragma once
#ifndef __SUBSET_HPP__
#define __SUBSET_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.8
*   @remark:    子集问题与全排列问题
*   @note:      Part1 子集问题
*				Part2 背包问题
*				Part3 滑动窗口问题
****************************************************************************/
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>

//#include<bits/stdc++.h>//所有stl头文件集合

using namespace std;

//*************************************************************************//
//							Part1 子集问题
//*************************************************************************//
class Subsets {
public:
	Subsets() {};//构造
	~Subsets() {};//析构
	set<vector<int>> Allsubsets(vector<int> ParentSet);			//题目1：输出所有可能的子集合（含空集），子集合不重复
	set<vector<int>> Allsubsets1(vector<int> ParentSet);		//题目1：输出所有可能的子集合（含空集），子集合不重复|递归方式
	set<vector<int>> SubsetSum(vector<int> ParentSet, int k);	//题目2：输出和为sum的所有可能的子集合，子集合不重复
	set<vector<int>> SubsetSum1(vector<int> ParentSet, int k);	//题目2：输出和为sum的所有可能的子集合，子集合不重复
	bool PartitionTwoSubsets(vector<int> nums);					//题目3：Leetcode 416.分割等和子集(【动态规划】-分割等和子集)
	bool PartitionKSubsets(vector<int> nums, int k);			//题目4：Leetcode 698.分割等和子集(【动态规划】-划分为k个相等的子集)
	set<vector<int>> PermuteRecrusive(vector<int> ints);		//题目5：不重复数字序列的全排列集合
	set<vector<int>> permuteUnique(vector<int> nums);			//题目6：带重复数字序列的全排列集合（集合元素有序）
	set<vector<int>> permutation(vector<int> nums);				//题目6：带重复数字序列的全排列集合（集合元素有序）|使用stl算法库
};
//////////////////////////////////////////////////////////

//*************************************************************************//
//							Part2 背包问题
//*************************************************************************//
class Backpack {
public:
	Backpack() {};//构造
	~Backpack() {};//析构
	friend class item;//声明友元类，用于访问item中的私有成员
	vector<int> ZeroOneBackpack(vector<pair<int, int>> items, int limit);				//题目1：01背包问题|动态规划(二维数组)
	int ZeroOneBackpack1(vector<pair<int, int>> items, int limit);						//题目1：01背包问题|动态规划(一维数组)
	vector<int> FullBackpack(vector<pair<int, int>> items, int limit);					//题目2：完全背包问题|动态规划(一维数组)
	vector<int> MultiplePack(vector<item> items, int limit);							//题目3：多重背包问题|动态规划(二维数组)
	vector<int> MultiplePack1(const vector<int>& P, const vector<int>& V, const vector<int>& M, int limit);//题目3：多重背包问题|动态规划(二维数组)|简化输入参数列表
};
//////////////////////////////////////////////////////////

//*************************************************************************//
//							Part3 滑动窗口问题
//*************************************************************************//
class SlideWindow {
public:
	SlideWindow() {};//构造
	~SlideWindow() {};//析构
	string minWindow(string s, string t);			//题目1：最小窗口子字符串 | 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串
	vector<int> lengthOfLIS(vector<int>& nums);		//题目2：最长上升子序列 | 给定一个无序的整数数组，找到其中最长上升子序列的长度。
};
//////////////////////////////////////////////////////////

//class Subsets成员函数定义
#ifndef SubsetsClass 
#define SubsetsClass
//题目1：输出所有可能的子集合（含空集），子集合不重复
//举例：输入{ 1,2,3], 输出{},{ 1 },{ 2 },{ 3 },{ 1,2 },{ 1,3 },{ 2,3 },{ 1,2,3 }
set<vector<int>> Subsets::Allsubsets(vector<int> ParentSet)
{
	set<vector<int>> resSet;
	//sort(ParentSet.begin(),ParentSet.end());//排序是为了方便有重复输入时判断重复;
	//初始化，加入空集
	resSet.insert(vector<int>());
	for (int i = 0; i < ParentSet.size(); ++i)
	{
		set<vector<int>> tmp;
		for(auto list : resSet)
		{
			//保留原结果
			tmp.insert(list);
			vector<int> clone(list);
			//在原有结果里加入新元素
			clone.push_back(ParentSet[i]);
			tmp.insert(clone);
		}
		resSet = tmp;
	}
	return resSet;
}

//递归方式
//题目1：输出所有可能的子集合（含空集），子集合不重复
//举例：输入{ 1,2,3], 输出{},{ 1 },{ 2 },{ 3 },{ 1,2 },{ 1,3 },{ 2,3 },{ 1,2,3 }
void Helper(vector<int> ParentSet, int start, vector<int> subset, set<vector<int>> &resSet)
{
	//保留中间结果，不能直接添加resSet,因为这是传址，它每次都变化;
	vector<int> clone(subset);
	resSet.insert(clone);
	for (int i = start; i < ParentSet.size(); ++i)
	{
		subset.push_back(ParentSet[i]);//加入新元素，并递归调用下一个元素;
		Helper(ParentSet, i + 1, subset, resSet);
		subset.pop_back();//退回，移除subset中最后一个索引位元素
	}
}
set<vector<int>> Subsets::Allsubsets1(vector<int> ParentSet)
{
	set<vector<int>> resSet;
	if (ParentSet.size() == 0)
	{
		return resSet;
	}
	//sort(ParentSet.begin(),ParentSet.end());//排序是为了方便有重复输入时判断重复;
	vector<int> subset;
	Helper(ParentSet, 0, subset, resSet);
	return resSet;
}

//题目2：输出和为sum的所有可能的子集合，子集合不重复
//子集求和并判断是否为k
bool sum(const std::vector<int> & v, int k)//求和
{
	int total = 0;
	for (std::vector<int>::const_iterator it = v.begin();
		it != v.end(); ++it)
	{
		total += *it;
	}
	return total == k;
}
//思路是这样的： 先求子集然后 求和。
//求和：
//假设这个集合有 3个数 a b c那么它就对应一个 3位的2进制数
//我们可以把它这些子集分别对应一个二进制数
//子集             空集{ c }，{ b }，{ c，b }，{ a }，{ a，c }，{ a，b }，{ a，b，c }
//对应的2进制数    000， 001， 010，    011，   100，   101，      110，     111
set<vector<int>> Subsets::SubsetSum(vector<int> ParentSet, int k) {
	set<vector<int>> resSet;
	for (int i = 0; i<(1 << ParentSet.size()); ++i)
	{
		//100必须大于ParentSet.size()，否则增加数值
		std::bitset<100> b(i);//从一整型转成 2进制数(2进制长度为100)
		std::vector<int> subvec;//存放 子集
		for (int index = 0; index != ParentSet.size(); index++)//把位为1的元素加入子集中
		{
			if (b[index] == 1)
				subvec.push_back(ParentSet[index]);
		}
		if (!subvec.empty() && sum(subvec, k))//如果子集的和等于k就打印
			resSet.insert(subvec);
	}

	return  resSet;
}

//题目2：输出和为sum的所有可能的子集合，子集合不重复
//子集求和并判断是否为k
int next(vector<int> &array, int n)
{
	--n;
	while (n >= 0 && array[n])
		array[n--] = 0;
	if (n<0)
		return 0;
	return array[n] = 1;
}
//思路和使用bitset方法一样，先枚举子集，再求和
set<vector<int>> Subsets::SubsetSum1(vector<int> ParentSet, int k) {
	set<vector<int>> resSet;
	int len = ParentSet.size();
	vector<int> arr(len, 0);
	while (next(arr, len))
	{
		int sum = 0;
		for (int j = 0; j < len; ++j)
			if (arr[j]) sum += ParentSet[j];
		if (sum == k)
		{
			vector<int> subvec;
			for (int k = 0; k < len; ++k)
				if (arr[k]) {
					cout << ParentSet[k] << " ";
					subvec.push_back(ParentSet[k]);
				}
			cout << endl;
			resSet.insert(subvec);
		}
	}
	return resSet;
}

//【动态规划】
//求出路径矩阵，再回溯路径
//题目3：Leetcode 416.分割等和子集(【动态规划】-分割等和子集,2等分)
bool Subsets::PartitionTwoSubsets(vector<int> nums) {
	int n = nums.size();
	int sum = 0;
	for (int i = 0; i<n; ++i) {
		sum += nums[i];
	}
	int t = sum / 2;
	//判断是否可以2等分
	if (sum % 2 != 0)
		return false;
	vector<vector<int>> dp(n + 1, vector<int>(t + 1));
	for (int i = 1; i <= t; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= t; ++j) {
			//printf("i = %d, j = %d\n", i,j);
			//assert(i >= 1 || i <= n || j >= 1 || j <= t);
			if (j >= nums[i - 1])
				dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - nums[i - 1]] + nums[i - 1]));
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	//路径矩阵
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = 1; j <= t; ++j) {
	//		printf("%2d ", dp[i][j]);
	//	}
	//	cout << endl;
	//}
	//记录路径
	vector<bool> used(n, false);
	for (int i = n; i >= 1; i--)
	{
		if (dp[i][t] == dp[i - 1][t])
			used[i - 1] = false;
		else
		{
			used[i - 1] = true;
			t -= nums[i - 1];
		}
	}

	t = sum >> 1;
	return (dp[n][t] == t) ? true : false;
}

//【动态规划】
//求出路径矩阵，再回溯路径
//题目4：Leetcode 698.分割等和子集(【动态规划】-分割等和子集,K等分)
bool dfs(vector<int> nums, int k, int target, int sum, int index, vector<bool> &used) {
	if (k == 1)//只剩下一个待分集合，就可以直接返回true了
		return true;
	if (target<0)
		return false;
	if (target == sum)
		return dfs(nums, k - 1, target, 0, 0, used);
	for (int i = index; i<nums.size(); i++) {
		if (used[i])//当前元素已访问
			continue;
		used[i] = true;//访问当前元素
		if (dfs(nums, k, target, sum + nums[i], i + 1, used))
			return true;
		used[i] = false;
	}
	return false;
}

bool Subsets::PartitionKSubsets(vector<int> nums, int k) {
	int n = nums.size();
	int sum = 0;
	for (int i = 0; i<n; ++i)
		sum += nums[i];
	vector<bool> used(n, false);
	if (sum % k != 0)
		return false;
	return dfs(nums, k, sum / k, 0, 0, used);
}

//题目5：不重复数字序列的全排列集合
void PermuteHelper(vector<int> ints, vector<int> &subset, set<vector<int>> &resSet)
{
	if (subset.size() == ints.size())
	{
		resSet.insert(subset);
		return; //为什么需要这个？因为add后需要回到上一层递归;
	}
	for (int i = 0; i < ints.size(); i++)
	{
		if (find(subset.begin(), subset.end(), ints[i]) != subset.end()) continue; //不能重复使用已有元素,为什么？
		subset.push_back(ints[i]);//加入新元素，递归调用下一个元素
		PermuteHelper(ints, subset, resSet);
		subset.pop_back();//回退
	}
}
set<vector<int>> Subsets::PermuteRecrusive(vector<int> ints)
{
	set<vector<int>> resSet;
	if (ints.size() == 0)
	{
		return resSet;
	}
	sort(ints.begin(), ints.end());

	vector<int> subset;
	PermuteHelper(ints, subset, resSet);
	return resSet;
}

//题目6：带重复数字序列的全排列集合（集合元素有序）
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
set<vector<int>> Subsets::permuteUnique(vector<int> nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	set<vector<int>> resSet;
	vector<bool> used(n, false);
	vector<int> subset;
	backTracking(nums, subset, resSet, used);
	return resSet;
}

//题目6：带重复数字序列的全排列集合（集合元素有序）|使用stl算法库
set<vector<int>> Subsets::permutation(vector<int> nums) {
	set<vector<int>> resSet;
	sort(nums.begin(), nums.end());
	do {
		vector<int> temp(nums.size());
		for (int i = 0; i<nums.size(); i++)
			temp[i] = nums[i];
		resSet.insert(temp);
	} while (next_permutation(nums.begin(), nums.end()));
	return resSet;
}


#endif

//class Backpack成员函数定义
#ifndef BackpackClass 
#define BackpackClass

/// \题目1：01背包问题(二维 动态规划解法)
/// \param1: vector<pair<int,int>> items 总物品(pair.first = 物品价值，pair.second = 物品重量)
/// \param2: limit 最大承重
/// \return vector<int>最大价值物品选取路径
vector<int> Backpack::ZeroOneBackpack(vector<pair<int,int>> items, int limit) {
	int n = items.size();//物品数
	vector<int> resvec;
	vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));
	for (int i = 1; i <= n; ++i)//第i个物品
		for (int j = limit; j >= 0; --j)//剩余空间j
		{
			//cout << "i:" << i << " j:" << j << endl;
			//assert(i >= 0 || i <= 7 || j >= 0 || j <= 13);
			if (j >= items[i-1].second)//如果装得下
				dp[i][j] = max(dp[i - 1][j - items[i-1].second] + items[i-1].first, dp[i - 1][j]);
			else//如果装不下
				dp[i][j] = dp[i - 1][j];
		}

	////路径矩阵
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = 1; j <= limit; ++j) {
	//		printf("%2d ", dp[i][j]);
	//	}
	//	cout << endl;
	//}
	//回溯法记录路径
	vector<bool> used(n, false);
	for (int i = n; i >= 1; --i)
	{
		if (dp[i][limit] == dp[i - 1][limit])
			used[i - 1] = false;
		else
		{
			used[i - 1] = true;
			//cout << items[i - 1].first << " ";
			resvec.push_back(items[i - 1].first);
			limit -= items[i - 1].second;
		}
	}
	//cout << endl;
	return resvec;
}

/// \题目1：01背包问题(二维 动态规划解法)
/// \param1: vector<pair<int,int>> items 总物品(pair.first = 物品价值，pair.second = 物品重量)
/// \param2: limit 最大承重
/// \return vector<int>最大价值物品选取路径
int Backpack::ZeroOneBackpack1(vector<pair<int, int>> items, int limit) {
	int n = items.size();//物品数
	//vector<int> resvec;
	vector<int> dp(limit + 1, 0);
	for (int i = 1; i <= n; ++i)//第i个物品
		for (int j = limit; j >= 1; --j)//剩余空间j
		{
			//cout << "i:" << i << " j:" << j << endl;
			//assert(i >= 0 || i <= 7 || j >= 0 || j <= 13);
			if (j - items[i - 1].second >= 0 && dp[j] <= dp[j - items[i - 1].second] + items[i - 1].first)//二维数组变一维数组
				dp[j] = dp[j - items[i - 1].second] + items[i - 1].first;//如果值得改变并且j的空间还装得下就赋新值
		}

	////路径矩阵
	for (int i = 1; i <= limit; ++i) {
		printf("%2d ", dp[i]);
	}

	//cout << endl;
	return dp[limit];
}

/// \题目2：完全背包问题|动态规划(一维数组)
/// \param1: vector<pair<int,int>> items 总物品(pair.first = 物品价值，pair.second = 物品重量)
/// \param2: limit 最大承重
/// \return vector<int>最大价值物品选取路径
vector<int> Backpack::FullBackpack(vector<pair<int, int>> items, int limit) {
	int n = items.size();//物品数
	vector<int> resvec;
	vector<int> dp(limit + 1, 0);//记录最优值
	vector<vector<bool>> path(n + 1, vector<bool>(limit + 1,false));  // 记录路径
	for (int i = 0; i < 5; i++)
		for (int j = items[i].second; j <= limit; j++) {
			if (j - items[i].second >= 0 && dp[j] < dp[j - items[i].second] + items[i].first) {
				path[i][j] = true;
				dp[j] = dp[j - items[i].second] + items[i].first;
			}
		}
	//输出路径
	while (n >= 1 && limit >= 0) {
		if (path[n-1][limit] == true) {
			cout << items[n-1].second << " ";
			resvec.push_back(items[n - 1].second);
			limit -= items[n - 1].second;
		}
		else {
			n--;
			//cout<<0<<"\t";
		}
	}

	return resvec;
}

/// \题目3：多重背包问题|动态规划(二维数组)
/// \param1: vector<item> items
/// \param2: limit 最大承重
/// \return vector<int>最大价值物品选取路径
class item {
public:
	item(int va, int vo, int nu) :value(va), volume(vo), num(nu) {};
	int getvalue() {
		return this->value;
	}
	int getvolume() {
		return this->volume;
	}
	int getnum() {
		return this->num;
	}
private:
	int value;//价值
	int volume;//体积
	int num;//数量
};
vector<int> Backpack::MultiplePack(vector<item> items, int limit) {
	int n = items.size();//物品数
	vector<int> resvec;
	vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));  // 记录最优值
	vector<vector<bool>> path(n + 1, vector<bool>(limit + 1, false));  // 记录价值路径
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= limit; ++j) {
			for (int k = 0; k <= items[i].getnum() && k * items[i].getvolume() <= j; ++k) {
				if (dp[i + 1][j] < dp[i][j - k * items[i].getvolume()] + k * items[i].getvalue()) {
					dp[i + 1][j] = dp[i][j - k * items[i].getvolume()] + k * items[i].getvalue();
					path[i + 1][j] = true;
				}
			}
		}
	}
	////路径矩阵
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = 1; j <= limit; ++j) {
	//		printf("%2d ", dp[i][j]);
	//	}
	//	cout << endl;
	//}
	//cout << dp[n][limit] << endl;
	//回溯法记录路径
	//输出路径
	vector<int> count(n);
	for (int i = 0; i < n; ++i) {
		count[i] = items[i].getnum();
	}
	while (n > 0 && limit > 0)
	{
		if (path[n][limit] == true && count[n-1] > 0)
		{
			cout << items[n - 1].getvolume() << ' ';
			resvec.push_back(items[n - 1].getvalue());
			limit -= items[n-1].getvolume();
			count[n - 1]--;
		}
		else
			n--;
	}

	return resvec;
}

/// \完全背包问题(二维 动态规划解法)|简化输入参数列表
/// \param1: vector<int> P 价值
/// \param2: vector<int> W 重量
/// \param3: vector<int> M 数量
/// \param4: limit 最大承重
/// \return vector<int>最大价值物品选取路径
vector<int> Backpack::MultiplePack1(const vector<int>& P, const vector<int>& V, const vector<int>& M, int limit) {
	int n = P.size();//物品数
	vector<int> resvec;
	vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));  // 记录最优值
	vector<vector<bool>> path(n + 1, vector<bool>(limit + 1, false));  // 记录价值路径
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= limit; ++j) {
			for (int k = 0; k <= M[i] && k * V[i] <= j; ++k) {
				if (dp[i + 1][j] < dp[i][j - k * V[i]] + k * P[i]) {
					dp[i + 1][j] = dp[i][j - k * V[i]] + k * P[i];
					path[i + 1][j] = true;
				}
			}
		}
	}
	//路径矩阵
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= limit; ++j) {
			printf("%2d ", dp[i][j]);
		}
		cout << endl;
	}
	cout << dp[n][limit] << endl;

	//输出路径
	vector<int> count(n);
	for (int i = 0; i < n; ++i) {
		count[i] = M[i];
	}
	while (n > 0 && limit > 0)
	{
		if (path[n][limit] == true && count[n - 1] > 0)
		{
			cout << V[n - 1] << ' ';
			resvec.push_back(P[n - 1]);
			limit -= V[n - 1];
			count[n - 1]--;
		}
		else
			n--;
	}

	return resvec;
}
#endif

//class SlideWindow成员函数定义
#ifndef SlideWindowClass 
#define SubsetsClassClass

/// \题目1：最小窗口子字符串
/// \描述：给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串
/// \解题思路：首尾双指针，尾指针右移扩张找到包含目标字符的子串，首指针右移收缩使字串最小。
/// \param1: string s 原字符串
/// \param2: string t 搜索字符串
/// \return string s中包含t所有字符的最小子字符串
string SlideWindow::minWindow(string s, string t) {
	if (s.length()<t.length() || s.length() == 0 || t.length() == 0)
		return "";

	//模拟哈希表，存储目标字符串的各个字符的个数
	vector<int> map(255);
	for (int i = 0; i<t.length(); i++) {
		map[t[i]]++;
	}

	//双指针遍历源字符串s
	int begin = 0, end = 0;
	//最小字符串的起点
	int minBegin = 0;
	//最小字符串的长度
	int res = INT_MAX;
	//用来记录匹配到字符的个数，如果count == t.length()意味着找到一个匹配的字串
	int count = 0;

	//遍历
	while (end < s.length()) {
		//这里可理解为缺失字符的个数，==0时则表示 这个字符匹配够了，==1则表示仍需要再匹配一个该字符
		if (map[s[end]]>0)
			count++;
		//不需要匹配的字符，其值此时小于0
		map[s[end]]--;
		//尾指针右移
		end++;
		//匹配到一个字串
		while (count == t.length()) {
			//比较字串长度，更新字串信息
			if (end - begin < res) {
				res = end - begin;
				minBegin = begin;
			}
			//如果首指针对应字符是目标字符之一，则跳出循环
			if (map[s[begin]] == 0)
				count--;
			//首指针对应字符的哈希值还原
			map[s[begin]]++;
			//首指针右移
			begin++;
		}
	}

	return res == INT_MAX ? "" : s.substr(minBegin, minBegin + res);
}

/// \题目2：最长上升子序列
/// \描述：给定一个无序的整数数组，找到其中最长上升子序列。
/// \解题思路：首尾双指针，尾指针右移扩张找到包含目标字符的子串，首指针右移收缩使字串最小。
/// \param1: vector<int>& nums 原序列 | 例：[10,9,2,5,3,7,101,18]
/// \return vector<int> 最长上升子序列 | 输出：[2,3,7,101]
vector<int> SlideWindow::lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	vector<int> dp(len, 1);
	int maxlen = 1,index = 0;
	for (int i = 0; i<len; ++i) {
		int temp = maxlen;
		for (int j = 0; j<i; ++j) {
			if (nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	//return maxlen;
	for (int i = 0; i < len; ++i) {
		index = maxlen == dp[i] ? index : i;//子序列末尾元素索引
		maxlen = maxlen > dp[i] ? maxlen : dp[i];//最长子序列长度
	}
	vector<int> LIS(maxlen);
	LIS[--maxlen] = nums[index];
	for (int i = index; i >= 0; --i) {
		if (nums[i] < nums[index] && dp[i] == dp[index] - 1) {
			LIS[--maxlen] = nums[i];
			index = i;
		}
	}
	return LIS;
}

#endif

#endif
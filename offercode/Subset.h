#pragma once
#ifndef __SUBSET_HPP__
#define __SUBSET_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.8
*   @remark:    子集问题与全排列问题
*   @note:      包含：子集和问题、背包问题
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
#endif

#endif
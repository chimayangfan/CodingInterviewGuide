#pragma once
#ifndef __MATCH_HPP__
#define __MATCH_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.8
*   @remark:    常见匹配算法集合
*   @note:      Part1 字符串匹配算法
*				Part2 
*				Part3
****************************************************************************/
#include<list>
#include<map>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

//*************************************************************************//
//							Part1 字符串匹配算法
//*************************************************************************//
class Stringmatch {
public:
	Stringmatch() {};//构造
	~Stringmatch() {};//析构
	int KMP(const string& src, const string& match);		//题目1：KMP算法(字符串快速模式匹配算法)
};
//////////////////////////////////////////////////////////

//class Stringmatch成员函数定义
#ifndef StringmatchClass 
#define StringmatchClass

//题目1：KMP算法(字符串快速模式匹配算法)

//求next数组
vector<int> getNextvec(const string& match){
	if (match.length() == 1) {
		return vector<int>();
	}
	vector<int> next(match.length());
	next[0] = -1, next[1] = 0;
	int pos = 2, cn = 0;
	while (pos < next.size()) {
		if (match[pos - 1] == match[cn]) {
			next[pos++] = ++cn;
		}
		else if(cn > 0){
			cn = next[cn];
		}
		else {
			next[pos++] = 0;
		}
	}
	return next;
}
int Stringmatch::KMP(const string& src, const string& match) {
	if (src.length() == 0 || match.length() == 0) {
		return -1;
	}
	int si = 0, mi = 0;
	vector<int> next = getNextvec(match);
	while (si < src.length() && mi < match.length()) {
		if (src[si] == match[mi]) {
			si++;
			mi++;
		}
		else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}
	}
	return mi == match.length() ? si - mi : -1;
}

#endif

#endif
#pragma once
#ifndef __MAP_HPP__
#define __MAP_HPP__

//greater<T>,less<T>原型
//包含在头文件<functional>中
// TEMPLATE STRUCT greater  
template<class _Ty>
struct greater
	: public binary_function<_Ty, _Ty, bool>
{   // functor for operator>  
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{   // apply operator> to operands  
		return (_Left > _Right);
	}
};

// TEMPLATE STRUCT less  
template<class _Ty>
struct less
	: public binary_function<_Ty, _Ty, bool>
{   // functor for operator<  
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{   // apply operator< to operands  
		return (_Left < _Right);
	}
};

/************************  map排序  ************************/

//1、按key排序(使用用map，通过构造参数列表中第三个参数控制升降，不写默认升序)
#include <map> 
#include <functional>  

using namespace std;

template <class T>
std::map<T, int, std::greater<T> > map;//按key降序排列
template <class T>
std::map<T, int, std::less<T> > map;//按key升序排列
template <class T>
std::map<T, int> map;//按key升序排列

//2、按value排序
//方式1:建立一个vector<pair<type, type>>的容器,使用sort()排序。
#include <string>
#include <functional>  
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool less_cmp(pair<string, int> a, pair<string, int> b) {
	return  a.second < b.second;  //升序
};

bool greater_cmp(pair<string, int> a, pair<string, int> b) {
	return  a.second > b.second;  //降序
};

std::map<std::string, int> disordermap;//待排序map
std::vector<std::pair<std::string, int>> tmp(disordermap.begin(), disordermap.end());
std::sort(tmp.begin(), tmp.end(), greater_cmp);

//方式2:首先建立一个临时map，然后通过transform函数将m中的元素inserter进tmp中。通过将map中元素的first和second交换达到，对value排序的目的。
#include <string>
#include <functional>  
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

std::map<string, int> disordermap;//待排序map

std::map<int, string> orderedmap;//按valse升序排列
//std::map<int, string, greater<int>> orderedmap;//按valse降序排列
std::transform(disordermap.begin(), disordermap.end(), std::inserter(orderedmap, orderedmap.begin()), [](std::pair<string, int> a)
{ return std::make_pair(a.second, a.first); });

#endif
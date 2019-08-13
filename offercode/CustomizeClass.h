#pragma once
#pragma once
#ifndef __SUBSET_HPP__
#define __SUBSET_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.8
*   @remark:    面试常见功能实现设计
*   @note:      Part1 LRU缓存数据结构
*				Part2 智能指针的实现
*				Part3 
****************************************************************************/
#include<list>
#include<map>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;


//*************************************************************************//
//							Part1 LRU缓存数据结构
//*************************************************************************//

//使用hash_map和list实现的LRU。 实现了get和put操作
//get 得到对应的value，并且移到队列首。
//put 不存在：队列首加入，此时根据容量可能会挤掉尾元素。存在：移动到队列首。
//改进点在于如果get发生缺页是否需要处理，这时候可以添加一个
//hash_map存储key-value，并在get不到数据时，put一下即可。
class LRUCache {
private:
	//LRU数据结构
	struct Node {
		int key;
		int value;
		Node(int k, int v) :key(k), value(v) {}
	};
public:
	LRUCache(int c) :capacity(c) {}

	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end())
			return -1; //这里产生缺页中断，根据页表将页面调入内存，然后set(key, value)
		//将key移到第一个，并更新cacheMap 
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end())
		{
			//淘汰最后一个，然后将其加到第一个位置
			if (cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(Node(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			//更新节点的值，并将其加到第一个位置
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	int capacity;
	list<Node> cacheList;
	unordered_map<int, list<Node>::iterator> cacheMap;
};


//*************************************************************************//
//							Part2 智能指针的实现
//*************************************************************************//
//智能指针：实际指行为类似于指针的类对象 ，它的一种通用实现方法是采用引用计数的方法。
//1.智能指针将一个计数器与类指向的对象相关联，引用计数跟踪共有多少个类对象共享同一指针。
//2.每次创建类的新对象时，初始化指针并将引用计数置为1；
//3.当对象作为另一对象的副本而创建时，拷贝构造函数拷贝指针并增加与之相应的引用计数；
//4.对一个对象进行赋值时，赋值操作符减少左操作数所指对象的引用计数（如果引用计数为减至0，则删除对象），并增加右操作数所指对象的引用计数；
//  这是因为左侧的指针指向了右侧指针所指向的对象，因此右指针所指向的对象的引用计数 + 1；
//5.调用析构函数时，构造函数减少引用计数（如果引用计数减至0，则删除基础对象）。
//6.实现智能指针有两种经典策略：一是引入辅助类，二是使用句柄类。这里主要讲一下引入辅助类的方法
template<typename SmartPointer, typename Type>
class PtrCount {
	friend SmartPointer;
	PtrCount(Type* _p) :p(_p), use(1) {}
	~PtrCount() { delete p; }
	Type *p;
	size_t use;
};

template<typename Type>
class SmartPtr {
public:
	SmartPtr(Type* p) :ptrCnt(new PtrCount<SmartPtr, Type>(p)) {};
	//复制构造函数
	SmartPtr(const SmartPtr& orig) :ptrCnt(orig.ptrCnt) {
		++ptrCnt->use;
	}
	//重载赋值操作符
	SmartPtr& operator=(const SmartPtr& rhs) {
		++rhs.ptrCnt->use; //首先将右操作数引用计数加1，
		if (--ptrCnt->use == 0) //然后将引用计数减1，可以应对自赋值
			delete ptrCnt;
		ptrCnt = rhs.ptrCnt;
		return *this;
	}
	~SmartPtr() {
		if (--ptrCnt->use == 0)//当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
			delete ptrCnt;
	}
private:
	PtrCount<SmartPtr, Type> *ptrCnt;
};

#endif
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
*				Part3 union-find算法(并查集)
*				Part4 环形队列
*				Part5 模板函数举例（找出两个数据较大值）
*				Part6 KMP算法
*				Part7 继承类模板
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
	typename pair<int, int> a;
	//LRU数据结构
	struct Node {
		int key;
		int value;
		Node(int k, int v) :key(k), value(v) {}
	};
	int capacity;
	list<Node> cacheList;
	unordered_map<int, list<Node>::iterator> cacheMap;
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

//shared_ptr循环引用问题举例
//循环引用本身就说明设计上可能存在一些问题，如果特殊原因不得不使用循环引用，那可以让引用链上的一方持用普通指针（或弱智能指针weak_ptr）即可。
class A
{
public:
	shared_ptr<B> m_b;
};
class B
{
public:
	shared_ptr<A> m_a;
};
int main()
{
	while (true)
	{
		shared_ptr<A> a(new A); //new出来的A的引用计数此时为1
		shared_ptr<B> b(new B); //new出来的B的引用计数此时为1
		a->m_b = b; //B的引用计数增加为2
		b->m_a = a; //A的引用计数增加为2
	}

	//b先出作用域，B的引用计数减少为1，不为0，所以堆上的B空间没有被释放
	//且B持有的A也没有机会被析构，A的引用计数也完全没减少

	//a后出作用域，同理A的引用计数减少为1，不为0，所以堆上A的空间也没有被释放
}

//*************************************************************************//
//							Part3 union-find算法(并查集)
//*************************************************************************//
//解决动态连通性一类问题的一种算法，使用到了一种叫做并查集的数据结构，称为Union-Find

template<typename T>
class Union_find{
public:
	//Union_find(int N);			//以整数标识（0到N-1）初始化N个触点
	//void unionline(int p, int q);	//在p和q之间添加一条连接
	//int find(int p);				//p（0到N-1）所在的分量的标识符
	//bool connected(int p, int q);	//如果p和q存在于同一个分量中则返回true
	//int count();					//联通分量的数量

	Union_find(int N)
	{
		// Initialize component id array.
		nums = N;
		id = new T[N];
		for (int i = 0; i < N; i++)
			id[i] = i;
	}

	void unionline(T p, T q)
	{
		// 获得p和q的组号
		T pID = find(p);
		T qID = find(q);
		// 如果两个组号相等，直接返回
		if (pID == qID) return;
		// 遍历一次，改变组号使他们属于一个组
		for (int i = 0; i < nums; i++)
			if (id[i] == pID) id[i] = qID;
		nums--;
	}
	T find(T p)
	{
		return id[p];
	}
	bool connected(T p, T q)
	{
		return find(p) == find(q);
	}
	int count()
	{
		return nums;
	}
private:
	T* id;	// 触点id
	int nums;	// 联通分量的数量
};

//*************************************************************************//
//							Part4 环形队列
//*************************************************************************//
template <class T>
class cycleQueue
{
private:
	unsigned int m_size;//最大容量m_size-1
	int m_front;//
	int m_rear;
	T*  m_data;
public:
	//构造函数
	cycleQueue(unsigned size)
		:m_size(size),
		m_front(0),
		m_rear(0)
	{
		m_data = new T[size];
	}
	//析构函数
	~cycleQueue()
	{
		delete[] m_data;
	}
	//空队时rear等于front，满队时必须空一个位置
	bool isEmpty()
	{
		return m_front == m_rear;
	}
	//空队时rear等于front，满队时必须空一个位置
	bool isFull()
	{
		return m_front == (m_rear + 1) % m_size;
	}
	//入队
	void push(T ele)throw(bad_exception)
	{
		if (isFull())
		{
			throw bad_exception();
		}
		m_data[m_rear] = ele;
		m_rear = (m_rear + 1) % m_size;
	}
	//出队
	T pop() throw(bad_exception)
	{
		if (isEmpty())
		{
			throw bad_exception();
		}
		T tmp = m_data[m_front];
		m_front = (m_front + 1) % m_size;
		return tmp;
	}
	//全部出队
	void popAll() throw(bad_exception)
	{
		while (!isEmpty())
		{
			pop();
		}
	}
};

//*************************************************************************//
//							Part5 模板函数举例（找出两个数据较大值）
//*************************************************************************//
template <typename T>
inline T const& max(T const& a, T const& b)
{
	// if a < b then use b else use a 
	return a<b ? b : a;
}

//*************************************************************************//
//							Part6 KMP算法
//*************************************************************************//
template <typename T>
inline T const& max(T const& a, T const& b)
{
	// if a < b then use b else use a 
	return a<b ? b : a;
}

//*************************************************************************//
//							Part7 继承类模板
//*************************************************************************//
class ClassA
{
public:
	ClassA() { cout << "ClassA::ClassA()" << endl; }
	virtual ~ClassA() { cout << "ClassA::~ClassA()" << endl; }

	void func1() { cout << "ClassA::func1()" << endl; }
	void func2() { cout << "ClassA::func2()" << endl; }

	virtual void vfunc1() { cout << "ClassA::vfunc1()" << endl; }
	virtual void vfunc2() { cout << "ClassA::vfunc2()" << endl; }
private:
	int aData;
};

class ClassB : public ClassA
{
public:
	ClassB() { cout << "ClassB::ClassB()" << endl; }
	virtual ~ClassB() { cout << "ClassB::~ClassB()" << endl; }

	void func1() { cout << "ClassB::func1()" << endl; }
	virtual void vfunc1() { cout << "ClassB::vfunc1()" << endl; }
private:
	int bData;
};

class ClassC : public ClassB
{
public:
	ClassC() { cout << "ClassC::ClassC()" << endl; }
	virtual ~ClassC() { cout << "ClassC::~ClassC()" << endl; }

	void func2() { cout << "ClassC::func2()" << endl; }
	virtual void vfunc2() { cout << "ClassC::vfunc2()" << endl; }
private:
	int cData;
};

#endif
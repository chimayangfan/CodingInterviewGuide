#pragma once
#ifndef __LINKLIST_HPP__
#define __LINKLIST_HPP__
#include <iostream>

using namespace std;

//结点模板类
template <typename T>
class Node {
private:
	T val;    //数据成员val
	Node<T> *next;  //后继结点指针
public:
	Node(T value)  
	:val(value), next(NULL) {}		//构造函数
	~Node() {}                      //析构函数
	T GetVal();						//获得成员变量val
	Node<T> * GetNext();			//获得后继结点地址
	void SetVal(T value);			//设置成员变量val
	void SetNext(Node<T> * x);		//设置成员变量next

};

//链表模板类
template <typename T>
class LinkList {
private:
	int num;            //链表结点个数,不包括头结点
	Node<T> * head;		//链表头结点指针
public:
	LinkList();  //构造函数
	~LinkList(); //析构函数
	void InsertFront(Node<T> &x);     //头插法
	void InsertAfter(Node<T> &x);     //尾插法
	void Insert(int i, Node<T> &x);   //在第i个结点处，插入一个结点
	void DeleteNode(int i);           //删除第i个结点
	void SetNode(int i, T val);		  //设置第i个结点的值
	void PrintAll();				  //打印整个表
};

/*
Node的成员函数
*/
template <typename T>  
//返回数据域val的值
T Node<T>::GetVal() {
	return val;
}

template <typename T>  
//返回后继结点指针
Node<T> * Node<T>::GetNext() {
	return next;
}

template <typename T>  
//设置数据域val的值
void Node<T>::SetVal(T value) {
	val = value;
}

template <typename T>  
//设置后继结点指针
void Node<T>::SetNext(Node<T> * x) {
	next = x;
}

/////////////////////////////////////////////////////////
/*
LinkList的成员函数
*/
template <typename T>  
//链表构造函数，创建头结点(头结点数值域没有意义，置为0)
LinkList<T>::LinkList() {
	num = 0;
	head = new Node<T>(0);
}

template <typename T>  
//链表析构函数，依次释放各个节点，包括头结点
LinkList<T>::~LinkList() {
	Node<T> *p = head;
	Node<T> *q = head->GetNext();
	while (p) {
		q = p->GetNext();
		if (p != NULL)
			delete p;
		p = q;
	}
}

//头插入
template <typename T>  
//从head指向的结点处插入结点
void LinkList<T>::InsertFront(Node<T> &x) {
	Node<T> *p = head->GetNext();
	head->SetNext(&x);
	x.SetNext(p);
	num++;
}

//尾插入
template <typename T>  
//从链表末尾插入结点
void LinkList<T>::InsertAfter(Node<T> &x) {
	Node<T> *p = head;
	Node<T> *q = NULL;
	while (p) {
		q = p->GetNext();
		if (q == NULL)
			p->SetNext(&x);
		p = q;
	}
	num++;
}

template <typename T>  
//在第i个结点处插入结点
void LinkList<T>::Insert(int i, Node<T> &x) {
	if (i == 1)
		InsertFront(x);
	else if (i>1 && i <= num) {
		num++;
		int j = 0;
		Node<T> * p = head;
		Node<T> * q = NULL;
		while (p) {
			j++;
			p = p->GetNext();
			q = p->GetNext();
			if (j == i - 1) {
				p->SetNext(&x);
				x.SetNext(q);
				break;
			}
		}
	}
	else {
		cout << "Error inserting location !" << endl;
		exit(1);
	}
}

template <typename T>   
//删除第i个结点
void LinkList<T>::DeleteNode(int i) {
	if (i >= 1 && i <= num) {
		int j = 0;
		Node<T> * p = head;
		Node<T> * q = NULL;
		while (p) {
			if (j == i - 1) {
				q = p->GetNext();
				p->SetNext(q->GetNext());
				delete q;
				num--;
				break;
			}
			j++;
			p = p->GetNext();
		}
	}
	else {
		cout << "Error deleting location !" << endl;
		exit(1);
	}
}

template <typename T> 
//设置第i个结点的数值域val
void LinkList<T>::SetNode(int i, T val) {
	int j = 0;
	Node<T> *p = head;
	while (p) {
		j++;
		p = p->GetNext();
		if (j == i) {
			p->SetVal(val);
		}
	}
}

template <typename T>   
//打印整个链表
void LinkList<T>::PrintAll() {
	Node<T> *p = head->GetNext();
	if (p == NULL)
	{
		cout << "LinkList is NULL" << endl;
		return;
	}		
	else {
		int i = 1;
		while (p) {
			cout << p->GetVal() << "-->";
			i++;
			p = p->GetNext();
		}
		cout  << "NULL" << endl;
	}
}

#endif

#pragma once
#ifndef __BINARYTREE_HPP__
#define __BINARYTREE_HPP__

#include<bits/stdc++.h>

#define PrevOrderCreat 1	//前序创建
#define LevelOrderCreat 2	//层序创建

#define CreatTreeMethod PrevOrderCreat

using namespace std;

template <typename T>
struct TreeNode{
	T val;
	struct TreeNode<T>* left;
	struct TreeNode<T>* right;
	TreeNode(T x) :
	val(x), left(NULL), right(NULL) {
	}
};

/****************************************************************************************************/
/*
功能：应用C++语言实现二叉树的各项操作
建立二叉树的节点结构TreeNode，封装一个BinaryTree类将有效节点链接起来
基本的成员函数：
构造函数、拷贝构造函数、赋值运算符的重载、析构函数
**
**二叉树的具体操作：
**                  1：前序遍历(递归与非递归)
**                  2：中序遍历(递归与非递归)
**                  3：后序遍历(递归与非递归)
**                  4：层序遍历
**                  5：节点数
**                  6：树深度
**                  7：叶节点数
**
**                                                             By ：汪亮
**
*/
/*****************************************************************************************************/
template <typename T>
class BinaryTree {
private:
	TreeNode<T>* root;		//树根结点指针
public:
	BinaryTree() :root(NULL) {};//无参的构造函数
	BinaryTree(const T* a, size_t size, const T& invalid);//有参构造函数		
	BinaryTree(const BinaryTree<T> &t);//拷贝构造
	BinaryTree<T>& operator=(BinaryTree<T> t);//赋值运算符的重载
	~BinaryTree();//析构函数
	TreeNode<T>* GetTreeRoot();//获得二叉树根节点

	void PrevOrder()//前序遍历
	{
		//_PrevOrder(root);
		_PreOrderNonrecursive(root);
		cout << "over" << endl;
	}
	void InOrder()//中序遍历
	{
		//_InOrder(root);
		_InOrderNonrecursive(root);
		cout << "over" << endl;
	}
	void PostOrder()//后序遍历
	{
		//_PostOrder(root);
		_PostOrderNonrecursive1(root);
		cout << "over" << endl;
	}
	void LevelOredr()//层次遍历
	{
		_LevelOrder(root);
		cout << "over" << endl;
	}
	size_t Size()//节点数
	{
		return _Size(root);
	}
	size_t Depth()//深度
	{
		return _Depth(root);
	}
	size_t LeafSize()//叶子节点数
	{
		return _LeafSize(root);
	}
	vector<string> binaryTreePaths(TreeNode<T>* root);			//打印根到叶节点的所有路径(string打印格式1->2->3)
	vector<vector<T> > allPaths(TreeNode<T>* root);				//保存根到叶节点的所有路径													
	int maxSumPath(TreeNode<T>* root);							//所有路径拓展|输出节点值和最大（小）的路径
	vector<vector<T> > FindPath(TreeNode<T>* root, int expectNumber);//找出结点值的和为输入整数的所有路径
	int FindMaxPath(TreeNode<T>* root, int expectNumber);			//找出结点值的和为输入整数的最长路径长度

protected:
	TreeNode<T>* _CreatBinaryTree(const T *a, size_t size, const T& invalid, size_t& index);	//创建二叉树TreeNode
	TreeNode<T>* _Copy(TreeNode<T>*  root);	//复制二叉树
	void _Delete(TreeNode<T>*  &root);		//删除
	void _PrevOrder(TreeNode<T>*  root);	//前序遍历：根节点--左子树--右子树
	void _PreOrderNonrecursive(TreeNode<T>*  root);//前序遍历非递归
	void _InOrder(TreeNode<T>*  root);		//中序遍历：左子树--根节点--右子树
	void _InOrderNonrecursive(TreeNode<T>* root);//中序遍历非递归
	void _PostOrder(TreeNode<T>*  root);	//后序遍历：左子树--右子树--根节点
	void _PostOrderNonrecursive1(TreeNode<T>*  T);//后序遍历非递归
	void _LevelOrder(TreeNode<T>* root);	//层次遍历
	size_t _Size(TreeNode<T>*  root);		//节点个数
	size_t _Depth(TreeNode<T>*  root);		//二叉树的深度
	size_t _LeafSize(TreeNode<T>*  root);	//叶子节点个数

};

/////////////////////////////////////////////////////////
//构造函数
template <typename T>
BinaryTree<T>::BinaryTree(const T* a, size_t size, const T& invalid)//有参构造函数	
	:root(NULL)
{
	size_t index = 0;
	root = _CreatBinaryTree(a, size, invalid, index);
}

//拷贝构造
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &t)
	:root(NULL)
{
	root = _Copy(t.root);
}

//赋值运算符的重载
template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> t)
{
	if (this != &t)//防止自赋值
	{
		swap(root, t.root);
	}
	return *this;
}

//析构函数
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	if (root)
	{
		_Delete(root);
	}
}

//获得二叉树根节点
template <typename T>
TreeNode<T>* BinaryTree<T>::GetTreeRoot() {
	return this->root;
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//成员函数
//创建二叉树TreeNode
template <typename T>
TreeNode<T>* BinaryTree<T>::_CreatBinaryTree(const T *a, size_t size, const T& invalid, size_t& index)
{
	TreeNode<T>*  cur = NULL;
	if (index < size && a[index] != invalid)//不能越界
	{
		switch (CreatTreeMethod)
		{
			case PrevOrderCreat:
			{
				cur = new TreeNode<T>(a[index]);//开辟节点
				cur->left = _CreatBinaryTree(a, size, invalid, ++index);//递归创建左子树
				cur->right = _CreatBinaryTree(a, size, invalid, ++index);//递归创建右子树
			}break;
			case LevelOrderCreat:
			{
				if (a[index] == '#')return NULL;

				cur = new TreeNode<T>(a[index]);//新建一个根结点

				size_t lnode = 2 * index + 1;
				size_t rnode = 2 * index + 2;

				if (lnode > size - 1) cur->left = NULL;
				else cur->left = _CreatBinaryTree(a, size, invalid, lnode);

				if (rnode > size - 1) cur->right = NULL;
				else cur->right = _CreatBinaryTree(a, size, invalid, rnode);
			}break;
			default:break;
		}
	}
	return cur;
}

//复制二叉树
template <typename T>
TreeNode<T>* BinaryTree<T>::_Copy(TreeNode<T>*  root)		
{
	TreeNode<T>* cur = NULL;
	if (root == NULL)
	{
		return NULL;
	}

	cur = new Node(root->_data);//创建该节点

	cur->left = _Copy(root->left);
	cur->right = _Copy(root->right);
	return cur;
}

//删除函数
template <typename T>
void BinaryTree<T>::_Delete(TreeNode<T>* &root)		
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)//该节点没有左右孩子
	{
		delete root;//释放该节点
		root = NULL;
		return;
	}
	_Delete(root->left);
	_Delete(root->right);
}

//前序遍历：根节点--左子树--右子树
template <typename T>
void BinaryTree<T>::_PrevOrder(TreeNode<T>* root)	
{
	if (root == NULL)
	{
		return;
	}

	cout << root->val << "->";
	_PrevOrder(root->left);
	_PrevOrder(root->right);
}
//先序遍历的非递归
template <typename T>
void BinaryTree<T>::_PreOrderNonrecursive(TreeNode<T>* root)
{
	if (!root)
		return;

	stack<TreeNode<T>* > s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode<T>* temp = s.top();
		cout << temp->val << "->";
		s.pop();
		if (temp->right)//右子树先进后出
			s.push(temp->right);
		if (temp->left)//左子树后进先出
			s.push(temp->left);
	}
}
//先序遍历的非递归1  
//template <typename T>
//void BinaryTree<T>::_PreOrderNonrecursive(TreeNode<T>* T)     //先序遍历的非递归    
//{
//	if (!T)
//		return;
//
//	stack<TreeNode<T>* > s;
//	while (T)          // 左子树上的节点全部压入到栈中    
//	{
//		s.push(T);
//		cout << T->val << "->";
//		T = T->left;
//	}
//
//	while (!s.empty())
//	{
//		TreeNode<T>* temp = s.top()->right;  // 栈顶元素的右子树    
//		s.pop();                        // 弹出栈顶元素    
//		while (temp)          // 栈顶元素存在右子树，则对右子树同样遍历到最下方    
//		{
//			cout << temp->val << "->";
//			s.push(temp);
//			temp = temp->left;
//		}
//	}
//}

//中序遍历：左子树--根节点--右子树
template <typename T>
void BinaryTree<T>::_InOrder(TreeNode<T>* root)		
{
	if (root == NULL)
	{
		return;
	}

	_InOrder(root->left);
	cout << root->val << "->";
	_InOrder(root->right);
}
// 中序遍历的非递归  
template <typename T>
void BinaryTree<T>::_InOrderNonrecursive(TreeNode<T>* root)
{
	if (!root)
		return;
	stack<TreeNode<T>*> s;
	TreeNode<T>* curr = root->left;    // 指向当前要检查的节点    
	s.push(root);
	while (curr != NULL || !s.empty())
	{
		while (curr != NULL)    // 一直向左走    
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->val << "->";
		curr = curr->right;
	}
}

//后序遍历：左子树--右子树--根节点
template <typename T>
void BinaryTree<T>::_PostOrder(TreeNode<T>*  root)	
{
	if (root == NULL)
	{
		return;
	}

	_PostOrder(root->left);
	_PostOrder(root->right);
	cout << root->val << "->";
}
//后序遍历的非递归
template <typename T>
void BinaryTree<T>::_PostOrderNonrecursive1(TreeNode<T>*  root)  // 后序遍历的非递归      
{
	stack<TreeNode<T>* > S;
	TreeNode<T>*  curr = root;           // 指向当前要检查的节点    
	TreeNode<T>*  previsited = NULL;    // 指向前一个被访问的节点    
	while (curr != NULL || !S.empty())  // 栈空时结束      
	{
		while (curr != NULL)            // 一直向左走直到为空    
		{
			S.push(curr);
			curr = curr->left;
		}
		curr = S.top();
		// 当前节点的右孩子如果为空或者已经被访问，则访问当前节点    
		if (curr->right == NULL || curr->right == previsited)
		{
			cout << curr->val << "->";
			previsited = curr;
			S.pop();
			curr = NULL;
		}
		else
			curr = curr->right;      // 否则访问右孩子    
	}
}

//层次遍历
template <typename T>
void BinaryTree<T>::_LevelOrder(TreeNode<T>* root)	
{
	queue<TreeNode<T>* > q;
	if (root == NULL)
	{
		return;
	}
	q.push(root);
	while (!q.empty())
	{
		if (q.front()->left != NULL)
		{
			q.push(q.front()->left);
		}
		if (q.front()->right != NULL)
		{
			q.push(q.front()->right);
		}
		cout << q.front()->val << "->";
		q.pop();
	}
}

//节点个数
template <typename T>
size_t BinaryTree<T>::_Size(TreeNode<T>*  root)		
{
	if (root == NULL)
	{
		return 0;
	}
	return _Size(root->left) + _Size(root->right) + 1;//当左子树或者右子树不为空时，该节点有数据
}

//二叉树的深度
template <typename T>
size_t BinaryTree<T>::_Depth(TreeNode<T>* root)		
{
	if (root == NULL)
	{
		return 0;
	}
	size_t leftDepth = _Depth(root->left);
	size_t rightDepth = _Depth(root->right);
	/*if (leftDepth >= rightDepth)
	{
	return leftDepth + 1;
	}
	else
	return rightDepth + 1;*/
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//叶子节点个数
template <typename T>
size_t BinaryTree<T>::_LeafSize(TreeNode<T>*  root)
{
	size_t size = 0;
	if (root == NULL)
	{
		return size;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		size++;
		return size;
	}

	return _LeafSize(root->left) + _LeafSize(root->right);
}

//打印根到叶节点的所有路径
template <typename T>
void treereverse(vector<string> &vec, string str, TreeNode<T>* root) {
	if (!root) return;
	if (!root->left && !root->right) {
		str += to_string(root->val);
		vec.push_back(str);
		return;
	}
	str += to_string(root->val) + "->";
	if (root->left) treereverse(vec, str, root->left);
	if (root->right) treereverse(vec, str, root->right);
}
template <typename T>
vector<string> BinaryTree<T>::binaryTreePaths(TreeNode<T>* root) {
	vector<string> path;
	if (!root) return path;
	treereverse(path, "", root);
	return path;
}

//保存根到叶节点的所有路径
template <typename T>
void treePathReverse(vector<vector<T> > &vec, vector<T> temp, TreeNode<T>* root) {
	if (!root) return;
	if (!root->left && !root->right) {
		temp.push_back(root->val);
		vec.push_back(temp);
		return;
	}
	temp.push_back(root->val);
	if (root->left) treePathReverse(vec, temp, root->left);
	if (root->right) treePathReverse(vec, temp, root->right);
}
template <typename T>
vector<vector<T> > BinaryTree<T>::allPaths(TreeNode<T>* root) {
	vector<vector<T> > path;
	vector<T> temp;
	if (!root) return path;
	treePathReverse(path, temp, root);
	return path;
}

//所有路径拓展|输出节点值和最大（小）的路径
template <typename T>
int BinaryTree<T>::maxSumPath(TreeNode<T>* root) {
	vector<vector<T> > paths;
	paths = allPaths(root);
	int maxsum = INT_MIN;
	int maxLen = 0;
	//int minsum = INT_MAX;
	//int minLen = INT_MAX;
	int len;
	for (int i = 0; i < paths.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < paths[i].size(); ++j) {
			sum += paths[i][j];
		}
		len = paths[i].size();
		maxsum = max(maxsum, sum);//节点路径和最大值
		maxLen = max(maxLen, len);//最长路径
		//minsum = min(minsum, sum);//节点路径和最小值
		//minLen = min(minLen, len);//最短路径
	}
	return maxsum;
}

//找出结点值的和为输入整数的所有路径
/*
思路：
递归先序遍历树， 把结点加入路径。
若该结点是叶子结点则比较当前路径和是否等于期待和，如果相等将路径添加的结果数组。
弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点（回溯法）。
*/
template <typename T>
void dfs(TreeNode<T>* root, int expectNumber, vector<vector<T>> &res, vector<T> path) {
	path.push_back(root->val);
	if (!root->left && !root->right) {
		if (expectNumber == root->val)
			res.push_back(path);
	}
	if (root->left)
		dfs(root->left, expectNumber - root->val, res, path);
	if (root->right)
		dfs(root->right, expectNumber - root->val, res, path);
	path.pop_back();

}
template <typename T>
vector<vector<T> > BinaryTree<T>::FindPath(TreeNode<T>* root, int expectNumber) {
	vector<vector<T>> res;
	vector<T> path;
	if (root)
		dfs(root, expectNumber, res, path);
	return res;
}

//找出结点值的和为输入整数的最长路径长度
template <typename T>
int BinaryTree<T>::FindMaxPath(TreeNode<T>* root, int expectNumber) {
	vector<vector<T>> res;
	vector<T> path;
	if (root)
		dfs(root, expectNumber, res, path);
	int maxLen = 0;
	int len;
	for (int i = 0; i < res.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < res[i].size(); ++j) {
			sum += res[i][j];
		}
		len = res[i].size();
		maxLen = max(maxLen, len);//最长路径
	}
	return maxLen;
}

#endif

//void Test()
//{
//	int array1[10] = { 1, 2, 3, '#', '#', 4, '#' , '#', 5, 6 };
//	BinaryTree<int> b1(array1, 10, '#');
//	cout << "前序遍历：";
//	b1.PrevOrder();
//	cout << "中序遍历：";
//	b1.InOrder();
//	cout << "后序遍历：";
//	b1.PostOrder();
//	cout << "层次遍历：";
//	b1.LevelOredr();
//	cout << endl;
//	cout << "节点数：" << b1.Size() << endl;
//	cout << "深度：" << b1.Depth() << endl;
//	cout << "叶子节点数：" << b1.LeafSize() << endl;
//	cout << endl;
//
//	BinaryTree<int> b2(b1);
//	cout << "前序遍历：";
//	b2.PrevOrder();
//	cout << "中序遍历：";
//	b2.InOrder();
//	cout << "后序遍历：";
//	b2.PostOrder();
//	cout << "层次遍历：";
//	b2.LevelOredr();
//	cout << endl;
//	cout << "节点数：" << b2.Size() << endl;
//	cout << "深度：" << b2.Depth() << endl;
//	cout << "叶子节点数：" << b2.LeafSize() << endl;
//	cout << endl;
//
//	BinaryTree<int> b3;
//	b3 = b1;
//	cout << "前序遍历：";
//	b3.PrevOrder();
//	cout << "中序遍历：";
//	b3.InOrder();
//	cout << "后序遍历：";
//	b3.PostOrder();
//	cout << "层次遍历：";
//	b3.LevelOredr();
//	cout << endl;
//	cout << "节点数：" << b3.Size() << endl;
//	cout << "深度：" << b3.Depth() << endl;
//	cout << "叶子节点数：" << b3.LeafSize() << endl;
//
//}
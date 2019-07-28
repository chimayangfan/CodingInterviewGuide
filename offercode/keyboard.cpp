//（1）输入一个数字再加上空格间隔的数组：
int num;
cin >> num;
int *arr = new int[len + 1]
for (int i = 0; i <= num; i++) {
	cin >> arr[i];
}
//（2）需要多次输入形式重复的数据：
while (cin >> k)
（3）对于不存在空格的字符数组：
char str[30];
cin >> str;
//（4）输入带有空格的字符数组：
char str[30];
cin.getline(str, len);//读入整行数据，它使用回车键输入的换行符来确定输入结尾。
					  //cin.get(str,len);//这个还会保留换行符
//（5）输入字符串string
string str;
getline(cin, str);
//（6）输入多个整数
int a, b, c, d;
cin >> a >> b >> c >> d;
//（7）具体应用：数组从小到大排列并去除重复项
//sort，将这组数字从小到大排列；
//unique，将相邻且重复的数放到vector的尾部，然后返回指向第一个重复元素的迭代器（需要注意的是，被放在尾部的数据有时会产生变化，所以不能继续使用了，需要废弃掉）；
//erase，擦除重复的数据
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	cout << "please input the number of vector's element" << endl;
	int number;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);   //在vector尾部加入一个数据
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
//（8）输出不定量的行的字符串
string str;
while (cin >> str)
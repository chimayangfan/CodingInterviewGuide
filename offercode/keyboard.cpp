//��1������һ�������ټ��Ͽո��������飺
int num;
cin >> num;
int *arr = new int[len + 1]
for (int i = 0; i <= num; i++) {
	cin >> arr[i];
}
//��2����Ҫ���������ʽ�ظ������ݣ�
while (cin >> k)
��3�����ڲ����ڿո���ַ����飺
char str[30];
cin >> str;
//��4��������пո���ַ����飺
char str[30];
cin.getline(str, len);//�����������ݣ���ʹ�ûس�������Ļ��з���ȷ�������β��
					  //cin.get(str,len);//������ᱣ�����з�
//��5�������ַ���string
string str;
getline(cin, str);
//��6������������
int a, b, c, d;
cin >> a >> b >> c >> d;
//��7������Ӧ�ã������С�������в�ȥ���ظ���
//sort�����������ִ�С�������У�
//unique�����������ظ������ŵ�vector��β����Ȼ�󷵻�ָ���һ���ظ�Ԫ�صĵ���������Ҫע����ǣ�������β����������ʱ������仯�����Բ��ܼ���ʹ���ˣ���Ҫ����������
//erase�������ظ�������
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
		v.push_back(temp);   //��vectorβ������һ������
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
//��8��������������е��ַ���
string str;
while (cin >> str)
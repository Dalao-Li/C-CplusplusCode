/*
set��vector��࣬����vector��Ψһ������ǣ�
set�����Ԫ�����������Ψһ�ģ�ֻҪ����set��
���Ԫ�أ����ͻ��Զ����򣬶��ң��������ӵ�
Ԫ��set���汾���ʹ��ڣ���ô�����Ӳ����Ͳ�ִ�С�
*/
#include<iostream>
#include<set>
#include<string>
using namespace std;
template <typename T>
void showset(set<T> v) {
	for (typename std::set<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it<<" ";
	}
	cout << endl;
}

int main() {
	set<int> s1 {9,8,1,2,3,4,5,5,5,6,7,7 }; //�Զ����򣬴�С����,�޳���ͬ��
	cout<<"�Զ����򣬴�С����,�޳���ͬ����s1:";
	showset(s1);
	set<string> s2 { "hello","sysy","school","hello" }; //�ֵ�������
	cout<<"�ֵ��������(��Ȼ�޳���ֵͬ)��s2:";
	showset(s2);
	s1.insert(9); //�����ֵ�ˣ�do nothing
	cout<<"��s1���ٲ���һ�����ڵ�ֵ��Ľ��:";
	showset(s1);
	cout<<"��s2�в���һ�������ڵ�ֵ��Ľ��:";
	s2.insert("aaa"); //û������ַ�������Ӳ�������
	showset(s2);

	system("pause");
	return 0;
}


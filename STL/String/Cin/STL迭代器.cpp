#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	v.push_back(3);  //����β������3
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	cout << " �±� " << v[3] << endl;
	cout << " ������ " << endl;
	for(vector<int>::iterator i = v.begin(); i!= v.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	//�ڵ�һ��Ԫ��֮ǰ����111  insert begin+n���ڵ�n��Ԫ��֮ǰ����
	v.insert(v.begin(),111);
	//�����һ��Ԫ��֮�����222 insert end + n ����n��Ԫ��֮�����
	v.insert(v.end(),222);
	for(vector<int>::iterator i = v.begin(); i!= v.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	vector<int> arr(10);
	for(int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	for(vector<int>::iterator i = arr.begin(); i!= arr.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	
	
	//ɾ�� ͬinsert
	arr.erase(arr.begin());   //ɾ���˿�ͷԪ�� 
	for(vector<int>::iterator i = arr.begin(); i!= arr.end(); ++i) {
		cout << *i << " " ;
	}
	cout << endl ;
	arr.erase(arr.begin(),arr.begin()+5);  //ɾ�����±�5(��)֮ǰ��Ԫ�� 
	for(vector<int>::iterator i = arr.begin(); i!= arr.end(); ++i) {
		cout << *i << " " ;
	}
	cout << endl ;
	return 0 ;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	string str="Hello World!";
	//ʹ��const_iterator�����ַ���,��ʱ����Ԫ��ʱ���ܶ�����д 
	for(string::const_iterator it = str.begin();it!=str.end();++it){
		cout<<*it;
	}
	cout<<endl;
	//��iterator�����ַ���������ÿ���ַ���Ϊa,����� 
	for(string::iterator it = str.begin();it!=str.end();++it){
		*it='a';
		cout<<*it;
	} 
	return 0;
} 

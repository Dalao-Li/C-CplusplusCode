#include<iostream>
#include<map>
using namespace std;
int main() {
	//map����������� 
	int temp;
	string str;
	map<int,string> m1;
	//1---one  2--two  3--three
	for(int i=0; i<3; i++) {
		//�����--ֵ,�ᰴ�ռ���˳���Զ����� 
		cin>>temp>>str;
		m1.insert(make_pair(temp,str));
	}
	
	cout<<"����m1�и���---ֵ"<<endl;
	for(map<int,string>::iterator it=m1.begin(); it!=m1.end(); it++) {
		cout<<it->first<<"------"<<it->second<<endl;
	}
	
	//map�Ĳ������ȡ
	
	//���Ҹ�ֵ�Ƿ���ڣ�����ʹ�ú���count(k),���ص���k���ֵĴ��� 
	if(m1.count(1)){
		cout<<"yes"<<endl;
	}
	
	//ȡ��ȡ��key��Ӧ��ֵ������ʹ�ú���find(k) 
	map<int,string>::iterator it;
	it=m1.find(1);
	if(it!=m1.end()){
		cout<<"1��Ӧ��ֵΪ:"<<it->second<<endl;
	}
	
	//map��ɾ��Ԫ��
	//ɾ������m�м�Ϊk��Ԫ��
	m1.erase(1);
	for(map<int,string>::iterator it=m1.begin(); it!=m1.end(); it++) {
		cout<<it->first<<"------"<<it->second<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
//����
void inputArray(vector<int> &v) {
	int len,i,t;
	cout<<"��������Ҫ���ӵĳ���"<<endl;
	cin>>len;
	cout<<"������"<<len<<"������"<<endl;
	for(i=0; i<len; i++) {
		cin>>t;
		v.push_back(t);
	}
}

//���
void ouputArray(vector<int> v) {
	cout<<"������Ϊ��";
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<"���鳤��Ϊ:"<<v.size()<<endl;
	cout<<endl;
}

//����
void findArray(vector<int> v,int n) {
	vector<int>::iterator it=find(v.begin(),v.end(),n);
	if(it!=v.end()) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main(int argc,char *args[]) {
	vector<int> v1;
	int botton,n;
	while(1) {
		cout<<"1----����   2----���     3---����"<<endl;
		cin>>botton;
		switch(botton) {
			case 1:
				inputArray(v1);
				break;
			case 2:
				ouputArray(v1);
				break;
			case 3:
				cout<<"������Ҫ���ҵ���:";
				cin>>n;
				findArray(v1,n);
				break; 
			default:
				cout<<"��Ч"<<endl;
		}
	}
	ouputArray(v1);
	return 0;
}

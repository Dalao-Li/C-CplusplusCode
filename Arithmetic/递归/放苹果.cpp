/*��M��ͬ����ƻ������N��ͬ���������
�����е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ
�ķַ���
*/
#include<iostream>
#include<vector>
using namespace std;
//m����ƻ����,n����������
int fun(int m,int n) {
	//���û��ƻ����������ֻ��һ��,�����ݹ�
	if(m==0||n==1) {
		return 1;
	}
	//�������������ƻ����,�൱�����ֻ��m��������װ��ƻ��
	if(m<n) {
		return fun(m,m);
	}
	//��Ȼ������һ�����ӿ���,�����൱�ڿ��Դ�ÿ���������õ�һ��ƻ������Ӱ�첻ͬ�ŷ�����Ŀ
	else {
		return fun(m,n-1)+fun(m-n,n);
	}
}

int main() {
	int t;
	int m,n;
	vector<int> v;
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>m>>n;
		v.push_back(fun(m,n));
	}
	for(int i=0; i<t; i++) {
		cout<<v[i]<<endl;
	}

	return 0;
}


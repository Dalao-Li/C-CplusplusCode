#include<iostream>
#include<vector>
using namespace std;
/*
��ά�������������⣺
�����ά��������������ֱ�Ӷ�arr[i][j]����ѭ����ֵ����
vector<vector<int>>�У���Ϊvector��һ��������������
vector�����з��Ÿ�С��vector��������vector����ŵ���
int�͵����֡�������������Ҫ������vector������ֵ����
������vector��ΪԪ�ز��뵽����vector�С�
�������£�
*/
int main() {
	vector<vector<int> >test;
	vector<int> v;
	int n,m,temp;
	cout<<"��������ά�ȣ�";
	cin>>n>>m;
	test.clear();
	//����
	for(int i = 0; i<n; i++) {
		//ÿ�μǵ�clear,�Ա�����һ�������vector�����ĸ�ֵ
		v.clear();
		for(int j = 0; j<m; j++) {
			cin>>temp;
			v.push_back(temp);
		}
		//���ڲ��õ�һ�в��������
		test.push_back(v);
	}
	//���
	cout<<"����Ϊ��"<<endl;
	/*
	
	for(vector<vector<int> >::iterator it = test.begin();it!=test.end();it++){
		for(vector<int>::iterator jt=v.begin();jt!=v.end();jt++){
			cout<<*jt<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << test[i][j] << " ";
		}
		cout << endl;
	}

}

/*
	int X,Y,i,j;
	cout<<"����һ��ά�Ĵ�С:";
	cin>>X>>Y;
	vector< vector<int> > a(X,vector<int>(Y));
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			cin>>a[i][j];
		}
	}
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
		cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
*/

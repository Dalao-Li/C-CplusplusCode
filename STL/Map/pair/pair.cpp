/*
pair�ǽ�2��������ϳ�һ������,����Ҫ����������ʱ�Ϳ���ʹ��pair,
��stl�е�map���ǽ�key��value����һ�������档��һ��Ӧ����,��һ��
������Ҫ����2�����ݵ�ʱ��,����ѡ��pair�� pair��ʵ����һ���ṹ��
,��Ҫ��������Ա������first second ��Ϊ��ʹ��struct����class,��
�Կ���ֱ��ʹ��pair�ĳ�Ա������

pair��һ��ֵ��ϳ�һ��ֵ,��һ��ֵ���Ծ��в�ͬ����������
(T1��T2),����ֵ���Էֱ���pair���������к���first��second���ʡ�
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	pair<int,double> p1;
	pair<int,double> p2;
	p1.first=1;
	p1.second=2.5;
	
	p2=make_pair(2,2.2);
	
	pair<int,double> p3=p1;
	
	cout<<"p1"<<" "<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2"<<" "<<p2.first<<" "<<p2.second<<endl;
	cout<<"p3"<<" "<<p3.first<<" "<<p3.second<<endl;
}

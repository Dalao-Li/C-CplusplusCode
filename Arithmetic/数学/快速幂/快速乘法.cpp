#include<iostream>
using namespace std;
typedef long long ll;
//a*b
ll rapidMultiplication(int a,int b) {
	ll ans = 0;
	while(b) {
		//��b�Ķ�����ĩλΪ1,��bΪ����ʱ 
		if(b&1) {
			//������ݴ���ans�� 
			ans+=a;
		}
		//��b 
		b>>=1;
		//��a 
		a<<=1;
	}
	return ans;
}
int main() {
	int a,b;
	cin>>a>>b;
	cout<<rapidMultiplication(a,b)<<endl;
}

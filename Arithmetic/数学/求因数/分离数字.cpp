//�����һ�����ֵ���������
#include<iostream>
using namespace std;
void divide(int n) {
	//1�϶�Ϊһ����������
	cout<<n<<"=1*";
	for(int i=2; i<n; i++) {
		while(n!=i) {
			if(n%i==0) {
				cout<<i<<"*";
				n=n/i;
			} else
				break;
		}
	}
	cout<<n<<endl;
}

int main() {
	int n,i;
	cin>>n;
	divide(n);
	return 0;
}


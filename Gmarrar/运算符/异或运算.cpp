#include<iostream>
using namespace std;
int add(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	//λ��
	int p1 = a&b;
	//cout<<"a&b="<<p1<<endl;
	//������ֻ���ǽ�λ
	p1 = p1 << 1;
	//cout<<"p1<<1="<<p1<<endl;
	//λ��򡣲����ǽ�λ
	int p2 = a^b;
	//�����ı�־��aΪ0�ˣ�����bΪ0��
	//cout<<"p1="<<p1<<" "<<"P2="<<p2<<endl; 
	return add(p2, p1);
}
int main() {
	int x = 3, y = 2;
	int sum = 0;
	sum = add(x,y);
	cout << sum << endl;

}


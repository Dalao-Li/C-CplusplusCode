//n�������ͼ�ֵ�ֱ�Ϊwi vi����Ʒ,����ѡ�����ز�����W����Ʒ,���ֵ�����ֵ
#include<iostream>
#include<algorithm> 
#define MAX 100
using namespace std;
int n,W;
int w[MAX],v[MAX];

//�ӵ�i����Ʒ���ҳ�����С��j�Ĳ��� 
int rec(int i,int j) {
	int res;
	//����Ѿ�ѡ���� 
	if(i==n) {
		res = 0;
	} else if(j<w[i]) {
		res = rec(i+1,j);
	} else {
		res = max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
	}
	return res;
}

int main() {
	cin>>W>>n;
	//for(int i=0;)
	printf("%d\n",rec(0,W));
}

//n�������ͼ�ֵ�ֱ�Ϊwi vi����Ʒ,����ѡ�����ز�����W����Ʒ,���ֵ�����ֵ
#include<iostream>
#include<algorithm> 
#include<cstring>
#define MAX 100
using namespace std;
int n,weight;
int w[MAX],v[MAX];

int dp[MAX][MAX]; 
//�ӵ�i����Ʒ���ҳ�����С��j�Ĳ��� 
int rec(int i,int j) {
	if(dp[i][j]>=0){
		return dp[i][j];
	}
	int res;
	//����Ѿ�ѡ���� 
	if(i==n) {
		res = 0;
	} 
	//���ѡ���� 
	else if(j<w[i]) {
		res = rec(i+1,j);
	} else {
		res = max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
	}
	return dp[i][j] = res;
}

int main() {
	memset(dp,-1,sizeof(dp));
	//cin>>
	printf("%d\n",rec(0,weight));
}

//�������ַ����������������
#include<iostream>
#include<algorithm>
#define MAX_N 100
using namespace std;

//������¼�����г���
int dp[MAX_N][MAX_N];
//�����ָ���������
int lcs[MAX_N][MAX_N];

string s,t;
int n,m;

//���������г���
void solve() {
	//cout<<"�����������г���"<<endl; 
	cin>>n>>s>>m>>t;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(s[i] == t[j]) {
				dp[i+1][j+1] = dp[i][j]+1;
				lcs[i+1][j+1] = 1;
			} else if(dp[i][j+1]>dp[i+1][j]) {
				dp[i+1][j+1] = dp[i][j+1];
				lcs[i+1][j+1] = 2;
			} else if(dp[i+1][j]>dp[i][j+1]) {
				dp[i+1][j+1] = dp[i+1][j];
				lcs[i+1][j+1] = 3;
			}
		}
	}
	cout<<dp[n][m]<<endl;
}

//����������
void ouputLcs(string &s,int i,int j) {
	if(i==0||j==0) {
		return ;
	}
	if(lcs[i][j]==1) {
		ouputLcs(s,i-1,j-1);
		cout<<s[i-1];
	} else if(lcs[i][j]==2) {
		ouputLcs(s,i-1,j);
	} else {
		ouputLcs(s,i,j-1);
	}
}

int main() {
	solve();
	ouputLcs(s,n,m);
}

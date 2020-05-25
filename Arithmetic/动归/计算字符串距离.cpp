/*
1.dp[i][j]����a�ַ���ǰi���ַ���b�ַ���ǰj���ַ��Ķ�����;
2.��i����0ʱ,��Ҫ�Ķ�j��,j����0ʱ,��Ҫ�Ķ�i��,��dp[0][j]=j,dp[i][0]=i;
3.��a[i]=b[j]ʱ,����Ҫ�Ķ�,��dp[i][j]=dp[i-1][j-1];
4.��a[i]!=b[j]ʱ,�����ָĶ���ʽ���ĳ�һ��,ɾa[i],ɾb[j],����dp[i][j]=min(f[i-1][j-1],dp[i-1][j],dp[i][j-1]);
*/ 


#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[1001][1001];
int main() {	
	memset(dp,0,sizeof(dp));
	string s1,s2;
	cin>>s1>>s2;
	int len1 = s1.size();
	int len2 = s2.size();
	for(int i = 0 ; i<len1 ; i++) {
		dp[i][0] = i;
	}
	for(int j = 0; j<len2 ; j++) {
		dp[0][j] = j;
	}
	for(int i = 0; i<len1 ; i++) {
		for(int j = 0; j<len2 ; j++) {
			if(s1[i]==s2[j]) {
				dp[i+1][j+1]=dp[i][j];
			} else {
				dp[i+1][j+1] = min(min(dp[i][j],dp[i][j+1]),dp[i+1][j])+1;
			}
		}
	}
	cout<<dp[len1][len2]<<endl;
	return 0;
}

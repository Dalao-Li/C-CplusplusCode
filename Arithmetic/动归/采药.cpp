//T�����ܹ��ܹ�������ҩ��ʱ�䣬M����ɽ����Ĳ�ҩ����Ŀ��
//��������M��ÿ�а���������1��100֮�䣨����1��100���ĵ�
//����,�ֱ��ʾ��ժĳ���ҩ��ʱ��������ҩ�ļ�ֵ��
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int M,T;
int t[101],m[101];
int dp[101][101];
//�ӵ�i����Ʒ���ҳ���ʱ��С��j�Ĳ���

int main() {
	cin>>T>>M;
	for(int j = 0; j<=T; j++) {
		dp[0][j] = 0;
	}
	for(int i = 0; i<M; i++) {
		cin>>t[i]>>m[i];
	}
	for(int i = 0; i<M; i++) {
		for(int j = 0; j<=T; j++) {
			//�������ѡ
			if(t[i]>j) {
				dp[i+1][j] = dp[i][j];
			} else {
				dp[i+1][j] = max(dp[i][j],dp[i][j-t[i]]+m[i]);
			}
		}
	}
	cout<<dp[M][T]<<endl;
	return 0;
}

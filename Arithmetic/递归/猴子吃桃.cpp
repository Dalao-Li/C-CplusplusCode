#include<iostream>
using namespace std;
int main() {
	//sum������������,beforeSum�����֮ǰʣ�µ�������
	int n,sum=0,beforeSum,i,j;
	//�����������
	cin>>n;
	//i�������һ���������ߵ�������
	for(i=1; ; i++) {
		//��Ϊʣ�µ�����ƽ���ֳ�N��,�ֶ���һ��,���Է�֮ǰΪn*i+1��
		beforeSum=n*i+1;
		//�����һ��������ǰ�ݹ�
		for(j=1; j<n; j++) {
			//�жϷ�֮ǰ����������������Ҫ��,��beforeSum-1�ܹ���n����
			if((beforeSum-1)%n!=0) {
				//�������,˵�����һ��һ�������õ����������ԣ�����ö��
				break;
			}
			//beforeSum/(n-1)����ǰһ���������ߵ�������
			beforeSum=beforeSum*n+1;
		}
		//����һ������ʱ�˳�ѭ��
		if(j==n) {
			break;
		}
	}
	cout<<beforeSum<<endl;
	return 0;
}

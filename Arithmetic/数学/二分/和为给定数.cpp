//��һ���������ҵ���������ʹ���Ϊһ��ָ������
//���������ÿһ��a[i],ͨ�����ֲ����ҵ���һ��a[mid]ͨ������֮����Ŀ��ֵm�ıȽϾ�����С����ķ�Χ
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long a[100000],n,m,i,j;
	//��Ǳ���
	bool flag=false;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
	}
	//Ŀ��ֵm
	cin>>m;
	//�������ź���
	sort(a,a+n);
	//�������鵱�ҽ���û�ҵ�Ŀ��ֵʱ
	for(i=0; i<n; i++) {
		//��������Ϊ[i+1,n-1]
		int l=i,r=n-1;
		while(l<r) {
			int mid=(r+l)/2;
			//���ҵ�Ŀ��ֵ�Ҳ��ظ�ʱ 
			if(m-a[i]==a[mid]&&i!=mid) {
				flag=true;
				cout<<a[i]<<" "<<a[mid]<<endl;
				break;
			}
			//������С��Χ[mid+1,r]
			else if(m-a[i]>a[mid]) {
				l=mid+1;
			} else {
				r=mid-1;
			}
		}
	}
	//���û�ҵ�
	if(flag==false) {
		cout<<"No"<<endl;
	}
	return 0;
}

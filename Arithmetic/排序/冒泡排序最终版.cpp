#include<iostream>
using namespace std;
int main() {
	int n,i,j,*a;
	a=new int[n];
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
	}

	//������¼���һ�ν�����λ��
	int lastExchangeIndex = 0;
	//�������еı߽磬ÿ�αȽ�ֻ��ȵ���Ϊֹ
	int sortBorder = n-1;
	for(i=0; i<n; i++) {
		//ÿһ�ֿ�ʼʱĬ��Ϊ�������򣬱��Ϊture
		bool isSorted= true ;
		for(j=0; j<sortBorder; j++) {
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//��Ԫ�ؽ�����˵���������򣬱�Ǳ�Ϊfalse
				isSorted=false;
				//��¼���һ�ν�����λ��
				lastExchangeIndex = j;
			}
			for(int i=0; i<n; i++) {
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}

		//���������б߽����Ϊ���һ�ν���Ԫ�ص�λ��
		sortBorder =lastExchangeIndex;
		//���ڲ�һ���������Ϊ����˵��������ɣ�����
		if(isSorted) {
			break;
		}
	}

	for(i=0; i<n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}




#include<iostream>
using namespace std;
int main() {
	int n,i,j,*a;
	a=new int[n];
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
	}

	//������¼�����Ҳ����һ�ν�����λ��
	int lastLeftExchangeIndex;
	int lastRightExchangeIndex;
	//�������е����ұ߽磬ÿ�αȽ�ֻ��ȵ�����Ϊֹ
	int leftSortBorder=0;
	int rightSortBorder= n-1;

	for(i=0; i<n/2; i++) {
		//ÿһ�ֿ�ʼʱĬ��Ϊ�������򣬱��Ϊture
		bool isSorted= true ;
		//�����֣��������ҽ��бȽϺͽ���
		for(j=leftSortBorder; j<rightSortBorder; j++) {
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//��Ԫ�ؽ�����˵���������򣬱�Ǳ�Ϊfalse
				isSorted=false;
				//��¼������һ�ν�����λ��
				lastLeftExchangeIndex=j;
			}
		}
		//���Ҳ��������еı߽����Ϊ������һ�ν�����λ��
		rightSortBorder= lastLeftExchangeIndex; 
		//���������Ϊ����˵��������ɣ������
		if(isSorted) {
			break;
		}
		//ÿһ�ֿ�ʼʱĬ��Ϊ�������򣬱��Ϊture
		isSorted =true;
		//ż���֣�����������бȽϺͽ���
		for(j=rightSortBorder; j>leftSortBorder; j--) {
			if(a[j]<a[j-1]) {
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				//��Ԫ�ؽ�����˵���������򣬱�Ǳ�Ϊfalse
				isSorted=false;
				//��¼�Ҳ����һ�ν�����λ��
				lastRightExchangeIndex=j;
			}
		}
		//������������еı߽����Ϊ�Ҳ����һ�ν�����λ��
		leftSortBorder= lastRightExchangeIndex;
		//���������Ϊ����˵��������ɣ������
		if(isSorted) {
			break;
		}
	}

	for(i=0; i<n; i++) {
		cout<<a[i]<<" ";
	}
	return 0;
}




#include<iostream>
#include<stdio.h>
#include<process.h>
using namespace std;

void shellSort(int a[],int len) {
	int h,i,j,temp;
	//��������
	for(h = len/2; h > 0; h /= 2) {
		//���forѭ������ǰ���ֱ�Ӳ�������
		for(i = h; i < len; i++) {
			temp = a[i];
			//ѭ����ӡ�����ÿ��Ԫ��
			for(j=i-h; j>=0&&temp<a[j]; j-=h) {
				a[j+h]=a[j];
			}
			a[j+h]=temp;
		}
	}
}

//�������
void printArray(int a[],int len) {
	for(int i=0; i<len; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int *a,n;
	cout<<"������Ҫ�������Ŀ"<<endl;            //����һ���Լ�����������
	cin>>n;
	a=new int[n];
	cout<<"������Ҫ���������"<<endl;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	cout<<"shell����ǰ:";
	printArray(a,n);
	shellSort(a,n);
	cout<<"shell�����(����):";
	printArray(a,n);
	delete[]a;
	return 0;
	system("pause");
}


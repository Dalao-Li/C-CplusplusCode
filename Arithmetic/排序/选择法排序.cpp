#include<iostream>
using namespace std;
//ѡ������
void selectionSort (int testData[],int len) {
	for(int i=0; i < len-1; i++) {
		//��ʼ��׼��Ϊ��ͷԪ��λ��
		int index = i;
		//����֮������Ԫ��
		for(int j = i+1; j <= len-1; j++) {
			//���ĳλ��Ԫ��С�ڻ�׼λ��Ԫ��
			if(testData[j] < testData[index]) {
				//���»�׼��
				index = j;
			}
		}
		//�����׼�벻�ǿ�ʼ���Ǹ�,˵����λ�õ�Ԫ����С
		if(index!=i) {
			//����С��Ԫ�ؽ�������ʼλ��
			swap(testData[i],testData[index]);
		}
		cout<<"��"<<i+1<<"�� ";
		for(int i = 0 ; i<len ;i++){
			cout<<testData[i]<<" ";
		} 
		cout<<endl;
	}
}
int main() {
	int a[10],i;
	cout<<"enter array :"<<endl;
	for(i=0; i<10; i++) {
		cin>>a[i];
	}
	selectionSort(a,10);
	cout<<"The sorted array:"<<endl;
	for(i=0; i<10; i++) {
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}



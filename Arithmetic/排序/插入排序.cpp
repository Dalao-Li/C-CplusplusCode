#include<iostream>
#define LEN sizeof(a)/sizeof(a[0])
using namespace std;
int main() {
	int a[]= {12,2,16,30,28,10,16,20,6,18};
	int i,j,temp;
	int c = 0,b = 0;
	//ѭ���ӵ�2��Ԫ�ؿ�ʼ
	for(i=1; i<LEN; i++) {
		//ǰһ��Ԫ�رȺ�һ��Ԫ�ش� 
		if(a[i-1] > a[i]) {
			c++;
			temp=a[i];
			//��ǰһ��Ԫ��λ�ÿ�ʼ,��δ����ͷ�ҵ�ǰλ��Ԫ�ش��ڴ�����Ԫ��temp 
			for(j = i-1; j >= 0 && temp < a[j]; j--) {
				//����Ԫ����������ƶ� 
				a[j+1] = a[j];
				b++;
			}
			//�˴�����Ϊ���������Ŀ�(�˳�ѭ��ʱj����1)
			//cout<<"����λ��Ϊ"<<j+1<<endl; 
			a[j+1] = temp;
			for(int i = 0 ; i<LEN ;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
	cout<<"���Ҵ���"<<c<<endl;
	cout<<"�ƶ�����"<<b<<endl;
	for(i=0; i<LEN; i++) {
		cout<<a[i]<<"  ";
	}
	return 0;
}

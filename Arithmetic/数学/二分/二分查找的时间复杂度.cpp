//����Ŀ�ģ���0 1 ... 99 100 ���������ÿ��Ԫ���輸�ζ��ֲ��Ҳ����ҵ��Ĵ��� 
#include<iostream>
using namespace std;
int main() {
	for(int i=0; i<=100; i++) {
		//left,right������������ķ�Χ 
		int left=0,right=100;
		//mid�����м�ֵ,�����ҵ���� 
		int mid;
		//count�����������Ĵ��� 
		int cont=0;
		//��������С�������䣬˵��������û���ҹ���ʱ�� 
		while(right>=left) {
			//�������� 
			cont++;
			//��ʼ������λ�� 
			mid=(left+right)/2;
			//�����ֵС���м�ֵ������С������[l,mid-1]
			if(i<mid) {         
				right=mid-1;	
			} 
			//�����ֵ�����м�ֵ������С������[mid+1,r]
			else if(i>mid) {  
				left=mid+1; 
			} 
			//������У�����
			else {
				break;          
			}
		}
		cout<<i<<"    "<<"һ��������"<<cont<<"��"<<endl;
	}
	return 0;
}

/*
��֪һ���Ѿ���С������������飬��������һ��ƽ̨��Plateau������������
һ��ֵ��ͬ��Ԫ�أ�������һ��Ԫ�ز��������졣���磬�� 1��2��2��3��3��3��
4��5��5��6��1��2-2��3-3-3��4��5-5��6����ƽ̨���Ա�дһ�����򣬽���һ��
���飬������������ƽ̨�ҳ� �����������������3-3-3�������ƽ̨��
����ƽ̨�ĳ��ȡ�
*/

/*
#include<iostream>
using namespace std;
int main()
{
	int a[1000],length=1,n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		//����lenth����¼��ǰ���ȣ�����lenth�����������plate��������ϸ����plate��lenth++����󷵻����lenth��
		if(a[i]==a[i-length]){
			length++;
		}
	}
	cout<<length<<endl;
	return 0;
}*/
#include<iostream>
using namespace std;
int main() {
	int n,x,i,maxs=1,cur,length=0; //cur�������浱ǰԪ��ֵ
	cin>>n>>x;
	cur=x;
	for(i=1; i<n; i++) {
		cin>>x;
		//���cur=x,��˵����һ��ƽ̨
		if(cur == x) { 
			length++;
		}
		//���������ƽ̨��������Ϊ1,�ҽ���Ԫ��ֵ���浽cur��
		else {
			length=1;
			cur=x;
		}
		maxs = max(maxs,length);
	}
	cout<<max<<endl;
	return 0;
}

















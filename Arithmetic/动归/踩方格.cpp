//һ�����޴�ķ���������򱱡����������������ߡ�
//����N�����ж����ֲ�ͬ�ķ�����
#include<iostream>
using namespace std;
/*Ii = Ni+Ei+Wi;Ni=Ni-1+Ei-1+Wi-1;
  Ei = Ni-1+Ei-1;Wi = Ni-1+Wi-1;

*/

int main(){
	int a[21];
	int n;
	a[1] = 3;
	a[2] = 7;   //3+2+1+1
	cin>>n;
	for(int i=3;i<=n;i++){
		a[i]=2*a[i-1]+a[i-2];
	} 
	cout<<a[n];
}


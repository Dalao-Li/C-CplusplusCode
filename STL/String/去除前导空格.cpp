#include<iostream>
using namespace std;
int main() {
	string strOld;
	string strNew;
	getline(cin,strOld);
	cout<<strOld<<endl;
	//���û��ǰ���ո�ֱ�Ӹ���
	if(strOld[0]!=' ') {
		strNew=strOld;
	}
	//����ڶ����ַ����ǿո񣬽�����ַ����ƹ�ȥ
	else if(strOld[1]!=' ') {
		strNew[0]=strOld[1];
	}
	//�� 
	for(int i=2,j=0,length=strOld.size(); i<length; i++) {
		if(strOld[i]!=' ') {
			strNew[j++]=strOld[i];
		} else {
			if(strOld[i-1]!=' '||strOld[i+1]!=' ') {
				strNew[j++]=strOld[i];
			}
		}
	}
}
cout<<strNew<<endl;
return 0;

}

#include<iostream>
using namespace std;

//���next����
void getNextArr(string str,int next[]) {
	next[0] = -1;
	int i = 0 ;
	//-1��ΪԽ���жϱ�ʶ
	int j = -1;
	while(i<str.length()) {
		//���Խ��(���˿�ͷ)����ƥ������
		if(j == -1 || str[i] == str[j]) {
			//��������
			i++;
			j++;
			next[i] = j;
		} else {
			//����jָ����ݣ�����λ��Ϊnext[j]
			j = next[j];
		}
	}
}

//�ַ���ƥ�䣬����ֵ��p����s�����״�ƥ�䵽��λ��
int kmp(string &s,string &p,int next[]) {
	//i��ʾs�ַ���ƥ�䵽��λ��
	int i = 0;
	//j��ʾp�ַ���ƥ�䵽��λ��
	int j = 0;
	while(i < s.length()) {
		//����p�ַ�����ʼλ�û��������ƥ��
		if(j == -1 || s[i] == p [j]) {
			i++;
			j++;
			//cout<<"i = "<<i<<endl;
			//cout<<"j = "<<j<<endl;
			//���Ѿ���pƥ���꣬������ѭ�� 
			if(j == p.length()){
				break;
			}
		} else {
			j = next[j];
			//cout<<"����j = "<<j<<endl;
		}
	}
	//cout<<"����i = "<<i<<endl;
	//cout<<"����j = "<<j<<endl;
	if(j == p.length()) {
		return i-j;
	}
	return -1;
}


int main() {
	string s = "BEFABFAF";
	string p = "BEFAB";
	int next[100]= {0};
	getNextArr(p,next);
	if(kmp(s,p,next)!=-1) {
		cout<<"ƥ�䵽���״�λ����:"<<kmp(s,p,next)<<endl;
	} else {
		cout<<"No"<<endl;
	}
	for(int i = 1 ; i< p.length()+1; i++) {
		printf("next[%d] = %d\n",i,next[i]);
	}
}

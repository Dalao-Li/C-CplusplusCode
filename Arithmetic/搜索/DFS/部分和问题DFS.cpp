#include<iostream>
using namespace std;

//ԭʼ���� 1,2,4,7;Ŀ���13,����н������OK 
int a[4] = {1,2,4,7};
int k = 13;
int n = 4;

//������ѡ����ǰi��,��ǰ��ֵΪsum
bool dfs(int i,int sum) {
	//����Ѿ�ѡ������
	if(i==n) {
		//�����sum��k���,����true
		if(sum==k) {
			return true;
		}
		//���򷵻�false
		return false;
	}
	//��ѡ��a[i]�����
	if(dfs(i+1,sum)) {
		return true;
	}
	//����a[i]�����
	if(dfs(i+1,sum+a[i])) {
		return true;
	}
	//����ô�������ܴճ�k
	return false;
}

int main() {
	if(dfs(0,0)) {
		cout<<"OK"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;

}

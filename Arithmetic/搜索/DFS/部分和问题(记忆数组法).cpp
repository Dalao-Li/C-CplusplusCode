#include<stdio.h>

int a[4] = {1,2,4,7};        //ԭʼ���� 1,2,4,7;Ŀ���13,����н������OK
int k = 13;
int n = 4;
int b[4];                    //�������

bool dfs(int x,int sum)  {

	if(sum>k) {              //��֦,���ⲻ��Ҫ�Ĳ���
		return false;
	}
	if(x==n) {               //���ǰn��������,����sum=k�Ƿ����
		return sum==k;
	}
	if(dfs(x+1,sum)) {
		b[x]=0;              //���������a[x]�����,b[x]���Ϊ0
		return true;
	}
	if(dfs(x+1,sum+a[x])) {
		b[x]=1;              //�������a[x]�����,b[x]���Ϊ1
		return true;
	}
	return false;
}

int main() {
	if(dfs(0,0)) {
		printf("YES\n");
		for(int i=0; i<n; i++) {
			if(b[i]) {
				printf("%d ",a[i]);
			}
		}
		printf("\n");
	} else {
		printf("NO\n");
	}
	return 0;
}


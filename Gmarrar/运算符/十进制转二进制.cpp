#include<stdio.h>
#include<stdlib.h>
//ע��������stdlib.h������
int main(void) {
	int a;
	scanf("%d",&a);
	char str[30];
	//2���Ǵ���ת��Ϊ2����
	itoa(a,str,2);
	printf("%s",str);
	return 0;
}


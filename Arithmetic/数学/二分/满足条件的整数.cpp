/*
����a��b��c��Ϊ������������a��b��c ����1��
����С�ڵ���100���ҳ����з������������顣
ע�⣺
1��Ϊ�����ظ������Ҫ��a<=b��
2���Ӻź͵Ⱥ����Ҹ���һ���ո񣬳���֮���޶���ո�
*/
#include<stdio.h>
int main() {
	int a,b,c;
	for(a=2; a<=100; a++) {
		for(b=a; b<=100; b++) {
			int l=b,r=100;
			while(r-1>=l) {
				c=(l+r)/2;
				if(a*a+b*b==c*c) {
					printf("%d*%d + %d*%d = %d*%d\n",a,a,b,b,c,c);
					break;
				} else if(a*a+b*b<c*c) {
					r=c;
				} else {
					l=c+1;
				}
			}
		}
	}
	return 0;
}


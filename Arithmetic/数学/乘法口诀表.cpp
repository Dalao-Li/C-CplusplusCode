#include<iostream>
#include<cstdio>
using namespace std;
void multiplicationTable(const int n){
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			/*-4d表示左对齐，占4位*/
			printf("%d*%d=%-4d ",j,i,i*j);        
		}
		cout<<endl;
	}
} 
int main() {
	int n;
	cin>>n;
	multiplicationTable(n);
	return 0;
}

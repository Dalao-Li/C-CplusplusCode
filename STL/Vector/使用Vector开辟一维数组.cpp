#include<iostream>
#include<vector>
using namespace std;
void inputArray(vector<int> &v) {
	int len,i,t;
	cout<<"���������鳤��"<<endl;
	cin>>len;
	cout<<"������"<<len<<"������"<<endl;
	for(i=0; i<len; i++) {
		cin>>t;
		v.push_back(t);
	}
}

void ouputArray(vector<int> &v) {
	cout<<"������Ϊ��";
	for(auto v_quote:v) {
		cout<<v_quote<<" ";
	}
}

int main(int argc,char *args[]) {
    vector<int> v1;
	inputArray(v1);
	ouputArray(v1);
	return 0;

}

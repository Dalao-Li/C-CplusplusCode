#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int n,*p;
	cout<<"请输入想要输入的数组的长度:";
	cin>>n;
	p=new int[n];
	ofstream outfile("file.txt",ios::out);
	if(!outfile){
		cerr<<"open error!"<<endl;
		exit(1);
	}
	cout<<"enter "<<n<<" numbers:"<<endl;
	for(int i=0;i<n;i++){
		cin>>*(p+i);
		outfile<<*(p+i)<<" ";
	}
	outfile.close();
	delete[]p;
	return 0;
	
	
	
} 

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//����1  ��������
template <typename T>
void showvector(vector<T> v) {
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it<<" ";
	}
	cout << endl;
}

/*
����2  �±귨
int length =v.size()
for(int i=0;i<length;i++){
    cout<<vec1[i];
}
*/



int main() {
	vector<string> v6 = { "hi","my","name","is","lee" };
	v6.resize(3);                    //���µ���vector������С
	cout<<"���µ���vector������С��v6:";
	showvector(v6);
	vector<string> v11 = {"HELLO","sa","wdasdas","sdaAAA"};
	v11.erase(v11.begin()+2,v11.end()-1);  //ɾ��֮���Ԫ�أ�����Ԫ��ǰ��
	showvector(v11);                       //HELLO sa wdasdas"
	vector<int> v5 = { 1,2,3,4,5 };        //�б��ʼ��,ע��ʹ�õ��ǻ�����
	cout <<"v5�ĵ�һ��Ԫ��: "<< v5.front() << endl;       //���ʵ�һ��Ԫ��
	cout <<"v5�����һ��Ԫ��: "<<v5.back() << endl;       //�������һ��Ԫ��
	cout<<"v5:";
	showvector(v5);
	v5.pop_back();                   //ɾ�����һ��Ԫ��
	cout<<"ɾ�����һ��Ԫ�غ��v5:";
	showvector(v5);
	v5.push_back(6);                 //����һ��Ԫ�ز������������
	cout<<"����һ��Ԫ�ز�������������v5:";
	showvector(v5);
	v5.insert(v5.begin()+1,9);       //�ڵڶ���λ�ò�����Ԫ��
	cout<<"�ڵڶ���λ�ò�����Ԫ��9��v5:";
	showvector(v5);
	v5.erase(v5.begin() + 3);        //ɾ�����ĸ�Ԫ��
	cout<<"ɾ�����ĸ�Ԫ�ص�v5:";
	showvector(v5);
	v5.insert(v5.begin() + 1, 7,8);  //��������7��8
	cout<<"��������7��8���v5:";
	showvector(v5);
	v5.clear();                      //�����������
	cout<<"������������ݺ��v5:";
	showvector(v5);

	system("pause");
	return 0;
}
